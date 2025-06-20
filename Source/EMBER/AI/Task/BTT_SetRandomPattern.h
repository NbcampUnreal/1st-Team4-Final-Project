// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTT_SetRandomPattern.generated.h"

/**
 * 
 */
UCLASS()
class EMBER_API UBTT_SetRandomPattern : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

	UBTT_SetRandomPattern();
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
