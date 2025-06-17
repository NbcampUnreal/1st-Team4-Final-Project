// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Boss/Dragon.h"

#include "AIWeapon/DragonSpitProjectile.h"
#include "AnimInstance/DragonAnimInstance.h"
#include "BehaviorTree/CBehaviorTreeComponent.h"

ADragon::ADragon()
{
}

void ADragon::BeginPlay()
{
	Super::BeginPlay();

	BTComp = Cast<UCBehaviorTreeComponent>(GetComponentByClass(UCBehaviorTreeComponent::StaticClass()));
	DragonAnim = Cast<UDragonAnimInstance>(GetMesh()->GetAnimInstance());
}

void ADragon::PerformAttack()
{
	if (bCanSpecialAttack)
	{
		if (IsTargetNear())
		{
			ComboAttack();
		}
		else
		{
			SpitAttack();
		}

		AttackStack = 0;
		bCanSpecialAttack = false;
	}

	else
	{
		NormalAttack();
	}
}

void ADragon::NormalAttack()
{
	DragonAnim->DesiredActionType = EAnimActionType::AttackNormal;
	DragonAnim->DragonAttackType = EDragonAttackType::BiteAttack;
	DragonAnim->PlayMontage();
}

void ADragon::ComboAttack()
{
	DragonAnim->DesiredActionType = EAnimActionType::AttackNormal;
	DragonAnim->DragonAttackType = EDragonAttackType::ComboAttack;
	DragonAnim->PlayMontage();
}

void ADragon::SpitAttack()
{
	if (!SpitClass) return;

	
	DragonAnim->DesiredActionType = EAnimActionType::AttackNormal;
	DragonAnim->DragonAttackType = EDragonAttackType::SpitAttack;
	DragonAnim->PlayMontage();
}

void ADragon::BreathAttack()
{
	DragonAnim->DesiredActionType = EAnimActionType::AttackNormal;
	DragonAnim->DragonAttackType = EDragonAttackType::BreathAttack;
	DragonAnim->PlayMontage();
}

void ADragon::OnNormalAttack()
{
	AttackStack++;

	if (AttackStack >= 3)
	{
		bCanSpecialAttack = true;
	}
}

bool ADragon::IsTargetNear() const
{
	float Distance = FVector::Dist(GetActorLocation(), BTComp->GetTarget()->GetActorLocation());
	return Distance < 1000.f;
}

void ADragon::SpawnSpit()
{
	if (SpitClass == nullptr) return;
	
	FVector SpawnLocation = GetMesh()->GetSocketLocation(TEXT("MouthSocket"));
	FRotator SpawnRotation = GetActorRotation();

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.Instigator = GetInstigator();

	GetWorld()->SpawnActor<ADragonSpitProjectile>(SpitClass, SpawnLocation, SpawnRotation, SpawnParams);
}
