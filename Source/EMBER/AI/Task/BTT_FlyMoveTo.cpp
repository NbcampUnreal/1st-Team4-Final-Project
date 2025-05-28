// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/BTT_FlyMoveTo.h"
#include "AI/BaseAI.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

EBTNodeResult::Type UBTT_FlyMoveTo::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ABaseAI* BaseAI = Cast<ABaseAI>(OwnerComp.GetAIOwner()->GetPawn());
	if (!BaseAI) return EBTNodeResult::Failed;

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp) return EBTNodeResult::Failed;

	AActor* TargetActor = Cast<AActor>(BlackboardComp->GetValueAsObject("TargetActor"));
	if (!TargetActor) return EBTNodeResult::Failed;


	ABaseAIController* AIController = Cast<ABaseAIController>(BaseAI->GetController());

	FVector CurrentLocation = BaseAI->GetActorLocation();
	FVector TargetLocation = TargetActor->GetActorLocation();

	FVector Direction = (TargetLocation - BaseAI->GetActorLocation()).GetSafeNormal();
	float Speed = BaseAI->GetCharacterMovement()->MaxFlySpeed;

	BaseAI->GetCharacterMovement()->Velocity = Direction * Speed;

	AIController->ReceiveMoveCompleted.RemoveDynamic(this, &UBTT_FlyMoveTo::OnMoveCompleted);
	AIController->ReceiveMoveCompleted.AddDynamic(this, &UBTT_FlyMoveTo::OnMoveCompleted);
	return EBTNodeResult::InProgress; // 이동 중
}

void UBTT_FlyMoveTo::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
}
