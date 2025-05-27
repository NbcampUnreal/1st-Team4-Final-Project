// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/BTT_FlyMoveTo.h"
#include "AI/BaseAI.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTT_FlyMoveTo::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ABaseAI* BaseAI = Cast<ABaseAI>(OwnerComp.GetAIOwner()->GetPawn());
	if (!BaseAI) return EBTNodeResult::Failed;

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp) return EBTNodeResult::Failed;

	AActor* TargetActor = Cast<AActor>(BlackboardComp->GetValueAsObject("TargetActor"));
	if (!TargetActor) return EBTNodeResult::Failed;

	// 목표 액터로 이동
	ABaseAIController* AIController = Cast<ABaseAIController>(BaseAI->GetController());
	if (AIController)
	{
		AIController->MoveToActor(TargetActor, 100.0f);
	}
	
	AIController->ReceiveMoveCompleted.RemoveDynamic(this, &UBTT_FlyMoveTo::OnMoveCompleted);
	AIController->ReceiveMoveCompleted.AddDynamic(this, &UBTT_FlyMoveTo::OnMoveCompleted);
	return EBTNodeResult::InProgress; // 이동 중
}

void UBTT_FlyMoveTo::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
	
}
