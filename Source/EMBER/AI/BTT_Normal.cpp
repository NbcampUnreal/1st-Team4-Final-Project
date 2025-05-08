#include "EMBER/AI/BTT_Normal.h"
#include "EMBER/AI/BaseAIController.h"

UBTT_Normal::UBTT_Normal()
{
	NodeName = "NormalState";
}

EBTNodeResult::Type UBTT_Normal::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	
	ABaseAIController* AIController = Cast<ABaseAIController>(OwnerComp.GetAIOwner());
	

	
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
