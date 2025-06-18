#include "BTT_Fly.h"
#include "AI/Base/BaseAI.h"
#include "CAIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

UBTT_Fly::UBTT_Fly()
{
	NodeName = "Fly";
	bNotifyTick = true;
}

EBTNodeResult::Type UBTT_Fly::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	 AIController = Cast<ACAIController>(OwnerComp.GetAIOwner());
	 BlackboardComp = OwnerComp.GetBlackboardComponent();
	 AI = Cast<ABaseAI>(AIController->GetPawn());

	AIController->StopMovement(); // 이동 정지

	AActor* Target = Cast<AActor>(BlackboardComp->GetValueAsObject(TEXT("TargetActor")));
	if (Target == nullptr)
	{
		//UE_LOG(LogTemp, Error, TEXT("GuardTarget is null"));
		return EBTNodeResult::Failed;
	}

	AI->GetCharacterMovement()->SetMovementMode(MOVE_Flying);
	AI->GetCharacterMovement()->MaxFlySpeed = 700;
	AI->GetCharacterMovement()->GravityScale = 0.0f;
	// ControlledAnimal->SetFlySpeed();
	AI->GetCharacterMovement()->StopMovementImmediately();
	AI->LaunchCharacter(FVector(0, 0, 400), false, true);

	return EBTNodeResult::InProgress;
}

void UBTT_Fly::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	if (AI->GetActorLocation().Z>700.0f)
	{
		AI->GetCharacterMovement()->Velocity.Z = 0.0f;
	}
	if (AI->GetCharacterMovement()->IsMovingOnGround())
	{
		AI->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
		bNotifyTick = false;
	}
}
