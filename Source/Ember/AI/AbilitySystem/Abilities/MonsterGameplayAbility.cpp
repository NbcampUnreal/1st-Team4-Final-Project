// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterGameplayAbility.h"

#include "AIController.h"
#include "AI/Monster/MonsterAIBase.h"

AMonsterAIBase* UMonsterGameplayAbility::GetMonsterAIFromActorInfo() const
{
	return (CurrentActorInfo ? Cast<AMonsterAIBase>(CurrentActorInfo->AvatarActor.Get()) : nullptr);
}

AAIController* UMonsterGameplayAbility::GetMonsterAIControllerFromActorInfo() const
{
	return (CurrentActorInfo ? Cast<AAIController>(GetAvatarActorFromActorInfo()->GetInstigatorController()) : nullptr);
}
