// Fill out your copyright notice in the Description page of Project Settings.


#include "EmberWorldInteractable.h"
#include "AbilitySystemComponent.h"

AEmberWorldInteractable::AEmberWorldInteractable(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bReplicates = true;
	
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	MeshComponent->SetCollisionProfileName(TEXT("Interactable"));
	MeshComponent->SetCanEverAffectNavigation(true);
	SetRootComponent(MeshComponent);

	InteractionInfo.bVisible = false;
}

FEmberInteractionInfo AEmberWorldInteractable::GetPreInteractionInfo( const FEmberInteractionQuery& InteractionQuery) const
{
	return InteractionInfo;
}

UMeshComponent* AEmberWorldInteractable::GetMeshComponent() const
{
	return MeshComponent;
}

bool AEmberWorldInteractable::CanInteraction(UAbilitySystemComponent* ASC) const
{
	if (ASC == nullptr)
		return false;
	
	return ASC->HasAllMatchingGameplayTags(RequiredTags);
}
