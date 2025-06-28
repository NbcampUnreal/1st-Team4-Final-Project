#include "Interaction/RespawnSubsystem.h"

void URespawnSubsystem::SetNewRespawnTransform(const FTransform& NewTransform)
{
	CurrentRespawnTransform = NewTransform;
	bHasCustomRespawnLocation = true;
	UE_LOG(LogTemp, Log, TEXT("New respawn point set to: %s"), *NewTransform.GetLocation().ToString());
}

FTransform URespawnSubsystem::GetRespawnTransform() const
{
	if (bHasCustomRespawnLocation)
	{
		return CurrentRespawnTransform;
	}

	return FTransform::Identity;
}