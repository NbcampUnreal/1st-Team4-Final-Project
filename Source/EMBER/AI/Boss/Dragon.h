#pragma once

#include "CoreMinimal.h"
#include "AI/Base/BaseAI.h"
#include "Dragon.generated.h"

class ACAIController;
class ADragonSpitProjectile;
class ADragonBreathActor;
class UBTT_DragonAttack;

UCLASS()
class EMBER_API ADragon : public ABaseAI
{
	GENERATED_BODY()

public:
	ADragon();
	virtual void BeginPlay() override;

	UFUNCTION()
	void SpawnSpit();

	UFUNCTION()
	void SpawnBreath();

	UFUNCTION()
	void StopBreath();

	void Landed(const FHitResult& Hit) override;

	void SetLaunchZPower(float InZPower) { LaunchZPower = InZPower; }
	float GetLaunchZPower() const { return LaunchZPower; }

	UBTT_DragonAttack* GetCurrentAttackTask() const { return CurrentAttackTask; }
	void SetCurrentAttackTask(UBTT_DragonAttack* Task) { CurrentAttackTask = Task; }

	AActor* GetTargetActor() { return TargetActor; }

private:
	UPROPERTY(EditdefaultsOnly)
	TSubclassOf<ADragonSpitProjectile> SpitClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ADragonBreathActor> BreathClass;

	UPROPERTY()
	ADragonBreathActor* CurrentBreath;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<ACAIController> AIController;

	UPROPERTY(EditDefaultsOnly)
	UCBehaviorTreeComponent* BTComp;

	UPROPERTY()
	AActor* TargetActor;

	float LaunchZPower = 300.f;
	UBTT_DragonAttack* CurrentAttackTask;
};
