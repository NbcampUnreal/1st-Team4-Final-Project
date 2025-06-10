#include "PickupItemActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Net/UnrealNetwork.h"
#include "Item/ItemTemplate.h"
#include "Player/EmberPlayerCharacter.h"
#include "Item/Managers/InventoryManagerComponent.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"

APickupItemActor::APickupItemActor()
{
    PrimaryActorTick.bCanEverTick = false;
    bReplicates = true;
    SetReplicateMovement(true);

    DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
    RootComponent = DefaultSceneRoot;

    ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
    ItemMesh->SetupAttachment(RootComponent);
    ItemMesh->SetCollisionProfileName(TEXT("NoCollision"));

    InteractionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionSphere"));
    InteractionSphere->SetupAttachment(RootComponent);
    InteractionSphere->SetSphereRadius(150.0f);
    InteractionSphere->SetCollisionProfileName(TEXT("Trigger"));
    InteractionSphere->SetGenerateOverlapEvents(true);

    Quantity = 1;
    Rarity = EItemRarity::Common;
    ItemTemplateClass = nullptr;
    InteractionPromptWidget = nullptr;
    InteractionPromptWidgetClass = nullptr;
}

void APickupItemActor::BeginPlay()
{
    Super::BeginPlay();
    
    if (InteractionSphere)
    {
        InteractionSphere->OnComponentBeginOverlap.AddDynamic(this, &APickupItemActor::OnInteractionSphereOverlapBegin);
        InteractionSphere->OnComponentEndOverlap.AddDynamic(this, &APickupItemActor::OnInteractionRangeOverlapEnd);
    }
    
    UpdateItemVisuals();
}

void APickupItemActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(APickupItemActor, ItemTemplateClass);
    DOREPLIFETIME(APickupItemActor, Quantity);
    DOREPLIFETIME(APickupItemActor, Rarity);
}

void APickupItemActor::InitializePickup(TSubclassOf<UItemTemplate> InItemTemplateClass, int32 InQuantity, EItemRarity InRarity)
{
    if (HasAuthority())
    {
        ItemTemplateClass = InItemTemplateClass;
        Quantity = InQuantity;
        Rarity = InRarity;
        
        OnRep_ItemDataUpdated();
    }
}

void APickupItemActor::OnRep_ItemDataUpdated()
{
    UpdateItemVisuals();
}

void APickupItemActor::UpdateItemVisuals()
{
    if (ItemTemplateClass)
    {
        const UItemTemplate* Template = ItemTemplateClass->GetDefaultObject<UItemTemplate>();
        if (Template && ItemMesh)
        {
            UE_LOG(LogTemp, Log, TEXT("APickupItemActor: Visuals updated for %s"), *Template->DisplayName.ToString());
        }
    }
}

void APickupItemActor::OnInteractionSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    AEmberPlayerCharacter* PlayerCharacter = Cast<AEmberPlayerCharacter>(OtherActor);
    if (PlayerCharacter && PlayerCharacter->IsLocallyControlled())
    {
        if (InteractionPromptWidgetClass && !InteractionPromptWidget)
        {
            APlayerController* PC = PlayerCharacter->GetController<APlayerController>();
            if (PC)
            {
                InteractionPromptWidget = CreateWidget<UUserWidget>(PC, InteractionPromptWidgetClass);
                InteractionPromptWidget->AddToViewport();
            }
        }
    }
}

void APickupItemActor::OnInteractionRangeOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    AEmberPlayerCharacter* PlayerCharacter = Cast<AEmberPlayerCharacter>(OtherActor);
    if (PlayerCharacter && PlayerCharacter->IsLocallyControlled())
    {
        if (InteractionPromptWidget)
        {
            InteractionPromptWidget->RemoveFromParent();
            InteractionPromptWidget = nullptr;
        }
    }
}

void APickupItemActor::Server_RequestPickup_Implementation(AEmberPlayerCharacter* RequestingPlayer)
{
    if (!HasAuthority() || !RequestingPlayer || Quantity <= 0 || !ItemTemplateClass) return;

    UInventoryManagerComponent* PlayerInventory = RequestingPlayer->FindComponentByClass<UInventoryManagerComponent>();
    if (PlayerInventory)
    {
        const int32 AddedAmount = PlayerInventory->TryAddItemByRarity(ItemTemplateClass, Rarity, Quantity);
        
        if (AddedAmount >= Quantity)
        {
            UE_LOG(LogTemp, Log, TEXT("APickupItemActor: Player %s picked up all items. Destroying actor."), *RequestingPlayer->GetName());
            Destroy();
        }
        else if (AddedAmount > 0)
        {
            Quantity -= AddedAmount;
            UE_LOG(LogTemp, Log, TEXT("APickupItemActor: Player %s picked up partial items. Remaining quantity: %d"), *RequestingPlayer->GetName(), Quantity);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("APickupItemActor: Player %s inventory is full. Could not pick up item."), *RequestingPlayer->GetName());
        }
    }
}