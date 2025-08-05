// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Base.h"

#include "AIController.h"
#include "AI/Monster/MonsterAIBase.h"

UBTTask_Base::UBTTask_Base(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bCreateNodeInstance = true;
}

void UBTTask_Base::SetOwner(AActor* InActorOwner)
{
	AIOwner = Cast<AAIController>(InActorOwner);
	ActorOwner = Cast<AMonsterAIBase>(AIOwner->GetPawn());
}
