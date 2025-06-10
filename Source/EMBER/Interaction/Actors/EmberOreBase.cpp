// Fill out your copyright notice in the Description page of Project Settings.


#include "EmberOreBase.h"

#include "GameInfo/GameplayTags.h"

AEmberOreBase::AEmberOreBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	RequiredTags.AddTag(EmberGameplayTags::Ability_Mining);
}
