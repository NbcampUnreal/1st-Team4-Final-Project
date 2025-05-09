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
	const TArray<FInventoryEntry>& GetAllEntries() const { return Entries; }
	
private:
	friend class UInventoryManagerComponent;
	
	UPROPERTY()
	TArray<FInventoryEntry> Entries;
	
	UPROPERTY(NotReplicated)
	TObjectPtr<UInventoryManagerComponent> InventoryManager;
};

/////////////////
/////////////////

UCLASS(BlueprintType, Blueprintable)
class UInventoryManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInventoryManagerComponent(const FObjectInitializer& FObjectInitializer = FObjectInitializer::Get());

protected:
	//~UActorComponent Overrides
	virtual void InitializeComponent() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	//~End of UActorComponent Overrides
	
public:
	int32 CanAddItem(int32 ItemTemplateID, EItemRarity ItemRarity, int32 ItemCount, TArray<FIntPoint>& OutToItemSlotPoses, TArray<int32>& OutToItemCounts) const;
	
public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	int32 TryAddItemByRarity(TSubclassOf<UItemTemplate> ItemTemplateClass, EItemRarity ItemRarity, int32 ItemCount);
	
public:
	bool IsEmpty(const TArray<bool>& InSlotChecks, const FIntPoint& ItemSlotPos, const FIntPoint& ItemSlotCount) const;
	
	const TArray<FInventoryEntry>& GetAllEntries() const;

private:
	void MarkSlotChecks(TArray<bool>& InSlotChecks, bool bIsUsing, const FIntPoint& ItemSlotPos, const FIntPoint& ItemSlotCount) const;
	
public:
	FOnInventoryEntryChanged OnInventoryEntryChanged;
	
private:
	UPROPERTY(Replicated)
	FInventoryList InventoryList;

	UPROPERTY(Replicated)
	TArray<bool> SlotChecks;
	
	FIntPoint InventorySlotCount = FIntPoint(10, 5);
};
