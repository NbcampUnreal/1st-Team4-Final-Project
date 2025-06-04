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

TObjectPtr<ACharacter> UCBehaviorTreeComponent::GetTarget()
{
	if(Blackboard == nullptr)
	{
		UE_LOG(LogTemp, Error, L"Blackboard");
		return nullptr;
	}
	return Cast<ACharacter>(Blackboard->GetValueAsObject(TargetKey));
}

FVector UCBehaviorTreeComponent::GetPatrolLocation()
{
	return Blackboard->GetValueAsVector(PatrolLocationKey);
}

void UCBehaviorTreeComponent::SetPatrolLocation(const FVector& InLocation)
{
	Blackboard->SetValueAsVector(PatrolLocationKey, InLocation);
}

void UCBehaviorTreeComponent::SetWaitMode()
{
	ChangeType(EAnimalState::Idle);
}

void UCBehaviorTreeComponent::SetGuardMode()
{
	ChangeType(EAnimalState::Guard);
}

void UCBehaviorTreeComponent::SetRunMode()
{
	ChangeType(EAnimalState::Run);
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

void UCBehaviorTreeComponent::ChangeType(EAnimalState InType)
{
	EAnimalState prevType = GetType();

	Blackboard->SetValueAsEnum(AIStateTypeKey, (uint8)InType);

	if (OnAIStateTypeChanged.IsBound())
		OnAIStateTypeChanged.Broadcast(prevType, InType);
}