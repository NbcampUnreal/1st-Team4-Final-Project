#pragma once

#include "CoreMinimal.h"
#include "AI/Base/BaseAI.h"
#include "Dragon.generated.h"

class UCBehaviorTreeComponent;
class UDragonAnimInstance;
class ADragonSpitProjectile;

UCLASS()
class EMBER_API ADragon : public ABaseAI
{
	GENERATED_BODY()

public:
	ADragon();
	virtual void BeginPlay() override;

	void PerformAttack();
	void NormalAttack();
	void ComboAttack();
	void SpitAttack();
	void BreathAttack();

	void OnNormalAttack();
	bool IsTargetNear() const;

	UFUNCTION()
	void SpawnSpit();

private:
	UPROPERTY()
	TObjectPtr<UDragonAnimInstance> DragonAnim;

	UPROPERTY()
	TObjectPtr<UCBehaviorTreeComponent> BTComp;

	UPROPERTY(EditdefaultsOnly)
	TSubclassOf<ADragonSpitProjectile> SpitClass;
	
	int32 AttackStack = 0;
	bool bCanSpecialAttack = false;
};
