// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_BossPatrol.generated.h"

/**
 * 
 */
UCLASS()
class EMBER_API UBTT_BossPatrol : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UBTT_BossPatrol();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

private:
	UPROPERTY(EditAnywhere, Category = "Patrol")
	bool bDebugMode;
	UPROPERTY(EditAnywhere, Category = "Patrol")
	float AcceptanceDistance = 20.0f;
	UPROPERTY(EditAnywhere, Category = "Random")
	float RandomRaduis = 1500.0f;
};
