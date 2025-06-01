// Fill out your copyright notice in the Description page of Project Settings.


#include "EmberWorldPickupable.h"

AEmberWorldPickupable::AEmberWorldPickupable(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bReplicates = true;
	
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;
}

void AEmberWorldPickupable::SetPickupInfo(const FPickupInfo& InPickupInfo)
{
	if (HasAuthority() == false)
		return;

	if (InPickupInfo.ItemInstance)
	{
		PickupInfo = InPickupInfo;
		OnRep_PickupInfo(InPickupInfo);
	}
	else
	{
		Destroy();
	}
}

void AEmberWorldPickupable::OnRep_PickupInfo(const FPickupInfo& InPickupInfo)
{
	
}
