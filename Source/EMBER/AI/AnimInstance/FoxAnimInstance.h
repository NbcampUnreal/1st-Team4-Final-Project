#pragma once

#include "CoreMinimal.h"
#include "AI/AnimInstance/BaseAIAnimInstance.h"
#include "FoxAnimInstance.generated.h"


UCLASS()
class EMBER_API UFoxAnimInstance : public UBaseAIAnimInstance
{
	GENERATED_BODY()

public:
	virtual void PlayMontage(EAnimActionType Desired, EAnimActionType Fallback) override;
};
