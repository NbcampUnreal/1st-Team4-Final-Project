// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Service/CBTService_Griffon.h"
#include "AI/CAIController.h"
#include "AI/Boss/Griffon.h"
#include "BehaviorTree/BlackboardComponent.h"

UCBTService_Griffon::UCBTService_Griffon()
{
	Interval = 1.0f;
	RandomDeviation = 0.0f;
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

	//Target이 없으면 Patrol
	TObjectPtr<ACharacter> Target = AIState->GetTarget(); 
	if(Target == nullptr)
	{
		AIState->SetIdleMode();
		return;
	}
	//Target과 가까우면 AttackMode
	float distance = AI.Get()->GetDistanceTo(Target);
	if(distance < ActionRange)
	{
		AIState->SetActionMode();
		return;
	}
	FVector OriginLocation = Controller->GetBlackboardComponent()->GetValueAsVector("OriginLocation");
	FVector TargetLocation = Target->GetActorLocation();
	float Distance = FVector::Dist(OriginLocation, TargetLocation);
	if (Distance >= 3000.0f)
	{
		UE_LOG(LogTemp, Error, L"Distance is too Far in Service");
		AIState->SetIdleMode();
		return;
	}
}