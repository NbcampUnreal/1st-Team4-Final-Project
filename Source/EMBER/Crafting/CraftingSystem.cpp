#include "CraftingSystem.h"
#include "../GameInfo/GameFlag.h" 
#include "CraftingRecipe.h" 
#include "CraftingRecipeManager.h" 
#include "Player/EmberPlayerCharacter.h"
#include "UI/Data/EmberItemData.h"
#include "Math/UnrealMathUtility.h"

UCraftingSystem::UCraftingSystem()
{
    RecipeManager = nullptr;
    ProcessingAnimation = nullptr;
    CurrentStation = EStationType::CraftingTable;
}

void UCraftingSystem::BeginPlay()
{
    Super::BeginPlay();
}

void UCraftingSystem::StartCrafting(AEmberPlayerCharacter* Player, const FString& ItemName)
{
    if (!RecipeManager) return;

    UCraftingRecipe* SelectedRecipe = RecipeManager->GetRecipeByName(ItemName);
    if (!SelectedRecipe) return;

    if (!CanCraftInCurrentStation(SelectedRecipe)) return;

    TMap<FString, int32> AvailableIngredients = AggregateIngredients(Player);

    if (!CanActivateCraftingButton(SelectedRecipe, AvailableIngredients)) return;

    const int32 PlayerCraftingLevel = 1;
    if (!SelectedRecipe->CanCombine(AvailableIngredients, PlayerCraftingLevel)) return;

    EItemRarity FinalGrade = CalculateCraftingOutcome(SelectedRecipe, AvailableIngredients, true);

    if (ProcessingAnimation)
    {
    }

    AddItemToInventory(Player, ItemName);
    UE_LOG(LogTemp, Log, TEXT("Crafting finished: %s, Grade: %d"), *ItemName, (int32)FinalGrade);
}

TMap<FString, int32> UCraftingSystem::AggregateIngredients(AEmberPlayerCharacter* Player)
{
    TMap<FString, int32> InventoryIngredients;
    TMap<FString, int32> ChestIngredients = SearchNearChestsIngredients(Player);

    for (auto& Pair : ChestIngredients)
    {
        int32* Existing = InventoryIngredients.Find(Pair.Key);
        if (Existing)
        {
            *Existing += Pair.Value;
        }
        else
        {
            InventoryIngredients.Add(Pair.Key, Pair.Value);
        }
    }
    return InventoryIngredients;
}

void UCraftingSystem::AddItemToInventory(AEmberPlayerCharacter* Player, const FString& ItemName)
{
    if (!Player) return;
    UE_LOG(LogTemp, Log, TEXT("AddItemToInventory: %s added (functionality not implemented)."), *ItemName);
}

bool UCraftingSystem::CanCraftInCurrentStation(const UCraftingRecipe* Recipe) const
{
    if (!Recipe) return false;
    switch (CurrentStation)
    {
    case EStationType::CraftingTable:
        return Recipe->IsCraftableAtCraftingTable();
    case EStationType::Furnace:
        return Recipe->IsCraftableAtFurnace();
    case EStationType::CookingPot:
        return Recipe->IsCraftableAtCookingPot();
    case EStationType::WeaponTable:
        return Recipe->IsCraftableAtWeaponTable();
    case EStationType::ClothingTable:
        return Recipe->IsCraftableAtClothingTable();
    default:
        return false;
    }
}

TMap<FString, int32> UCraftingSystem::SearchNearChestsIngredients(AEmberPlayerCharacter* Player)
{
    TMap<FString, int32> ChestIngredients;
    return ChestIngredients;
}

EItemRarity UCraftingSystem::CalculateCraftingOutcome(const UCraftingRecipe* Recipe, const TMap<FString, int32>& ChosenMaterials, bool bIsWeapon)
{
    int32 TotalScore = 0;

    auto GetWeaponMaterialScore = [](const FString& MaterialName) -> int32
    {
        if (MaterialName == "돌") return 1;
        else if (MaterialName == "일반 뼈") return 2;
        else if (MaterialName == "흑요석") return 3;
        else if (MaterialName == "단단한 뼈") return 4;
        else if (MaterialName == "철") return 5;
        else if (MaterialName == "희귀한 뼈") return 6;
        return 0;
    };

    auto GetClothingMaterialScore = [](const FString& MaterialName) -> int32
    {
        if (MaterialName == "찢어진 가죽") return 1;
        else if (MaterialName == "나무") return 2;
        else if (MaterialName == "온전한 가죽") return 3;
        else if (MaterialName == "흑요석") return 4;
        else if (MaterialName == "질긴 가죽") return 5;
        else if (MaterialName == "철") return 6;
        return 0;
    };

    for (const TPair<FString, int32>& Pair : ChosenMaterials)
    {
        int32 MaterialScore = bIsWeapon ? GetWeaponMaterialScore(Pair.Key) : GetClothingMaterialScore(Pair.Key);
        TotalScore += MaterialScore * Pair.Value;
    }

    FString MainMaterialStr = Recipe->MainMaterialType.GetTagName().ToString();
    int32 MainMaterialCount = 0;
    if (ChosenMaterials.Contains(MainMaterialStr))
    {
        MainMaterialCount = ChosenMaterials[MainMaterialStr];
    }

    if (MainMaterialCount != Recipe->MainMaterialRequired)
    {
        return EItemRarity::Poor;
    }

    float NormalizedScore = (float)TotalScore * 10.0f;

    if (NormalizedScore < 20.0f)
    {
        return EItemRarity::Poor;
    }
    else if (NormalizedScore < 40.0f)
    {
        float randVal = FMath::FRand();
        return (randVal < 0.7f) ? EItemRarity::Poor : EItemRarity::Common;
    }
    else if (NormalizedScore < 60.0f)
    {
        float randVal = FMath::FRand();
        if (randVal < 0.2f)
            return EItemRarity::Poor;
        else if (randVal < 0.8f)
            return EItemRarity::Common;
        else
            return EItemRarity::Uncommon;
    }
    else if (NormalizedScore < 80.0f)
    {
        float randVal = FMath::FRand();
        if (randVal < 0.25f)
            return EItemRarity::Common;
        else if (randVal < 0.85f)
            return EItemRarity::Uncommon;
        else
            return EItemRarity::Rare;
    }
    else
    {
        float randVal = FMath::FRand();
        if (randVal < 0.25f)
            return EItemRarity::Uncommon;
        else if (randVal < 0.88f)
            return EItemRarity::Rare;
        else
            return EItemRarity::Legendary;
    }
}

bool UCraftingSystem::CanActivateCraftingButton(const UCraftingRecipe* Recipe, const TMap<FString, int32>& AggregatedIngredients)
{
    if (!Recipe)
    {
        return false;
    }

    FString MainMaterialStr = Recipe->MainMaterialType.GetTagName().ToString();
    int32 MainMaterialCount = 0;
    if (AggregatedIngredients.Contains(MainMaterialStr))
    {
        MainMaterialCount = AggregatedIngredients[MainMaterialStr];
    }

    return (MainMaterialCount == Recipe->MainMaterialRequired);
}
