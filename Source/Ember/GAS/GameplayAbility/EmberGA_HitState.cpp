// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/GameplayAbility/EmberGA_HitState.h"

#include "Character/EmberCharacter.h"
#include "GameFramework/Character.h"
#include "Utility/CLog.h"

UEmberGA_HitState::UEmberGA_HitState()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

void UEmberGA_HitState::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	DebugLogW("Hit");
	AEmberCharacter* a = Cast<AEmberCharacter>(ActorInfo->AvatarActor);
	if (a == nullptr)
		return;
	UAbilitySystemComponent* asc = ActorInfo->AbilitySystemComponent.Get();
	if (asc == nullptr)
		return;
}

void UEmberGA_HitState::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}


void UEmberGA_HitState::OnCompleteCallback()
{
	DebugLogE("complete");
	bool bReplicatedEndAbility = true;
	bool bWasCancelled = false;
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, bReplicatedEndAbility, bWasCancelled);
}