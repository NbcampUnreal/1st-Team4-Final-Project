// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/BTT_DragonAttack.h"
#include "CAIController.h"
#include "Boss/Dragon.h"
#include "AnimInstance/DragonAnimInstance.h"
#include "BehaviorTree/DragonBehaviorTreeComponent.h"

UBTT_DragonAttack::UBTT_DragonAttack()
{
	NodeName = TEXT("Dragon Attack");
	CachedOwnerComp = nullptr;
}

EBTNodeResult::Type UBTT_DragonAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// ACAIController* AIController = Cast<ACAIController>(OwnerComp.GetAIOwner());
	// ADragon* Dragon = Cast<ADragon>(AIController->GetPawn());
	// if (!Dragon) return EBTNodeResult::Failed;
	//
	// UDragonAnimInstance* DragonAnim = Cast<UDragonAnimInstance>(Dragon->GetMesh()->GetAnimInstance());
	// if (!DragonAnim) return EBTNodeResult::Failed;
	//
	// //Dragon->PerformAttack();
	//
	// FOnMontageEnded MontageEndedDelegate;
	// MontageEndedDelegate.BindUObject(this, &UBTT_DragonAttack::OnAttackMontageEnded);
	//
	// if (UAnimMontage* CurrentMontage = DragonAnim->GetCurrentActiveMontage())
	// {
	// 	DragonAnim->Montage_SetEndDelegate(MontageEndedDelegate, CurrentMontage);
	// }
	// else
	// {
	// 	return EBTNodeResult::Failed;
	// }
	//
	// CachedOwnerComp = &OwnerComp;
	return EBTNodeResult::InProgress;
}

void UBTT_DragonAttack::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	// if (CachedOwnerComp)
	// {
	// 	if (ADragon* Dragon = Cast<ADragon>(CachedOwnerComp->GetAIOwner()->GetPawn()))
	// 	{
	// 		if (UDragonBehaviorTreeComponent* DragonBT = Cast<UDragonBehaviorTreeComponent>(Dragon->GetComponentByClass(UDragonBehaviorTreeComponent::StaticClass())))
	// 		{
	// 			DragonBT->SetAttackState(EDragonAttackState::None);
	// 		}
	// 	}
	// 	FinishLatentTask(*CachedOwnerComp, bInterrupted ? EBTNodeResult::Failed : EBTNodeResult::Succeeded);
	// 	CachedOwnerComp = nullptr;
	// }
}
