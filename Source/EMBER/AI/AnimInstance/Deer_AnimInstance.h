#pragma once

#include "CoreMinimal.h"
#include "AnimInstance/BaseAIAnimInstance.h"
#include "Deer_AnimInstance.generated.h"


UCLASS()
class EMBER_API UDeer_AnimInstance : public UBaseAIAnimInstance
{
	GENERATED_BODY()
	UDeer_AnimInstance();

public:
	void PlayTurnMontage(bool direction);
	UFUNCTION()
	void OnTurnMontageEnded(UAnimMontage* Montage, bool bInterrupted);
	void StopMontage();
	
	virtual void SetBlackboardBool(FName KeyName, bool bValue) override;
	
	UPROPERTY(BlueprintReadWrite, Category = "Animation")
	UAnimMontage* LeftTurnMontage;

	UPROPERTY(BlueprintReadWrite, Category = "Animation")
	UAnimMontage* RightTurnMontage;

	UPROPERTY(BlueprintReadWrite, Category = "Animation")
	UAnimMontage* AroundMontage;
	
	FTimerHandle TurnMontageTimer;
};
