#include "AI/Animal/Deer.h"
#include "AI/BaseAIController.h"

ADeer::ADeer()
{
	AnimalType = EAnimalType::Passive;
}

void ADeer::BeginPlay()
{
	Super::BeginPlay();
	AIControllerClass = ABaseAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	
}




