// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BaseAIAnimInstance.h"

void UBaseAIAnimInstance::PlayAttackMontage()
{
	if (AttackMontage)
	{
		Montage_Play(AttackMontage);
	}
}
