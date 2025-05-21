#include "CraftingRecipeListWidget.h"
#include "Components/ScrollBox.h"
#include "Components/TextBlock.h"

void UCraftingRecipeListWidget::SetRecipeList(const TArray<FString>& Recipes)
{
	if (!RecipeListScrollBox)
	{
		UE_LOG(LogTemp, Warning, TEXT("RecipeListScrollBox is null!"));
		return;
	}

	RecipeListScrollBox->ClearChildren();

	for (const FString& Recipe : Recipes)
	{
		UTextBlock* RecipeText = NewObject<UTextBlock>(this);
		if (RecipeText)
		{
			RecipeText->SetText(FText::FromString(Recipe));
			RecipeListScrollBox->AddChild(RecipeText);
		}
	}
}
