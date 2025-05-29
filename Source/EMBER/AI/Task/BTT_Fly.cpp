#include "AI/Task/BTT_Fly.h"
#include "AI/BaseAI.h"
#include "AI/Animal/Crow.h"
#include "AnimInstance/Crow_AnimInstance.h"


UBTT_Fly::UBTT_Fly()
{
	NodeName = "Fly";
}

EBTNodeResult::Type UBTT_Fly::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ABaseAIController* Controller = Cast<ABaseAIController>(OwnerComp.GetAIOwner());
	ACrow* ControlledAnimal = Cast<ACrow>(Controller->GetPawn());

	if (UCrow_AnimInstance* AnimInstance = Cast<UCrow_AnimInstance>(ControlledAnimal->GetMesh()->GetAnimInstance()))
	{
		AnimInstance->AnimalState = EAnimalState::Flying;
		AnimInstance->Crow_Height = 100.f;
	}
	
	

	
	return EBTNodeResult::Succeeded;
}
