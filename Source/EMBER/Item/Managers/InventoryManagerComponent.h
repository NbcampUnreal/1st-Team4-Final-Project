// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Net/Serialization/FastArraySerializer.h"

#include "InventoryManagerComponent.generated.h"

enum class EItemRarity : uint8;
class UItemTemplate;
class UItemInstance;
class UInventoryManagerComponent;

DECLARE_MULTICAST_DELEGATE_ThreeParams(FOnInventoryEntryChanged, const FIntPoint&/*ItemSlotPos*/, UItemInstance*, int32/*ItemCount*/)

USTRUCT(BlueprintType)
struct FInventoryEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UItemInstance* GetItemInstance() const { return ItemInstance; }
	int32 GetItemCount() const { return ItemCount; }

private:
	UItemInstance* Init(int32 InItemTemplateID, int32 InItemCount, EItemRarity InItemRarity);
	void Init(UItemInstance* InItemInstance, int32 InItemCount);
	
private:
	friend class UInventoryManagerComponent;
	friend struct FInventoryList;
	
	UPROPERTY()
	TObjectPtr<UItemInstance> ItemInstance;

	UPROPERTY()
	int32 ItemCount = 0;	
};

/////////////////
/////////////////

USTRUCT(BlueprintType)
struct FInventoryList : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	FInventoryList() : InventoryManager(nullptr) { }
	FInventoryList(UInventoryManagerComponent* InOwnerComponent) : InventoryManager(InOwnerComponent) {}

public:
	//~FFastArraySerializer 
	bool NetDeltaSerialize(FNetDeltaSerializeInfo& DeltaParams);
	void PostReplicatedAdd(const TArrayView<int32> AddedIndices, int32 FinalSize);
	void PostReplicatedChange(const TArrayView<int32> ChangedIndices, int32 FinalSize);
	//~End of FFastArraySerializer

private:
	void BroadcastChangedMessage(const FIntPoint& ItemSlotPos, UItemInstance* ItemInstance, int32 ItemCount);
	
public:
	const TArray<FInventoryEntry>& GetAllEntries() const { return Entries; }
	
private:
	friend class UInventoryManagerComponent;

	UPROPERTY()
	TArray<FInventoryEntry> Entries;
	
	UPROPERTY(NotReplicated)
	TObjectPtr<UInventoryManagerComponent> InventoryManager;
};

template<>
struct TStructOpsTypeTraits<FInventoryList> : public TStructOpsTypeTraitsBase2<FInventoryList>
{
	enum
	{
		WithNetDeltaSerializer = true
	};
};

/////////////////
/////////////////

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UInventoryManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInventoryManagerComponent(const FObjectInitializer& FObjectInitializer = FObjectInitializer::Get());

protected:
	//~UActorComponent Overrides
	virtual void InitializeComponent() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual bool ReplicateSubobjects(UActorChannel* Channel, FOutBunch* Bunch, FReplicationFlags* RepFlags) override;
	virtual void ReadyForReplication() override;
	//~End of UActorComponent Overrides
	
public:
	int32 CanAddItem(int32 ItemTemplateID, EItemRarity ItemRarity, int32 ItemCount, TArray<FIntPoint>& OutToItemSlotPoses, TArray<int32>& OutToItemCounts) const;
	
public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	int32 TryAddItemByRarity(TSubclassOf<UItemTemplate> ItemTemplateClass, EItemRarity ItemRarity, int32 ItemCount);
	
public:
	bool IsEmpty(const TArray<bool>& InSlotChecks, const FIntPoint& ItemSlotPos, const FIntPoint& ItemSlotCount) const;
	
	const TArray<FInventoryEntry>& GetAllEntries() const;
	FIntPoint GetInventorySlotCount() const { return InventorySlotCount; }
	
private:
	void MarkSlotChecks(TArray<bool>& InSlotChecks, bool bIsUsing, const FIntPoint& ItemSlotPos, const FIntPoint& ItemSlotCount) const;
	void MarkSlotChecks(bool bIsUsing, const FIntPoint& ItemSlotPos, const FIntPoint& ItemSlotCount);
	
public:
	FOnInventoryEntryChanged OnInventoryEntryChanged;
	
private:
	UPROPERTY(Replicated)
	FInventoryList InventoryList;

	UPROPERTY(Replicated)
	TArray<bool> SlotChecks;
	
	FIntPoint InventorySlotCount = FIntPoint(10, 5);
};
