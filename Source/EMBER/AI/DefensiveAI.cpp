#include "AI/DefensiveAI.h"
#include "Perception/AIPerceptionComponent.h"

ADefensiveAI::ADefensiveAI()
{
	AnimalType = EAnimalType::Defensive;
}

void ADefensiveAI::BeginPlay()
{
	Super::BeginPlay();
}

float ADefensiveAI::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	if (ActualDamage > 0 && !bIsDie)
	{
		SetRunSpeed();
	}

	return ActualDamage;
}

void ADefensiveAI::OnTargetPerceptionUpdated(AActor* UpdatedActor, FAIStimulus Stimulus)
{
}


