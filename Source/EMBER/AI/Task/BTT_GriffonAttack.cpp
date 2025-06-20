// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/BTT_GriffonAttack.h"
#include "AI/Boss/Griffon.h"
#include "CAIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTT_GriffonAttack::UBTT_GriffonAttack()
{
	NodeName = TEXT("GriffonAttack");
}

EBTNodeResult::Type UBTT_GriffonAttack::ExecuteTask(UBehaviorTreeComponent& Comp, uint8* NodeMemory)
{
	ACAIController* AIController = Cast<ACAIController>(Comp.GetAIOwner());
	AGriffon* Griffon = Cast<AGriffon>(AIController ? AIController->GetPawn() : nullptr);

	// Griffon->Attack();
	return EBTNodeResult::Succeeded;
}
