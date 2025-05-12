#include "BTT_Guard.h"
#include "BaseAIController.h"
#include "BaseAI.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

UBTT_Guard::UBTT_Guard()
{
	NodeName = "GuardState";
}


//Guard는 움직임을 멈추고 

EBTNodeResult::Type UBTT_Guard::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner(); //컨트롤러 참조
	ABaseAIController* Controller = Cast<ABaseAIController>(AIController);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	ABaseAI* ControlledAnimal = Cast<ABaseAI>(Controller->GetPawn());

	AIController->StopMovement(); // 이동 정지
	ControlledAnimal->GetCharacterMovement()->MaxWalkSpeed = 400.0f; //속도 증가

	Controller->StopMovement();
	AActor* Target = Cast<AActor>(BlackboardComp->GetValueAsObject(TEXT("TargetActor")));
if (Target == nullptr)
{
	return EBTNodeResult::Failed;
}
	FVector TargetLocation = FVector(Target->GetActorLocation());
	FVector MyLocation = ControlledAnimal->GetActorLocation();

	FRotator LookRotaion = (TargetLocation - MyLocation).Rotation();
	ControlledAnimal->SetActorRotation(LookRotaion); //대상을 향해서 회전

	return EBTNodeResult::Succeeded;
}
