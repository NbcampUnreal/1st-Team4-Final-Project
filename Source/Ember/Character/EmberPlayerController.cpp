#include "EmberPlayerController.h"

#include "EmberCharacter.h"
#include "Utility/CLog.h"
#include "EnhancedInputSubsystems.h"
#include "kismet/GameplayStatics.h"
#include "InputMappingContext.h"

void AEmberPlayerController::BeginPlay()
{
	Super::BeginPlay();
	// LocalPlayer�� Pawn�� ��ȿ�� �������� ��ٸ�
	FTimerHandle TimerHandle;
	FTimerHandle TimerHandle2;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AEmberPlayerController::SetupInputMapping, 0.1f, false);
	if (IsLocalController())
	{
		GetWorld()->GetTimerManager().SetTimer(TimerHandle2, this, &AEmberPlayerController::SpawnFX, 1.5f, false);
	}
}

void AEmberPlayerController::SetupInputMapping()
{
	TObjectPtr<ULocalPlayer> player = GetLocalPlayer();
	if (player == nullptr)
	{
		DebugLogE("Local player is null");
		return;
	}

	TObjectPtr<UEnhancedInputLocalPlayerSubsystem> subsystem = player->GetSubsystem<
		UEnhancedInputLocalPlayerSubsystem>();
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

void AEmberPlayerController::SpawnFX()
{
	if (!SnowFXClass) return;

	AEmberCharacter* EmCharacter = Cast<AEmberCharacter>(GetPawn());
	FVector EmSpawnLocation = EmCharacter->GetActorLocation();
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	SnowFXActor = GetWorld()->SpawnActor<AActor>(
		SnowFXClass, EmSpawnLocation, FRotator::ZeroRotator, SpawnParams);

	SnowFXActor->AttachToActor(EmCharacter, FAttachmentTransformRules::KeepRelativeTransform);
	SnowFXActor->GetRootComponent()->SetRelativeLocation(FVector(0, 0, 200));
}