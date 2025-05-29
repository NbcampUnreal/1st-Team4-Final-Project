#include "UI/Crafting/CraftingIngredientWidget.h"
#include "Components/VerticalBox.h"
#include "Components/TextBlock.h"
#include "GameplayTagContainer.h"

UCraftingIngredientWidget::UCraftingIngredientWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UCraftingIngredientWidget::SetIngredientData(const TMap<FGameplayTag, int32>& Ingredients)
{
	if (!IngredientDisplayBox)
	{
		UE_LOG(LogTemp, Warning, TEXT("IngredientDisplayBox is null!"));
		return;
	}

	IngredientDisplayBox->ClearChildren();

	for (const TPair<FGameplayTag, int32>& IngredientPair : Ingredients)
	{
		UTextBlock* IngredientText = NewObject<UTextBlock>(this);
		if (IngredientText)
		{
			FString TagName = IngredientPair.Key.ToString(); 
			FString DisplayText = FString::Printf(TEXT("%s: %d"), *TagName, IngredientPair.Value);
			IngredientText->SetText(FText::FromString(DisplayText));
			IngredientDisplayBox->AddChild(IngredientText);
		}
	}
}