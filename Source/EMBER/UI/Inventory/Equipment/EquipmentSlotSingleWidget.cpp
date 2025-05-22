// Fill out your copyright notice in the Description page of Project Settings.


#include "EquipmentSlotSingleWidget.h"

#include "Components/Image.h"
#include "Managers/InventoryEquipmentManagerComponent.h"
#include "UI/Inventory/ItemWidgets/ItemDragDrop.h"

UEquipmentSlotSingleWidget::UEquipmentSlotSingleWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
}

void UEquipmentSlotSingleWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (Image_BaseIcon)
	{
		Image_BaseIcon->SetBrushFromTexture(BaseIconTexture, true);
	}
}

bool UEquipmentSlotSingleWidget::NativeOnDragOver(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	Super::NativeOnDragOver(InGeometry, InDragDropEvent, InOperation);

	if (bAlreadyHovered)
		return true;
	
	bAlreadyHovered = true;

	UItemDragDrop* ItemDragDrop = Cast<UItemDragDrop>(InOperation);
	if (ItemDragDrop == nullptr)
		return false;

	UItemInstance* FromItemInstance = ItemDragDrop->FromItemInstance;
	if (FromItemInstance == nullptr)
		return false;
	
	bool bIsValid = false;
	if (UInventoryManagerComponent* FromInventoryManager = ItemDragDrop->FromInventoryManager)
	{
		if (InventoryEquipmentManager->IsSlotEquipped(EquipmentSlotType))
		{
			FIntPoint OutToItemSlotPos;
			bIsValid = InventoryEquipmentManager->CanSwapEquipment(FromInventoryManager, ItemDragDrop->FromItemSlotPos, EquipmentSlotType, OutToItemSlotPos);
		}
		else
		{
			bIsValid = InventoryEquipmentManager->CanMoveOrMergeEquipment(FromInventoryManager, ItemDragDrop->FromItemSlotPos, EquipmentSlotType) > 0;
		}
	}
	// TODO: 장비창 간의 이동 구현 고려
	/*
	else if (UEquipmentManagerComponent* FromEquipmentManager = ItemDragDrop->FromEquipmentManager)
	{
		if (EquipmentManager->GetItemInstance(ToEquipmentSlotType))
		{
			bIsValid = EquipmentManager->CanSwapEquipment(FromEquipmentManager, ItemDragDrop->FromEquipmentSlotType, ToEquipmentSlotType);
		}
		else
		{
			bIsValid = EquipmentManager->CanMoveOrMergeEquipment(FromEquipmentManager, ItemDragDrop->FromEquipmentSlotType, ToEquipmentSlotType) > 0;
		}
	}
	*/
	
	ChangeSlotState(bIsValid);

	return true;
}

void UEquipmentSlotSingleWidget::OnDragEnded()
{
	Super::OnDragEnded();

	ChangeSlotState(false);
}

void UEquipmentSlotSingleWidget::ChangeSlotState(bool bIsValid)
{
	if (bIsValid)
	{
		Image_Red->SetVisibility(ESlateVisibility::Hidden);
		Image_Green->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		Image_Red->SetVisibility(ESlateVisibility::Visible);
		Image_Green->SetVisibility(ESlateVisibility::Hidden);
	}
}
