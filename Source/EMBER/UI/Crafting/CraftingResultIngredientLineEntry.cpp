#include "UI/Crafting/CraftingResultIngredientLineEntry.h" // 실제 헤더 경로로 수정
#include "Components/TextBlock.h"
#include "Components/HorizontalBox.h"
#include "Styling/SlateColor.h"

UCraftingResultIngredientLineEntry::UCraftingResultIngredientLineEntry(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	IngredientNameText = nullptr;
	QuantityRatioText = nullptr;
	LayoutHorizontalBox = nullptr;
}

void UCraftingResultIngredientLineEntry::SetLineData(const FText& IngredientName, int32 OwnedCount, int32 RequiredCount, bool bHasEnough)
{
	if (IngredientNameText)
	{
		IngredientNameText->SetText(IngredientName);
	}

	if (QuantityRatioText)
	{
		QuantityRatioText->SetText(FText::FromString(FString::Printf(TEXT("%d / %d"), OwnedCount, RequiredCount)));
		QuantityRatioText->SetColorAndOpacity(bHasEnough ? FSlateColor(FLinearColor::White) : FSlateColor(FLinearColor::Red));
	}
}