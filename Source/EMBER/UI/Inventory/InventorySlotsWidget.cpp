// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Inventory/InventorySlotsWidget.h"

#include "UI/Data/EmberUIData.h"
#include "InventorySlotWidget.h"
#include "InventoryValidWidget.h"
#include "Components/TextBlock.h"
#include "Components/UniformGridPanel.h"

class UItemInstance;
struct FInventoryEntry;

UInventorySlotsWidget::UInventorySlotsWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	TitleText = FText::FromString(TEXT("Title"));
}

void UInventorySlotsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Text_Title->SetText(TitleText);
}

void UInventorySlotsWidget::NativeDestruct()
{
	Super::NativeDestruct();
}

void UInventorySlotsWidget::ConstructUI()
{
	// TODO : MagicNumber 수정 예정
	const FIntPoint& InventorySlotCount = FIntPoint(10, 5);
	const int32 InventorySlotNum = InventorySlotCount.X * InventorySlotCount.Y;
	SlotWidgets.SetNum(InventorySlotNum);
	ValidWidgets.SetNum(InventorySlotNum);
	
	for (int32 y = 0; y < InventorySlotCount.Y; y++)
	{
		for (int32 x = 0; x < InventorySlotCount.X; x++)
		{
			TSubclassOf<UInventorySlotWidget> SlotWidgetClass = UEmberUIData::Get().InventorySlotWidgetClass;
			UInventorySlotWidget* SlotWidget = CreateWidget<UInventorySlotWidget>(GetOwningPlayer(), SlotWidgetClass);
			SlotWidgets[y * InventorySlotCount.X + x] = SlotWidget;
			GridPanel_Slots->AddChildToUniformGrid(SlotWidget, y, x);

			TSubclassOf<UInventoryValidWidget> ValidWidgetClass = UEmberUIData::Get().InventoryValidWidgetClass;
			UInventoryValidWidget* ValidWidget = CreateWidget<UInventoryValidWidget>(GetOwningPlayer(), ValidWidgetClass);
			ValidWidgets[y * InventorySlotCount.X + x] = ValidWidget;
			GridPanel_ValidSlots->AddChildToUniformGrid(ValidWidget, y, x);
		}
	}
}

void UInventorySlotsWidget::DestructUI()
{
	
}
