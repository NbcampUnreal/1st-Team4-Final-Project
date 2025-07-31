#include "RaidGameState.h"
#include "Character/EmberCharacter.h"
#include "kismet/GameplayStatics.h"


void ARaidGameState::SpawnSnowFX_Implementation()
{
	if (!SnowFXClass) return;
	// if (IsNetMode(NM_Client))
	// {
	// 	UE_LOG(LogTemp, Error, TEXT("Client: SpawnSnowFX triggered"));
	// }
	// else if (HasAuthority())
	// {
	// 	UE_LOG(LogTemp, Error, TEXT("Server: SpawnSnowFX triggered"));
	// }

	// 월드 내 모든 EmberCharacter 찾기
	TArray<AActor*> FoundCharacters;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEmberCharacter::StaticClass(), FoundCharacters);

	for (AActor* Actor : FoundCharacters)
	{
		AEmberCharacter* EmberChar = Cast<AEmberCharacter>(Actor);
		if (!EmberChar) continue;

		FVector SpawnLocation = EmberChar->GetActorLocation();
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		AActor* SnowFXActor = GetWorld()->SpawnActor<AActor>(
			SnowFXClass, SpawnLocation, FRotator::ZeroRotator, SpawnParams);

		if (!SnowFXActor) continue;

		// EmberCharacter에 FX 어태치
		SnowFXActor->AttachToActor(EmberChar, FAttachmentTransformRules::KeepRelativeTransform);
		SnowFXActor->GetRootComponent()->SetRelativeLocation(FVector(0, 0, 200));
	}
}
