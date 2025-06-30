// Fill out your copyright notice in the Description page of Project Settings.


#include "System/GameMode/C_EmberGameMode.h"
#include "../Interaction/RespawnSubsystem.h"

void AC_EmberGameMode::RestartPlayer(AController* NewPlayer)
{
	if (!NewPlayer || !DefaultPawnClass) return;

	URespawnSubsystem* RespawnSS = GetGameInstance()->GetSubsystem<URespawnSubsystem>();
	FTransform SpawnTransform = RespawnSS
		? RespawnSS->GetRespawnTransform()
		: FTransform::Identity;

	if (APawn* OldPawn = NewPlayer->GetPawn())
	{
		OldPawn->DetachFromControllerPendingDestroy();
		OldPawn->Destroy();
	}

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.Instigator = GetInstigator();
	SpawnParams.SpawnCollisionHandlingOverride =
		ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	APawn* NewPawn = GetWorld()->SpawnActor<APawn>(
		DefaultPawnClass,
		SpawnTransform.GetLocation(),
		SpawnTransform.GetRotation().Rotator(),
		SpawnParams);

	if (NewPawn)
	{
		NewPlayer->Possess(NewPawn);
	}
}