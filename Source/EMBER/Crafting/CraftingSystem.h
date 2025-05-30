#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Crafting/CraftingRecipeManager.h"
#include "GameFlag.h"
#include "Player/EmberPlayerCharacter.h"
#include "CraftingSystem.generated.h"

class UInventoryManagerComponent;
class UItemTemplate;
class UItemInstance;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class EMBER_API UCraftingSystem : public UActorComponent
{
    GENERATED_BODY()

public:
    UCraftingSystem();

protected:
    virtual void InitializeComponent() override;
    virtual void BeginPlay() override;

public:
    UFUNCTION(BlueprintCallable, Category = "Crafting")
    UItemInstance* StartCrafting(AEmberPlayerCharacter* Player, const FCraftingRecipeRow& Recipe, const TMap<FGameplayTag, int32>& InSelectedMainIngredients);

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    bool CanCraftRecipeAtStation(const FCraftingRecipeRow& Recipe, EStationType Station) const;

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    bool HasRequiredMaterials(AEmberPlayerCharacter* Player, const FCraftingRecipeRow& Recipe, const TMap<FGameplayTag, int32>& InSelectedMainIngredients) const;

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    TMap<FGameplayTag, int32> AggregateIngredients(AEmberPlayerCharacter* Player) const;

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    TMap<EItemRarity, float> GetRarityProbabilities(const FCraftingRecipeRow& Recipe, const TMap<FGameplayTag, int32>& InSelectedMainIngredients) const;

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    EItemRarity EvaluateItemRarity(const FCraftingRecipeRow& Recipe, const TMap<FGameplayTag, int32>& InSelectedMainIngredients) const;
    
    UFUNCTION(BlueprintPure, Category = "Crafting")
    int32 GetMaterialScore(const FGameplayTag& MaterialTag) const;

private:
    void InitializeTagMap();
    int32 CalculateScore(const FCraftingRecipeRow& Recipe, const TMap<FGameplayTag, int32>& InSelectedMainIngredients) const;
    bool ConsumeMaterials(AEmberPlayerCharacter* Player, const FCraftingRecipeRow& Recipe, const TMap<FGameplayTag, int32>& InSelectedMainIngredients);
    const UItemTemplate* GetItemTemplateById(int32 TemplateID) const;

public:
    EStationType CurrentStation = EStationType::None;

    UPROPERTY(EditAnywhere, Category = "Crafting System")
    TObjectPtr<UCraftingRecipeManager> RecipeManager;

private:
    TMap<FGameplayTag, int32> TagToScoreMap;
};