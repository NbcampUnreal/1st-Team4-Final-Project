#include "BTT_Normal.h"
#include "BaseAI.h"
#include "GameFramework/CharacterMovementComponent.h"

UBTT_Normal::UBTT_Normal()
{
	NodeName = "NormalState";
}

EBTNodeResult::Type UBTT_Normal::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* Controller = OwnerComp.GetAIOwner();
	ABaseAI* Self = Cast<ABaseAI>(Controller->GetPawn());
	Self->GetCharacterMovement()->MaxWalkSpeed = 200.0f;//원레 속도로 복원


	return EBTNodeResult::Succeeded;
}
