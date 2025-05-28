#include "CraftingListEntryWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "CraftingResultWidget.h"

void UCraftingListEntryWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SetIsEnabled(true);
}

void UCraftingListEntryWidget::Init(UCraftingRecipeData* InRecipe, UCraftingResultWidget* InResultWidget)
{
	Recipe = InRecipe;
	ResultWidget = InResultWidget;

	if (RecipeNameText && Recipe)
	{
		RecipeNameText->SetText(Recipe->RecipeDisplayName);
	}
}

void UCraftingListEntryWidget::OnClicked()
{
	if (ResultWidget && Recipe)
	{
		ResultWidget->SetTargetRecipe(Recipe);
	}
}
