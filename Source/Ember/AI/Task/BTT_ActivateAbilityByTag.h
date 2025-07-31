// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BTTask_Base.h"
#include "BTT_ActivateAbilityByTag.generated.h"

UCLASS()
class EMBER_API UBTT_ActivateAbilityByTag : public UBTTask_Base
{
	GENERATED_BODY()

public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	UPROPERTY(EditAnywhere, Category = "Ability", Meta = (Categories = "Ability.AI"))
	FGameplayTag GameplayTag;
};
