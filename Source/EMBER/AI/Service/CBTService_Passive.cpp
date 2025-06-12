// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Service/CBTService_Passive.h"
#include "AI/BehaviorTree/CBehaviorTreeComponent.h"
#include "CAIController.h"
#include "AI/Base/HumanAIBase.h"
#include "BehaviorTree/BlackboardComponent.h"

UCBTService_Passive::UCBTService_Passive()
{
	NodeName = "Passive";
	Interval = 1.0f;
	RandomDeviation = 0.0f;
}

void UCBTService_Passive::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	TObjectPtr<ACAIController> Controller = Cast<ACAIController>(OwnerComp.GetOwner());
	if (Controller.Get() == nullptr)
	{
		UE_LOG(LogTemp, Error, L"controller is null");
		return;
	}
	TObjectPtr<ABaseAI> AI = Cast<ABaseAI>(Controller->GetPawn());
	if (AI.Get() == nullptr)
	{
		UE_LOG(LogTemp, Error, L"ai is null");
		return;
	}
	TObjectPtr<UCBehaviorTreeComponent> AIState = Cast<UCBehaviorTreeComponent>(
		AI->GetComponentByClass(UCBehaviorTreeComponent::StaticClass()));
	if (AIState.Get() == nullptr)
	{
		UE_LOG(LogTemp, Error, L"aistate is null");
		return;
	}

	AActor* TagetActor = Cast<AActor>(Controller->GetBlackboardComponent()->GetValueAsObject("TargetActor"));

	if (TagetActor)
	{
		FVector TargetLocation = TagetActor->GetActorLocation();
		FVector AILocation = AI->GetActorLocation();

		float Distance = FVector::Dist(TargetLocation, AILocation);

		if (Distance < RunRange)
		{
			AIState->SetRunMode();
		}
		return;
	}

	if (AIState->IsHittedMode())
	{
		AIState->SetRunMode();
		return;
	}
}
