#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BaseAIAnimInstance.generated.h"

UCLASS()
class EMBER_API UBaseAIAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void PlayAttackMontage();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UAnimMontage* AttackMontage;
};
