// Fill out your copyright notice in the Description page of Project Settings.


#include "EmbeInteractionActorBase.h"

#include "Components/SphereComponent.h"

AEmbeInteractionActorBase::AEmbeInteractionActorBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bReplicates = true;
	
	InteractionInfo.bVisible = true;
	PrimaryActorTick.bCanEverTick = false;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetCollisionProfileName(TEXT("NoCollision"));
	SetRootComponent(MeshComponent);

	PickupCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	PickupCollision->SetCollisionProfileName(TEXT("Pickupable"));
	PickupCollision->SetupAttachment(GetRootComponent());
}