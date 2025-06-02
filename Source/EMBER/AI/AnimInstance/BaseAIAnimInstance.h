#pragma once

#include "CoreMinimal.h"
#include "AI_Interface.h"
#include "BaseAIController.h"
#include "Animation/AnimInstance.h"
#include "BaseAIAnimInstance.generated.h"

UENUM(BlueprintType)
enum class EAnimActionType : uint8
{
	AttackNormal,
	AttackJump,
	AttackRun,
	
	HitFront,
	HitLeft,
	HitRight,

	MAX
};

UCLASS()
class EMBER_API UBaseAIAnimInstance : public UAnimInstance, public IAI_Interface
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Movement")
	float CurrentSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Movement")
	float CurrentHeight;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Movement")
	float CurrentDirection;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Movement")
	bool bIsAirborne;
	
	virtual void PlayMontage(EAnimActionType Desired, EAnimActionType Fallback);
	virtual void PlayStateMontage(); //AnimalState에 따라 자동으로 몽타주 재생
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EAnimalState AnimalState;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Anim")
	TMap<EAnimActionType, FName> AnimSectionMap;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Anim")
	UAnimMontage* IdleMontage;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Anim")
	UAnimMontage* AttackMontage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Anim")
	UAnimMontage* HitMontage;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Anim")
	UAnimMontage* DeathMontage;

	virtual UAnimMontage* GetMontageToPlay(EAnimActionType ActionType) const;
	virtual UAnimMontage* GetMontageToPlay();

	virtual void SetBlackboardBool(FName KeyName, bool bValue) override;
	virtual void SetBlackboardInt(FName KeyName, int value) override;
	virtual void SetBlackboardFloat(FName KeyName, float value) override;
	virtual void SetBlackboardVector(FName KeyName, FVector value) override;
	virtual void SetBlackboardObject(FName KeyName, UObject* object) override;

	UBlackboardComponent* BlackboardComp;

	
};