// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameData.h"
#include "Components/PawnComponent.h"
#include "Net/Serialization/FastArraySerializer.h"

#include "InventoryEquipmentManagerComponent.generated.h"

class UItemInstance;
class UItemFragment_Equipable;
class UInventoryManagerComponent;
class UInventoryEquipmentManagerComponent;

USTRUCT(BlueprintType)
struct FEquipmentEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UItemInstance* GetItemInstance() const { return ItemInstance; }
	int32 GetItemCount() const { return ItemCount; }
	
private:
	UPROPERTY()
	TObjectPtr<UItemInstance> ItemInstance;

	UPROPERTY()
	int32 ItemCount = 0;
	
private:
	UPROPERTY(NotReplicated)
	EEquipmentSlotType EquipmentSlotType = EEquipmentSlotType::Count;
	
	UPROPERTY(NotReplicated)
	TObjectPtr<UInventoryEquipmentManagerComponent> EquipmentManager;
};

USTRUCT(BlueprintType)
struct FEquipmentList : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	FEquipmentList() : InventoryEquipmentManager(nullptr) {}
	FEquipmentList(UInventoryEquipmentManagerComponent* InInventoryEquipmentManager) : InventoryEquipmentManager(InInventoryEquipmentManager) {}

public:
	//~FFastArraySerializer Overrides
	bool NetDeltaSerialize(FNetDeltaSerializeInfo& DeltaParams);
	void PostReplicatedAdd(const TArrayView<int32> AddedIndices, int32 FinalSize);
	void PostReplicatedChange(const TArrayView<int32> ChangedIndices, int32 FinalSize);
	//~End of FFastArraySerializer Overrides

public:
	const TArray<FEquipmentEntry>& GetAllEntries() const { return Entries; }
	
private:
	UPROPERTY()
	TArray<FEquipmentEntry> Entries;
	
	UPROPERTY(NotReplicated)
	TObjectPtr<UInventoryEquipmentManagerComponent> InventoryEquipmentManager;
};

template<>
struct TStructOpsTypeTraits<FEquipmentList> : public TStructOpsTypeTraitsBase2<FEquipmentList>
{
	enum
	{
		WithNetDeltaSerializer = true
	};
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class EMBER_API UInventoryEquipmentManagerComponent : public UPawnComponent
{
	GENERATED_BODY()

public:
	UInventoryEquipmentManagerComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
public:
	int32 CanMoveOrMergeEquipment(UInventoryEquipmentManagerComponent* OtherComponent, EEquipmentSlotType FromEquipmentSlotType, EEquipmentSlotType ToEquipmentSlotType) const;
	int32 CanMoveOrMergeEquipment(UInventoryManagerComponent* OtherComponent, const FIntPoint& FromItemSlotPos, EEquipmentSlotType ToEquipmentSlotType) const;

	bool CanSwapEquipment(UInventoryEquipmentManagerComponent* OtherComponent, EEquipmentSlotType FromEquipmentSlotType, EEquipmentSlotType ToEquipmentSlotType) const;
	bool CanSwapEquipment(UInventoryManagerComponent* OtherComponent, const FIntPoint& FromItemSlotPos, EEquipmentSlotType ToEquipmentSlotType, FIntPoint& OutToItemSlotPos);

	int32 CanAddEquipment(int32 FromItemTemplateID, EItemRarity FromItemRarity, int32 FromItemCount, EEquipmentSlotType ToEquipmentSlotType) const;

	bool IsMatchingSlotType(EEquipmentType FromEquipmentType, EEquipmentSlotType ToEquipmentSlotType) const;
	bool IsMatchingSlotType(const UItemFragment_Equipable* FromEquippableFragment, EEquipmentSlotType ToEquipmentSlotType) const;
	bool IsSlotEquipped(EEquipmentSlotType EquipmentSlotType) const;
	bool IsSameComponent(const UInventoryEquipmentManagerComponent* OtherComponent) const;

public:
	UItemInstance* GetItemInstance(EEquipmentSlotType EquipmentSlotType) const;
	UItemInstance* GetItemInstance(const UInventoryEquipmentManagerComponent* OtherComponent, EEquipmentSlotType EquipmentSlotType) const;

	const FEquipmentList& GetEquipmentList() const { return EquipmentList; }
	int32 GetItemCount(EEquipmentSlotType EquipmentSlotType) const;
	
private:
	UPROPERTY(Replicated)
	FEquipmentList EquipmentList;
};
