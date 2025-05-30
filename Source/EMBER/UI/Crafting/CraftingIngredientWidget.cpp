#include "UI/Crafting/CraftingIngredientWidget.h"
#include "Components/VerticalBox.h"
#include "Components/TextBlock.h"
#include "GameplayTagContainer.h"
#include "Crafting/CraftingRecipeManager.h"

UCraftingIngredientWidget::UCraftingIngredientWidget(const FObjectInitializer& ObjectInitializer) 
	: Super(ObjectInitializer)
{
}

void UCraftingIngredientWidget::UpdateDisplay(const FCraftingRecipeRow& ForRecipe, const TMap<FGameplayTag, int32>& PlayerOwnedIngredients, int32 CraftingAmount)
{
	if (!IngredientDisplayBox)
	{
		UE_LOG(LogTemp, Warning, TEXT("IngredientDisplayBox is null in UCraftingIngredientWidget!"));
		return;
	}
	IngredientDisplayBox->ClearChildren();

	if (CraftingAmount <= 0) 
	{
		return;
	}

	for (const TPair<FGameplayTag, int32>& RequiredIngredientPair : ForRecipe.Ingredients)
	{
		UTextBlock* IngredientLineText = NewObject<UTextBlock>(this);
		if (IngredientLineText)
		{
			const FGameplayTag& IngredientTag = RequiredIngredientPair.Key;
			const int32 RequiredPerItem = RequiredIngredientPair.Value;
			const int32 TotalRequiredForBatch = RequiredPerItem * CraftingAmount;
			const int32 OwnedAmount = PlayerOwnedIngredients.FindRef(IngredientTag);

			FString MaterialName = IngredientTag.GetTagName().ToString(); 
			FString DisplayText = FString::Printf(TEXT("%s: %d / %d"), *MaterialName, OwnedAmount, TotalRequiredForBatch);
			IngredientLineText->SetText(FText::FromString(DisplayText));

			if (OwnedAmount < TotalRequiredForBatch)
			{
				IngredientLineText->SetColorAndOpacity(FSlateColor(FLinearColor::Red));
			}
			else
			{
				IngredientLineText->SetColorAndOpacity(FSlateColor(FLinearColor::White));
			}
			IngredientDisplayBox->AddChild(IngredientLineText);
		}
	}
}