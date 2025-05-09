// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryManagerComponent.h"

#include "GameFlag.h"
#include "ItemTemplate.h"
#include "ItemInstance.h"
#include "Net/UnrealNetwork.h"
#include "UI/Data/EmberItemData.h"

UInventoryManagerComponent::UInventoryManagerComponent(const FObjectInitializer& FObjectInitializer) : Super(FObjectInitializer), InventoryList(this)
{
	bWantsInitializeComponent = true;
}

void UInventoryManagerComponent::InitializeComponent()
{
	Super::InitializeComponent();

	if (GetOwner() && GetOwner()->HasAuthority())
	{
		TArray<FInventoryEntry>& Entries = InventoryList.Entries;
		Entries.SetNum(InventorySlotCount.X * InventorySlotCount.Y);
	
		for (FInventoryEntry& Entry : Entries)
		{
			InventoryList.MarkItemDirty(Entry);
		}

		SlotChecks.SetNumZeroed(InventorySlotCount.X * InventorySlotCount.Y);
	}
}

void UInventoryManagerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, InventoryList);
	DOREPLIFETIME(ThisClass, SlotChecks);
}


int32 UInventoryManagerComponent::CanAddItem(int32 ItemTemplateID, EItemRarity ItemRarity, int32 ItemCount, TArray<FIntPoint>& OutToItemSlotPoses, TArray<int32>& OutToItemCounts) const
{
	OutToItemSlotPoses.Reset();
	OutToItemCounts.Reset();

	if (ItemTemplateID <= 0 || ItemRarity == EItemRarity::Count || ItemCount <= 0)
		return 0;

	const UItemTemplate& ItemTemplate = UEmberItemData::Get().FindItemTemplateByID(ItemTemplateID);
	int32 LeftItemCount = ItemCount;

	// 아이템 중첩 개수가 2개 이상인 경우
	// 소지 아이템들을 탐색하여 개수를 증가시킨다. 
	if (ItemTemplate.MaxStackCount > 1)
	{
		const TArray<FInventoryEntry>& ToEntries = GetAllEntries();

		for (int32 i = 0; i < ToEntries.Num(); i++)
		{
			const FInventoryEntry& ToEntry = ToEntries[i];
			const UItemInstance* ToItemInstance = ToEntry.GetItemInstance();
			const int32 ToItemCount = ToEntry.GetItemCount();

			if (ToItemInstance == nullptr)
				continue;

			if (ToItemInstance->GetItemTemplateID() != ItemTemplateID)
				continue;

			if (ToItemInstance->GetItemRarity() != ItemRarity)
				continue;

			if (int32 AddCount = FMath::Min(ToItemCount + LeftItemCount ,ItemTemplate.MaxStackCount) - ToItemCount)
			{
				OutToItemSlotPoses.Emplace(i % InventorySlotCount.X, i / InventorySlotCount.X);
				OutToItemCounts.Emplace(AddCount);
				LeftItemCount -= AddCount;

				if (LeftItemCount == 0)
					return ItemCount;
			}
		}
	}

	// 인벤토리 빈 공간을 확인하여 아이템을 추가한다.
	const FIntPoint& ItemSlotCount = ItemTemplate.SlotCount;
	TArray<bool> TempSlotChecks = SlotChecks;

	const FIntPoint StartSlotPos = FIntPoint::ZeroValue;
	const FIntPoint EndSlotPos = InventorySlotCount - ItemSlotCount;

	for (int32 y = StartSlotPos.Y; y <= EndSlotPos.Y; y++)
	{
		for (int32 x = StartSlotPos.X; x <= EndSlotPos.X; x++)
		{
			int32 Index = y * InventorySlotCount.X + x;
			if (TempSlotChecks.IsValidIndex(Index) == false || TempSlotChecks[Index])
				continue;

			FIntPoint ItemSlotPos = FIntPoint(x, y);
			if (IsEmpty(TempSlotChecks, ItemSlotPos, ItemSlotCount))
			{
				MarkSlotChecks(TempSlotChecks, true, ItemSlotPos, ItemSlotCount);
				
				int32 AddCount = FMath::Min(LeftItemCount, ItemTemplate.MaxStackCount);
				OutToItemSlotPoses.Emplace(ItemSlotPos);
				OutToItemCounts.Emplace(AddCount);
				
				LeftItemCount -= AddCount;
				
				if (LeftItemCount == 0)
					return ItemCount;
			}
		}
	}

	return ItemCount - LeftItemCount;
}

int32 UInventoryManagerComponent::TryAddItemByRarity(TSubclassOf<UItemTemplate> ItemTemplateClass, EItemRarity ItemRarity, int32 ItemCount)
{
	check(GetOwner()->HasAuthority());

	if (ItemTemplateClass == nullptr || ItemRarity == EItemRarity::Count || ItemCount <= 0)
		return 0;

	int32 ItemTemplateID = UEmberItemData::Get().FindItemTemplateIDByClass(ItemTemplateClass);
	const UItemTemplate& ItemTemplate = UEmberItemData::Get().FindItemTemplateByID(ItemTemplateID);

	TArray<FIntPoint> ToItemSlotPoses;
	TArray<int32> ToItemCounts;

	int32 AddableItemCount = CanAddItem(ItemTemplateID, ItemRarity, ItemCount, ToItemSlotPoses, ToItemCounts);
	
	return ItemCount;
}

bool UInventoryManagerComponent::IsEmpty(const TArray<bool>& InSlotChecks, const FIntPoint& ItemSlotPos, const FIntPoint& ItemSlotCount) const
{
	if (ItemSlotPos.X < 0 || ItemSlotPos.Y < 0)
		return false;

	if (ItemSlotPos.X + ItemSlotCount.X > InventorySlotCount.X || ItemSlotPos.Y + ItemSlotCount.Y > InventorySlotCount.Y)
		return false;

	const FIntPoint StartSlotPos = ItemSlotPos;
	const FIntPoint EndSlotPos = ItemSlotPos + ItemSlotCount;

	for (int32 y = StartSlotPos.Y; y < EndSlotPos.Y; y++)
	{
		for (int32 x = StartSlotPos.X; x < EndSlotPos.X; x++)
		{
			int32 Index = y * InventorySlotCount.X + x;
			if (InSlotChecks.IsValidIndex(Index) == false || InSlotChecks[Index])
				return false;
		}
	}
	
	return true;
}

const TArray<FInventoryEntry>& UInventoryManagerComponent::GetAllEntries() const
{
	return InventoryList.GetAllEntries();
}

void UInventoryManagerComponent::MarkSlotChecks(TArray<bool>& InSlotChecks, bool bIsUsing, const FIntPoint& ItemSlotPos, const FIntPoint& ItemSlotCount) const
{
	if (ItemSlotPos.X < 0 || ItemSlotPos.Y < 0)
		return;

	if (ItemSlotPos.X + ItemSlotCount.X > InventorySlotCount.X || ItemSlotPos.Y + ItemSlotCount.Y > InventorySlotCount.Y)
		return;

	const FIntPoint StartSlotPos = ItemSlotPos;
	const FIntPoint EndSlotPos = ItemSlotPos + ItemSlotCount;

	for (int32 y = StartSlotPos.Y; y < EndSlotPos.Y; y++)
	{
		for (int32 x = StartSlotPos.X; x < EndSlotPos.X; x++)
		{
			int32 Index = y * InventorySlotCount.X + x;
			if (InSlotChecks.IsValidIndex(Index))
			{
				InSlotChecks[Index] = bIsUsing;
			}
		}
	}
}
