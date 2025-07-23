// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "RaidGameMode.generated.h"

enum class WeatherType
{
	Clear UMETA(DisplayName = "CLEAR"),
	Snow UMETA(DisplayName = "SNOW"),
	Storm UMETA(DisplayName = "STORM"),
};

UCLASS()
class EMBER_API ARaidGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ARaidGameMode();
	virtual void BeginPlay() override;

protected:
	void PlayerDamage();
	

protected:
	float GameTime;
	float Temperature;
	
	WeatherType CurrentWeather;
	FTimerHandle GameTimer;
};
