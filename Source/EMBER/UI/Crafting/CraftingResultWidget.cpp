#include "CraftingResultWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void UCraftingResultWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (CraftButton)
	{
		CraftButton->OnClicked.AddDynamic(this, &UCraftingResultWidget::OnCraftButtonClicked);
	}
}

void UCraftingResultWidget::OnCraftButtonClicked()
{
	OnCraftActionRequested.Broadcast();
}

void UCraftingResultWidget::UpdateRarityChances(const TMap<EItemRarity, float>& RarityChances)
{
	if(ResultText)
	{
		FString DisplayText = TEXT("Rarity Chances:\n");
		for (const auto& Pair : RarityChances)
		{
			DisplayText += FString::Printf(TEXT("- Chance: %.2f%%\n"), Pair.Value * 100.0f);
		}
		ResultText->SetText(FText::FromString(DisplayText));
	}
}

void UCraftingResultWidget::RefreshRarityPreview()
{
}

void UCraftingResultWidget::SetTargetRecipe(UCraftingRecipeData* InRecipe)
{
	TargetRecipe = InRecipe;
	if (ResultText && TargetRecipe)
	{
		// ResultText->SetText(TargetRecipe->RecipeName);
	}
	RefreshRarityPreview();
}

void UCraftingResultWidget::SetProvidedIngredients(const TMap<FGameplayTag, int32>& InIngredients)
{
	ProvidedIngredients = InIngredients;
}