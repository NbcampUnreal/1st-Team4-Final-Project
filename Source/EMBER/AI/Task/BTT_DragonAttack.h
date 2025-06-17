#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTT_DragonAttack.generated.h"

class UDragonAnimInstance;

UCLASS()
class EMBER_API UBTT_DragonAttack : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTT_DragonAttack();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UFUNCTION()
	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);

private:
	UBehaviorTreeComponent* CachedOwnerComp;
};
