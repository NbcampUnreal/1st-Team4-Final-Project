// Fill out your copyright notice in the Description page of Project Settings.


#include "EmberPickupableItemBase.h"

#include "Components/SphereComponent.h"



AEmberPickupableItemBase::AEmberPickupableItemBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bReplicates = true;

	PrimaryActorTick.bCanEverTick = false;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetCollisionProfileName(TEXT("NoCollision"));
	SetRootComponent(MeshComponent);

	PickupCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	PickupCollision->SetCollisionProfileName(TEXT("Pickupable"));
	PickupCollision->SetupAttachment(GetRootComponent());
}
