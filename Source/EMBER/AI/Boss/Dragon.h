#pragma once

#include "CoreMinimal.h"
#include "AI/Base/BaseAI.h"
#include "AIComponent/CAIWeaponComponent.h"
#include "Dragon.generated.h"

class UDragonAnimInstance;
class ADragonSpitProjectile;

UCLASS()
class EMBER_API ADragon : public ABaseAI
{
	GENERATED_BODY()

public:
	ADragon();
	virtual void BeginPlay() override;

	// void PerformAttack();
	// void NormalAttack();
	// void ComboAttack();
	// void SpitAttack();
	// void BreathAttack();

	UFUNCTION()
	void SpawnSpit();

private:
	UPROPERTY()
	TObjectPtr<UDragonAnimInstance> DragonAnim;

	// UPROPERTY()
	// TObjectPtr<UDragonBehaviorTreeComponent> DragonBTComp;

	UPROPERTY(EditdefaultsOnly)
	TSubclassOf<ADragonSpitProjectile> SpitClass;
};
