// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryEquipmentManagerComponent.h"

#include "EmberPlayerState.h"
#include "ItemInstance.h"
#include "Fragments/ItemFragment_Equipable.h"
#include "InventoryManagerComponent.h"
#include "Fragments/ItemFragment_Equipable_Armor.h"
#include "Fragments/ItemFragment_Equipable_Weapon.h"
#include "Net/UnrealNetwork.h"
#include "UI/Data/EmberItemData.h"

bool FEquipmentList::NetDeltaSerialize(FNetDeltaSerializeInfo& DeltaParams)
{
	return FFastArraySerializer::FastArrayDeltaSerialize<FEquipmentEntry, FEquipmentList>(Entries, DeltaParams, *this);
}

void FEquipmentList::PostReplicatedAdd(const TArrayView<int32> AddedIndices, int32 FinalSize)
{
	
}

void FEquipmentList::PostReplicatedChange(const TArrayView<int32> ChangedIndices, int32 FinalSize)
{
}


UInventoryEquipmentManagerComponent::UInventoryEquipmentManagerComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UInventoryEquipmentManagerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, EquipmentList);
}

int32 UInventoryEquipmentManagerComponent::CanMoveOrMergeEquipment(UInventoryEquipmentManagerComponent* OtherComponent, EEquipmentSlotType FromEquipmentSlotType, EEquipmentSlotType ToEquipmentSlotType) const
{
	if (OtherComponent == nullptr || FromEquipmentSlotType == EEquipmentSlotType::Count)
		return 0;

	const UItemInstance* FromItemInstance = OtherComponent->GetItemInstance(FromEquipmentSlotType);
	if (FromItemInstance == nullptr)
		return 0;
	
	const int32 FromItemCount = OtherComponent->GetItemCount(FromEquipmentSlotType);
	if (IsSameComponent(OtherComponent) && FromEquipmentSlotType == ToEquipmentSlotType)
		return FromItemCount;

	return CanAddEquipment(FromItemInstance->GetItemTemplateID(), FromItemInstance->GetItemRarity(), FromItemCount, ToEquipmentSlotType);
}

int32 UInventoryEquipmentManagerComponent::CanMoveOrMergeEquipment(UInventoryManagerComponent* OtherComponent, const FIntPoint& FromItemSlotPos, EEquipmentSlotType ToEquipmentSlotType) const
{
	if (OtherComponent == nullptr)
		return 0;

	const FIntPoint& FromInventorySlotCount = OtherComponent->GetInventorySlotCount();
	if (FromItemSlotPos.X < 0 || FromItemSlotPos.Y < 0 || FromItemSlotPos.X >= FromInventorySlotCount.X || FromItemSlotPos.Y >= FromInventorySlotCount.Y)
		return 0;

	const UItemInstance* FromItemInstance = OtherComponent->GetItemInstance(FromItemSlotPos);
	if (FromItemInstance == nullptr)
		return 0;
	
	const int32 FromItemCount = OtherComponent->GetItemCount(FromItemSlotPos);
	return CanAddEquipment(FromItemInstance->GetItemTemplateID(), FromItemInstance->GetItemRarity(), FromItemCount, ToEquipmentSlotType);
}

bool UInventoryEquipmentManagerComponent::CanSwapEquipment(UInventoryEquipmentManagerComponent* OtherComponent, EEquipmentSlotType FromEquipmentSlotType, EEquipmentSlotType ToEquipmentSlotType) const
{
	if (IsSameComponent(OtherComponent) && FromEquipmentSlotType == ToEquipmentSlotType)
		return false;
	
	UItemInstance* FromItemInstance = GetItemInstance(OtherComponent, FromEquipmentSlotType);
	if (FromItemInstance == nullptr)
		return false;
	
	const UItemInstance* ToItemInstance = GetItemInstance(ToEquipmentSlotType);
	if (ToItemInstance == nullptr)
		return false;

	const UItemFragment_Equipable* FromEquippableFragment = FromItemInstance->FindFragmentByClass<UItemFragment_Equipable>();
	if (FromEquippableFragment == nullptr)
		return false;

	if (FromEquippableFragment->EquipmentType == EEquipmentType::Count)
		return false;

	return true;
}

bool UInventoryEquipmentManagerComponent::CanSwapEquipment(UInventoryManagerComponent* OtherComponent, const FIntPoint& FromItemSlotPos, EEquipmentSlotType ToEquipmentSlotType, FIntPoint& OutToItemSlotPos)
{
	if (OtherComponent == nullptr || ToEquipmentSlotType == EEquipmentSlotType::Count)
		return false;

	const FIntPoint& FromInventorySlotCount = OtherComponent->GetInventorySlotCount();
	if (FromItemSlotPos.X < 0 || FromItemSlotPos.Y < 0 || FromItemSlotPos.X >= FromInventorySlotCount.X || FromItemSlotPos.Y >= FromInventorySlotCount.Y)
		return false;

	UItemInstance* FromItemInstance = OtherComponent->GetItemInstance(FromItemSlotPos);
	if (FromItemInstance == nullptr)
		return false;

	const UItemInstance* ToItemInstance = GetItemInstance(ToEquipmentSlotType);
	if (ToItemInstance == nullptr)
		return false;

	const UItemFragment_Equipable* FromEquippableFragment = FromItemInstance->FindFragmentByClass<UItemFragment_Equipable>();
	if (FromEquippableFragment == nullptr)
		return false;

	const EEquipmentType FromEquipmentType = FromEquippableFragment->EquipmentType;
	if (IsMatchingSlotType(FromEquipmentType, ToEquipmentSlotType) == false)
		return false;

	const UItemTemplate& FromItemTemplate = UEmberItemData::Get().FindItemTemplateByID(FromItemInstance->GetItemTemplateID());
	const FIntPoint& FromSlotCount = FromItemTemplate.SlotCount;
			
	const UItemTemplate& ToItemTemplate = UEmberItemData::Get().FindItemTemplateByID(ToItemInstance->GetItemTemplateID());
	const FIntPoint& ToSlotCount = ToItemTemplate.SlotCount;

	TArray<bool> TempSlotChecks = OtherComponent->SlotChecks;
	OtherComponent->MarkSlotChecks(TempSlotChecks, false, FromItemSlotPos, FromSlotCount);

	if (OtherComponent->IsEmpty(TempSlotChecks, FromItemSlotPos, ToSlotCount))
	{
		OutToItemSlotPos = FromItemSlotPos;
		return true;
	}
	else
	{
		const FIntPoint StartSlotPos = FIntPoint::ZeroValue;
		const FIntPoint EndSlotPos = FromInventorySlotCount - ToSlotCount;
	
		for (int32 y = StartSlotPos.Y; y <= EndSlotPos.Y; y++)
		{
			for (int32 x = StartSlotPos.X; x <= EndSlotPos.X; x++)
			{
				int32 Index = y * FromInventorySlotCount.X + x;
				if (TempSlotChecks.IsValidIndex(Index) == false || TempSlotChecks[Index])
					continue;

				FIntPoint ToItemSlotPos = FIntPoint(x, y);
				if (OtherComponent->IsEmpty(TempSlotChecks, ToItemSlotPos, ToSlotCount))
				{
					OutToItemSlotPos = ToItemSlotPos;
					return true;
				}
			}
		}
	}

	return false;
}

int32 UInventoryEquipmentManagerComponent::CanAddEquipment(int32 FromItemTemplateID, EItemRarity FromItemRarity, int32 FromItemCount, EEquipmentSlotType ToEquipmentSlotType) const
{
	if (FromItemTemplateID <= 0 || FromItemRarity == EItemRarity::Count || FromItemCount <= 0)
		return 0;

	if (ToEquipmentSlotType == EEquipmentSlotType::Count)
		return 0;

	const UItemTemplate& ItemTemplate = UEmberItemData::Get().FindItemTemplateByID(FromItemTemplateID);
	const UItemFragment_Equipable* FromEquippableFragment = ItemTemplate.FindFragmentByClass<UItemFragment_Equipable>();
	if (FromEquippableFragment == nullptr)
		return 0;

	const UItemInstance* ToItemInstance = GetItemInstance(ToEquipmentSlotType);
	const int32 ToItemCount = GetItemCount(ToEquipmentSlotType);

	if (ToItemInstance)
	{
		if (FromEquippableFragment->EquipmentType == EEquipmentType::Weapon || FromEquippableFragment->EquipmentType == EEquipmentType::Armor)
			return 0;
		
		const int32 ToTemplateID = ToItemInstance->GetItemTemplateID();
		if (FromItemTemplateID != ToTemplateID)
			return 0;

		if (FromItemRarity != ToItemInstance->GetItemRarity())
			return 0;
		
		if (ItemTemplate.MaxStackCount <= 1)
			return 0;

		return FMath::Min(FromItemCount + ToItemCount, ItemTemplate.MaxStackCount) - ToItemCount;
	}
	else
	{
		AEmberPlayerState* EmberPlayerState = GetPlayerState<AEmberPlayerState>();
		if (EmberPlayerState == nullptr)
			return 0;
		
		if (IsMatchingSlotType(FromEquippableFragment, ToEquipmentSlotType) == false)
			return 0;

		// TODO: 캐릭터 능력에 따른 아이템 장착 제한 구현
	}

	return FromItemCount;
}

bool UInventoryEquipmentManagerComponent::IsMatchingSlotType(EEquipmentType FromEquipmentType, EEquipmentSlotType ToEquipmentSlotType) const
{
	if (FromEquipmentType == EEquipmentType::Weapon)
	{
		return ToEquipmentSlotType >= EEquipmentSlotType::Primary_LeftHand && ToEquipmentSlotType <= EEquipmentSlotType::Primary_TwoHand;
	}
	if (FromEquipmentType == EEquipmentType::Armor)
	{
		return ToEquipmentSlotType >= EEquipmentSlotType::Helmet && ToEquipmentSlotType <= EEquipmentSlotType::Foot;
	}
	if (FromEquipmentType == EEquipmentType::Utility)
	{
		return ToEquipmentSlotType >= EEquipmentSlotType::Utility_Primary && ToEquipmentSlotType <= EEquipmentSlotType::Utility_Quaternary;
	}

	return false;
}

bool UInventoryEquipmentManagerComponent::IsMatchingSlotType(const UItemFragment_Equipable* FromEquippableFragment, EEquipmentSlotType ToEquipmentSlotType) const
{
	if (FromEquippableFragment == nullptr)
		return false;
	
	if (FromEquippableFragment->EquipmentType == EEquipmentType::Weapon)
	{
		const UItemFragment_Equipable_Weapon* FromWeaponFragment = Cast<UItemFragment_Equipable_Weapon>(FromEquippableFragment);
		EWeaponHandType FromWeaponHandType = FromWeaponFragment->WeaponHandType;
			
		if (FromWeaponHandType == EWeaponHandType::OneHand)
		{
			return GetItemInstance(EEquipmentSlotType::Primary_TwoHand) == nullptr;
		}
		if (FromWeaponHandType == EWeaponHandType::TwoHand)
		{
			return GetItemInstance(EEquipmentSlotType::Primary_LeftHand) == nullptr;
		}
	}
	else if (FromEquippableFragment->EquipmentType == EEquipmentType::Armor)
	{
		const UItemFragment_Equipable_Armor* FromArmorFragment = Cast<UItemFragment_Equipable_Armor>(FromEquippableFragment);
		const EArmorType ArmorType = FromArmorFragment->ArmorType;
		
		return (ToEquipmentSlotType == EEquipmentSlotType::Helmet	&& ArmorType == EArmorType::Helmet)
			|| (ToEquipmentSlotType == EEquipmentSlotType::Shoulder && ArmorType == EArmorType::Shoulder)
			|| (ToEquipmentSlotType == EEquipmentSlotType::Chest	&& ArmorType == EArmorType::Chest)
			|| (ToEquipmentSlotType == EEquipmentSlotType::Cloak	&& ArmorType == EArmorType::Cloak)
			|| (ToEquipmentSlotType == EEquipmentSlotType::Gloves   && ArmorType == EArmorType::Gloves)
			|| (ToEquipmentSlotType == EEquipmentSlotType::Pants	&& ArmorType == EArmorType::Pants)
			|| (ToEquipmentSlotType == EEquipmentSlotType::Foot		&& ArmorType == EArmorType::Foot);
	}
	else if (FromEquippableFragment->EquipmentType == EEquipmentType::Utility)
	{
		return (EEquipmentSlotType::Utility_Primary <= ToEquipmentSlotType && ToEquipmentSlotType <= EEquipmentSlotType::Utility_Quaternary);
	}

	return false;
}

bool UInventoryEquipmentManagerComponent::IsSlotEquipped(EEquipmentSlotType EquipmentSlotType) const
{
	if (EquipmentSlotType == EEquipmentSlotType::Count)
		return false;

	const TArray<FEquipmentEntry>& Entries = EquipmentList.GetAllEntries();
	const FEquipmentEntry& Entry = Entries[(int32)EquipmentSlotType];
	
	return Entry.GetItemInstance() != nullptr;
}

bool UInventoryEquipmentManagerComponent::IsSameComponent(const UInventoryEquipmentManagerComponent* OtherComponent) const
{
	return this == OtherComponent;
}

UItemInstance* UInventoryEquipmentManagerComponent::GetItemInstance(EEquipmentSlotType EquipmentSlotType) const
{
	return GetItemInstance(this, EquipmentSlotType);
}

UItemInstance* UInventoryEquipmentManagerComponent::GetItemInstance(const UInventoryEquipmentManagerComponent* OtherComponent, EEquipmentSlotType EquipmentSlotType) const
{
	if (OtherComponent == nullptr || EquipmentSlotType == EEquipmentSlotType::Count)
		return nullptr;

	const TArray<FEquipmentEntry>& Entries = OtherComponent->GetEquipmentList().GetAllEntries();
	const FEquipmentEntry& Entry = Entries[(int32)EquipmentSlotType];
	
	return Entry.GetItemInstance();
}

int32 UInventoryEquipmentManagerComponent::GetItemCount(EEquipmentSlotType EquipmentSlotType) const
{
	if (EquipmentSlotType == EEquipmentSlotType::Count)
		return 0;

	const TArray<FEquipmentEntry>& Entries = EquipmentList.GetAllEntries();
	const FEquipmentEntry& Entry = Entries[(int32)EquipmentSlotType];
	
	return Entry.GetItemCount();
}
