// Fill out your copyright notice in the Description page of Project Settings.


#include "EmberTreeBase.h"

#include "GameInfo/GameplayTags.h"

AEmberTreeBase::AEmberTreeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	RequiredTags.AddTag(EmberGameplayTags::Ability_Logging);
}