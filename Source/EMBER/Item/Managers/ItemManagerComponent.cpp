// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemManagerComponent.h"

#include "GameFlag.h"
#include "InventoryEquipmentManagerComponent.h"
#include "InventoryManagerComponent.h"

UItemManagerComponent::UItemManagerComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SetIsReplicatedByDefault(true);
}

void UItemManagerComponent::Server_InventoryToEquipment_Implementation(UInventoryManagerComponent* FromInventoryManager, const FIntPoint& FromItemSlotPos, UInventoryEquipmentManagerComponent* ToInventoryEquipmentManager, EEquipmentSlotType ToEquipmentSlotType)
{
	if (HasAuthority() == false)
    	return;

	if (FromInventoryManager == nullptr || ToInventoryEquipmentManager == nullptr)
		return;

	/*if (IsAllowedComponent(FromInventoryManager) == false ||  IsAllowedComponent(ToEquipmentManager) == false)
		return;*/
	
	int32 MovableCount = ToInventoryEquipmentManager->CanMoveOrMergeEquipment(FromInventoryManager, FromItemSlotPos, ToEquipmentSlotType);
	if (MovableCount > 0)
	{
		UItemInstance* RemovedItemInstance = FromInventoryManager->RemoveItem_Unsafe(FromItemSlotPos, MovableCount);
		ToInventoryEquipmentManager->AddEquipment_Unsafe(ToEquipmentSlotType, RemovedItemInstance, MovableCount);
	}
	else
	{
		FIntPoint ToItemSlotPos;
		if (ToInventoryEquipmentManager->CanSwapEquipment(FromInventoryManager, FromItemSlotPos, ToEquipmentSlotType, ToItemSlotPos))
		{
			const int32 FromItemCount = FromInventoryManager->GetItemCount(FromItemSlotPos);
			const int32 ToItemCount = ToInventoryEquipmentManager->GetItemCount(ToEquipmentSlotType);

			UItemInstance* RemovedItemInstanceFrom = FromInventoryManager->RemoveItem_Unsafe(FromItemSlotPos, FromItemCount);
			UItemInstance* RemovedItemInstanceTo = ToInventoryEquipmentManager->RemoveEquipment_Unsafe(ToEquipmentSlotType, ToItemCount);
			FromInventoryManager->AddItem_Unsafe(ToItemSlotPos, RemovedItemInstanceTo, ToItemCount);
			ToInventoryEquipmentManager->AddEquipment_Unsafe(ToEquipmentSlotType, RemovedItemInstanceFrom, FromItemCount);
		}
	}
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


void UItemManagerComponent::Server_EquipmentToInventory_Implementation(UInventoryEquipmentManagerComponent* FromEquipmentManager, EEquipmentSlotType FromEquipmentSlotType, UInventoryManagerComponent* ToInventoryManager, const FIntPoint& ToItemSlotPos)
{
	
}

void UItemManagerComponent::Server_EquipmentToEquipment_Implementation(UInventoryEquipmentManagerComponent* FromEquipmentManager, EEquipmentSlotType FromEquipmentSlotType, UInventoryEquipmentManagerComponent* ToEquipmentManager, EEquipmentSlotType ToEquipmentSlotType)
{
	
}


