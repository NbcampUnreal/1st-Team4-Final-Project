// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTT_Guard.generated.h"

/**
 * 
 */
UCLASS()
class EMBER_API UBTT_Guard : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

	UBTT_Guard();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	void ActorRotateUpdate();

	UBehaviorTreeComponent* Owner;
	FTimerHandle TimerHandle;
};
