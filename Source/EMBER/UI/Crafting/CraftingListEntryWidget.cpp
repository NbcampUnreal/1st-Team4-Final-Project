#include "UI/Crafting/CraftingListEntryWidget.h" 
#include "Components/TextBlock.h"
#include "UI/Crafting/CraftingRecipeListItemData.h" 
#include "Crafting/CraftingRecipeManager.h" 


UCraftingListEntryWidget::UCraftingListEntryWidget(const FObjectInitializer& ObjectInitializer) 
	: Super(ObjectInitializer)
{
	CurrentListItemData = nullptr;
}

void UCraftingListEntryWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UCraftingListEntryWidget::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	CurrentListItemData = Cast<UCraftingRecipeListItemData>(ListItemObject);

	if (CurrentListItemData && RecipeNameText)
	{
		RecipeNameText->SetText(CurrentListItemData->RecipeData.RecipeDisplayName);
	}
	else if (RecipeNameText)
	{
		RecipeNameText->SetText(FText::FromString(TEXT("Invalid Data")));
	}
}

void UCraftingListEntryWidget::HandleClick()
{
	if (CurrentListItemData)
	{
		OnThisEntryClicked.Broadcast(CurrentListItemData);
	}
}