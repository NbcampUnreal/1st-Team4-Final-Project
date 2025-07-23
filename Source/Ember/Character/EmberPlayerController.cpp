#include "EmberPlayerController.h"
#include "Utility/CLog.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"

void AEmberPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// LocalPlayer와 Pawn이 유효한 시점까지 기다림
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AEmberPlayerController::SetupInputMapping, 0.1f, false);
}

void AEmberPlayerController::SetupInputMapping()
{
	TObjectPtr<ULocalPlayer> player = GetLocalPlayer();
	if (player == nullptr)
	{
		DebugLogE("Local player is null");
		return;
	}

	TObjectPtr<UEnhancedInputLocalPlayerSubsystem> subsystem = player->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	if (subsystem == nullptr)
	{
		DebugLogE("subsystem is null");
		return;
	}

	if (DefaultMappingContext == nullptr)
	{
		DebugLogE("Input Mapping Context is null");
		return;
	}

	subsystem->AddMappingContext(DefaultMappingContext, 0);
}
