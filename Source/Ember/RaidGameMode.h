// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Utility/GameFlag.h"
#include "RaidGameMode.generated.h"

class ARaidGameState;
UCLASS()
class EMBER_API ARaidGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ARaidGameMode();
	virtual void BeginPlay() override;

protected:
	void UpdateWeather();
	void AddNiagara();
	void PlayerDamage();
	void SpawnSnowFX();
private:
	UPROPERTY(EditAnywhere)
	float WeatherTerm;
	UPROPERTY(EditDefaultsOnly, Category = "Weather")
	TSubclassOf<AActor> SnowFXClass;

	float GameTime; //게임내시간
	float Temperature; //서버 온도

	ARaidGameState* RaidGameState;
	EWeatherType CurrentWeather; //서버 날씨상태
	FTimerHandle GameTimer;
};
