#pragma once

#include "CoreMinimal.h"
#include "CAIController.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTT_Fly.generated.h"

class ABaseAI;

UCLASS()
class EMBER_API UBTT_Fly : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTT_Fly();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	TObjectPtr<ACAIController> AIController;
	TObjectPtr<UBlackboardComponent> BlackboardComp;
	TObjectPtr<ABaseAI> AI;
};