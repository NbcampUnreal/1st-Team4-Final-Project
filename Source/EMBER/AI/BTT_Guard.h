#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTT_Guard.generated.h"


UCLASS()
class EMBER_API UBTT_Guard : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTT_Guard();
};
