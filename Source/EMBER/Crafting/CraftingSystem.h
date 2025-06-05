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
class ACraftingBuilding;

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
    bool RequestServerCraft(AEmberPlayerCharacter* Player, ACraftingBuilding* CraftingStationActor, FName RecipeRowName, const TMap<FGameplayTag, int32>& InSelectedMainIngredients);

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

    UFUNCTION(BlueprintPure, Category = "Crafting")
    const UItemTemplate* GetItemTemplateById(int32 TemplateID) const; 
    
    UFUNCTION(BlueprintCallable, Category = "Crafting") 
    bool ConsumeMaterials(AEmberPlayerCharacter* Player, const FCraftingRecipeRow& Recipe, const TMap<FGameplayTag, int32>& InSelectedMainIngredients);

private:
    void InitializeTagMap();
    int32 CalculateScore(const FCraftingRecipeRow& Recipe, const TMap<FGameplayTag, int32>& InSelectedMainIngredients) const;
    
public:
    EStationType CurrentStationForSystem = EStationType::None; 

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting System")
    TObjectPtr<UCraftingRecipeManager> RecipeManager;

private:
    TMap<FGameplayTag, int32> TagToScoreMap;
};