// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Service/CBTService_Aggressive.h"
#include "AI/BehaviorTree/CBehaviorTreeComponent.h"
#include "CAIController.h"
#include "C_StateComponent.h"
#include "HumanAIBase.h"

UCBTService_Aggressive::UCBTService_Aggressive()
{
	NodeName = "Aggressive";
	Interval = 1.0f;
	RandomDeviation = 0.0f;
}

void UCBTService_Aggressive::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	TObjectPtr<ACAIController> controller = Cast<ACAIController>(OwnerComp.GetOwner());
	if (controller.Get() == nullptr)
	{
		UE_LOG(LogTemp, Error, L"controller is null");
		return;
	}
	TObjectPtr<AHumanAIBase> ai = Cast<AHumanAIBase>(controller->GetPawn());
	if (ai.Get() == nullptr)
	{
		UE_LOG(LogTemp, Error, L"ai is null");
		return;
	}
	TObjectPtr<UC_StateComponent> state = Cast<UC_StateComponent>(ai->GetComponentByClass(UC_StateComponent::StaticClass()));
	if (state.Get() == nullptr)
	{
		UE_LOG(LogTemp, Error, L"state is null");
		return;
	}
	TObjectPtr<UCBehaviorTreeComponent> aiState = Cast<UCBehaviorTreeComponent>(ai->GetComponentByClass(UCBehaviorTreeComponent::StaticClass()));
	if (aiState.Get() == nullptr)
	{
		UE_LOG(LogTemp, Error, L"aistate is null");
		return;
	}

	if (state->IsDeadMode() == true)
	{
		//controller->StopMovement();
		aiState->SetDeadMode();
		return;
	}

	if (state->IsHittdMode() == true)
	{
		aiState->SetHittedMode();
		return;
	}

	TObjectPtr<ACharacter> target = aiState->GetTarget();
	if (target == nullptr)
	{
		aiState->SetPatrolMode();
		return;
	}

	float distance = ai.Get()->GetDistanceTo(target);
	if (distance < ActionRange)
	{
		aiState->SetActionMode();
		return;
	}

	aiState->SetChaseMode();
}
