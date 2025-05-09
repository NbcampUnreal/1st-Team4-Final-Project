// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTT_Guard.h"

UBTT_Guard::UBTT_Guard()
{
	NodeName = "GuardState";
}

EBTNodeResult::Type UBTT_Guard::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	

	return EBTNodeResult::Succeeded;
}
