// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/BTT_FlyMoveTo.h"
#include "AI/Base/BaseAI.h"
#include "AI/CAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

UBTT_FlyMoveTo::UBTT_FlyMoveTo()
{
	bNotifyTick = true;
}

EBTNodeResult::Type UBTT_FlyMoveTo::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	BaseAI = Cast<ABaseAI>(OwnerComp.GetAIOwner()->GetPawn());
	if (!BaseAI) return EBTNodeResult::Failed;
	OwnerCompRef = &OwnerComp;
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp) return EBTNodeResult::Failed;

	ACAIController* AIController = Cast<ACAIController>(BaseAI->GetController());
	AActor* TargetActor = Cast<AActor>(BlackboardComp->GetValueAsObject("TargetActor"));
	if (TargetActor)
	{
		CurrentLocation = BaseAI->GetActorLocation();
		TargetLocation = TargetActor->GetActorLocation();
		FVector Direction = (TargetLocation - CurrentLocation).GetSafeNormal();
		float Speed = BaseAI->GetCharacterMovement()->MaxFlySpeed;
		BaseAI->GetCharacterMovement()->Velocity = Direction * Speed;
	}

	
	return EBTNodeResult::InProgress;
}

bool UBTT_FlyMoveTo::IsNearGround()
{
	if (!BaseAI) return false;

	FVector Start = BaseAI->GetActorLocation();
	FVector End = Start - FVector(0, 0, 200.0f); // 아래로 100cm 트레이스

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(BaseAI);

	FHitResult Hit;
	bool bHit = BaseAI->GetWorld()->LineTraceSingleByChannel(
		Hit,
		Start,
		End,
		ECC_Visibility,
		Params
	);
	DrawDebugLine(
		BaseAI->GetWorld(),
		Start,
		End,
		bHit ? FColor::Green : FColor::Red, // 맞으면 초록, 아니면 빨강
		false,
		0.1f,
		0,
		2.0f
	);


	return bHit;
}

void UBTT_FlyMoveTo::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	// if (IsNearGround())
	// {
	// 	UE_LOG(LogTemp, Warning, TEXT("Get Ground"));
	// 	BaseAI->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	// 	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	// }

	CurrentLocation = BaseAI->GetActorLocation();
	float Distance = FVector::Dist(CurrentLocation, TargetLocation);

	if (BaseAI->GetCharacterMovement()->IsMovingOnGround())
	{
		UE_LOG(LogTemp, Display, TEXT("Movement already in progress"));
		BaseAI->GetCharacterMovement()->GravityScale = 1.0f;
		BaseAI->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}
}




//NavMesh 적용될 떄만 호출가능 (MoveToLocation(), MoveToActor())
// void UBTT_FlyMoveTo::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
// {
// 	UE_LOG(LogTemp, Warning, TEXT("FlyMoveCompleted"));
// 	ABaseAI* BaseAI = Cast<ABaseAI>(OwnerCompRef->GetAIOwner()->GetPawn());
// 	BaseAI->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
// 	FinishLatentTask(*OwnerCompRef, EBTNodeResult::Succeeded);
// }
