#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CraftingRecipe.generated.h"

UCLASS(BlueprintType)
class EMBER_API UCraftingRecipe : public UObject
{
    GENERATED_BODY()

public:
    UCraftingRecipe();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
    FString ItemName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
    TMap<FString, int32> Ingredients;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
    int32 RequiredCraftingLevel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
    float CraftingTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
    bool bCraftInTable;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
    bool bCraftInFurnace;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
    bool bCraftInCookingPot;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
    bool bCraftInWeaponTable;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
    bool bCraftInClothingTable;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
    int32 MainMaterialRequired;

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    bool CanCombine(const TMap<FString, int32>& AvailableIngredients, int32 PlayerCraftingLevel) const;

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    bool IsCraftableAtCraftingTable() const;

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    bool IsCraftableAtFurnace() const;

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    bool IsCraftableAtCookingPot() const;

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    bool IsCraftableAtWeaponTable() const;

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    bool IsCraftableAtClothingTable() const;
};
