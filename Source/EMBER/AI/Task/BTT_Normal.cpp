#include "BTT_Normal.h"
#include "BaseAI.h"
#include "CAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AI/AnimInstance/BaseAIAnimInstance.h"

UBTT_Normal::UBTT_Normal()
{
	NodeName = "NormalState";
}

EBTNodeResult::Type UBTT_Normal::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ACAIController* Controller = Cast<ACAIController>(OwnerComp.GetAIOwner());
	ABaseAI* ControlledAI = Cast<ABaseAI>(Controller->GetPawn());
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp) return EBTNodeResult::Failed;
	if (UBaseAIAnimInstance* AnimInstance = Cast<UBaseAIAnimInstance>(ControlledAI->GetMesh()->GetAnimInstance()))
	{
		// AnimInstance->AnimalState = EAnimalState::Idle;
		// AnimInstance->PlayStateMontage();
	}
	
	return EBTNodeResult::InProgress;
}