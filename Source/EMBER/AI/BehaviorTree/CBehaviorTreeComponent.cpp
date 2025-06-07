// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BehaviorTree/CBehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"

UCBehaviorTreeComponent::UCBehaviorTreeComponent()
{
}


void UCBehaviorTreeComponent::BeginPlay()
{
	Super::BeginPlay();
}

EAnimalState UCBehaviorTreeComponent::GetType()
{
	return (EAnimalState)Blackboard->GetValueAsEnum(AIStateTypeKey);
}

#pragma region GetState

bool UCBehaviorTreeComponent::IsWaitMode()
{
	return GetType() == EAnimalState::Idle;
}

bool UCBehaviorTreeComponent::IsGuardMode()
{
	return GetType() == EAnimalState::Guard;
}

bool UCBehaviorTreeComponent::IsRunMode()
{
	return GetType() == EAnimalState::Run;
}

bool UCBehaviorTreeComponent::IsDetect()
{
	return GetType() == EAnimalState::Detect;
}

bool UCBehaviorTreeComponent::IsFlyingMode()
{
	return GetType() == EAnimalState::Flying;
}

bool UCBehaviorTreeComponent::IsPatrolMode()
{
	return GetType() == EAnimalState::Patrol;
}

bool UCBehaviorTreeComponent::IsChaseMode()
{
	return GetType() == EAnimalState::Chase;
}

bool UCBehaviorTreeComponent::IsActionMode()
{
	return GetType() == EAnimalState::Attack;
}

bool UCBehaviorTreeComponent::IsHittedMode()
{
	return GetType() == EAnimalState::Hit;
}

bool UCBehaviorTreeComponent::IsDeadMode()
{
	return GetType() == EAnimalState::Death;
}

FVector UCBehaviorTreeComponent::GetPatrolLocation()
{
	return Blackboard->GetValueAsVector(PatrolLocationKey);
}

TObjectPtr<ACharacter> UCBehaviorTreeComponent::GetTarget()
{
	if (Blackboard == nullptr)
	{
		UE_LOG(LogTemp, Error, L"Blackboard");
		return nullptr;
	}
	return Cast<ACharacter>(Blackboard->GetValueAsObject(TargetKey));
}
#pragma endregion

#pragma region SetState
void UCBehaviorTreeComponent::SetIdleMode()
{
	ChangeType(EAnimalState::Idle);
	Blackboard->SetValueAsBool("IsDetect", false);
}

void UCBehaviorTreeComponent::SetGuardMode()
{
	ChangeType(EAnimalState::Guard);
}

void UCBehaviorTreeComponent::SetRunMode()
{
	ChangeType(EAnimalState::Run);
}

void UCBehaviorTreeComponent::SetDetectMode()
{
	ChangeType(EAnimalState::Detect);
	Blackboard->SetValueAsBool("IsDetect", true);
	Blackboard->SetValueAsVector("OriginLocation", GetOwner()->GetActorLocation());
}

void UCBehaviorTreeComponent::SetFlyingMode()
{
	ChangeType(EAnimalState::Flying);
}

void UCBehaviorTreeComponent::SetPatrolMode()
{
	ChangeType(EAnimalState::Patrol);
}

void UCBehaviorTreeComponent::SetChaseMode()
{
	ChangeType(EAnimalState::Chase);
}

void UCBehaviorTreeComponent::SetActionMode()
{
	ChangeType(EAnimalState::Attack);
}

void UCBehaviorTreeComponent::SetHittedMode()
{
	ChangeType(EAnimalState::Hit);
}

void UCBehaviorTreeComponent::SetDeadMode()
{
	ChangeType(EAnimalState::Death);
}

void UCBehaviorTreeComponent::SetPatrolLocation(const FVector& InLocation)
{
	Blackboard->SetValueAsVector(PatrolLocationKey, InLocation);
}
#pragma endregion

#pragma region SetBlackboard
void UCBehaviorTreeComponent::SetBlackboard_Bool(FName Keyname, bool Value)
{
	Blackboard->SetValueAsBool(Keyname, Value);
}

void UCBehaviorTreeComponent::SetBlackboard_String(FName Keyname, FString Value)
{
	Blackboard->SetValueAsString(Keyname, Value);
}

void UCBehaviorTreeComponent::SetBlackboard_Int(FName Keyname, int Value)
{
	Blackboard->SetValueAsInt(Keyname, Value);
}

void UCBehaviorTreeComponent::SetBlackboard_Float(FName Keyname, float Value)
{
	Blackboard->SetValueAsFloat(Keyname, Value);
}

void UCBehaviorTreeComponent::SetBlackboard_Enum(FName Keyname, EAnimalState Value)
{
	Blackboard->SetValueAsEnum(Keyname, (uint8)Value);
}

void UCBehaviorTreeComponent::SetBlackboard_Object(FName Keyname, UObject* Value)
{
	Blackboard->SetValueAsObject(Keyname, Value);
}

void UCBehaviorTreeComponent::SetBlackboard_Vector(FName Keyname, FVector Value)
{
	Blackboard->SetValueAsVector(Keyname, Value);
}


#pragma endregion

void UCBehaviorTreeComponent::ChangeType(EAnimalState InType)
{
	EAnimalState prevType = GetType();

	Blackboard->SetValueAsEnum(AIStateTypeKey, (uint8)InType);

	if (OnAIStateTypeChanged.IsBound())
		OnAIStateTypeChanged.Broadcast(prevType, InType);
}
