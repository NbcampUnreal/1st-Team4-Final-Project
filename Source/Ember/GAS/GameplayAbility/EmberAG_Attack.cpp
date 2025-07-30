#include "GAS/GameplayAbility/EmberAG_Attack.h"

#include "EmberWeaponDataAsset.h"
#include "WeaponStruct.h"
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
	PlayCurrentComboMontage();
	/*ACharacter* character = Cast<ACharacter>(ActorInfo->AvatarActor.Get());
	if (character == nullptr)
	{
		DebugLogE("character is null");
		return;
	}
	UWeaponComponent* weapon = CHelpers::GetComponent<UWeaponComponent>(character);
	CurrentComboData = weapon->GetWeaponAsset();
	if (CurrentComboData.Get()->GetActionData(CurrentCombo).bCanMove == false)
	{
		UCustomMoveComponent* move = CHelpers::GetComponent<UCustomMoveComponent>(character);
		if (move == nullptr)
		{
			DebugLogE("move component is null");
			return;
		}

		move->ShouldMove(CurrentComboData.Get()->GetActionData(CurrentCombo).bCanMove);
	}
	UAbilityTask_PlayMontageAndWait* attackMontage = UAbilityTask_PlayMontageAndWait::CreatePlayMontageAndWaitProxy(this, NAME_None,CurrentComboData.Get()->GetActionData(CurrentCombo).Montage, CurrentComboData.Get()->GetActionData(CurrentCombo).PlayRate);

	attackMontage->OnCompleted.AddDynamic(this,&UEmberAG_Attack::OnCompleteCallback);
	attackMontage->OnInterrupted.AddDynamic(this,&UEmberAG_Attack::OnInterruptedCallback);

	attackMontage->ReadyForActivation();

	StartComboTimer();*/
}

void UEmberAG_Attack::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
	CurrentComboData = nullptr;
	CurrentCombo = 0;
	bHasNextComboInput = false;
	ACharacter* character = Cast<ACharacter>(ActorInfo->AvatarActor.Get());
	if (character == nullptr)
	{
		DebugLogE("character is null");
		return;
	}
	UWeaponComponent* weapon = CHelpers::GetComponent<UWeaponComponent>(character);
	CurrentComboData = weapon->GetWeaponAsset();
	
	UCustomMoveComponent* move = CHelpers::GetComponent<UCustomMoveComponent>(character);
	if (move == nullptr)
	{
		DebugLogE("move component is null");
		return;
	}
	move->ShouldMove(!CurrentComboData.Get()->GetActionData(CurrentCombo).bCanMove);
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
	DebugLogW("Pressed");
	if (ComboTimerHandle.IsValid() == false)
		bHasNextComboInput = false;
	else
		bHasNextComboInput = true;
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

void UEmberAG_Attack::PlayCurrentComboMontage()
{
	ACharacter* character = Cast<ACharacter>(CurrentActorInfo->AvatarActor.Get());
	if (character == nullptr)
	{
		DebugLogE("character is null");
		return;
	}
	UWeaponComponent* weapon = CHelpers::GetComponent<UWeaponComponent>(character);
	CurrentComboData = weapon->GetWeaponAsset();
	if (CurrentComboData.Get()->GetActionData(CurrentCombo).bCanMove == false)
	{
		UCustomMoveComponent* move = CHelpers::GetComponent<UCustomMoveComponent>(character);
		if (move == nullptr)
		{
			DebugLogE("move component is null");
			return;
		}

		move->ShouldMove(CurrentComboData.Get()->GetActionData(CurrentCombo).bCanMove);
	}
	UAbilityTask_PlayMontageAndWait* attackMontage = UAbilityTask_PlayMontageAndWait::CreatePlayMontageAndWaitProxy(this, NAME_None, CurrentComboData.Get()->GetActionData(CurrentCombo).Montage, CurrentComboData.Get()->GetActionData(CurrentCombo).PlayRate);

	attackMontage->OnCompleted.AddDynamic(this, &UEmberAG_Attack::OnCompleteCallback);
	attackMontage->OnInterrupted.AddDynamic(this, &UEmberAG_Attack::OnInterruptedCallback);

	attackMontage->ReadyForActivation();

	StartComboTimer();
}

//FName UEmberAG_Attack::GetNextSection()
//{
//	if (CurrentComboData.Get()->GetMontageSectionNamePrefix() == TEXT("Default"))
//	{
//		CurrentCombo += 1;
//		return TEXT("Default");
//	}
//	CurrentCombo = FMath::Clamp(CurrentCombo + 1, 1, CurrentComboData.Get()->GetDoActionCount());
//	FName next = *FString::Printf(TEXT("%s%d"),*CurrentComboData->GetMontageSectionNamePrefix(), CurrentCombo);
//	return next;
//}

void UEmberAG_Attack::StartComboTimer()
{
	if (CurrentComboData.Get()->GetDoActionCount() < CurrentCombo)
		return;
	if (CurrentComboData->GetEffectiveFrameCount(CurrentCombo) <= 0)
		return;
	float comboEffectiveTime = CurrentComboData->GetEffectiveFrameCount(CurrentCombo) / CurrentComboData->GetFrameRate();
	if (comboEffectiveTime > 0.0f)
		GetWorld()->GetTimerManager().SetTimer(ComboTimerHandle,this,&UEmberAG_Attack::CheckComboInput, comboEffectiveTime,false);
}

void UEmberAG_Attack::CheckComboInput()
{
	ComboTimerHandle.Invalidate();
	if (bHasNextComboInput == true)
	{
		PlayCurrentComboMontage();
		//MontageJumpToSection(GetNextSection());
		StartComboTimer();
		CurrentCombo++;
		bHasNextComboInput = false;
	}
}
