#include "AI/Task/BTT_Guard.h"
#include "Base/BaseAI.h"
#include "AI/CAIController.h"
#include "AnimInstance/BaseAIAnimInstance.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Tasks/BTTask_RotateToFaceBBEntry.h"

EBTNodeResult::Type UBTT_Guard::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Owner = &OwnerComp;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UBTT_Guard::ActorRotateUpdate, 3.0f, true);
	return EBTNodeResult::InProgress;
}

void UBTT_Guard::ActorRotateUpdate()
{
	ACAIController* Controller = Cast<ACAIController>(Owner->GetAIOwner());
	ABaseAI* AI = Controller ? Cast<ABaseAI>(Controller->GetPawn()) : nullptr;
	if (AI == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("AI가 null fuck"));
		return;
	}
	UBaseAIAnimInstance* AnimInstance = Cast<UBaseAIAnimInstance>(AI->GetMesh()->GetAnimInstance());
	AActor* Target = Cast<AActor>(Owner->GetBlackboardComponent()->GetValueAsObject("TargetActor"));
	if (Target == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Target nulptr"));
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

	AnimInstance->StopAllMontages(1.0f);
	Controller->StopMovement();

	FVector DirectionToTarget = (Target->GetActorLocation() - AI->GetActorLocation()).GetSafeNormal();
	FRotator TargetRotation = DirectionToTarget.Rotation();

	AI->SetActorRotation(TargetRotation);

	TObjectPtr<UCBehaviorTreeComponent> AIState = Cast<UCBehaviorTreeComponent>(AI->GetComponentByClass(UCBehaviorTreeComponent::StaticClass()));
	if (!AIState->IsDetect())
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	}
}
