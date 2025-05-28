// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTT_Fly.generated.h"

/**
 * 
 */
UCLASS()
class EMBER_API UBTT_Fly : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTT_Fly();
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
