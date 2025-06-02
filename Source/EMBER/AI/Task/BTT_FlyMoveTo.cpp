// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/BTT_FlyMoveTo.h"
#include "AI/BaseAI.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

EBTNodeResult::Type UBTT_FlyMoveTo::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ABaseAI* BaseAI = Cast<ABaseAI>(OwnerComp.GetAIOwner()->GetPawn());
	if (!BaseAI) return EBTNodeResult::Failed;
	OwnerCompRef = &OwnerComp;
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
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::InProgress;
}


//NavMesh 적용될 떄만 호출가능 (MoveToLocation(), MoveToActor())
void UBTT_FlyMoveTo::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
	UE_LOG(LogTemp, Warning, TEXT("FlyMoveCompleted"));
	ABaseAI* BaseAI = Cast<ABaseAI>(OwnerCompRef->GetAIOwner()->GetPawn());
	BaseAI->SetRunSpeed();
	FinishLatentTask(*OwnerCompRef, EBTNodeResult::Succeeded);
}
