#include "CraftingRecipeManager.h"

UCraftingRecipe* UCraftingRecipeManager::GetRecipeByName(const FString& RecipeName) const
{
	for (UCraftingRecipe* Recipe : Recipes)
	{
		if (Recipe && Recipe->ItemName.Equals(RecipeName))
		{
			return Recipe;
		}
	}
	return nullptr;
}
