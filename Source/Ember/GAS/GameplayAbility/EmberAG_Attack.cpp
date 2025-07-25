#include "GAS/GameplayAbility/EmberAG_Attack.h"

#include "EmberWeaponDataAsset.h"
#include "Character/EmberCharacter.h"
#include "Component/CustomMoveComponent.h"
#include "Component/WeaponComponent.h"
#include "Utility/CHelpers.h"
#include "Utility/CLog.h"
#include "Abilities/Tasks/AbilityTask_PlayMontageAndWait.h"

UEmberAG_Attack::UEmberAG_Attack()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

void UEmberAG_Attack::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	ACharacter* character = Cast<ACharacter>(ActorInfo->AvatarActor.Get());
	if (character == nullptr)
	{
		DebugLogE("character is null");
		return;
	}
	UWeaponComponent* weapon = CHelpers::GetComponent<UWeaponComponent>(character);
	CurrentComboData = weapon->GetWeaponData();
	if (CurrentComboData.Get()->GetCanMove() == false)
	{
		UCustomMoveComponent* move = CHelpers::GetComponent<UCustomMoveComponent>(character);
		if (move == nullptr)
		{
			DebugLogE("move component is null");
			return;
		}

		move->ShouldMove(CurrentComboData.Get()->GetCanMove());
	}
	UAbilityTask_PlayMontageAndWait* attackMontage = UAbilityTask_PlayMontageAndWait::CreatePlayMontageAndWaitProxy(this, TEXT("Default"),CurrentComboData.Get()->GetAttackMontage(),1.0f);

	attackMontage->OnCompleted.AddDynamic(this,&UEmberAG_Attack::OnCompleteCallback);
	attackMontage->OnInterrupted.AddDynamic(this,&UEmberAG_Attack::OnInterruptedCallback);

	attackMontage->ReadyForActivation();

}

void UEmberAG_Attack::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
	ACharacter* character = Cast<ACharacter>(ActorInfo->AvatarActor.Get());
	if (character == nullptr)
	{
		DebugLogE("character is null");
		return;
	}
	UWeaponComponent* weapon = CHelpers::GetComponent<UWeaponComponent>(character);
	CurrentComboData = weapon->GetWeaponData();
	
	UCustomMoveComponent* move = CHelpers::GetComponent<UCustomMoveComponent>(character);
	if (move == nullptr)
	{
		DebugLogE("move component is null");
		return;
	}
	move->ShouldMove(true);
}

void UEmberAG_Attack::CancelAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateCancelAbility)
{
	Super::CancelAbility(Handle, ActorInfo, ActivationInfo, bReplicateCancelAbility);
}

void UEmberAG_Attack::InputPressed(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo)
{
	Super::InputPressed(Handle, ActorInfo, ActivationInfo);
}

void UEmberAG_Attack::OnCompleteCallback()
{
	bool bReplicatedEndAbility = true;
	bool bWasCancelled = false;
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, bReplicatedEndAbility, bWasCancelled);
}

void UEmberAG_Attack::OnInterruptedCallback()
{
	bool bReplicatedEndAbility = true;
	bool bWasCancelled = false;
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, bReplicatedEndAbility, bWasCancelled);

}

FName UEmberAG_Attack::GetNextSection()
{
	return "";
}

void UEmberAG_Attack::StartComboTimer()
{
}

void UEmberAG_Attack::CheckComboInput()
{
}
