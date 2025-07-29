#include "TestMonsterActor.h"
#include "Kismet/GameplayStatics.h"
#include "Interface/LootableInterface.h"

ATestMonsterActor::ATestMonsterActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATestMonsterActor::BeginPlay()
{
	Super::BeginPlay();


}

void ATestMonsterActor::SimulateDeath()
{
	// 1. 메시지 구성
	FMonsterDiedMessage Message;
	Message.MonsterID = FName("Test");           // MasterLootTable에 "TestMonster" RowName 필요
	Message.DeathLocation = GetActorLocation();

	// 2. 월드에서 LootableInterface 구현체 탐색
	TArray<AActor*> FoundLootables;
	UGameplayStatics::GetAllActorsWithInterface(GetWorld(), ULootableInterface::StaticClass(), FoundLootables);

	for (AActor* LootableActor : FoundLootables)
	{
		if (LootableActor && LootableActor->GetClass()->ImplementsInterface(ULootableInterface::StaticClass()))
		{
			ILootableInterface::Execute_NotifyMonsterDied(LootableActor, Message);
			UE_LOG(LogTemp, Log, TEXT("[Test] Sent MonsterDiedMessage to %s"), *LootableActor->GetName());
		}
	}
}
