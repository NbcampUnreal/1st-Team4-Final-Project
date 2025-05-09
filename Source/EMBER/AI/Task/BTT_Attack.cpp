#include "BTT_Attack.h"
#include "BaseAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "../Player/EmberPlayerCharacter.h"
#include "Animation/AnimInstance.h"


UBTT_Attack::UBTT_Attack()
{
	NodeName = TEXT("AttackState");
}

EBTNodeResult::Type UBTT_Attack::ExecuteTask(UBehaviorTreeComponent& Comp, uint8* NodeMemory)
{
	return EBTNodeResult::Succeeded;
}
