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

public:

	UFUNCTION(BlueprintImplementableEvent, Category = "Weather")
	void OnWeatherChanged();
	
	void UpdateWeather();
	
	void PlayerDamage();

	UPROPERTY(EditAnywhere,BlueprintReadWrite ,Category = "FX")
	EWeatherType CurrentWeather;
private:
	
	
	UPROPERTY(EditAnywhere)
	float WeatherTerm;

	float GameTime; //게임내시간
	
	float Temperature; //서버 온도

	bool IsOnFX;
	ARaidGameState* RaidGameState;
	
	
	
	FTimerHandle GameTimer;
};
