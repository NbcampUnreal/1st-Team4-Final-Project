#include "BTT_Run.h"

#include "BaseAI.h"
#include "BaseAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

UBTT_Run::UBTT_Run()
{
	NodeName = "RunState";
}

EBTNodeResult::Type UBTT_Run::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	OwnerCompRef = &OwnerComp;
	ABaseAIController* Controller = Cast<ABaseAIController>(OwnerComp.GetOwner());
	BlackboardComponent = OwnerComp.GetBlackboardComponent();
	ControlledAnimal = Cast<ABaseAI>(Controller->GetPawn());

	AActor* Target = Cast<AActor>(BlackboardComponent->GetValueAsObject("TargetActor"));
	if (Target == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("RunTarget is null"));
		return EBTNodeResult::Failed;
	}

	ControlledAnimal->SetRunSpeed();
	FVector TargetLocation = Target->GetActorLocation();
	FVector AI_Location = ControlledAnimal->GetActorLocation();
	FVector Direction = (AI_Location - TargetLocation).GetSafeNormal(); //방향벡터만 남기고 1로 설정
	FVector NewLocation = AI_Location + Direction * 1500.0f;
	
	Controller->ReceiveMoveCompleted.RemoveDynamic(this, &UBTT_Run::OnMoveCompleted);
	Controller->MoveToLocation(NewLocation, 50.f);
	Controller->ReceiveMoveCompleted.AddDynamic(this, &UBTT_Run::OnMoveCompleted);

	return EBTNodeResult::InProgress;
}

void UBTT_Run::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
	UE_LOG(LogTemp, Warning, TEXT("On Run Completed"));
	BlackboardComponent->SetValueAsBool("IsHit", false);
	ControlledAnimal->SetWalkSpeed();
	FinishLatentTask(*OwnerCompRef, EBTNodeResult::Succeeded);
}
