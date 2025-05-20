// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UI/Inventory/ItemWidgets/ItemEntryWidget.h"
#include "EquipmentEntryWidget.generated.h"

/**
 * 
 */
UCLASS()
class EMBER_API UEquipmentEntryWidget : public UItemEntryWidget
{
	GENERATED_BODY()

public:
	UEquipmentEntryWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	//~UUserWidget Overrides
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation) override;
	//~End of UUserWidget Overrides
};
