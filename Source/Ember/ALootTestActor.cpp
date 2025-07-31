#include "ALootTestActor.h"
#include "Kismet/GameplayStatics.h"
#include "Interface/LootableInterface.h"
#include "ALootManagerActor.h"

ALootTestActor::ALootTestActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ALootTestActor::BeginPlay()
{
	Super::BeginPlay();

	// 1초 후 메시지 전송
	GetWorld()->GetTimerManager().SetTimer(
		MessageTimerHandle,
		this,
		&ALootTestActor::SendLootMessage,
		1.0f,
		false
	);
}

void ALootTestActor::SendLootMessage()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ALootManagerActor::StaticClass(), FoundActors);

	if (FoundActors.Num() > 0)
	{
		ALootManagerActor* Manager = Cast<ALootManagerActor>(FoundActors[0]);

		FMonsterDiedMessage Msg;
		Msg.MonsterID = FName("Test");
		Msg.DeathLocation = GetActorLocation();

		UE_LOG(LogTemp, Warning, TEXT("[ALootTestActor] Sending Loot Message"));

		ILootableInterface::Execute_NotifyMonsterDied(Manager, Msg);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("[ALootTestActor] No ALootManagerActor found"));
	}

	// 드롭 후 자기 자신 제거
	Destroy();
}
