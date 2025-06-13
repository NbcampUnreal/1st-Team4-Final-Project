#include "Item/Drop/LootDropManagerComponent.h"
#include "Item/Drop/LootTable.h"
#include "Engine/DataTable.h"
#include "Item/ItemTemplate.h"
#include "Item/Drop/PickupItemActor.h"
#include "GameFramework/GameStateBase.h"
#include "GameFramework/GameplayMessageSubsystem.h"
#include "Kismet/GameplayStatics.h"

ULootDropManagerComponent::ULootDropManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	MasterLootTable = nullptr;
	PickupItemActorClass = nullptr;
}

void ULootDropManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	if (GetOwner() && GetOwner()->HasAuthority())
	{
		if (MonsterDiedChannel.IsValid())
		{
			UGameplayMessageSubsystem& MessageSubsystem = UGameplayMessageSubsystem::Get(GetWorld());
			MessageListenerHandle = MessageSubsystem.RegisterListener(MonsterDiedChannel, this, &ULootDropManagerComponent::OnMonsterDiedMessageReceived);
			UE_LOG(LogTemp, Log, TEXT("LootDropManagerComponent: Listening for monster deaths on channel %s"), *MonsterDiedChannel.ToString());
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("LootDropManagerComponent: MonsterDiedChannel GameplayTag is not set in the component's defaults!"));
		}
	}
}

void ULootDropManagerComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (GetOwner() && GetOwner()->HasAuthority())
	{
		if (MessageListenerHandle.IsValid())
		{
			UGameplayMessageSubsystem& MessageSubsystem = UGameplayMessageSubsystem::Get(GetWorld());
			MessageSubsystem.UnregisterListener(MessageListenerHandle);
		}
	}
	Super::EndPlay(EndPlayReason);
}

void ULootDropManagerComponent::OnMonsterDiedMessageReceived(FGameplayTag Channel, const FMonsterDiedMessage& Message)
{
	if (!GetOwner() || !GetOwner()->HasAuthority()) return;

	UE_LOG(LogTemp, Log, TEXT("[SERVER] LootDropManager: Received FMonsterDiedMessage for MonsterID: %s"), *Message.MonsterID.ToString());

	if (!MasterLootTable)
	{
		UE_LOG(LogTemp, Error, TEXT("[SERVER] LootDropManager: MasterLootTable is not set!"));
		return;
	}

	if (!PickupItemActorClass)
	{
		UE_LOG(LogTemp, Error, TEXT("[SERVER] LootDropManager: PickupItemActorClass is not set!"));
		return;
	}

	const FMonsterLootProfile* LootProfile = MasterLootTable->FindRow<FMonsterLootProfile>(Message.MonsterID, TEXT("OnMonsterDiedMessageReceived"));
	if (!LootProfile)
	{
		UE_LOG(LogTemp, Warning, TEXT("[SERVER] LootDropManager: No loot profile found for MonsterID: %s in DT_MasterLootTable."), *Message.MonsterID.ToString());
		return;
	}

	UWorld* World = GetWorld();
	if (!World) return;

	for (const FLootDropItem& DropItem : LootProfile->LootDrops)
	{
		const float RandomRollForDrop = FMath::FRand();
		if (RandomRollForDrop < DropItem.DropChance)
		{
			if (DropItem.ItemTemplateClass && DropItem.QuantityRange.Y > 0 && DropItem.PossibleRarities.Num() > 0)
			{
				const int32 QuantityToDrop = FMath::RandRange(DropItem.QuantityRange.X, DropItem.QuantityRange.Y);

				if (QuantityToDrop > 0)
				{
					float TotalWeight = 0.f;
					for (const FRarityDropInfo& RarityInfo : DropItem.PossibleRarities)
					{
						TotalWeight += RarityInfo.Weight;
					}

					EItemRarity FinalRarity = EItemRarity::Common;
					if (TotalWeight > 0.f)
					{
						float RandomRollForRarity = FMath::FRand() * TotalWeight;
						for (const FRarityDropInfo& RarityInfo : DropItem.PossibleRarities)
						{
							if (RandomRollForRarity < RarityInfo.Weight)
							{
								FinalRarity = RarityInfo.Rarity;
								break;
							}
							RandomRollForRarity -= RarityInfo.Weight;
						}
					}
					
					const FVector SpawnLocation = Message.DeathLocation + FVector(FMath::RandRange(-50, 50), FMath::RandRange(-50, 50), 20.0f);
					const FRotator SpawnRotation = FRotator::ZeroRotator;
					
					FActorSpawnParameters SpawnParams;
					SpawnParams.Owner = GetOwner();
					SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

					APickupItemActor* NewPickup = World->SpawnActor<APickupItemActor>(PickupItemActorClass, SpawnLocation, SpawnRotation, SpawnParams);
					if (NewPickup)
					{
						NewPickup->InitializeForLootDrop(DropItem.ItemTemplateClass, QuantityToDrop, FinalRarity);
						UE_LOG(LogTemp, Log, TEXT("[SERVER] LootDropManager: Spawned pickup item '%s' (Rarity: %s) x%d at %s"), 
							*DropItem.ItemTemplateClass->GetName(), *UEnum::GetValueAsString(FinalRarity), QuantityToDrop, *SpawnLocation.ToString());
					}
				}
			}
		}
	}
}