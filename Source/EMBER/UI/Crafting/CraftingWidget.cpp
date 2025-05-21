#include "CraftingWidget.h"
#include "Components/TextBlock.h"

UCraftingWidget::UCraftingWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UCraftingWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (ItemNameText)
	{
		ItemNameText->SetText(FText::FromString(TEXT("Item Name Not Set")));
	}
}

void UCraftingWidget::InitializeWidget(const FString& ItemName)
{
	if (ItemNameText)
	{
		ItemNameText->SetText(FText::FromString(ItemName));
	}
}
