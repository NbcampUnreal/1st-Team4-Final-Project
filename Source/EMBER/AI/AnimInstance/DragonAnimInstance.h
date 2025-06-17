#pragma once

#include "CoreMinimal.h"
#include "AI/AnimInstance/BaseAIAnimInstance.h"
#include "DragonAnimInstance.generated.h"

UENUM(BlueprintType)
enum class EDragonAttackType : uint8
{
	RightAttack,
	LeftAttack,
	BiteAttack,
	ComboAttack,
	SpitAttack,
	BreathAttack,
};

UCLASS()
class EMBER_API UDragonAnimInstance : public UBaseAIAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Dragon|Anim")
	EDragonAttackType DragonAttackType;
	
	//virtual void PlayMontage() override;

	UFUNCTION()
	void AnimNotify_SpawnSpit();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dragon|Anim")
	TMap<EAnimActionType, FName> DragonAttackSectionMap;
	
	//virtual UAnimMontage* GetMontageToPlay(EAnimActionType ActionType) const override;
};
