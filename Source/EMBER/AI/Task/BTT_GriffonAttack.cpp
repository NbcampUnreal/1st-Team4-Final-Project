// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/BTT_GriffonAttack.h"
#include "AI/BaseAI.h"
#include "kismet/GameplayStatics.h"
#include "BaseAIController.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTT_GriffonAttack::ExecuteTask(UBehaviorTreeComponent& Comp, uint8* NodeMemory)
{
	ABaseAI* BaseAI = Cast<ABaseAI>(Comp.GetOwner());
	ABaseAIController* Controller = Cast<ABaseAIController>(BaseAI->GetController());
	
	return EBTNodeResult::InProgress;
}
