// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/BTT_Hitte.h"

UBTT_Hitte::UBTT_Hitte()
{
	NodeName = L"Hitted";
}

EBTNodeResult::Type UBTT_Hitte::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}

EBTNodeResult::Type UBTT_Hitte::AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return Super::AbortTask(OwnerComp, NodeMemory);
}

void UBTT_Hitte::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
}
