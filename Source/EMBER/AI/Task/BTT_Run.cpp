// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_Run.h"

#include "BaseAI.h"
#include "BaseAIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTT_Run::UBTT_Run()
{
	NodeName = "RunState";
}

EBTNodeResult::Type UBTT_Run::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ABaseAIController* Controller = Cast<ABaseAIController>(OwnerComp.GetOwner());
	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();

	AActor* Target = Cast<AActor>(BlackboardComponent->GetValueAsObject("TargetActor"));
	if (Target==nullptr)
	{
		return EBTNodeResult::Failed;
	}
	ABaseAI* ControlledAnimal = Cast<ABaseAI>(Controller->GetPawn());
	
	FVector TargetLocation = Target->GetActorLocation();
	FVector AI_Location = ControlledAnimal->GetActorLocation();

	FVector Direction = (AI_Location - TargetLocation).GetSafeNormal();//방향벡터만 남기고 1로 설정
	FVector NewLocation = AI_Location + Direction * 500.0f;
	Controller->MoveToLocation(NewLocation);

	return EBTNodeResult::Succeeded;
}
