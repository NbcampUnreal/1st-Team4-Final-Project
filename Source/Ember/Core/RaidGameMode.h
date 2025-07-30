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
	void OnWeatherChanged(); //날씨변경됨에 따른 비쥬얼 변경
	
	void UpdateWeather(); //날씨가 변경됨에 따른 전체적 설정
	
	void PlayerDamage(); //미구현

	void OrderSpawnSnowFX(); //최초한번만 vfx를 스폰
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite ,Category = "FX")
	EWeatherType CurrentWeather;
private:
	
	
	UPROPERTY(EditAnywhere)
	float WeatherTerm;

	float GameTime; //게임내시간
	
	float Temperature; //서버 온도

	bool IsOnFX;
	TObjectPtr<ARaidGameState> RaidGameState;
	
	
	
	FTimerHandle GameTimer;
};
