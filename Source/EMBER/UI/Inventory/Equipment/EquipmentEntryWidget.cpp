// Fill out your copyright notice in the Description page of Project Settings.


#include "EquipmentEntryWidget.h"

UEquipmentEntryWidget::UEquipmentEntryWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UEquipmentEntryWidget::Init(UItemInstance* InItemInstance, int32 InItemCount, EEquipmentSlotType InEquipmentSlotType, UInventoryEquipmentManagerComponent* InInventoryEquipmentManager)
{
	if (InEquipmentSlotType == EEquipmentSlotType::Count)
		return;

	RefreshUI(InItemInstance, InItemCount);
	
	EquipmentSlotType = InEquipmentSlotType;
	InventoryEquipmentManager = InInventoryEquipmentManager;
}

FReply UEquipmentEntryWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	return Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
}

void UEquipmentEntryWidget::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent,
	UDragDropOperation*& OutOperation)
{
	Super::NativeOnDragDetected(InGeometry, InMouseEvent, OutOperation);
}
