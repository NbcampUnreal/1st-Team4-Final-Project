// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "CBTService_Dragon.generated.h"

/**
 * 
 */
UCLASS()
class EMBER_API UCBTService_Dragon : public UBTService
{
	GENERATED_BODY()

public:
	UCBTService_Dragon();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

private:
	UPROPERTY(EditAnywhere, Category = "Action")
	float ActionRange = 150.0f;
};
