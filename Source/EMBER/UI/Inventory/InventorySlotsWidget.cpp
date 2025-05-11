// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Inventory/InventorySlotsWidget.h"

#include "UI/Data/EmberUIData.h"
#include "InventorySlotWidget.h"
#include "InventoryValidWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/TextBlock.h"
#include "Components/UniformGridPanel.h"
#include "Managers/InventoryManagerComponent.h"
#include "InventoryEntryWidget.h"

UInventorySlotsWidget::UInventorySlotsWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	TitleText = FText::FromString(TEXT("Title"));
}

void UInventorySlotsWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	Text_Title->SetText(TitleText);
}

void UInventorySlotsWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	UGameplayMessageSubsystem& MessageSubsystem = UGameplayMessageSubsystem::Get(this);
	MessageListenerHandle = MessageSubsystem.RegisterListener(MessageChannelTag, this, &ThisClass::ConstructUI);
}

void UInventorySlotsWidget::NativeDestruct()
{
	Super::NativeDestruct();
}

void UInventorySlotsWidget::ConstructUI(FGameplayTag Channel, const FInventoryInitializeMessage& Message)
{
	if (Message.InventoryManager == nullptr)
		return;

	InventoryManager = Message.InventoryManager;
		
	const FIntPoint& InventorySlotCount = InventoryManager->GetInventorySlotCount();
	const int32 InventorySlotNum = InventorySlotCount.X * InventorySlotCount.Y;
	SlotWidgets.SetNum(InventorySlotNum);
	EntryWidgets.SetNum(InventorySlotNum);
	ValidWidgets.SetNum(InventorySlotNum);
	
	for (int32 y = 0; y < InventorySlotCount.Y; y++)
	{
		for (int32 x = 0; x < InventorySlotCount.X; x++)
		{
			TSubclassOf<UInventorySlotWidget> SlotWidgetClass = UEmberUIData::Get().InventorySlotWidgetClass;
			UInventorySlotWidget* SlotWidget = CreateWidget<UInventorySlotWidget>(GetOwningPlayer(), SlotWidgetClass);
			SlotWidgets[y * InventorySlotCount.X + x] = SlotWidget;
			GridPanel_Slots->AddChildToUniformGrid(SlotWidget, y, x);

			TSubclassOf<UInventoryValidWidget> ValidWidgetClass = UEmberUIData::Get().InventoryValidWidgetClass;
			UInventoryValidWidget* ValidWidget = CreateWidget<UInventoryValidWidget>(GetOwningPlayer(), ValidWidgetClass);
			ValidWidgets[y * InventorySlotCount.X + x] = ValidWidget;
			GridPanel_ValidSlots->AddChildToUniformGrid(ValidWidget, y, x);
		}
	}

	const TArray<FInventoryEntry>& Entries = InventoryManager->GetAllEntries();
	for (int32 i = 0; i < Entries.Num(); i++)
	{
		const FInventoryEntry& Entry = Entries[i];
		if (UItemInstance* ItemInstance = Entry.GetItemInstance())
		{
			FIntPoint ItemSlotPos = FIntPoint(i % InventorySlotCount.X, i / InventorySlotCount.X);
			OnInventoryEntryChanged(ItemSlotPos, ItemInstance, Entry.GetItemCount());
		}
	}
	
	EntryChangedDelegateHandle = InventoryManager->OnInventoryEntryChanged.AddUObject(this, &ThisClass::OnInventoryEntryChanged);
}

void UInventorySlotsWidget::DestructUI()
{
	InventoryManager->OnInventoryEntryChanged.Remove(EntryChangedDelegateHandle);
	EntryChangedDelegateHandle.Reset();
	
	CanvasPanel_Entries->ClearChildren();
	EntryWidgets.Reset();
	
	GridPanel_Slots->ClearChildren();
	SlotWidgets.Reset();
}

void UInventorySlotsWidget::OnInventoryEntryChanged(const FIntPoint& InItemSlotPos, UItemInstance* InItemInstance, int32 InItemCount)
{
	const FIntPoint& InventorySlotCount = InventoryManager->GetInventorySlotCount();
	int32 SlotIndex = InItemSlotPos.Y * InventorySlotCount.X + InItemSlotPos.X;

	if (UInventoryEntryWidget* EntryWidget = EntryWidgets[SlotIndex])
	{
		UItemInstance* ItemInstance = EntryWidget->GetItemInstance();
		if (ItemInstance && ItemInstance == InItemInstance)
		{
			EntryWidget->RefreshItemCount(InItemCount);
			return;
		}
		
		CanvasPanel_Entries->RemoveChild(EntryWidget);
		EntryWidgets[SlotIndex] = nullptr;
	}
	
	if (InItemInstance)
	{
		FIntPoint UnitInventorySlotSize = UEmberUIData::Get().UnitInventorySlotSize;
		
		TSubclassOf<UInventoryEntryWidget> EntryWidgetClass = UEmberUIData::Get().InventoryEntryWidgetClass;
		UInventoryEntryWidget* EntryWidget = CreateWidget<UInventoryEntryWidget>(GetOwningPlayer(), EntryWidgetClass);
		EntryWidgets[SlotIndex] = EntryWidget;
		
		EntryWidget->Init(this, InItemInstance, InItemCount);
		
		UCanvasPanelSlot* CanvasPanelSlot = CanvasPanel_Entries->AddChildToCanvas(EntryWidget);
		CanvasPanelSlot->SetAutoSize(true);
		CanvasPanelSlot->SetPosition(FVector2D(InItemSlotPos.X * UnitInventorySlotSize.X, InItemSlotPos.Y * UnitInventorySlotSize.Y));
	}
}
