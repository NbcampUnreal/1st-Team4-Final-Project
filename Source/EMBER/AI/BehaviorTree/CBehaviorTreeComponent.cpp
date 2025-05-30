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

EAIStateType UCBehaviorTreeComponent::GetType()
{
	return (EAIStateType)Blackboard->GetValueAsEnum(AIStateTypeKey);
}

bool UCBehaviorTreeComponent::IsWaitMode()
{
	return GetType() == EAIStateType::Wait;
}

bool UCBehaviorTreeComponent::IsApproachMode()
{
	return GetType() == EAIStateType::Approach;
}

bool UCBehaviorTreeComponent::IsActionMode()
{
	return GetType() == EAIStateType::Action;
}

bool UCBehaviorTreeComponent::IsPatrolMode()
{
	return GetType() == EAIStateType::Patrol;
}

bool UCBehaviorTreeComponent::IsHittedMode()
{
	return GetType() == EAIStateType::Hitted;
}

bool UCBehaviorTreeComponent::IsAvoidMode()
{
	return GetType() == EAIStateType::Avoid;
}

bool UCBehaviorTreeComponent::IsDeadMode()
{
	return GetType() == EAIStateType::Dead;
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

//FVector UCBehaviorTreeComponent::GetPatrolLocation()
//{
//	return Blackboard->GetValueAsVector(PatrolLocationKey);
//}

//FVector UCBehaviorTreeComponent::GetAvoidlocation()
//{
//	return Blackboard->GetValueAsVector(AvoidLocationKey);
//}



//void UCBehaviorTreeComponent::SetPatrolLocation(const FVector& InLocation)
//{
//	Blackboard->SetValueAsVector(PatrolLocationKey, InLocation);
//}

void UCBehaviorTreeComponent::SetWaitMode()
{
	ChangeType(EAIStateType::Wait);
}

void UCBehaviorTreeComponent::SetApproachMode()
{
	ChangeType(EAIStateType::Approach);
}

void UCBehaviorTreeComponent::SetActionMode()
{
	ChangeType(EAIStateType::Action);
}

void UCBehaviorTreeComponent::SetPatrolMode()
{
	ChangeType(EAIStateType::Patrol);
}

void UCBehaviorTreeComponent::SetHittedMode()
{
	ChangeType(EAIStateType::Hitted);
}

void UCBehaviorTreeComponent::SetAvoidMode()
{
	ChangeType(EAIStateType::Avoid);
}

void UCBehaviorTreeComponent::SetDeadMode()
{
	ChangeType(EAIStateType::Dead);
}

void UCBehaviorTreeComponent::ChangeType(EAIStateType InType)
{
	EAIStateType prevType = GetType();

	Blackboard->SetValueAsEnum(AIStateTypeKey, (uint8)InType);

	if (OnAIStateTypeChanged.IsBound())
		OnAIStateTypeChanged.Broadcast(prevType, InType);
}