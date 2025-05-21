// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AnimInstance/Rabbit_AnimInstance.h"

void URabbit_AnimInstance::AnimNotify_EndIdle()
{
	AnimalState = EAnimalState::Eating;
}

void URabbit_AnimInstance::AnimNotify_EndEat()
{
	AnimalState = EAnimalState::Looking;
}

void URabbit_AnimInstance::AnimNotify_EndLook()
{
	AnimalState = EAnimalState::Idle;
}

