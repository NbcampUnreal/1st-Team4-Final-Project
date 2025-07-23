// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterAIBase.h"

#include "MonsterAIController.h"

AMonsterAIBase::AMonsterAIBase()
{
	SetReplicates(true);
	PrimaryActorTick.bCanEverTick = false;

	AIControllerClass = AMonsterAIController::StaticClass();
}

void AMonsterAIBase::BeginPlay()
{
	Super::BeginPlay();
}

