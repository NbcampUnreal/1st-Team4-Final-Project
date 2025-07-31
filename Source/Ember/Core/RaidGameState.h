// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "Utility/GameFlag.h"
#include "RaidGameState.generated.h"


UCLASS()
class EMBER_API ARaidGameState : public AGameState
{
	GENERATED_BODY()
	public:
	
	UFUNCTION(NetMulticast, reliable)
	void SpawnSnowFX();

	UPROPERTY(EditDefaultsOnly, Category = "FX")
	TSubclassOf<AActor> SnowFXClass;

	// UFUNCTION(BlueprintImplementableEvent, Category = "Weather")
	// void OnWeatherChanged();
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite ,Category = "FX")
	EWeatherType CurrentWeather;
	EWorldTimeState CurrentTimeOfDay;
};