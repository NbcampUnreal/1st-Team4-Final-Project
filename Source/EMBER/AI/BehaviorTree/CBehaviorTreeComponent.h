// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI_Interface.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "CBehaviorTreeComponent.generated.h"



UCLASS()
class EMBER_API UCBehaviorTreeComponent : public UBehaviorTreeComponent
{
	GENERATED_BODY()

public:
	FORCEINLINE void SetBlackboard(UBlackboardComponent* InBlackboard) { Blackboard = InBlackboard; }

public:
	UCBehaviorTreeComponent();

protected:
	virtual void BeginPlay() override;

private:
	EAnimalState GetType();

public:
	bool IsWaitMode();
	bool IsApproachMode();
	bool IsActionMode();
	bool IsPatrolMode();
	bool IsHittedMode();
	bool IsAvoidMode();
	bool IsDeadMode();

public:
	TObjectPtr<ACharacter> GetTarget();

	FVector GetPatrolLocation();
	void SetPatrolLocation(const FVector& InLocation);

	void SetWaitMode();
	void SetApproachMode();
	void SetActionMode();
	void SetPatrolMode();
	void SetHittedMode();
	void SetAvoidMode();
	void SetDeadMode();

private:
	void ChangeType(EAnimalState InType);

public:
	FAnimalStateChaged OnAIStateTypeChanged;
private:
	UPROPERTY(EditAnywhere, Category = "Key")
	FName AIStateTypeKey = "AIState";
	UPROPERTY(EditAnywhere, Category = "Key")
	FName TargetKey = "Target";
	UPROPERTY(EditAnywhere, Category = "Key")
	FName PatrolLocationKey = "Patrol_Location";

private:
	TObjectPtr<UBlackboardComponent> Blackboard;
};
