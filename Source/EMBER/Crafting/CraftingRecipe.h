#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "CraftingRecipe.generated.h"

UCLASS(Blueprintable)
class EMBER_API UCraftingRecipe : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting Recipe")
    FGameplayTag RecipeTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting Recipe")
    TMap<FString, int32> Ingredients;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting Recipe")
    float CraftingTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting Recipe")
    FGameplayTag EffectTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting Recipe")
    FGameplayTag MainMaterialType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting Recipe")
    int32 MainMaterialRequired;

    UFUNCTION(BlueprintCallable, Category = "Crafting Recipe")
    bool IsCraftableAtCraftingTable() const { return true; }
    
    UFUNCTION(BlueprintCallable, Category = "Crafting Recipe")
    bool IsCraftableAtFurnace() const { return true; }
    
    UFUNCTION(BlueprintCallable, Category = "Crafting Recipe")
    bool IsCraftableAtCookingPot() const { return true; }
    
    UFUNCTION(BlueprintCallable, Category = "Crafting Recipe")
    bool IsCraftableAtWeaponTable() const { return true; }
    
    UFUNCTION(BlueprintCallable, Category = "Crafting Recipe")
    bool IsCraftableAtClothingTable() const { return true; }

    UFUNCTION(BlueprintCallable, Category = "Crafting Recipe")
    bool CanCombine(const TMap<FString, int32>& ProvidedIngredients, int32 PlayerCraftingLevel) const {
         return true;
    }
};
