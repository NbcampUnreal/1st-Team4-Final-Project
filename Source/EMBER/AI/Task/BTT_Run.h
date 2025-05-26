#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "Navigation/PathFollowingComponent.h"
#include "BaseAI.h"
#include "BTT_Run.generated.h"

UCLASS()
class EMBER_API UBTT_Run : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTT_Run();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	UFUNCTION()
	void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result);

	UBehaviorTreeComponent* OwnerCompRef;
	ABaseAI* ControlledAnimal;
	UBlackboardComponent* BlackboardComponent;
};
