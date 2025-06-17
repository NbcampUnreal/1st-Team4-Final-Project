// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTT_RotateToActor.generated.h"

/**
 * 
 */
UCLASS()
class EMBER_API UBTT_RotateToActor : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UBTT_RotateToActor();

	UPROPERTY(EditAnywhere)
	UAnimMontage* TurnLeftMontage;
	UPROPERTY(EditAnywhere)
	UAnimMontage* TurnRightMontage;
};
