#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTT_Run.generated.h"


UCLASS()
class EMBER_API UBTT_Run : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTT_Run();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
