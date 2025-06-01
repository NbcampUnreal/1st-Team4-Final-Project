// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EmberPickupable.h"
#include "GameFramework/Actor.h"
#include "Interaction/EmberInteractable.h"
#include "EmberWorldPickupable.generated.h"

class UItemInstance;

UCLASS()
class EMBER_API AEmberWorldPickupable : public AActor, public IEmberInteractable, public IEmberPickupable
{
	GENERATED_BODY()

public:
	AEmberWorldPickupable(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	//~IEmberPickupable Override
	UFUNCTION()
	virtual FPickupInfo GetPickupInfo() const override { return PickupInfo; }
	//~End of IEmberPickupable Override

public:
	virtual void SetPickupInfo(const FPickupInfo& InPickupInfo);
	
protected:
	UFUNCTION()
	virtual void OnRep_PickupInfo(const FPickupInfo& InPickupInfo);
	
protected:
	UPROPERTY(ReplicatedUsing=OnRep_PickupInfo)
	FPickupInfo PickupInfo;
};
