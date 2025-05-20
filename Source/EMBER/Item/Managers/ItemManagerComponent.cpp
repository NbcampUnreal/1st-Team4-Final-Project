// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemManagerComponent.h"

UItemManagerComponent::UItemManagerComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SetIsReplicatedByDefault(true);
}

void UItemManagerComponent::Server_EquipmentToInventory_Implementation(UEquipmentManagerComponent* FromEquipmentManager, EEquipmentSlotType FromEquipmentSlotType, UInventoryManagerComponent* ToInventoryManager, const FIntPoint& ToItemSlotPos)
{
}

void UItemManagerComponent::Server_InventoryToInventory_Implementation(UInventoryManagerComponent* FromInventoryManager, const FIntPoint& FromItemSlotPos, UInventoryManagerComponent* ToInventoryManager, const FIntPoint& ToItemSlotPos)
{
}
