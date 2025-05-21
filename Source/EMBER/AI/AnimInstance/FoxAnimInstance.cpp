#include "FoxAnimInstance.h"

void UFoxAnimInstance::PlayAttackMontage(int32 Index)
{
	if (!AttackMontage || !AttackSection.IsValidIndex(Index)) return;

	FName SectionName = AttackSection[Index];
	Montage_Play(AttackMontage);
	Montage_JumpToSection(SectionName);
}
