// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "EquipmentManagerComponent.generated.h"

enum class EWeaponSlotType : uint8;
class UItemTemplate;
class UItemInstance;
class AEquipmentBase;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class EMBER_API UEquipmentManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UEquipmentManagerComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
public:
	void AddEquipment(EWeaponSlotType WeaponSlotType, TSubclassOf<UItemTemplate> ItemTemplateClass);

public:
	UAnimMontage* GetAttackAnimMontage();
	
private:
	UFUNCTION()
	void OnRep_ItemTemplateID(int32 PrevItemTemplateID);
	
	UPROPERTY(ReplicatedUsing=OnRep_ItemTemplateID)
	int32 ItemTemplateID = INDEX_NONE;

	UPROPERTY()
	AEquipmentBase* SpawnedWeapon;
};
