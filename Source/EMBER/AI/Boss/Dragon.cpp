// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Boss/Dragon.h"

#include "AIWeapon/DragonSpitProjectile.h"
#include "AnimInstance/DragonAnimInstance.h"

ADragon::ADragon()
{
	// DragonBTComp = CreateDefaultSubobject<UDragonBehaviorTreeComponent>(TEXT("DragonBT"));
	// AddOwnedComponent(DragonBTComp);
}

void ADragon::BeginPlay()
{
	Super::BeginPlay();
	
	DragonAnim = Cast<UDragonAnimInstance>(GetMesh()->GetAnimInstance());
	//DragonBTComp = Cast<UDragonBehaviorTreeComponent>(GetComponentByClass(UDragonBehaviorTreeComponent::StaticClass()));
}

// void ADragon::PerformAttack()
// {
// 	switch (DragonBTComp->GetAttackState())
// 	{
// 	case EDragonAttackState::Normal:
// 		NormalAttack();
// 		break;
// 	case EDragonAttackState::Combo:
// 		ComboAttack();
// 		break;
// 	case EDragonAttackState::Spit:
// 		SpitAttack();
// 		break;
// 	case EDragonAttackState::Breath:
// 		BreathAttack();
// 		break;
// 	default:
// 		break;
// 	}
// }
//
// void ADragon::NormalAttack()
// {
// 	DragonAnim->DesiredActionType = EAnimActionType::AttackNormal;
// 	DragonAnim->DragonAttackType = EDragonAttackType::BiteAttack;
// 	DragonAnim->PlayMontage();
// }
//
// void ADragon::ComboAttack()
// {
// 	DragonAnim->DesiredActionType = EAnimActionType::AttackNormal;
// 	DragonAnim->DragonAttackType = EDragonAttackType::ComboAttack;
// 	DragonAnim->PlayMontage();
// }
//
// void ADragon::SpitAttack()
// {
// 	DragonAnim->DesiredActionType = EAnimActionType::AttackNormal;
// 	DragonAnim->DragonAttackType = EDragonAttackType::SpitAttack;
// 	DragonAnim->PlayMontage();
// }
//
// void ADragon::BreathAttack()
// {
// 	DragonAnim->DesiredActionType = EAnimActionType::AttackNormal;
// 	DragonAnim->DragonAttackType = EDragonAttackType::BreathAttack;
// 	DragonAnim->PlayMontage();
// }

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
