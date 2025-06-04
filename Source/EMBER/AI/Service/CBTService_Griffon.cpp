// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Service/CBTService_Griffon.h"
#include "AI/CAIController.h"
#include "AI/Boss/Griffon.h"

UCBTService_Griffon::UCBTService_Griffon()
{
}

void UCBTService_Griffon::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);


	TObjectPtr<ACAIController> Controller = Cast<ACAIController>(OwnerComp.GetOwner());
	if(Controller.Get() == nullptr)
	{
		UE_LOG(LogTemp, Error, L"Controller is null");
		return;
	}
	TObjectPtr<AGriffon> AI = Cast<AGriffon>(Controller->GetPawn());
	if (AI.Get() == nullptr)
	{
		UE_LOG(LogTemp, Error, L"AI is null");
		return;
	}

	TObjectPtr<UCBehaviorTreeComponent> AIState = Cast<UCBehaviorTreeComponent>(AI->GetComponentByClass(UCBehaviorTreeComponent::StaticClass()));
	if (AIState.Get() == nullptr)
	{
		UE_LOG(LogTemp, Error, L"AIstate is null");
		return;
	}

	if(AIState->IsDeadMode() == true)
	{
		Controller->StopMovement();
		AIState->SetDeadMode();
		return;
	}

	if(AIState->IsHittedMode() == true)
	{
		AIState->SetHittedMode();
		return;
	}
	//Target이 없으면 Patrol
	TObjectPtr<ACharacter> target = AIState->GetTarget(); 
	if(target == nullptr)
	{
		AIState->SetPatrolMode();
		return;
	}
	//Target과 가까우면 공격
	float distance = AI.Get()->GetDistanceTo(target);
	if(distance < ActionRange)
	{
		AIState->SetActionMode();
		return;
	}
	//Default State
	AIState->SetWaitMode();
}
