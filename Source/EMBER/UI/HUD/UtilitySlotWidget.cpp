// Fill out your copyright notice in the Description page of Project Settings.


#include "UtilitySlotWidget.h"

#include "EmberPlayerCharacter.h"
#include "ItemInstance.h"
#include "ItemTemplate.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Managers/InventoryEquipmentManagerComponent.h"
#include "UI/Data/EmberItemData.h"

UUtilitySlotWidget::UUtilitySlotWidget(const FObjectInitializer& ObjectInitializer) : Super (ObjectInitializer)
{
}

void UUtilitySlotWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	FText SlotNumber = FText::AsNumber((int32)WidgetUtilitySlotType + 1);
	Text_SlotNumber->SetText(SlotNumber);
}

void UUtilitySlotWidget::NativeConstruct()
{
	Super::NativeConstruct();

	AEmberPlayerCharacter* EmberCharacter = Cast<AEmberPlayerCharacter>(GetOwningPlayerPawn());
	if (EmberCharacter == nullptr)
		return;

	EquipmentManager = EmberCharacter->GetComponentByClass<UEquipmentManagerComponent>();
	InventoryEquipmentManager = EmberCharacter->GetComponentByClass<UInventoryEquipmentManagerComponent>();
	if (EquipmentManager == nullptr || InventoryEquipmentManager == nullptr)
		return;
	
	const TArray<FEquipmentEntry>& Entries  = InventoryEquipmentManager->GetAllEntries();
	for (int32 i = 0; i < Entries.Num(); i++)
	{
		const FEquipmentEntry& Entry = Entries[i];
		if (UItemInstance* ItemInstance = Entry.GetItemInstance())
		{
			OnEquipmentEntryChanged((EEquipmentSlotType)i, ItemInstance, Entry.GetItemCount());
		}
	}

	EntryChangedDelegateHandle = InventoryEquipmentManager->OnEquipmentEntryChanged.AddUObject(this, &ThisClass::OnEquipmentEntryChanged);
	EEquipState CurrentEquipState = EquipmentManager->GetCurrentEquipState();
}

void UUtilitySlotWidget::NativeDestruct()
{
	if (InventoryEquipmentManager)
	{
		InventoryEquipmentManager->OnEquipmentEntryChanged.Remove(EntryChangedDelegateHandle);
		EntryChangedDelegateHandle.Reset();
	}

	if (EquipmentManager)
	{

	}
	
	Super::NativeDestruct();
}

void UUtilitySlotWidget::OnEquipmentEntryChanged(EEquipmentSlotType EquipmentSlotType, UItemInstance* ItemInstance, int32 ItemCount)
{
	EUtilitySlotType EntryUtilitySlotType = UInventoryEquipmentManagerComponent::ConvertToUtilitySlotType(EquipmentSlotType);
	if (EntryUtilitySlotType != WidgetUtilitySlotType)
		return;

	if (ItemInstance)
	{
		const UItemTemplate& ItemTemplate = UEmberItemData::Get().FindItemTemplateByID(ItemInstance->GetItemTemplateID());

		Image_Icon->SetBrushFromTexture(ItemTemplate.IconTexture, true);
		Image_Icon->SetVisibility(ESlateVisibility::HitTestInvisible);

		if (ItemCount > 1)
		{
			Text_Count->SetText(FText::AsNumber(ItemCount));
			Text_Count->SetVisibility(ESlateVisibility::HitTestInvisible);
		}
		else
		{
			Text_Count->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	else
	{
		Image_Icon->SetVisibility(ESlateVisibility::Hidden);
		Text_Count->SetVisibility(ESlateVisibility::Hidden);
	}
}
