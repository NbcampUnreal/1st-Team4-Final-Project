#include "BTT_Normal.h"
#include "BaseAI.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AI/AnimInstance/BaseAIAnimInstance.h"

UBTT_Normal::UBTT_Normal()
{
	NodeName = "NormalState";
}

EBTNodeResult::Type UBTT_Normal::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ABaseAIController* Controller = Cast<ABaseAIController>(OwnerComp.GetAIOwner());
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	ABaseAI* ControlledAI = Cast<ABaseAI>(Controller->GetPawn());
	UBaseAIAnimInstance* AnimInstance = Cast<UBaseAIAnimInstance>(ControlledAI->GetMesh()->GetAnimInstance());
	if (!BlackboardComp) return EBTNodeResult::Failed;
	
	AnimInstance->AnimalState = EAnimalState::Idle;
	AnimInstance->PlayMontage();


	bool bIsRest = BlackboardComp->GetValueAsBool(TEXT("IsRest"));
	if (!bIsRest) // false일 때
	{
		UBehaviorTreeComponent* BTComp = Cast<UBehaviorTreeComponent>(
			Controller->GetComponentByClass(UBehaviorTreeComponent::StaticClass()));
		if (BTComp)
		{
			BTComp->RestartTree();
		}
	}

	return EBTNodeResult::InProgress;
}
