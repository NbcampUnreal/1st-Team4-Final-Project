#pragma once

#include "CoreMinimal.h"
#include "AI/BaseAI.h"
#include "PassiveAI.generated.h"

UCLASS()
class EMBER_API APassiveAI : public ABaseAI
{
	GENERATED_BODY()

public:
	APassiveAI();
	virtual void BeginPlay() override;
	
	void CheckDetection(bool IsDetect);
	//근접한 적 업데이트 타이머
	void UpdateClosestActorTimer();
	//근접한 적 업데이트
//	virtual void OnTargetPerceptionUpdated(AActor* UpdatedActor, FAIStimulus Stimulus) override;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	virtual void OnDeath() override;
	TArray<AActor*> EnemyActors;
	AActor* ClosestActor;

	FTimerHandle UpdateDistanceTimer;
	bool bIsHit;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float ClosestDistanceBoundary;

	float ClosestDistance;

};


