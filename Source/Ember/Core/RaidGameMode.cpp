#include "Core/RaidGameMode.h"
#include "Core/RaidGameState.h"
#include "Character/EmberCharacter.h"
#include "Character/EmberPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Utility/CLog.h"
#include "EngineUtils.h"


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
		OrderSpawnSnowFX();
		// RaidGameState->SpawnSnowFX();
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
		CurrentWeather = EWeatherType::Clear;
		UE_LOG(LogTemp, Warning, TEXT("Weather: %s"), *UEnum::GetValueAsString(CurrentWeather));
		OnWeatherChanged();
		break;
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

void ARaidGameMode::OrderSpawnSnowFX()
{
	for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
	{
		AEmberPlayerController* Controller = Cast<AEmberPlayerController>(*It);
		if (Controller)
		{
			Controller->SpawnSnowFX(); // 클라이언트에서 자기 FX 생성
		}
	}
}
