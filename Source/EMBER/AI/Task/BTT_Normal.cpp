#include "BTT_Normal.h"
#include "BaseAI.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

UBTT_Normal::UBTT_Normal()
{
	NodeName = "NormalState";
}

EBTNodeResult::Type UBTT_Normal::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ABaseAIController* Controller = Cast<ABaseAIController>(OwnerComp.GetAIOwner());
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	ABaseAI* ControlledAnimal = Cast<ABaseAI>(Controller->GetPawn());
	
	if (!ControlledAnimal) return EBTNodeResult::Failed;

	if (!BlackboardComp) return EBTNodeResult::Failed;

	//ControlledAnimal->GetCharacterMovement()->MaxWalkSpeed = 200.0f; //속도는 동물별 변수를 생성

	bool bIsRest = BlackboardComp->GetValueAsBool(TEXT("IsRest"));
	if (!bIsRest) // false일 때
	{
		UBehaviorTreeComponent* BTComp = Cast<UBehaviorTreeComponent>(Controller->GetComponentByClass(UBehaviorTreeComponent::StaticClass()));
		if (BTComp)
		{
			BTComp->RestartTree();
		}
	}

	return EBTNodeResult::InProgress;
}
