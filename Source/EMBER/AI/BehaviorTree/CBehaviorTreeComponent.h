// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "CBehaviorTreeComponent.generated.h"

UENUM()
enum EAIStateType
{
	Wait = 0, Approach, Action, Patrol, Hitted, Avoid, Dead, MAX
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAIStateTypeChanged, EAIStateType, InPrevType, EAIStateType, InNewType);

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
	EAIStateType GetType();

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

	void SetWaitMode();
	void SetApproachMode();
	void SetActionMode();
	void SetPatrolMode();
	void SetHittedMode();
	void SetAvoidMode();
	void SetDeadMode();

private:
	void ChangeType(EAIStateType InType);

public:
	FAIStateTypeChanged OnAIStateTypeChanged;
private:
	UPROPERTY(EditAnywhere, Category = "Key")
	FName AIStateTypeKey = "AIState";
	UPROPERTY(EditAnywhere, Category = "Key")
	FName TargetKey = "Target";
	UPROPERTY(EditAnywhere, Category = "Key")
	FName AvoidLocationKey= "Avoid Location";

private:
	TObjectPtr<UBlackboardComponent> Blackboard;
};
