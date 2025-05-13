// Fill out your copyright notice in the Description page of Project Settings.


#include "EmberGameplayAbility.h"

#include "Player/EmberPlayerCharacter.h"
#include "Player/EmberPlayerController.h"

UEmberGameplayAbility::UEmberGameplayAbility(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ReplicationPolicy = EGameplayAbilityReplicationPolicy::ReplicateNo;
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
	NetSecurityPolicy = EGameplayAbilityNetSecurityPolicy::ClientOrServer;
	
	ActivationPolicy = EEmberAbilityActivationPolicy::OnInputTriggered;
}

AEmberPlayerCharacter* UEmberGameplayAbility::GetEmberCharacterFromActorInfo() const
{
	return (CurrentActorInfo ? Cast<AEmberPlayerCharacter>(CurrentActorInfo->AvatarActor.Get()) : nullptr);
}

AEmberPlayerController* UEmberGameplayAbility::GetEmberPlayerControllerFromActorInfo() const
{
	return (CurrentActorInfo ? Cast<AEmberPlayerController>(CurrentActorInfo->PlayerController.Get()) : nullptr);
}
