// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Service/CBTService_Passive.h"
#include "AI/BehaviorTree/CBehaviorTreeComponent.h"
#include "CAIController.h"
#include "C_StateComponent.h"
#include "AI/Base/HumanAIBase.h"

UCBTService_Passive::UCBTService_Passive()
{
	NodeName = "Passive";
	Interval = 1.0f;
	RandomDeviation = 0.0f;
}

void UCBTService_Passive::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	TObjectPtr<ACAIController> controller = Cast<ACAIController>(OwnerComp.GetOwner());
	if (controller.Get() == nullptr)
	{
		UE_LOG(LogTemp, Error, L"controller is null");
		return;
	}
	TObjectPtr<ABaseAI> AI = Cast<ABaseAI>(controller->GetPawn());
	if (AI.Get() == nullptr)
	{
		UE_LOG(LogTemp, Error, L"ai is null");
		return;
	}
	TObjectPtr<UC_StateComponent> state = Cast<UC_StateComponent>(AI->GetComponentByClass(UC_StateComponent::StaticClass()));
	if (state.Get() == nullptr)
	{
		UE_LOG(LogTemp, Error, L"state is null");
		return;
	}
	TObjectPtr<UCBehaviorTreeComponent> AIState = Cast<UCBehaviorTreeComponent>(AI->GetComponentByClass(UCBehaviorTreeComponent::StaticClass()));
	if (AIState.Get() == nullptr)
	{
		UE_LOG(LogTemp, Error, L"aistate is null");
		return;
	}

	if (bDrawDebug)
	{
		FVector start = AI->GetActorLocation();
		start.Z -= 25;

		FVector end = start;
		DrawDebugCylinder(AI->GetWorld(), start, end, RunRange, 10, FColor::Red, false, Interval);
	}
	
	//Target이 없으면 Idle
	// TObjectPtr<ACharacter> Target = AIState->GetTarget(); 
	// if(Target == nullptr)
	// {
	// 	AIState->SetIdleMode();
	// 	return;
	// }
	
	// //Target과 가까우면 도망
	// float distance = AI.Get()->GetDistanceTo(Target);
	// if(distance < RunRange)
	// {
	// 	AIState->SetRunMode();
	// 	return;
	// }

	
}
