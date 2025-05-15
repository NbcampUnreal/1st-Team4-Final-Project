#include "AI/DefensiveAI.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"

ADefensiveAI::ADefensiveAI()
{
	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("RunPerception"));
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("RunSightConfig"));
}

void ADefensiveAI::BeginPlay()
{
	Super::BeginPlay();
}

void ADefensiveAI::OnTargetPerceptionUpdated(AActor* UpdatedActor, FAIStimulus Stimulus)
{
	Super::OnTargetPerceptionUpdated(UpdatedActor, Stimulus);
}


