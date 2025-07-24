// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterAIController.h"

#include "Runtime/AIModule/Classes/Perception/AIPerceptionComponent.h"
#include "Runtime/AIModule/Classes/Perception/AISenseConfig_Sight.h"
#include "Utility/CHelpers.h"
#include "Utility/CLog.h"

AMonsterAIController::AMonsterAIController()
{
	bWantsPlayerState = true;
	PrimaryActorTick.bCanEverTick = false;

	CHelpers::CreateActorComponent(this, &AISenseConfigSight, TEXT("AISenseConfigSight"));
	AISenseConfigSight->SightRadius = DetectionRadius;
	AISenseConfigSight->LoseSightRadius = LoseInterestRadius;
	AISenseConfigSight->PeripheralVisionAngleDegrees = SightAngleDegree;
	
	CHelpers::CreateActorComponent(this, &AIPerceptionComponent, TEXT("AIPerceptionComponent"));
	AIPerceptionComponent->ConfigureSense(*AISenseConfigSight);
	AIPerceptionComponent->SetDominantSense(UAISense_Sight::StaticClass());
	AIPerceptionComponent->OnTargetPerceptionUpdated.AddUniqueDynamic(this, &ThisClass::OnTargetPerceptionUpdated);
}

void AMonsterAIController::BeginPlay()
{
	Super::BeginPlay();
}

FGenericTeamId AMonsterAIController::GetGenericTeamId() const
{
	return FGenericTeamId((uint8)EGameTeamID::Monster);
}

void AMonsterAIController::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	CLog::DebugLogD("");
}

