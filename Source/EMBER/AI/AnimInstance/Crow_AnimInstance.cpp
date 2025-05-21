// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AnimInstance/Crow_AnimInstance.h"

void UCrow_AnimInstance::AnimNotify_EndEat()
{
	CrowState = ECrowState::Looking;
}

void UCrow_AnimInstance::AnimNotify_EndLook()
{
	CrowState = ECrowState::Scretching;
}

void UCrow_AnimInstance::AnimNotify_EndScratching()
{
	CrowState = ECrowState::Stretching;
}

void UCrow_AnimInstance::AnimNotify_EndStretching()
{
	CrowState = ECrowState::Eating;
}
