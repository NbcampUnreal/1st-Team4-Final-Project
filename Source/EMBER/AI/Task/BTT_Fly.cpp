#include "BTT_Fly.h"
#include "AI/Base/BaseAI.h"
#include "CAIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

UBTT_Fly::UBTT_Fly()
{
	NodeName = "Fly";
}

EBTNodeResult::Type UBTT_Fly::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ACAIController* Controller = Cast<ACAIController>(OwnerComp.GetAIOwner());
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	ABaseAI* ControlledAnimal = Cast<ABaseAI>(Controller->GetPawn());

	Controller->StopMovement(); // 이동 정지

	AActor* Target = Cast<AActor>(BlackboardComp->GetValueAsObject(TEXT("TargetActor")));
	if (Target == nullptr)
	{
		//UE_LOG(LogTemp, Error, TEXT("GuardTarget is null"));
		return EBTNodeResult::Failed;
	}
	// FVector TargetLocation = FVector(Target->GetActorLocation());
	// FVector MyLocation = ControlledAnimal->GetActorLocation();
	//
	// FVector ForwardVector = ControlledAnimal->GetActorForwardVector();
	// FVector ToTarget = (TargetLocation - MyLocation).GetSafeNormal();
	// FVector Cross = FVector::CrossProduct(ForwardVector, ToTarget);
	//
	// //플레이어가 왼쪽인지 오른쪽인지 판별
	// bool bDirection = (Cross.Z < 0);
	//
	// //플레이어와의 각도 계산
	// float AngleDegrees = FMath::Abs(FMath::Acos(FVector::DotProduct(ForwardVector, ToTarget)) * (180 / PI));

	ControlledAnimal->GetCharacterMovement()->SetMovementMode(MOVE_Flying);
	ControlledAnimal->GetCharacterMovement()->MaxFlySpeed = 700;
	ControlledAnimal->GetCharacterMovement()->GravityScale = 0.0f;
	// ControlledAnimal->SetFlySpeed();
	ControlledAnimal->GetCharacterMovement()->StopMovementImmediately();
	ControlledAnimal->LaunchCharacter(FVector(0, 0, 400), false, true);

	return EBTNodeResult::InProgress;
}