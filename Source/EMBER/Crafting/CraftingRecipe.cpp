#include "CraftingRecipe.h"

UCraftingRecipe::UCraftingRecipe()
    : ItemName(TEXT(""))
    , RequiredCraftingLevel(0)
    , CraftingTime(0.f)
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
        const int32* FoundQty = AvailableIngredients.Find(Pair.Key);
        if (!FoundQty || *FoundQty < Pair.Value)
        {
            return false;
        }
    }

    return true;
}
