#pragma once

#include "CoreMinimal.h"
#include "AI_Interface.h"
#include "BaseAIController.h"
#include "Animation/AnimInstance.h"
#include "BaseAIAnimInstance.generated.h"

UCLASS()
class EMBER_API UBaseAIAnimInstance : public UAnimInstance, public IAI_Interface
{
	GENERATED_BODY()

public:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Movement")
	float CurrentSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Movement")
	float CurrentDirection;
	
	virtual void PlayAttackMontage();
	virtual void PlayDeathMontage();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UAnimMontage* AttackMontage;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UAnimMontage* DeathMontage;

	virtual void SetBlackboardBool(FName KeyName, bool bValue) override;
	virtual void SetBlackboardInt(FName KeyName, int value) override;
	virtual void SetBlackboardFloat(FName KeyName, float value) override;
	virtual void SetBlackboardVector(FName KeyName, FVector value) override;
	virtual void SetBlackboardObject(FName KeyName, UObject* object) override;

	UBlackboardComponent* BlackboardComp;
	
	EAnimalState AnimalState;
};
