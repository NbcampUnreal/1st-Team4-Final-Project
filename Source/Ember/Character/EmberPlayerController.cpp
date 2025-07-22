#include "EmberPlayerController.h"
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
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		if (DefaultMappingContext)
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
			UE_LOG(LogTemp, Warning, TEXT("MappingContext 적용됨"));
		}
	}
}
