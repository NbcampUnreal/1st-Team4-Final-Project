
#pragma once

#include "CoreMinimal.h"
#include "AI/AnimInstance/BaseAIAnimInstance.h"
#include "Griffon_AnimInstance.generated.h"


UCLASS()
class EMBER_API UGriffon_AnimInstance : public UBaseAIAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	float CurrentFlySpeed;
};
