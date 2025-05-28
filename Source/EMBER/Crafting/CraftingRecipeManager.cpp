#include "CraftingRecipeManager.h"

UCraftingRecipeData* UCraftingRecipeManager::GetRecipeByTemplateID(int32 TemplateID) const
{
    for (UCraftingRecipeData* Recipe : Recipes)
    {
        if (Recipe && Recipe->OutputItemTemplateID == TemplateID)
        {
            return Recipe;
        }
    }
    return nullptr;
}

FGameplayTag UCraftingRecipeManager::GetMaterialTagForItem(int32 ItemTemplateID) const
{
    const FGameplayTag* FoundTag = ItemIDToMaterialTagMap.Find(ItemTemplateID);
    if (FoundTag)
    {
        return *FoundTag;
    }
    return FGameplayTag::EmptyTag;
}