#include "Component/LootDropManagerComponent.h"
#include "Item/Drop/PickupItemActor.h"
#include "Item/LootResultData.h"
#include "DataTable/LootTable.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/DataTable.h"

ULootDropManagerComponent::ULootDropManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void ULootDropManagerComponent::BeginPlay()
{
	Super::BeginPlay();
}

void ULootDropManagerComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void ULootDropManagerComponent::HandleMonsterDied(const FMonsterDiedMessage& Message)
{
	UE_LOG(LogTemp, Warning, TEXT("HandleMonsterDied() called for ID: %s"), *Message.MonsterID.ToString());
	if (!GetOwner() || !GetOwner()->HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("No Authority"));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("[LootDropManager] NotifyMonsterDied Called. Monster ID: %s"), *Message.MonsterID.ToString());

	if (!MasterLootTable || !PickupItemActorClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("LootDropManager: Missing MasterLootTable or PickupItemActorClass."));
		return;
	}

	const FMonsterLootProfile* LootProfile = MasterLootTable->FindRow<FMonsterLootProfile>(
		Message.MonsterID, TEXT("NotifyMonsterDied"));

	if (!LootProfile)
	{
		UE_LOG(LogTemp, Warning, TEXT("LootDropManager: No loot profile found for MonsterID %s"), *Message.MonsterID.ToString());
		return;
	}

	TArray<FLootResultData> FinalLoots;

	for (const FLootDropItem& Drop : LootProfile->LootDrops)
	{
		if (FMath::FRand() < Drop.DropChance)
		{
			if (!Drop.ItemTemplateClass || Drop.QuantityRange.Y <= 0 || Drop.PossibleRarities.Num() == 0)
				continue;

			int32 Quantity = FMath::RandRange(Drop.QuantityRange.X, Drop.QuantityRange.Y);

			EItemRarity FinalRarity = EItemRarity::Common;
			float TotalWeight = 0.f;

			for (const FRarityDropInfo& RarityInfo : Drop.PossibleRarities)
			{
				TotalWeight += RarityInfo.Weight;
			}

			float RarityRoll = FMath::FRand() * TotalWeight;

			for (const FRarityDropInfo& RarityInfo : Drop.PossibleRarities)
			{
				if (RarityRoll < RarityInfo.Weight)
				{
					FinalRarity = RarityInfo.Rarity;
					break;
				}
				RarityRoll -= RarityInfo.Weight;
			}

			FLootResultData Result;
			Result.ItemTemplateClass = Drop.ItemTemplateClass;
			Result.Quantity = Quantity;
			Result.Rarity = FinalRarity;

			FinalLoots.Add(Result);
		}
	}

	if (FinalLoots.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("LootDropManager: No items dropped for %s"), *Message.MonsterID.ToString());
		return;
	}
	else
	{
		for (const FLootResultData& Loot : FinalLoots)
		{
			FVector RandomOffset = FVector(
				FMath::RandRange(-30.f, 30.f),
				FMath::RandRange(-30.f, 30.f),
				50.f
			);

			FTransform SpawnTransform(Message.DeathLocation + RandomOffset);

			APickupItemActor* LootActor = GetWorld()->SpawnActorDeferred<APickupItemActor>(
				PickupItemActorClass,
				SpawnTransform,
				nullptr,
				nullptr,
				ESpawnActorCollisionHandlingMethod::AlwaysSpawn
			);

			if (LootActor)
			{
				LootActor->InitializeLootDrop(Loot);  // 여기서 메시/이펙트 등 설정
				LootActor->FinishSpawning(SpawnTransform);

				UE_LOG(LogTemp, Log, TEXT("[LootDropManager] Dropped item: %s x%d (Rarity: %d)"),
					*Loot.ItemTemplateClass->GetName(),
					Loot.Quantity,
					(int32)Loot.Rarity);
			}
		}
	}


}
