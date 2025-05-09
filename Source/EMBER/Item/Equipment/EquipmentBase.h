﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFlag.h"
#include "GameFramework/Actor.h"
#include "EquipmentBase.generated.h"

class UArrowComponent;

UCLASS(Abstract, BlueprintType)
class EMBER_API AEquipmentBase : public AActor
{
	GENERATED_BODY()

public:
	AEquipmentBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
private:
	UFUNCTION()
	void OnRep_ItemTemplateID();
	
	UFUNCTION()
	void OnRep_EquipmentSlotType();

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UArrowComponent> ArrowComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<USkeletalMeshComponent> MeshComponent;
	
protected:
	UPROPERTY(ReplicatedUsing=OnRep_ItemTemplateID)
	int32 ItemTemplateID = INDEX_NONE;
	
	UPROPERTY(ReplicatedUsing=OnRep_EquipmentSlotType)
	EEquipmentSlotType EquipmentSlotType = EEquipmentSlotType::Count;
};
