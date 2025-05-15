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
	virtual void Tick(float DeltaTime) override;
	//RunState Perception 사정거리
	UFUNCTION()
	void OnRunPerceptionUpdate(AActor* UpdatedActor, FAIStimulus Stimulus);
	//근접한 적 업데이트
	void UpdateClosestActorTimer();
	//GuardState Perception 사정거리
	virtual void OnTargetPerceptionUpdate(AActor* UpdatedActor, FAIStimulus Stimulus);

	void CheckDetection();
	//RunPerception 생성
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	UAISenseConfig_Sight* RunSightConfig;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	UAIPerceptionComponent* RunPerception;

	UBlackboardComponent* BlackboardComp;
	TArray<AActor*> EnemyActors;
	AActor* ClosestActor;

	FTimerHandle UpdateDistanceTimer;
	bool bIsDetect;
};


