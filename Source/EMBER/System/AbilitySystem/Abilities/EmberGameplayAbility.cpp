// Fill out your copyright notice in the Description page of Project Settings.


#include "EmberGameplayAbility.h"

#include "EmberLocalPlayer.h"
#include "Player/EmberPlayerCharacter.h"
#include "Player/EmberPlayerController.h"
#include "AbilitySystemComponent.h"
#include "System/AbilitySystem/EmberAbilitySystemComponent.h"

UEmberGameplayAbility::UEmberGameplayAbility(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ReplicationPolicy = EGameplayAbilityReplicationPolicy::ReplicateNo;
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
	NetSecurityPolicy = EGameplayAbilityNetSecurityPolicy::ClientOrServer;
	
	ActivationPolicy = EEmberAbilityActivationPolicy::OnInputTriggered;
}

void UEmberGameplayAbility::TryActivateAbilityOnSpawn(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) const
{
	const bool bIsPredicting = (Spec.ActivationInfo.ActivationMode == EGameplayAbilityActivationMode::Predicting);

	if (ActorInfo && !Spec.IsActive() && !bIsPredicting && (ActivationPolicy == EEmberAbilityActivationPolicy::OnSpawn))
	{
		UAbilitySystemComponent* ASC = ActorInfo->AbilitySystemComponent.Get();
		const AActor* AvatarActor = ActorInfo->AvatarActor.Get();

		if (ASC && AvatarActor && !AvatarActor->GetTearOff() && (AvatarActor->GetLifeSpan() <= 0.0f))
		{
			const bool bIsLocalExecution = (NetExecutionPolicy == EGameplayAbilityNetExecutionPolicy::LocalPredicted) || (NetExecutionPolicy == EGameplayAbilityNetExecutionPolicy::LocalOnly);
			const bool bIsServerExecution = (NetExecutionPolicy == EGameplayAbilityNetExecutionPolicy::ServerOnly) || (NetExecutionPolicy == EGameplayAbilityNetExecutionPolicy::ServerInitiated);

			const bool bClientShouldActivate = ActorInfo->IsLocallyControlled() && bIsLocalExecution;
			const bool bServerShouldActivate = ActorInfo->IsNetAuthority() && bIsServerExecution;

			if (bClientShouldActivate || bServerShouldActivate)
			{
				ASC->TryActivateAbility(Spec.Handle);
			}
		}
	}
}

UEmberAbilitySystemComponent* UEmberGameplayAbility::GetEmberAbilitySystemComponentFromActorInfo() const
{
	return (CurrentActorInfo ? Cast<UEmberAbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent.Get()) : nullptr);
}

AEmberPlayerCharacter* UEmberGameplayAbility::GetEmberCharacterFromActorInfo() const
{
	return (CurrentActorInfo ? Cast<AEmberPlayerCharacter>(CurrentActorInfo->AvatarActor.Get()) : nullptr);
}

AEmberPlayerController* UEmberGameplayAbility::GetEmberPlayerControllerFromActorInfo() const
{
	return (CurrentActorInfo ? Cast<AEmberPlayerController>(CurrentActorInfo->PlayerController.Get()) : nullptr);
}

AController* UEmberGameplayAbility::GetControllerFromActorInfo() const
{
	return (CurrentActorInfo ? CurrentActorInfo->PlayerController.Get() : nullptr);
}

UEmberLocalPlayer* UEmberGameplayAbility::GetEmberLocalPlayerFromActorInfo() const
{
	if (APlayerController* Controller = CurrentActorInfo->PlayerController.Get())
	{
		return Cast<UEmberLocalPlayer>(Controller->Player);
	}

	return nullptr;
}

bool UEmberGameplayAbility::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, FGameplayTagContainer* OptionalRelevantTags) const
{
	if (!ActorInfo || !ActorInfo->AbilitySystemComponent.IsValid())
	{
		return false;
	}

	if (!Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags))
	{
		return false;
	}

	return true;
}
