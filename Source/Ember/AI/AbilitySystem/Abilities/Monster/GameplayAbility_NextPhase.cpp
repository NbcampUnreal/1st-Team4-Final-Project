// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility_NextPhase.h"

#include "Abilities/Tasks/AbilityTask_PlayMontageAndWait.h"
#include "Utility/EmberGameplayTags.h"

UGameplayAbility_NextPhase::UGameplayAbility_NextPhase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bServerRespectsRemoteAbilityCancellation = true;
	bRetriggerInstancedAbility = true;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::ServerInitiated;

	AbilityTags.AddTag(EmberGameplayTags::AI_Ability_Phase);
	ActivationOwnedTags.AddTag(EmberGameplayTags::Status_Phase);
}

void UGameplayAbility_NextPhase::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	PlayNextStep();
}


void UGameplayAbility_NextPhase::PlayNextStep()
{
	StepIndex++;

	if (MontageSteps.IsValidIndex(StepIndex) == false)
	{
		EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
		return;
	}

	const FMontageStep& MontageStep = MontageSteps[StepIndex];
	if (MontageStep.Montage == false)
	{
		PlayNextStep();
		return;
	}

	if (UAbilityTask_PlayMontageAndWait* PlayMontageTask = UAbilityTask_PlayMontageAndWait::CreatePlayMontageAndWaitProxy(this, TEXT("Montage"), MontageStep.Montage, MontageStep.Rate, NAME_None, false, 1.f, 0.f, false))
	{
		PlayMontageTask->OnCompleted.AddDynamic(this, &ThisClass::OnMontageFinished);
		PlayMontageTask->OnBlendOut.AddDynamic(this, &ThisClass::OnMontageFinished);   
		PlayMontageTask->OnInterrupted.AddDynamic(this, &ThisClass::OnMontageInterrupted);
		PlayMontageTask->OnCancelled.AddDynamic(this, &ThisClass::OnMontageInterrupted);
		PlayMontageTask->ReadyForActivation();
	}
}


void UGameplayAbility_NextPhase::OnMontageFinished()
{
	PlayNextStep();
}

void UGameplayAbility_NextPhase::OnMontageInterrupted()
{
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
}
