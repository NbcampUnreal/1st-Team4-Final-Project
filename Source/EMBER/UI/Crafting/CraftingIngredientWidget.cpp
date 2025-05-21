#include "CraftingIngredientWidget.h"
#include "Components/VerticalBox.h"
#include "Components/TextBlock.h"

void UCraftingIngredientSelectionWidget::SetIngredientData(const TMap<FString, int32>& Ingredients)
{
	if (!IngredientSelectionBox)
	{
		UE_LOG(LogTemp, Warning, TEXT("IngredientSelectionBox is null!"));
		return;
	}

	IngredientSelectionBox->ClearChildren();

	for (const TPair<FString, int32>& IngredientPair : Ingredients)
	{
		UTextBlock* IngredientText = NewObject<UTextBlock>(this);
		if (IngredientText)
		{
			FString DisplayText = FString::Printf(TEXT("%s: %d"), *IngredientPair.Key, IngredientPair.Value);
			IngredientText->SetText(FText::FromString(DisplayText));
			IngredientSelectionBox->AddChild(IngredientText);
		}
	}
}
