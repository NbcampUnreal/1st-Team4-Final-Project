#include "CraftingRecipe.h"

UCraftingRecipe::UCraftingRecipe()
    : RequiredCraftingLevel(0)
    , CraftingTime(0.f)
    , bCraftInTable(true)
    , bCraftInFurnace(false)
    , bCraftInCookingPot(false)
    , bCraftInWeaponTable(false)
    , bCraftInClothingTable(false)
    , MainMaterialRequired(0)
{
}

bool UCraftingRecipe::CanCombine(const TMap<FString, int32>& AvailableIngredients, int32 PlayerCraftingLevel) const
{
    if (PlayerCraftingLevel < RequiredCraftingLevel)
    {
        return false;
    }
    
    for (const auto& Pair : Ingredients)
    {
        const FString& IngredientName = Pair.Key;
        int32 RequiredAmount = Pair.Value;
        const int32* PlayerAmount = AvailableIngredients.Find(IngredientName);
        if (!PlayerAmount || *PlayerAmount < RequiredAmount)
        {
            return false;
        }
    }
    
    return true;
}

bool UCraftingRecipe::IsCraftableAtCraftingTable() const
{
    return bCraftInTable;
}

bool UCraftingRecipe::IsCraftableAtFurnace() const
{
    return bCraftInFurnace;
}

bool UCraftingRecipe::IsCraftableAtCookingPot() const
{
    return bCraftInCookingPot;
}

bool UCraftingRecipe::IsCraftableAtWeaponTable() const
{
    return bCraftInWeaponTable;
}

bool UCraftingRecipe::IsCraftableAtClothingTable() const
{
    return bCraftInClothingTable;
}
