// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/BTT_RotateToActor.h"

#include "AIController.h"
#include "Base/BaseAI.h"
#include "BehaviorTree/BlackboardComponent.h"


UBTT_RotateToActor::UBTT_RotateToActor()
{
	NodeName = TEXT("Turn To Target");
}

EBTNodeResult::Type UBTT_RotateToActor::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (!AIController) return EBTNodeResult::Failed;
	ABaseAI* AI = Cast<ABaseAI>(AIController->GetPawn());
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp) return EBTNodeResult::Failed;
	AActor* Target = Cast<AActor>(BlackboardComp->GetValueAsObject("TargetActor"));
	
	// 방향 계산
	FVector Direction = Target->GetActorLocation() - AI->GetActorLocation();
	Direction.Z = 0.0f; // Yaw 회전만 하도록 Z 제거

	if (Direction.IsNearlyZero())
	{
		return EBTNodeResult::Succeeded; // 이미 같은 위치라면 회전 생략
	}
	FRotator NewRotation = Direction.Rotation();
	AI->SetActorRotation(NewRotation);

	FVector Forward = AI->GetActorForwardVector();
	FVector ToTarget = (Target->GetActorLocation() - AI->GetActorLocation()).GetSafeNormal2D();

	float RightDot = FVector::CrossProduct(Forward, ToTarget).Z;
	
	if (RightDot > 0.1f && TurnRightMontage)
	{
		AI->PlayAnimMontage(TurnRightMontage);
	}
	else if (RightDot < -0.1f && TurnLeftMontage)
	{
		AI->PlayAnimMontage(TurnLeftMontage);
	}
	return EBTNodeResult::Succeeded;
}
