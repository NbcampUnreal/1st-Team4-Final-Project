// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemManagerComponent.h"

#include "GameFlag.h"
#include "InventoryManagerComponent.h"

UItemManagerComponent::UItemManagerComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SetIsReplicatedByDefault(true);
}

void UItemManagerComponent::Server_InventoryToInventory_Implementation(UInventoryManagerComponent* FromInventoryManager, const FIntPoint& FromItemSlotPos, UInventoryManagerComponent* ToInventoryManager, const FIntPoint& ToItemSlotPos)
{
	if (HasAuthority() == false)
		return;

	if (FromInventoryManager == nullptr || ToInventoryManager == nullptr)
		return;

	if (FromInventoryManager == ToInventoryManager && FromItemSlotPos == ToItemSlotPos)
		return;

	int32 MovableCount = ToInventoryManager->CanMoveOrMergeItem(FromInventoryManager, FromItemSlotPos, ToItemSlotPos);
	if (MovableCount > 0)
	{
		UItemInstance* RemovedItemInstance = FromInventoryManager->RemoveItem_Unsafe(FromItemSlotPos, MovableCount);
		ToInventoryManager->AddItem_Unsafe(ToItemSlotPos, RemovedItemInstance, MovableCount);
	}
}


void UItemManagerComponent::Server_EquipmentToInventory_Implementation(UEquipmentManagerComponent* FromEquipmentManager, EEquipmentSlotType FromEquipmentSlotType, UInventoryManagerComponent* ToInventoryManager, const FIntPoint& ToItemSlotPos)
{
	
}

