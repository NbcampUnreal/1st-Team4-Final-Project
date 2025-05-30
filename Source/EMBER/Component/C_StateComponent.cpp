﻿#include "Component/C_StateComponent.h"

UC_StateComponent::UC_StateComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UC_StateComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UC_StateComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

bool UC_StateComponent::IsIdleMode() const
{
	return CurrentStateType == EStateType::Idle;
}

bool UC_StateComponent::IsEquipMode() const
{
	return CurrentStateType == EStateType::Equip;
}

bool UC_StateComponent::IsActionMode() const
{
	return CurrentStateType == EStateType::Action;
}

bool UC_StateComponent::IsHittdMode() const
{
	return CurrentStateType == EStateType::Hitted;
}

bool UC_StateComponent::IsDeadMode() const
{
	return CurrentStateType == EStateType::Dead;
}

void UC_StateComponent::SetIdleMode()
{
	CurrentStateType = EStateType::Idle;
}

void UC_StateComponent::SetEquipMode()
{
	CurrentStateType = EStateType::Equip;
}

void UC_StateComponent::SetActionMode()
{
	CurrentStateType = EStateType::Action;
}

void UC_StateComponent::SetHittdMode()
{
	CurrentStateType = EStateType::Hitted;
}

void UC_StateComponent::SetDeadMode()
{
	CurrentStateType = EStateType::Dead;
}

