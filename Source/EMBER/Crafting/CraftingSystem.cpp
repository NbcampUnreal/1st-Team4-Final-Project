#include "Crafting/CraftingSystem.h"
#include "Player/EmberPlayerCharacter.h"
#include "Item/Managers/InventoryManagerComponent.h"
#include "Item/ItemInstance.h"
#include "Item/ItemTemplate.h"
#include "Crafting/CraftingRecipeManager.h"
#include "GameplayTagsManager.h"

UCraftingSystem::UCraftingSystem()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UCraftingSystem::InitializeComponent()
{
    Super::InitializeComponent();
    InitializeTagMap();
}

void UCraftingSystem::InitializeTagMap()
{
    TagToScoreMap.Empty();
    TagToScoreMap.Add(UGameplayTagsManager::Get().RequestGameplayTag(FName("Material.Stone")), 1);
    TagToScoreMap.Add(UGameplayTagsManager::Get().RequestGameplayTag(FName("Material.Bone.Normal")), 2);
    TagToScoreMap.Add(UGameplayTagsManager::Get().RequestGameplayTag(FName("Material.Obsidian")), 3);
    TagToScoreMap.Add(UGameplayTagsManager::Get().RequestGameplayTag(FName("Material.Bone.Hard")), 4);
    TagToScoreMap.Add(UGameplayTagsManager::Get().RequestGameplayTag(FName("Material.Iron")), 5);
    TagToScoreMap.Add(UGameplayTagsManager::Get().RequestGameplayTag(FName("Material.Bone.Rare")), 6);
}

void UCraftingSystem::BeginPlay()
{
    Super::BeginPlay();
}

void UCraftingSystem::StartCrafting(AEmberPlayerCharacter* Player, const FCraftingRecipeRow& Recipe, const TMap<FGameplayTag, int32>& InSelectedMainIngredients)
{
    if (!Player) return;
    if (!RecipeManager)
    {
        UE_LOG(LogTemp, Error, TEXT("CraftingSystem: RecipeManager is not set!"));
        return;
    }
    if (!CanCraftRecipeAtStation(Recipe, CurrentStation))
    {
        UE_LOG(LogTemp, Warning, TEXT("CraftingSystem: Cannot craft recipe at this station."));
        return;
    }

    if (!HasRequiredMaterials(Player, Recipe, InSelectedMainIngredients))
    {
        UE_LOG(LogTemp, Warning, TEXT("CraftingSystem: Missing required materials."));
        return;
    }

    EItemRarity FinalRarity = EItemRarity::Common;
    bool bUsesQuality = Recipe.RequiredMainMaterialCount > 0;

    if (bUsesQuality)
    {
        FinalRarity = EvaluateItemRarity(Recipe, InSelectedMainIngredients);
    }

    if (!ConsumeMaterials(Player, Recipe, InSelectedMainIngredients))
    {
        UE_LOG(LogTemp, Warning, TEXT("CraftingSystem: Failed to consume materials."));
        return;
    }

    UItemInstance* NewItem = NewObject<UItemInstance>(Player);
    if (NewItem)
    {
        NewItem->Init(Recipe.OutputItemTemplateID, FinalRarity);
        
        UInventoryManagerComponent* PlayerInventory = Player->FindComponentByClass<UInventoryManagerComponent>();
        if(PlayerInventory)
        {
            const UItemTemplate* OutputItemTemplate = GetItemTemplateById(Recipe.OutputItemTemplateID);
            if(OutputItemTemplate)
            {
                UE_LOG(LogTemp, Warning, TEXT("Crafted Item: TemplateID = %d, Rarity = %s. ADD TO INVENTORY (using TryAddItemByRarity or similar) NEEDED."),
                    NewItem->GetItemTemplateID(),
                    *UEnum::GetValueAsString(FinalRarity));
            }
            else
            {
                UE_LOG(LogTemp, Error, TEXT("CraftingSystem: Could not find ItemTemplate for OutputItemTemplateID %d to add to inventory."), Recipe.OutputItemTemplateID);
            }
        }
        else
        {
             UE_LOG(LogTemp, Error, TEXT("CraftingSystem: PlayerInventory not found to add crafted item."));
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("CraftingSystem: Failed to create NewItem instance."));
    }
}

bool UCraftingSystem::CanCraftRecipeAtStation(const FCraftingRecipeRow& Recipe, EStationType Station) const
{
    if (Recipe.bCraftableByCharacter && Station == EStationType::None) return true;
    return Recipe.CraftingStation == Station;
}

bool UCraftingSystem::HasRequiredMaterials(AEmberPlayerCharacter* Player, const FCraftingRecipeRow& Recipe, const TMap<FGameplayTag, int32>& InSelectedMainIngredients) const
{
    if (!Player || !RecipeManager) return false;

    UInventoryManagerComponent* PlayerInventory = Player->FindComponentByClass<UInventoryManagerComponent>();
    if (!PlayerInventory) return false;

    TMap<FGameplayTag, int32> PlayerOwnedIngredients = AggregateIngredients(Player);
    bool bUsesQuality = Recipe.RequiredMainMaterialCount > 0;

    if (bUsesQuality)
    {
        int32 ProvidedMainCount = 0;
        for (const auto& Pair : InSelectedMainIngredients)
        {
            if (Recipe.AllowedMainMaterialTags.HasTag(Pair.Key))
            {
                ProvidedMainCount += Pair.Value;
            }
        }
        if (ProvidedMainCount < Recipe.RequiredMainMaterialCount)
        {
            UE_LOG(LogTemp, Warning, TEXT("CraftingSystem: Not enough selected main material count. Need %d, Got %d"), Recipe.RequiredMainMaterialCount, ProvidedMainCount);
            return false;
        }
        for (const auto& SelectedPair : InSelectedMainIngredients)
        {
            const int32* OwnedCount = PlayerOwnedIngredients.Find(SelectedPair.Key);
            if (!OwnedCount || *OwnedCount < SelectedPair.Value)
            {
                 UE_LOG(LogTemp, Warning, TEXT("CraftingSystem: Player does not own enough of selected main material %s. Need %d, Got %d"), *SelectedPair.Key.ToString(), SelectedPair.Value, OwnedCount ? *OwnedCount : 0);
                return false;
            }
        }
    }

    for (const auto& RequiredPair : Recipe.Ingredients)
    {
        const int32* OwnedCount = PlayerOwnedIngredients.Find(RequiredPair.Key);
        if (!OwnedCount || *OwnedCount < RequiredPair.Value)
        {
            UE_LOG(LogTemp, Warning, TEXT("CraftingSystem: Not enough general material %s. Need %d, Got %d"), *RequiredPair.Key.ToString(), RequiredPair.Value, OwnedCount ? *OwnedCount : 0);
            return false;
        }
    }

    return true;
}


TMap<FGameplayTag, int32> UCraftingSystem::AggregateIngredients(AEmberPlayerCharacter* Player) const
{
    TMap<FGameplayTag, int32> AggregatedMap;
    if (!Player || !RecipeManager) return AggregatedMap;

    UInventoryManagerComponent* PlayerInventory = Player->FindComponentByClass<UInventoryManagerComponent>();
    if (!PlayerInventory) return AggregatedMap;

    const TArray<FInventoryEntry>& AllEntries = PlayerInventory->GetAllEntries();
    for (const FInventoryEntry& Entry : AllEntries)
    {
        UItemInstance* ItemInstance = Entry.GetItemInstance();
        if (ItemInstance && Entry.GetItemCount() > 0)
        {
            FGameplayTag MaterialTag = RecipeManager->GetMaterialTagForItem(ItemInstance->GetItemTemplateID());
            if (MaterialTag.IsValid())
            {
                AggregatedMap.FindOrAdd(MaterialTag) += Entry.GetItemCount();
            }
        }
    }
    return AggregatedMap;
}

int32 UCraftingSystem::CalculateScore(const FCraftingRecipeRow& Recipe, const TMap<FGameplayTag, int32>& InSelectedMainIngredients) const
{
    if (Recipe.RequiredMainMaterialCount == 0) return 0;

    int32 Score = 0;
    for (const auto& Pair : InSelectedMainIngredients)
    {
        if (Recipe.AllowedMainMaterialTags.HasTag(Pair.Key))
        {
            const int32* FoundScore = TagToScoreMap.Find(Pair.Key);
            if (FoundScore)
            {
                Score += (*FoundScore) * Pair.Value;
            }
        }
    }
    return Score;
}

TMap<EItemRarity, float> UCraftingSystem::GetRarityProbabilities(const FCraftingRecipeRow& Recipe, const TMap<FGameplayTag, int32>& InSelectedMainIngredients) const
{
    TMap<EItemRarity, float> Result;
    bool bUsesQuality = Recipe.RequiredMainMaterialCount > 0;

    if (!bUsesQuality)
    {
        Result.Add(EItemRarity::Common, 1.f);
        return Result;
    }
    
    int32 Score = CalculateScore(Recipe, InSelectedMainIngredients);
    int32 MaxScore = Recipe.RequiredMainMaterialCount * 6;
    int32 MinScore = Recipe.RequiredMainMaterialCount * 1;

    float Ratio = MaxScore > MinScore ? (float)(Score - MinScore) / (MaxScore - MinScore) : 0.f;
    Ratio = FMath::Clamp(Ratio, 0.f, 1.f);

    float Common = 0.f, Uncommon = 0.f, Rare = 0.f, Unique = 0.f, Legendary = 0.f;

    if (Ratio <= 0.2f)
    {
        Common = 1.f;
    }
    else if (Ratio <= 0.4f)
    {
        float T = (Ratio - 0.2f) / 0.2f;
        Common = FMath::Lerp(1.f, 0.7f, T);
        Uncommon = FMath::Lerp(0.f, 0.3f, T);
    }
    else if (Ratio <= 0.6f)
    {
        float T = (Ratio - 0.4f) / 0.2f;
        Common = FMath::Lerp(0.7f, 0.2f, T);
        Uncommon = FMath::Lerp(0.3f, 0.6f, T);
        Rare = FMath::Lerp(0.f, 0.2f, T);
    }
    else if (Ratio <= 0.8f)
    {
        float T = (Ratio - 0.6f) / 0.2f;
        Uncommon = FMath::Lerp(0.6f, 0.25f, T);
        Rare = FMath::Lerp(0.2f, 0.6f, T);
        Unique = FMath::Lerp(0.f, 0.15f, T);
    }
    else 
    {
        float T = (Ratio - 0.8f) / 0.2f;
        Rare = FMath::Lerp(0.6f, 0.25f, T);
        Unique = FMath::Lerp(0.15f, 0.63f, T);
        Legendary = FMath::Lerp(0.f, 0.12f, T);
    }

    Result.Add(EItemRarity::Common, Common > 0.f ? Common : 0.f);
    Result.Add(EItemRarity::Uncommon, Uncommon > 0.f ? Uncommon : 0.f);
    Result.Add(EItemRarity::Rare, Rare > 0.f ? Rare : 0.f);
    Result.Add(EItemRarity::Unique, Unique > 0.f ? Unique : 0.f);
    Result.Add(EItemRarity::Legendary, Legendary > 0.f ? Legendary : 0.f);

    return Result;
}

EItemRarity UCraftingSystem::EvaluateItemRarity(const FCraftingRecipeRow& Recipe, const TMap<FGameplayTag, int32>& InSelectedMainIngredients) const
{
    bool bUsesQuality = Recipe.RequiredMainMaterialCount > 0;
    if (!bUsesQuality) return EItemRarity::Common;

    TMap<EItemRarity, float> Probs = GetRarityProbabilities(Recipe, InSelectedMainIngredients);
    float Rand = FMath::FRand();
    float Accum = 0.f;

    TArray<EItemRarity> RarityOrder = { EItemRarity::Common, EItemRarity::Uncommon, EItemRarity::Rare, EItemRarity::Unique, EItemRarity::Legendary };

    for (EItemRarity Rarity : RarityOrder)
    {
        if (Probs.Contains(Rarity))
        {
            Accum += Probs.FindChecked(Rarity);
            if (Rand < Accum)
            {
                return Rarity;
            }
        }
    }
    return EItemRarity::Common;
}

const UItemTemplate* UCraftingSystem::GetItemTemplateById(int32 TemplateID) const
{
    UE_LOG(LogTemp, Error, TEXT("UCraftingSystem::GetItemTemplateById - NOT IMPLEMENTED. Please implement item template fetching."));
    return nullptr;
}

bool UCraftingSystem::ConsumeMaterials(AEmberPlayerCharacter* Player, const FCraftingRecipeRow& Recipe, const TMap<FGameplayTag, int32>& InSelectedMainIngredients)
{
    if (!Player || !RecipeManager) return false; // Recipe is now a reference, always "valid" if passed
    UInventoryManagerComponent* PlayerInventory = Player->FindComponentByClass<UInventoryManagerComponent>();
    if (!PlayerInventory) return false;

    UE_LOG(LogTemp, Warning, TEXT("CraftingSystem: ConsumeMaterials - Material consumption logic needs to be fully implemented based on InventoryManagerComponent capabilities."));

    bool bUsesQuality = Recipe.RequiredMainMaterialCount > 0;

    if (bUsesQuality)
    {
        for (const auto& Pair : InSelectedMainIngredients)
        {
            UE_LOG(LogTemp, Warning, TEXT("Attempting to consume MAIN material %s x %d"), *Pair.Key.ToString(), Pair.Value);
        }
    }

    for (const auto& Pair : Recipe.Ingredients)
    {
        UE_LOG(LogTemp, Warning, TEXT("Attempting to consume GENERAL material %s x %d"), *Pair.Key.ToString(), Pair.Value);
    }
    return true; 
}

int32 UCraftingSystem::GetMaterialScore(const FGameplayTag& MaterialTag) const
{
    const int32* ScorePtr = TagToScoreMap.Find(MaterialTag);
    return ScorePtr ? *ScorePtr : 0;
}