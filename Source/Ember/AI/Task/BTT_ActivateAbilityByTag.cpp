// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_ActivateAbilityByTag.h"

#include "AbilitySystemComponent.h"
#include "AI/AbilitySystem/MonsterAbilitySystemComponent.h"
#include "AI/Monster/MonsterAIBase.h"

EBTNodeResult::Type UBTT_ActivateAbilityByTag::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	if (ActorOwner == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	
	if (UMonsterAbilitySystemComponent* ASC = Cast<UMonsterAbilitySystemComponent>(ActorOwner->GetAbilitySystemComponent()))
	{
		if (ASC->TryActivateAbilityByTag(GameplayTag) == false)
		{
			Result = EBTNodeResult::Failed;
		}
	}

	return Result;
}
