#pragma once

#include "CoreMinimal.h"
#include "AI/AnimInstance/BaseAIAnimInstance.h"
#include "DragonAnimInstance.generated.h"

UCLASS()
class EMBER_API UDragonAnimInstance : public UBaseAIAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;

protected:
	UFUNCTION()
	void AnimNotify_SpawnSpit();

	UFUNCTION()
	void AnimNotify_Fly();

	UFUNCTION()
	void AnimNotify_Land();
};
