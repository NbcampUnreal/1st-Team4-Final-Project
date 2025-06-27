// Fill out your copyright notice in the Description page of Project Settings.


#include "EmberGameplayAbility_BodyTemperature.h"

#include "GameInfo/GameplayTags.h"
#include "Tasks/EmberAbilityTask_DecreaseBodyTemperature.h"

UEmberGameplayAbility_BodyTemperature::UEmberGameplayAbility_BodyTemperature(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::ServerOnly;
	NetSecurityPolicy = EGameplayAbilityNetSecurityPolicy::ServerOnly;
	
	ActivationPolicy = EEmberAbilityActivationPolicy::OnSpawn;

	FGameplayTagContainer DefaultAbilityTags;
	DefaultAbilityTags.AddTag(EmberGameplayTags::Ability_BodyTemperature);
	SetAssetTags(DefaultAbilityTags);
	ActivationOwnedTags.AddTag(EmberGameplayTags::Status_BodyTemperature);
	
	DecreaseIntervalRate = 1.0f;
	DecreaseAmount = 0.1f;
}

void UEmberGameplayAbility_BodyTemperature::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (UEmberAbilityTask_DecreaseBodyTemperature* DecreaseBodyTemperatureTask = UEmberAbilityTask_DecreaseBodyTemperature::WaitForDecreaseBodyTemperature(this, FEmberBodyTemperatureQuery(), DecreaseIntervalRate, DecreaseAmount))
	{
		DecreaseBodyTemperatureTask->ReadyForActivation();
	}
}

