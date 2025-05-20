// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFlag.h"
#include "Blueprint/DragDropOperation.h"
#include "ItemDragDrop.generated.h"

class UItemEntryWidget;
class UItemInstance;
class UInventoryManagerComponent;
class UEquipmentManagerComponent;

/**
 * 
 */
UCLASS()
class EMBER_API UItemDragDrop : public UDragDropOperation
{
	GENERATED_BODY()

public:
	UItemDragDrop(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UPROPERTY()
	TObjectPtr<UInventoryManagerComponent> FromInventoryManager;

	FIntPoint FromItemSlotPos = FIntPoint::ZeroValue;
	
	UPROPERTY()
	TObjectPtr<UInventoryManagerComponent> ToInventoryManager;

	FIntPoint ToItemSlotPos = FIntPoint::ZeroValue;

public:
	UPROPERTY()
	TObjectPtr<UEquipmentManagerComponent> FromEquipmentManager;

	EEquipmentSlotType FromEquipmentSlotType = EEquipmentSlotType::Count;
	
	UPROPERTY()
	TObjectPtr<UEquipmentManagerComponent> ToEquipmentManager;

	EEquipmentSlotType ToEquipmentSlotType = EEquipmentSlotType::Count;

public:
	UPROPERTY()
	TObjectPtr<UItemEntryWidget> FromEntryWidget;

	UPROPERTY()
	TObjectPtr<UItemInstance> FromItemInstance;

	FVector2D DeltaWidgetPos = FVector2D::ZeroVector;
};
