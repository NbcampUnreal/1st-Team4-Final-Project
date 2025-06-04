// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI_Interface.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "CBehaviorTreeComponent.generated.h"


UENUM(BlueprintType)
enum class EAnimalState : uint8
{
	Idle UMETA(DisplayName = "Idle"),
	Guard UMETA(DisplayName = "Guard"),//경계
	//Near UMETA(DisplayName = "Near"),//->서비스에서 대체
	Run UMETA(DisplayName = "Running"),//도망
	Patrol UMETA(DisplayName = "Patrol"),
	Chase UMETA(DisplayName = "Chase"),
	Attack UMETA(DisplayName = "Attack"),
	Hit UMETA(DisplayName = "Hit"),
	Death UMETA(DisplayName = "Death"),
	Flying UMETA(DisplayName = "Flying"),//
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAnimalStateChaged, EAnimalState, InPrevType, EAnimalState, InNewType);

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
	bool IsGuardMode();
	bool IsRunMode();
	bool IsFlyingMode();
	bool IsPatrolMode();
	bool IsChaseMode();
	bool IsActionMode();
	bool IsHittedMode();
	bool IsDeadMode();

public:
	TObjectPtr<ACharacter> GetTarget();

	FVector GetPatrolLocation();
	void SetPatrolLocation(const FVector& InLocation);

	void SetWaitMode();
	void SetGuardMode();
	void SetRunMode();
	void SetFlyingMode();
	void SetPatrolMode();
	void SetChaseMode();
	void SetActionMode();
	void SetHittedMode();
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
