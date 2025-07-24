// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "MonsterAIController.generated.h"

enum EGameTeamID :uint8
{
	Monster = 0,
	Team1
};

UCLASS()
class EMBER_API AMonsterAIController : public AAIController
{
	GENERATED_BODY()

public:
	AMonsterAIController();

protected:
	virtual void BeginPlay() override;

/* 팀 설정 */
public:
	//~ IGenericTeamAgentInterface interface
	virtual FGenericTeamId GetGenericTeamId() const override;
	//~ End of IGenericTeamAgentInterface interface
	
/* AI 감지 */
protected:
	UFUNCTION()
	virtual void OnTargetPerceptionUpdated(AActor* Actor, struct FAIStimulus Stimulus);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UAIPerceptionComponent> AIPerceptionComponent;
	
/* AI 감지 - 시야 */
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
