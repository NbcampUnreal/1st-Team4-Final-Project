#include "C_CharacterStateComponent.h"

UC_CharacterStateComponent::UC_CharacterStateComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UC_CharacterStateComponent::BeginPlay()
{
	Super::BeginPlay();
}
