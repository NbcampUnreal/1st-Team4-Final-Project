// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemEntryWidget.h"

#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "UI/Data/EmberItemData.h"
#include "ItemTemplate.h"
#include "ItemInstance.h"

class UItemTemplate;

UItemEntryWidget::UItemEntryWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UItemEntryWidget::RefreshUI(UItemInstance* NewItemInstance, int32 NewItemCount)
{
	if (NewItemInstance == nullptr || NewItemCount < 1)
		return;

	ItemInstance = NewItemInstance;
	ItemCount = NewItemCount;

	const UItemTemplate& ItemTemplate = UEmberItemData::Get().FindItemTemplateByID(ItemInstance->GetItemTemplateID());
	
	Image_Icon->SetBrushFromTexture(ItemTemplate.IconTexture, true);
	Text_Count->SetText(ItemCount <= 1 ? FText::GetEmpty() : FText::AsNumber(ItemCount));
}

void UItemEntryWidget::NativeOnInitialized()
{
	Text_Count->SetText(FText::GetEmpty());
}

void UItemEntryWidget::NativeConstruct()
{
	Image_Hover->SetVisibility(ESlateVisibility::Hidden);
}

void UItemEntryWidget::NativeDestruct()
{
	
}

void UItemEntryWidget::RefreshItemCount(int32 NewItemCount)
{
	if (NewItemCount < 1)
		return;
	
	ItemCount = NewItemCount;
	Text_Count->SetText(ItemCount <= 1 ? FText::GetEmpty() : FText::AsNumber(ItemCount));
}


