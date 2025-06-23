#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DragonBreathActor.generated.h"

class UNiagaraSystem;

UCLASS()
class EMBER_API ADragonBreathActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ADragonBreathActor();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DragonBreath|Damage")
	float Damage = 10.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DragonBreath|Trace")
	float TraceLength = 1200.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DragonBreath|Trace")
	float TraceRadius = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DragonBreath|Trace")
	int32 TraceCount = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DragonBreath|Trace")
	float TotalSpreadAngle = 30.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DragonBreath|VFX")
	UNiagaraSystem* BreathEffect;

private:
	TSet<AActor*> DamagedActors;
	FTimerHandle DestroyHandle;

	void SprayDamage();
};
