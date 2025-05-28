#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "CraftingRecipeManager.h"
#include "GameFlag.h"
#include "CraftingSystem.generated.h"

class AEmberPlayerCharacter;
class UCraftingRecipeData;
class UInventoryManagerComponent;
class UItemTemplate;
class UCraftingRecipeManager;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class EMBER_API UCraftingSystem : public UActorComponent
{
    GENERATED_BODY()

public:
    UCraftingSystem();

protected:
    virtual void BeginPlay() override;

public:
    UFUNCTION(BlueprintCallable, Category = "Crafting")
    void StartCrafting(AEmberPlayerCharacter* Player, UCraftingRecipeData* Recipe, const TMap<FGameplayTag, int32>& InSelectedMainIngredients);

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    bool CanCraftRecipeAtStation(const UCraftingRecipeData* Recipe, EStationType Station) const;

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    bool HasRequiredMaterials(AEmberPlayerCharacter* Player, const UCraftingRecipeData* Recipe, const TMap<FGameplayTag, int32>& InSelectedMainIngredients) const;

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    TMap<FGameplayTag, int32> AggregateIngredients(AEmberPlayerCharacter* Player) const;

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    TMap<EItemRarity, float> GetRarityProbabilities(const UCraftingRecipeData* Recipe, const TMap<FGameplayTag, int32>& InSelectedMainIngredients) const;

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    EItemRarity EvaluateItemRarity(const UCraftingRecipeData* Recipe, const TMap<FGameplayTag, int32>& InSelectedMainIngredients) const;

private:
    int32 CalculateScore(const UCraftingRecipeData* Recipe, const TMap<FGameplayTag, int32>& InSelectedMainIngredients) const;
    bool ConsumeMaterials(AEmberPlayerCharacter* Player, const UCraftingRecipeData* Recipe, const TMap<FGameplayTag, int32>& InSelectedMainIngredients);
    const UItemTemplate* GetItemTemplateById(int32 TemplateID) const;

public:
    EStationType CurrentStation = EStationType::None;

    UPROPERTY(EditInstanceOnly, Category = "Crafting System")
    TObjectPtr<UCraftingRecipeManager> RecipeManager;

private:
    TMap<FGameplayTag, int32> TagToScoreMap;
};