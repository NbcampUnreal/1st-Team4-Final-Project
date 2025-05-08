#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_Normal.generated.h"

class AC_AnimalController;

UCLASS()
class EMBER_API UBTT_Normal : public UBTTaskNode
{
	GENERATED_BODY()
	
	public:

	UBTT_Normal();
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};
