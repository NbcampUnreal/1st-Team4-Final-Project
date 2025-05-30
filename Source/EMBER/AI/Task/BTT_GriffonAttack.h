#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTT_GriffonAttack.generated.h"

UCLASS()
class EMBER_API UBTT_GriffonAttack : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTT_GriffonAttack();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& Comp, uint8* NodeMemory) override;
};
