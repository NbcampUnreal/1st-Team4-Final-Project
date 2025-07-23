#include "RaidGameMode.h"
#include "Character/EmberCharacter.h"
#include "EngineUtils.h"
#include "RaidGameState.h"
#include "kismet/GameplayStatics.h"

ARaidGameMode::ARaidGameMode()
{
	CurrentWeather = EWeatherType::Clear;
	WeatherTerm = 5.0f;
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

void ARaidGameMode::SpawnSnowFX()
{
	if (!SnowFXClass) return;

	ACharacter* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (!Player) return;

	FVector SpawnLocation = Player->GetActorLocation();
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AActor* SnowFXActor = GetWorld()->SpawnActor<AActor>(SnowFXClass, SpawnLocation, FRotator::ZeroRotator, SpawnParams);

	// 플레이어에 붙이기 (FX가 따라다니게)
	SnowFXActor->AttachToActor(Player, FAttachmentTransformRules::KeepRelativeTransform);
}
