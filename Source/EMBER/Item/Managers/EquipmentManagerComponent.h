// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ActiveGameplayEffectHandle.h"
#include "GameFlag.h"
#include "Components/PawnComponent.h"
#include "System/AbilitySystem/Data/EmberAbilitySet.h"

#include "EquipmentManagerComponent.generated.h"

enum class EEquipmentSlotType : uint8;
enum class EWeaponSlotType : uint8;
class UItemTemplate;
class UItemInstance;
class AEquipmentBase;
struct FAttackData;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class EMBER_API UEquipmentManagerComponent : public UPawnComponent
{
	GENERATED_BODY()

public:
	UEquipmentManagerComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void BeginPlay() override;
	
protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
public:
	void AddEquipment(EWeaponSlotType WeaponSlotType, TSubclassOf<UItemTemplate> ItemTemplateClass);
	void Equip(EEquipmentSlotType EquipmentSlotType, UItemInstance* ItemInstance);
	void Unequip(EEquipmentSlotType EquipmentSlotType, UItemInstance* ItemInstance);

	AEquipmentBase* GetHandEquipment() const;
	void SetEquipmentActor(AEquipmentBase* InHandEquipment) { SpawnedHandEquipment = InHandEquipment; }
	
private:
	void Equip_HandEquipment(EEquipmentSlotType EquipmentSlotType, UItemInstance* ItemInstance);
	void Equip_Armor(UItemInstance* ItemInstance);
	void Unequip_HandEquipment();
	void Unequip_Armor(UItemInstance* ItemInstance);
	
public:
	UFUNCTION()
	FAttackData GetAttackInfo() const;
	UFUNCTION()
	void GetMontageIndex() const;
	
private:
	UFUNCTION()
	void OnRep_ItemTemplateID(int32 PrevItemTemplateID);

private:
	UPROPERTY(ReplicatedUsing=OnRep_ItemTemplateID)
	int32 ItemTemplateID = INDEX_NONE;

	UPROPERTY()
	AEquipmentBase* SpawnedWeapon;

	UPROPERTY()
	TObjectPtr<AEquipmentBase> SpawnedHandEquipment;
	
public:
	void Attack();

private:
	UPROPERTY(Replicated)
	FEmberAbilitySet_GrantedHandles BaseAbilitySetHandles;

	UPROPERTY(Replicated)
	FActiveGameplayEffectHandle BaseStatHandle;
	
private:
	ACharacter* OwnerCharacter;
	TObjectPtr<class UArmorComponent> ArmorComponent;
	TObjectPtr<class UMontageSystemComponent> MontageComponent;
	TObjectPtr<class UC_StateComponent> StateComponent;

	bool bIsClick;
};
