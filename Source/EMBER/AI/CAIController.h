// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CAIController.generated.h"

class UAISenseConfig_Sight;
class AHumanAIBase;
class UCBehaviorTreeComponent;
/**
 * 
 */
UCLASS()
class EMBER_API ACAIController : public AAIController
{
	GENERATED_BODY()
public:
	ACAIController();

protected:
	void OnPossess(APawn* InPawn) override;
	void OnUnPossess() override;
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnPerceptionUpdate(const TArray<AActor*>& UpdatedActors);
private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAIPerceptionComponent> Perception;

private:
	TObjectPtr<AHumanAIBase> AI;
	TObjectPtr<UCBehaviorTreeComponent> Behavior;
	TObjectPtr<UAISenseConfig_Sight> Sight;
};
