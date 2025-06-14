#include "Item/Drop/PickupItemActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"
#include "Item/ItemTemplate.h"
#include "Item/ItemInstance.h"
#include "Player/EmberPlayerCharacter.h"
#include "Item/Managers/InventoryManagerComponent.h"
#include "UI/Data/EmberItemData.h"
#include "UI/Item/InteractionPromptWidget.h"

APickupItemActor::APickupItemActor()
{
    bReplicates = true;
    SetReplicateMovement(true);

    InteractionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionSphere"));
    InteractionSphere->SetupAttachment(GetRootComponent());
    InteractionSphere->SetSphereRadius(200.0f);
    InteractionSphere->SetCollisionProfileName(TEXT("Trigger"));
}

void APickupItemActor::BeginPlay()
{
    Super::BeginPlay();

    if (InteractionSphere)
    {
        InteractionSphere->OnComponentBeginOverlap.AddDynamic(this, &APickupItemActor::OnInteractionSphereOverlapBegin);
        InteractionSphere->OnComponentEndOverlap.AddDynamic(this, &APickupItemActor::OnInteractionSphereOverlapEnd);
    }
}

void APickupItemActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME_CONDITION(APickupItemActor, LootContents, COND_None);
}

void APickupItemActor::InitializeLootPouch(const TArray<FLootResultData>& InLootData)
{
    if (HasAuthority())
    {
        LootContents = InLootData;
        if(LootContents.IsEmpty())
        {
            Destroy();
        }
        else
        {
            OnRep_LootContents();
        }
    }
}

void APickupItemActor::OnRep_LootContents()
{
    if (LootContents.IsEmpty())
    {
        if (InteractionPromptWidget)
        {
            InteractionPromptWidget->RemoveFromParent();
            InteractionPromptWidget = nullptr;
        }
        
        SetActorHiddenInGame(true);
        SetActorEnableCollision(false);
        if (HasAuthority())
        {
            Destroy();
        }
    }
}

void APickupItemActor::OnInteractionSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void APickupItemActor::OnInteractionSphereOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void APickupItemActor::Server_RequestLootAll_Implementation(AEmberPlayerCharacter* RequestingPlayer)
{
    if (!HasAuthority() || !RequestingPlayer || LootContents.IsEmpty()) return;

    UInventoryManagerComponent* PlayerInventory = RequestingPlayer->FindComponentByClass<UInventoryManagerComponent>();
    if (!PlayerInventory) return;

    TArray<FLootResultData> RemainingLoot;
    for (const FLootResultData& LootItem : LootContents)
    {
        if (LootItem.ItemTemplateClass && LootItem.Quantity > 0)
        {
            const int32 AddedAmount = PlayerInventory->TryAddItemByRarity(LootItem.ItemTemplateClass, LootItem.Rarity, LootItem.Quantity);
            if (AddedAmount < LootItem.Quantity)
            {
                FLootResultData Remainder = LootItem;
                Remainder.Quantity -= AddedAmount;
                if (Remainder.Quantity > 0)
                {
                    RemainingLoot.Add(Remainder);
                }
            }
        }
    }
    
    LootContents = RemainingLoot;
    OnRep_LootContents();
}