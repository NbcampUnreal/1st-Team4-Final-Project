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
	
	//RunState Perception 사정거리
	UFUNCTION()
	void OnRunPerceptionUpdate(AActor* UpdatedActor, FAIStimulus Stimulus);

	void CheckDetection();
	//근접한 적 업데이트 타이머
	void UpdateClosestActorTimer();
	//근접한 적 업데이트
	virtual void OnTargetPerceptionUpdated(AActor* UpdatedActor, FAIStimulus Stimulus) override;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	UAISenseConfig_Sight* RunSightConfig;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	UAIPerceptionComponent* RunPerception;

	TArray<AActor*> EnemyActors;
	AActor* ClosestActor;

	FTimerHandle UpdateDistanceTimer;
	bool bIsDetect;
	bool bIsHit;
};


