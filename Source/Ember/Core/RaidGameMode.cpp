#include "Core/RaidGameMode.h"
#include "Core/RaidGameState.h"
#include "Character/EmberCharacter.h"
#include "Utility/CLog.h"
#include "EngineUtils.h"
#include "SNegativeActionButton.h"
#include "kismet/GameplayStatics.h"

ARaidGameMode::ARaidGameMode()
{
	IsOnFX = false;
	CurrentWeather = EWeatherType::Clear;
	WeatherTerm = 5.0f;
}

void ARaidGameMode::BeginPlay()
{
	Super::BeginPlay();
	RaidGameState = GetGameState<ARaidGameState>();
	GetWorld()->GetTimerManager().SetTimer(GameTimer, this, &ARaidGameMode::UpdateWeather, WeatherTerm, true);
}

void ARaidGameMode::UpdateWeather()
{
	if (!IsOnFX)
	{
		RaidGameState->SpawnSnowFX();
		IsOnFX = true;
	}
	switch (CurrentWeather)
	{
	case EWeatherType::Clear:
		CurrentWeather = EWeatherType::Snow;
		UE_LOG(LogTemp, Warning, TEXT("Weather: %s"), *UEnum::GetValueAsString(CurrentWeather));
		OnWeatherChanged();
		break;
	case EWeatherType::Snow:
		CurrentWeather = EWeatherType::Storm;
		UE_LOG(LogTemp, Warning, TEXT("Weather: %s"), *UEnum::GetValueAsString(CurrentWeather));
		OnWeatherChanged();
		break;
	case EWeatherType::Storm:
		CurrentWeather = EWeatherType::Storm;
		UE_LOG(LogTemp, Warning, TEXT("Weather: %s"), *UEnum::GetValueAsString(CurrentWeather));
		OnWeatherChanged();
	default: break;
	}
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
