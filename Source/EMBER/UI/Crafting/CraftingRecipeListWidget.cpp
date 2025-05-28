#include "CraftingRecipeListWidget.h"
#include "Components/ListView.h"
#include "Crafting/CraftingRecipeManager.h"

void UCraftingRecipeListWidget::SetRecipeList(const TArray<UCraftingRecipeData*>& Recipes)
{
	if (!RecipeListView) return;

	RecipeListView->ClearListItems();

	for (UCraftingRecipeData* Recipe : Recipes)
	{
		if (Recipe)
		{
			RecipeListView->AddItem(Recipe);
		}
	}
}
