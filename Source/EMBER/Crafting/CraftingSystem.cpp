#include "Crafting/CraftingSystem.h"
#include "Player/EmberPlayerCharacter.h"
#include "Item/Managers/InventoryManagerComponent.h"
#include "Item/ItemInstance.h"
#include "Item/ItemTemplate.h"
#include "Crafting/CraftingRecipeManager.h"
#include "GameplayTagsManager.h"
#include "UI/Data/EmberItemData.h"
#include "Item/Crafting/CraftingBuilding.h"
#include "UI/Crafting/CraftingWidget.h"


UCraftingSystem::UCraftingSystem()
{
    PrimaryComponentTick.bCanEverTick = false;
    RecipeManager = nullptr;
    CurrentStationForSystem = EStationType::None;
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

FCraftingResult UCraftingSystem::Client_PreCraftCheck(AEmberPlayerCharacter* Player, const FCraftingRecipeRow& Recipe, const TMap<FGameplayTag, int32>& InSelectedMainIngredients)
{
    FCraftingResult Result;
    Result.bWasSuccessful = false;

    if (!Player || !RecipeManager)
    {
        return Result;
    }
    
    if (!CanCraftRecipeAtStation(Recipe, CurrentStationForSystem))
    {
        return Result;
    }
    
    if (!HasRequiredMaterials(Player, Recipe, InSelectedMainIngredients))
    {
        return Result;
    }
    
    Result.bWasSuccessful = true;
    Result.Rarity = EvaluateItemRarity(Recipe, InSelectedMainIngredients);
    Result.ItemTemplateClass = Recipe.ItemTemplateClass;

    return Result;
}


bool UCraftingSystem::RequestServerCraft(AEmberPlayerCharacter* Player, ACraftingBuilding* CraftingStationActor, FName RecipeRowName, const TMap<FGameplayTag, int32>& InSelectedMainIngredients)
{
    if (!Player || !CraftingStationActor || RecipeRowName.IsNone()) return false;
    
    TArray<FGameplayTag> SelectedTagsArray;
    TArray<int32> SelectedQuantitiesArray;
    for (const auto& Pair : InSelectedMainIngredients)
    {
        SelectedTagsArray.Add(Pair.Key);
        SelectedQuantitiesArray.Add(Pair.Value);
    }

    CraftingStationActor->Server_ExecuteCrafting(RecipeRowName, SelectedTagsArray, SelectedQuantitiesArray, Player);
    return true;
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
        if (ProvidedMainCount < Recipe.RequiredMainMaterialCount) return false;
        
        for (const auto& SelectedPair : InSelectedMainIngredients)
        {
            const int32* OwnedCount = PlayerOwnedIngredients.Find(SelectedPair.Key);
            if (!OwnedCount || *OwnedCount < SelectedPair.Value) return false;
        }
    }

    for (const auto& RequiredPair : Recipe.Ingredients)
    {
        if (RequiredPair.Value <= 0) continue;
        const int32* OwnedCount = PlayerOwnedIngredients.Find(RequiredPair.Key);
        if (!OwnedCount || *OwnedCount < RequiredPair.Value) return false;
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
    int32 MaxPossibleScore = 0; 
    for(const FGameplayTag& Tag : Recipe.AllowedMainMaterialTags) MaxPossibleScore += GetMaterialScore(Tag) * Recipe.RequiredMainMaterialCount;
    if(MaxPossibleScore == 0 && Recipe.RequiredMainMaterialCount > 0) MaxPossibleScore = Recipe.RequiredMainMaterialCount * 6; 

    int32 MinPossibleScore = Recipe.RequiredMainMaterialCount * 1; 
    float Ratio = MaxPossibleScore > MinPossibleScore ? static_cast<float>(Score - MinPossibleScore) / (MaxPossibleScore - MinPossibleScore) : 0.f;
    Ratio = FMath::Clamp(Ratio, 0.f, 1.f);

    float Common = 0.f, Uncommon = 0.f, Rare = 0.f, Unique = 0.f, Legendary = 0.f;
    if (Ratio <= 0.2f) { Common = 1.f; }
    else if (Ratio <= 0.4f) { float T = (Ratio - 0.2f) / 0.2f; Common = FMath::Lerp(1.f, 0.7f, T); Uncommon = FMath::Lerp(0.f, 0.3f, T); }
    else if (Ratio <= 0.6f) { float T = (Ratio - 0.4f) / 0.2f; Common = FMath::Lerp(0.7f, 0.2f, T); Uncommon = FMath::Lerp(0.3f, 0.6f, T); Rare = FMath::Lerp(0.f, 0.2f, T); }
    else if (Ratio <= 0.8f) { float T = (Ratio - 0.6f) / 0.2f; Uncommon = FMath::Lerp(0.6f, 0.25f, T); Rare = FMath::Lerp(0.2f, 0.6f, T); Unique = FMath::Lerp(0.f, 0.15f, T); }
    else { float T = (Ratio - 0.8f) / 0.2f; Rare = FMath::Lerp(0.6f, 0.25f, T); Unique = FMath::Lerp(0.15f, 0.63f, T); Legendary = FMath::Lerp(0.f, 0.12f, T); }

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
            if (Rand < Accum) return Rarity;
        }
    }
    return EItemRarity::Common;
}

bool UCraftingSystem::ConsumeMaterials_Server(AEmberPlayerCharacter* Player, const FCraftingRecipeRow& Recipe, const TMap<FGameplayTag, int32>& InSelectedMainIngredients)
{
    if (!Player) return false; 
    UE_LOG(LogTemp, Warning, TEXT("CraftingSystem: ConsumeMaterials_Server - STUB! Material consumption logic needed here."));
    return true; 
}

int32 UCraftingSystem::GetMaterialScore(const FGameplayTag& MaterialTag) const
{
    const int32* ScorePtr = TagToScoreMap.Find(MaterialTag);
    return ScorePtr ? *ScorePtr : 0;
}