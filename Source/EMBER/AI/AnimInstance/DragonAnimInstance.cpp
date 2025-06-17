#include "AI/AnimInstance/DragonAnimInstance.h"
#include "Boss/Dragon.h"

void UDragonAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
}

// void UDragonAnimInstance::PlayMontage()
// {
// 	if (DesiredActionType == EAnimActionType::AttackNormal)
// 	{
// 		if (!AttackMontage) return;
// 		
// 		FName SectionName = *UEnum::GetValueAsString(DragonAttackType).RightChop(FString("EDragonAttackType::").Len());
//
// 		Montage_Play(AttackMontage);
// 		Montage_JumpToSection(SectionName, AttackMontage);
// 	}
//
// 	else
// 	{
// 		Super::PlayMontage();
// 	}
// }

void UDragonAnimInstance::AnimNotify_SpawnSpit()
{
	if (ADragon* Dragon = Cast<ADragon>(TryGetPawnOwner()))
	{
		Dragon->SpawnSpit();
	}
}

// UAnimMontage* UDragonAnimInstance::GetMontageToPlay(EAnimActionType ActionType) const
// {
// 	if (ActionType == EAnimActionType::AttackNormal)
// 	{
// 		switch (DragonAttackType)
// 		{
// 		case EDragonAttackType::RightAttack:
// 		case EDragonAttackType::LeftAttack:
// 		case EDragonAttackType::BiteAttack:
// 		case EDragonAttackType::ComboAttack:
// 		case EDragonAttackType::SpitAttack:
// 		case EDragonAttackType::BreathAttack:
// 			return AttackMontage;
// 		}
// 	}
// 	return Super::GetMontageToPlay(ActionType);
// }
