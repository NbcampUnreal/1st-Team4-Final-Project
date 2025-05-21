#include "CraftingResultWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

void UCraftingResultPreviewWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (CraftButton)
	{
		CraftButton->OnClicked.AddDynamic(this, &UCraftingResultPreviewWidget::OnCraftButtonClicked);
	}
}

void UCraftingResultPreviewWidget::UpdateResultPreview(const FString& PreviewText)
{
	if (ResultPreviewText)
	{
		ResultPreviewText->SetText(FText::FromString(PreviewText));
	}
}

void UCraftingResultPreviewWidget::OnCraftButtonClicked()
{
	OnCraftButtonPressed();

}
