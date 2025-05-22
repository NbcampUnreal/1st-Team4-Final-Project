// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AnimInstance/Mammoth_AnimInstance.h"

void UMammoth_AnimInstance::AnimNotify_Idle()
{
	AnimalState = EAnimalState::Idle;
}

void UMammoth_AnimInstance::AnimNotify_Run()
{
	AnimalState = EAnimalState::Run;
}

void UMammoth_AnimInstance::AnimNotify_Eat()
{
	AnimalState = EAnimalState::Eating;
}
