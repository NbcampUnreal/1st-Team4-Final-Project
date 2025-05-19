#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BaseAIAnimInstance.generated.h"

UCLASS()
class EMBER_API UBaseAIAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeUpdateAnimation(float DeltaTime) override;
	
	virtual void PlayAttackMontage();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Movement")
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Movement")
	float Direction;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UAnimMontage* AttackMontage;
};
