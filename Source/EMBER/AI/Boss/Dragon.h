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

	UFUNCTION()
	void SpawnSpit();

	void SetLaunchZPower(float InZPower) { LaunchZPower = InZPower; }
	float GetLaunchZPower() const { return LaunchZPower; }

private:
	UPROPERTY()
	TObjectPtr<UDragonAnimInstance> DragonAnim;

	UPROPERTY(EditdefaultsOnly)
	TSubclassOf<ADragonSpitProjectile> SpitClass;

	float LaunchZPower = 600.f;
};
