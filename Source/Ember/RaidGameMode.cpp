// Fill out your copyright notice in the Description page of Project Settings.


#include "RaidGameMode.h"
#include "Character/EmberCharacter.h"
#include "EngineUtils.h"
#include "RaidGameState.h"
#include "Utility/CLog.h"

ARaidGameMode::ARaidGameMode()
{
	CurrentWeather = EWeatherType::Clear;
	WeatherTerm = 300.0f;
}

void ARaidGameMode::BeginPlay()
{
	Super::BeginPlay();
	RaidGameState = GetGameState<ARaidGameState>();
	GetWorld()->GetTimerManager().SetTimer(GameTimer, this, &ARaidGameMode::UpdateWeather, WeatherTerm);
}

void ARaidGameMode::UpdateWeather()
{
	switch (RaidGameState->CurrentWeather)
	{
	case EWeatherType::Clear:
		RaidGameState->CurrentWeather = EWeatherType::Snow;
		break;
	case EWeatherType::Snow:
		RaidGameState->CurrentWeather = EWeatherType::Storm;
		break;
	case EWeatherType::Storm:
		RaidGameState->CurrentWeather = EWeatherType::Clear;
	default: break;
	}
}

void ARaidGameMode::AddNiagara()
{
}

void ARaidGameMode::PlayerDamage()
{
	// 월드에서 모든 EmberCharacter 찾기
	for (TActorIterator<AEmberCharacter> It(GetWorld()); It; ++It)
	{
		AEmberCharacter* Player = *It;
		if (!Player) continue;
	}
}
