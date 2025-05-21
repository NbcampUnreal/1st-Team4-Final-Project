// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Animal/Fox.h"
#include "AI/AnimInstance/FoxAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"

AFox::AFox()
{
	WalkSpeed=150.f;
	RunSpeed=600.f;
}

void AFox::Attack()
{
	Super::Attack();

	if (UFoxAnimInstance* FoxAnim = Cast<UFoxAnimInstance>(GetMesh()->GetAnimInstance()))
	{
		float Speed = GetVelocity().Size();
		bool bIsInAir = GetCharacterMovement()->IsFalling();

		// if (bIsInAir)
		// {
		// 	FoxAnim->PlayAttackMontage(EFoxAttackType::JumpBite);
		// }
		// else if (Speed >= RunSpeed)
		// {
		// 	FoxAnim->PlayAttackMontage(EFoxAttackType::RunBite);
		// }
		// else
		// {
		// 	FoxAnim->PlayAttackMontage(EFoxAttackType::Bite);
		// }
	}
}
