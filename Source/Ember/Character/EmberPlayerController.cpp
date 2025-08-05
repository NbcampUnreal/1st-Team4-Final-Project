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
<<<<<<< HEAD
	SetupInputMapping();
=======
	if (IsLocalController())
	{
		GetWorld()->GetTimerManager().SetTimer(TimerHandle2, this, &AEmberPlayerController::SpawnFX, 1.5f, false);
	}
>>>>>>> ba365bd79a733d9559315d4f9eb1d1f97b323e73
}

void AEmberPlayerController::SetupInputMapping()
{
	UE_LOG(LogTemp, Warning, TEXT("[Controller] SetupInputMapping() called"));

<<<<<<< HEAD
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
=======
	TObjectPtr<UEnhancedInputLocalPlayerSubsystem> subsystem = player->GetSubsystem<
		UEnhancedInputLocalPlayerSubsystem>();
	if (subsystem == nullptr)
>>>>>>> ba365bd79a733d9559315d4f9eb1d1f97b323e73
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
<<<<<<< HEAD
=======

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
>>>>>>> ba365bd79a733d9559315d4f9eb1d1f97b323e73
}