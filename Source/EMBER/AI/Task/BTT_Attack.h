#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTT_Attack.generated.h"


UCLASS()
class EMBER_API UBTT_Attack : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTT_Attack();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& Comp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, Category="Attack")
	UAnimMontage* AttackMontage;
};
