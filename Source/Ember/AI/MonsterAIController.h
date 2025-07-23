// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "MonsterAIController.generated.h"

struct FAIStimulus;

UCLASS()
class EMBER_API AMonsterAIController : public AAIController
{
	GENERATED_BODY()

public:
	AMonsterAIController();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UAIPerceptionComponent> AIPerceptionComponent;
	
/* AI 시야 감지 */
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UAISenseConfig_Sight> AISenseConfigSight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI|Sight")
	float DetectionRadius = 1500.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI|Sight")
	float LoseInterestRadius = 2000.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI|Sight")
	float SightAngleDegree = 60.f;
};
