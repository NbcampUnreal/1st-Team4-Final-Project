// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "CBTDecorator_FarAttack.generated.h"

/**
 * 
 */
UCLASS()
class EMBER_API UCBTDecorator_FarAttack : public UBTDecorator
{
	GENERATED_BODY()
public:
	virtual FName GetNodeIconName() const override;
protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

private:
	UPROPERTY(EditAnywhere)
	float FarAttackRange;
	UPROPERTY(EditAnywhere)
	bool bDebug;
};
