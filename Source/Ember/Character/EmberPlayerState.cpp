// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/EmberPlayerState.h"
#include "Utility/CHelpers.h"
#include "AbilitySystemComponent.h"

AEmberPlayerState::AEmberPlayerState()
{
	CHelpers::CreateActorComponent(this, &ASC, "Ability System Component");
	ASC->SetIsReplicated(true);
}

UAbilitySystemComponent* AEmberPlayerState::GetAbilitySystemComponent() const
{
	return  ASC;
}
