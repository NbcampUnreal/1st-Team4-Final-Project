#include "UI/Crafting/CraftingRecipeListWidget.h"
#include "Components/ListView.h"
#include "Crafting/CraftingRecipeManager.h"
#include "UI/Crafting/CraftingRecipeListItemData.h"

UCraftingRecipeListWidget::UCraftingRecipeListWidget(const FObjectInitializer& ObjectInitializer) 
	: Super(ObjectInitializer)
{
}

void UCraftingRecipeListWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (RecipeListView && !RecipeListView->OnItemClicked().IsBound())
	{
		RecipeListView->OnItemClicked().AddUObject(this, &UCraftingRecipeListWidget::HandleRecipeClicked);
	}
}

void UCraftingRecipeListWidget::SetRecipeList(const TArray<FCraftingRecipeRow>& Recipes)
{
	if (!RecipeListView)
	{
		UE_LOG(LogTemp, Warning, TEXT("UCraftingRecipeListWidget::SetRecipeList - RecipeListView is NULL."));
		return;
	}
    
	RecipeListView->ClearListItems();

	for (const FCraftingRecipeRow& Recipe : Recipes)
	{
		UCraftingRecipeListItemData* NewListItemData = NewObject<UCraftingRecipeListItemData>(this);
		if (NewListItemData)
		{
			NewListItemData->RecipeData = Recipe;
			RecipeListView->AddItem(NewListItemData);
		}
	}
}

void UCraftingRecipeListWidget::HandleRecipeClicked(UObject* ItemObject)
{
	UCraftingRecipeListItemData* ClickedListItemData = Cast<UCraftingRecipeListItemData>(ItemObject);
	if (ClickedListItemData)
	{
		OnRecipeSelected.Broadcast(ClickedListItemData->RecipeData);
	}
}