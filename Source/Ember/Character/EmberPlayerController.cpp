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
	SetupInputMapping();
}

void AEmberPlayerController::SetupInputMapping()
{
	UE_LOG(LogTemp, Warning, TEXT("[Controller] SetupInputMapping() called"));

	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (DefaultMappingContext)
			{
				Subsystem->AddMappingContext(DefaultMappingContext, 0);
				UE_LOG(LogTemp, Warning, TEXT("[Controller] MappingContext added"));
			}
		}
	}
}