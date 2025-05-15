// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemHoverEntryWidget.h"

#include "ItemInstance.h"
#include "ItemTemplate.h"
#include "Components/RichTextBlock.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "UI/Data/EmberItemData.h"
#include "UI/Data/EmberUIData.h"

#define LOCTEXT_NAMESPACE "ItemHoverWidget"

UItemHoverEntryWidget::UItemHoverEntryWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UItemHoverEntryWidget::RefreshUI(const UItemInstance* ItemInstance)
{
	if (ItemInstance == nullptr)
	{
		SetVisibility(ESlateVisibility::Collapsed);
		return;
	}

	SetVisibility(ESlateVisibility::HitTestInvisible);
	PlayAnimationForward(Animation_FadeIn);

	const UItemTemplate& ItemTemplate = UEmberItemData::Get().FindItemTemplateByID(ItemInstance->GetItemTemplateID());
	const EItemRarity ItemRarity = ItemInstance->GetItemRarity();

	// Default Visibility
	Text_AttributeModifiers->SetVisibility(ESlateVisibility::Collapsed);
	Text_AdditionalAttributeModifiers->SetVisibility(ESlateVisibility::Collapsed);
	Text_Description->SetVisibility(ESlateVisibility::Collapsed);
	VerticalBox_EquipableClasses->SetVisibility(ESlateVisibility::Collapsed);

	// Display Name
	Text_DisplayName->SetText(ItemTemplate.DisplayName);

	FText ItemRarityText;
	switch (ItemRarity)
	{
	case EItemRarity::Poor:			ItemRarityText = LOCTEXT("ItemRarity-Poor",			"Poor");		break;
	case EItemRarity::Common:		ItemRarityText = LOCTEXT("ItemRarity-Common",		"Common");		break;
	case EItemRarity::Uncommon:		ItemRarityText = LOCTEXT("ItemRarity-Uncommon",		"Uncommon");	break;
	case EItemRarity::Rare:			ItemRarityText = LOCTEXT("ItemRarity-Rare",			"Rare");		break;
	case EItemRarity::Legendary:	ItemRarityText = LOCTEXT("ItemRarity-Legendary",	"Legendary");	break;
	}
	Text_ItemRarity->SetText(ItemRarityText);
	// Text_DisplayName->SetColorAndOpacity(RarityColor);
}

#undef LOCTEXT_NAMESPACE