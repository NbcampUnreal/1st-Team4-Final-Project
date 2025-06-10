#pragma once

#include "CoreMinimal.h"
#include "AI/Base/PassiveAI.h"
#include "Griffon.generated.h"

UCLASS()
class EMBER_API AGriffon : public APassiveAI
{
	GENERATED_BODY()

public:
	AGriffon();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void Attack();
	
	//virtual void OnTargetPerceptionUpdated(AActor* UpdatedActor, FAIStimulus Stimulus) override;

	void SetCombatState();
};
