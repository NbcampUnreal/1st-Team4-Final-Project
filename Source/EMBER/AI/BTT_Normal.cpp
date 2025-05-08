#include "EMBER/AI/BTT_Normal.h"

UBTT_Normal::UBTT_Normal()
{
	NodeName = "NormalState";
}

EBTNodeResult::Type UBTT_Normal::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	
	AC_AnimalController* AIController = Cast<AC_AnimalController>(OwnerComp.GetAIOwner());

	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
