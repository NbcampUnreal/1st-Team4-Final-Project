﻿#include "BTT_Patrol.h"
#include "BaseAI.h"
#include "AIController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTT_Patrol::UBTT_Patrol()
{
	NodeName = "PatrolState";
}

EBTNodeResult::Type UBTT_Patrol::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	OwnerCompRef = &OwnerComp;
	AAIController* AIController = OwnerComp.GetAIOwner(); //컨트롤러 참조
	if (!AIController)
	{
		UE_LOG(LogTemp, Warning, TEXT("Miss Controller"));
		return EBTNodeResult::Failed;
	}
	
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent(); //블랙보드 참조
	AllBlack = BlackboardComp;
	ABaseAI* ControlledAnimal = Cast<ABaseAI>(BlackboardComp->GetValueAsObject("PatrolPoint")); //사용되는 액터 참조

	
	if (ControlledAnimal == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Miss Animal"));
		FinishLatentTask(*OwnerCompRef, EBTNodeResult::Failed);
	}
	if (ControlledAnimal->patrolpoint.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("empty PatrolPoint"));
		FinishLatentTask(*OwnerCompRef, EBTNodeResult::Failed);
	}

	ControlledAnimal->GetCharacterMovement()->MaxWalkSpeed = 170.0f; //속도조절
	
	int32 CurrentIndex = BlackboardComp->GetValueAsInt("PatrolIndex"); //현재 위치인덱스
	CurrentIndex = (CurrentIndex + 1) % ControlledAnimal->patrolpoint.Num(); //다음이동인덱스 업데이트

	BlackboardComp->SetValueAsInt("PatrolIndex", CurrentIndex); //블랙보드에 인덱스 업데이트
	ATargetPoint* NextPoint = ControlledAnimal->patrolpoint[CurrentIndex]; //이동할액터위치 설정

	AIController->MoveToActor(NextPoint);
	if (NextPoint != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Moving to: %s"), *NextPoint->GetName());
	}


	AIController->ReceiveMoveCompleted.AddDynamic(this, &UBTT_Patrol::OnMoveCompleted);
	UE_LOG(LogTemp, Warning, TEXT("Move Completed Delegate Bound"));
	return EBTNodeResult::InProgress;
}

void UBTT_Patrol::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
	if (Result == EPathFollowingResult::Success)
	{
		UE_LOG(LogTemp, Warning, TEXT("OnMoveCompleted"));
		AllBlack->SetValueAsBool("IsRest", true);
		FinishLatentTask(*OwnerCompRef, EBTNodeResult::Succeeded);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("OnMoveFailed"));
		FinishLatentTask(*OwnerCompRef, EBTNodeResult::Failed);
	}
}
