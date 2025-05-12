// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryEntryWidget.h"

#include "UI/Data/EmberItemData.h"
#include "UI/Data/EmberUIData.h"
#include "ItemInstance.h"
#include "ItemTemplate.h"
#include "Components/SizeBox.h"

UInventoryEntryWidget::UInventoryEntryWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UInventoryEntryWidget::Init(UInventorySlotsWidget* InSlotsWidget, UItemInstance* InItemInstance, int32 InItemCount)
{
	if (InSlotsWidget == nullptr || InItemInstance == nullptr)
		return;
	
	SlotsWidget = InSlotsWidget;

	// 슬롯 사이즈(X,Y) 설정하기
	FIntPoint UnitInventorySlotSize = UEmberUIData::Get().UnitInventorySlotSize;
	const UItemTemplate& ItemTemplate = UEmberItemData::Get().FindItemTemplateByID(InItemInstance->GetItemTemplateID());

	FVector2D WidgetSize = FVector2D(ItemTemplate.SlotCount.X * UnitInventorySlotSize.X, ItemTemplate.SlotCount.Y * UnitInventorySlotSize.Y);
	SizeBox_Root->SetWidthOverride(WidgetSize.X);
	SizeBox_Root->SetHeightOverride(WidgetSize.Y);

	// UI 업데이트하기
	RefreshUI(InItemInstance, InItemCount);
}
