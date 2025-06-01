// Fill out your copyright notice in the Description page of Project Settings.


#include "EmberPickupableItemBase.h"

#include "Components/SphereComponent.h"


AEmberPickupableItemBase::AEmberPickupableItemBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bReplicates = true;

	PrimaryActorTick.bCanEverTick = false;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	MeshComponent->SetCollisionProfileName("NoCollision");
	SetRootComponent(MeshComponent);

	PickupCollision = CreateDefaultSubobject<USphereComponent>("SphereCollision");
	PickupCollision->SetCollisionProfileName("Pickupable");
	PickupCollision->SetupAttachment(GetRootComponent());
}
