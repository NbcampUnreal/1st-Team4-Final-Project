#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "Navigation/PathFollowingComponent.h" 
#include "BTT_FlyMoveTo.generated.h"

UCLASS()
class EMBER_API UBTT_FlyMoveTo : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UFUNCTION()
	void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result);

	UBehaviorTreeComponent* OwnerCompRef;

};
