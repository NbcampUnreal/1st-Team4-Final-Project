#include "BTT_Guard.h"
#include "BaseAIController.h"
#include "BaseAI.h"
#include "BaseAIAnimInstance.h"
#include "PassiveAI.h"
#include "Animal/Deer_AnimInstance.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

UBTT_Guard::UBTT_Guard()
{
	NodeName = "GuardState";
}

EBTNodeResult::Type UBTT_Guard::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ABaseAIController* Controller = Cast<ABaseAIController>(OwnerComp.GetAIOwner());
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	ABaseAI* ControlledAnimal = Cast<ABaseAI>(Controller->GetPawn());

	Controller->StopMovement(); // 이동 정지

	AActor* Target = Cast<AActor>(BlackboardComp->GetValueAsObject(TEXT("TargetActor")));
	if (Target == nullptr)
	{
		//UE_LOG(LogTemp, Error, TEXT("GuardTarget is null"));
		return EBTNodeResult::Failed;
	}
	FVector TargetLocation = FVector(Target->GetActorLocation());
	FVector MyLocation = ControlledAnimal->GetActorLocation();
	
	FVector ForwardVector = ControlledAnimal->GetActorForwardVector();
	FVector ToTarget = (TargetLocation - MyLocation).GetSafeNormal();

	FVector Cross = FVector::CrossProduct(ForwardVector, ToTarget);
	bool bDirection = (Cross.Z < 0);

	if (UDeer_AnimInstance* AnimInstance = Cast<UDeer_AnimInstance>(ControlledAnimal->GetMesh()->GetAnimInstance()))
	{
		AnimInstance->PlayTurnMontage(bDirection);
	}

	return EBTNodeResult::InProgress;
}
