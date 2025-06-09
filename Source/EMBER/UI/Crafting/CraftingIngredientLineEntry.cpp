#include "UI/Crafting/CraftingIngredientLineEntry.h"
#include "Components/TextBlock.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Styling/SlateColor.h"

void UCraftingIngredientLineEntry::SetData(const FText& InName, int32 InOwned, int32 InRequired, bool bHasEnough)
{
	if (IngredientName_Text)
	{
		IngredientName_Text->SetText(InName);
	}

	if (Quantity_Text)
	{
		Quantity_Text->SetText(FText::FromString(FString::Printf(TEXT("%d / %d"), InOwned, InRequired)));
		Quantity_Text->SetColorAndOpacity(bHasEnough ? FSlateColor(FLinearColor::White) : FSlateColor(FLinearColor::Red));
	}
}