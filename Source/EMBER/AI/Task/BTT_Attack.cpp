#include "BTT_Attack.h"
#include "BaseAI.h"
#include "BaseAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "../Player/EmberPlayerCharacter.h"
#include "Animation/AnimInstance.h"
#include "kismet/GameplayStatics.h"


UBTT_Attack::UBTT_Attack()
{
	NodeName = TEXT("AttackState");
}

EBTNodeResult::Type UBTT_Attack::ExecuteTask(UBehaviorTreeComponent& Comp, uint8* NodeMemory)
{
	ABaseAIController* AIController = Cast<ABaseAIController>(Comp.GetAIOwner());
	
	if (ABaseAI* AICharacter = Cast<ABaseAI>(AIController ? AIController->GetCharacter() : nullptr))
	{
		AICharacter->PlayAttackAnimation();
		
		if (AActor* TargetActor = Cast<AActor>(Comp.GetBlackboardComponent()->GetValueAsObject("TargetActor")))
		{
			UGameplayStatics::ApplyDamage(TargetActor, AICharacter->GetAttackPower(), AIController, AICharacter, nullptr);
		}
	}
	return EBTNodeResult::Succeeded;
}
