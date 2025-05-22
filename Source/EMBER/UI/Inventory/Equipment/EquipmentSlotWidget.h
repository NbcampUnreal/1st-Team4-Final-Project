// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "EquipmentSlotWidget.generated.h"

class UInventoryEquipmentManagerComponent;

/**
 * 
 */
UCLASS()
class EMBER_API UEquipmentSlotWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UEquipmentSlotWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	virtual void NativeOnDragLeave(const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
	virtual void OnDragEnded();

protected:
	UPROPERTY()
	TObjectPtr<UInventoryEquipmentManagerComponent> InventoryEquipmentManager;

protected:
	bool bAlreadyHovered = false;
};
