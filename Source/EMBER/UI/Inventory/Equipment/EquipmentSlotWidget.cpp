// Fill out your copyright notice in the Description page of Project Settings.


#include "EquipmentSlotWidget.h"

UEquipmentSlotWidget::UEquipmentSlotWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UEquipmentSlotWidget::NativeOnDragLeave(const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	Super::NativeOnDragLeave(InDragDropEvent, InOperation);

	OnDragEnded();
}

void UEquipmentSlotWidget::OnDragEnded()
{
}
