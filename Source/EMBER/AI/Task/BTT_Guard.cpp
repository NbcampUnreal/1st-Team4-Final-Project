#include "AI/Task/BTT_Guard.h"
#include "Base/BaseAI.h"
#include "AI/CAIController.h"
#include "AnimInstance/BaseAIAnimInstance.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Tasks/BTTask_RotateToFaceBBEntry.h"

UBTT_Guard::UBTT_Guard()
{
	NodeName = TEXT("Guard");
}

EBTNodeResult::Type UBTT_Guard::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Owner = &OwnerComp;
	ACAIController* AIController = Cast<ACAIController>(OwnerComp.GetOwner());
	ABaseAI* AI = Cast<ABaseAI>(AIController->GetPawn());
	UBaseAIAnimInstance* AnimInstance = Cast<UBaseAIAnimInstance>(AI->GetMesh()->GetAnimInstance());

	AIController->StopMovement();
	AnimInstance->StopAllMontages(0.5f);

	// GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UBTT_Guard::ActorRotateUpdate, 3.0f, true);
	return EBTNodeResult::InProgress;
}

void UBTT_Guard::ActorRotateUpdate()
{
	ACAIController* Controller = Cast<ACAIController>(Owner->GetAIOwner());
	ABaseAI* AI = Controller ? Cast<ABaseAI>(Controller->GetPawn()) : nullptr;
	if (AI == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Guard: AI가 null fuck"));
		return;
	}
	UBaseAIAnimInstance* AnimInstance = Cast<UBaseAIAnimInstance>(AI->GetMesh()->GetAnimInstance());
	AActor* Target = Cast<AActor>(Owner->GetBlackboardComponent()->GetValueAsObject("TargetActor"));
	if (Target == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Guard: Target nulptr"));
		return;
	}
	// FVector MyLocation = AI->GetActorLocation();
	// FVector TargetLocation = FVector(Target->GetActorLocation());
	//
	// FVector ForwardVector = AI->GetActorForwardVector();
	// FVector ToTarget = (TargetLocation - MyLocation).GetSafeNormal();
	// FVector Cross = FVector::CrossProduct(ForwardVector, ToTarget);
	//
	// //플레이어가 왼쪽인지 오른쪽인지 판별
	// bool bDirection = (Cross.Z < 0);

	// FVector DirectionToTarget = (Target->GetActorLocation() - AI->GetActorLocation()).GetSafeNormal();
	// FRotator TargetRotation = DirectionToTarget.Rotation();
	//
	// AI->SetActorRotation(TargetRotation);

	TObjectPtr<UCBehaviorTreeComponent> AIState = Cast<UCBehaviorTreeComponent>(
		AI->GetComponentByClass(UCBehaviorTreeComponent::StaticClass()));
	if (!AIState->IsDetectMode())
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	}
}
