// Fill out your copyright notice in the Description page of Project Settings.


#include "EmberPlayerState.h"

#include "EmberPlayerCharacter.h"
#include "Managers/InventoryManagerComponent.h"
#include "System/AbilitySystem/EmberAbilitySystemComponent.h"


AEmberPlayerState::AEmberPlayerState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	AbilitySystemComponent = ObjectInitializer.CreateDefaultSubobject<UEmberAbilitySystemComponent>(this, "EmberAbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
}

void AEmberPlayerState::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	check(AbilitySystemComponent);
	AbilitySystemComponent->InitAbilityActorInfo(this, GetPawn());
}

UAbilitySystemComponent* AEmberPlayerState::GetAbilitySystemComponent() const
{
	return GetEmberAbilitySystemComponent();
}


void AEmberPlayerState::Server_AddInventoryItem_Implementation(TSubclassOf<UItemTemplate> InItemTemplateClass, EItemRarity InItemRarity, int32 InItemCount)
{
	if (HasAuthority() == false)
		return;

	if (AEmberPlayerCharacter* EmberCharacter = GetPawn<AEmberPlayerCharacter>())
	{
		if (UInventoryManagerComponent* InventoryManager = EmberCharacter->GetComponentByClass<UInventoryManagerComponent>())
		{
			InventoryManager->TryAddItemByRarity(InItemTemplateClass, InItemRarity, InItemCount);
		}
	}
}
