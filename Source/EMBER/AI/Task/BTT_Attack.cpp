#include "BTT_Attack.h"
#include "BaseAI.h"
#include "BaseAIController.h"
#include "AnimInstance/BaseAIAnimInstance.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "../Player/EmberPlayerCharacter.h"
#include "Kismet/GameplayStatics.h"


UBTT_Attack::UBTT_Attack()
{
	NodeName = TEXT("AttackState");
	bNotifyTick = true;
	bIsMontagePlaying = false;
}

EBTNodeResult::Type UBTT_Attack::ExecuteTask(UBehaviorTreeComponent& Comp, uint8* NodeMemory)
{
	ABaseAIController* AIController = Cast<ABaseAIController>(Comp.GetAIOwner());
	if (!AIController) return EBTNodeResult::Failed;
	
	ABaseAI* AICharacter = Cast<ABaseAI>(AIController->GetCharacter());
	if (!AICharacter) return EBTNodeResult::Failed;

	AActor* TargetActor = Cast<AActor>(Comp.GetBlackboardComponent()->GetValueAsObject("TargetActor"));
	if (!TargetActor) return EBTNodeResult::Failed;

	UBaseAIAnimInstance* AIAnimInstance = Cast<UBaseAIAnimInstance>(AICharacter->GetMesh()->GetAnimInstance());
	if (!AIAnimInstance) return EBTNodeResult::Failed;

	CachedAnimInstance = AIAnimInstance;
	bIsMontagePlaying = true;

	AIAnimInstance->OnMontageEnded.AddDynamic(this, &UBTT_Attack::OnMontageEnded);
	
	AICharacter->OnAttack();
	
	UGameplayStatics::ApplyDamage(TargetActor, AICharacter->GetAttackPower(), AIController, AICharacter, nullptr);

	return EBTNodeResult::InProgress;
}

void UBTT_Attack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	if (!bIsMontagePlaying)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}
}

void UBTT_Attack::OnMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	if (CachedAnimInstance)
	{
		CachedAnimInstance->OnMontageEnded.RemoveDynamic(this, &UBTT_Attack::OnMontageEnded);
	}

	bIsMontagePlaying = false;
}


