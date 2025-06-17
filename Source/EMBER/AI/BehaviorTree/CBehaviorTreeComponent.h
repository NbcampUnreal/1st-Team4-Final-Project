// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "CBehaviorTreeComponent.generated.h"

UENUM(BlueprintType)
enum class EAnimalState : uint8
{
	Idle UMETA(DisplayName = "Idle"),
	Guard UMETA(DisplayName = "Guard"),//���
	Detect UMETA(DisplayName = "Detect"),
	Run UMETA(DisplayName = "Running"),//����
	Avoid UMETA(DisplayName = "Avoid"),
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
	bool IsAvoidMode();
	bool IsDetect();
	bool IsFlyingMode();
	bool IsPatrolMode();
	bool IsChaseMode();
	bool IsActionMode();
	bool IsHittedMode();
	bool IsDeadMode();

public:
	void SetTarget(TObjectPtr<ACharacter> Target);
	TObjectPtr<ACharacter> GetTarget();

	FVector GetAvoidLocation();
	FVector GetPatrolLocation();
	void SetPatrolLocation(const FVector& InLocation);

	void SetIdleMode();
	void SetGuardMode();
	void SetRunMode();
	void SetAvoidMode();
	void SetDetectMode();
	void SetFlyingMode();
	void SetPatrolMode();
	void SetChaseMode();
	void SetActionMode();
	void SetHittedMode();
	void SetDeadMode();

	void SetBlackboard_Bool(FName Keyname, bool Value);
	void SetBlackboard_String(FName Keyname, FString Value);
	void SetBlackboard_Int(FName Keyname, int Value);
	void SetBlackboard_Float(FName Keyname, float Value);
	void SetBlackboard_Enum(FName Keyname, EAnimalState Value);
	void SetBlackboard_Object(FName Keyname, UObject* Value);
	void SetBlackboard_Vector(FName Keyname, FVector Value);
private:
	void ChangeType(EAnimalState InType);

public:
	FAnimalStateChaged OnAIStateTypeChanged;
private:
	UPROPERTY(EditAnywhere, Category = "Key")
	FName AIStateTypeKey = "AIState";
	UPROPERTY(EditAnywhere, Category = "Key")
	FName TargetKey = "TargetActor";
	UPROPERTY(EditAnywhere, Category = "Key")
	FName PatrolLocationKey = "Patrol_Location";
	UPROPERTY(EditAnywhere, Category = "Key")
	FName AvoidLocationKey = "Avoid_Location";

private:
	TObjectPtr<UBlackboardComponent> Blackboard;
};
