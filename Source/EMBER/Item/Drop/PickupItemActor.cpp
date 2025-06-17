#include "Item/Drop/PickupItemActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"
#include "Item/ItemTemplate.h"
#include "Item/ItemInstance.h"
#include "Player/EmberPlayerCharacter.h"
#include "Interaction/EmberInteractionQuery.h"
#include "Interaction/EmberInteractionInfo.h"
#include "Interaction/Abilities/EmberGameplayAbility_Interact_Pickup.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"
#include "System/AbilitySystem/EmberAbilitySystemComponent.h"
#include "GameplayEffect.h"
#include "GameInfo/GameplayTags.h"
#include "Item/Managers/InventoryManagerComponent.h"
#include "UI/Data/EmberItemData.h"

APickupItemActor::APickupItemActor()
{
    bReplicates = true;
    SetReplicateMovement(true);

    PrimaryActorTick.bCanEverTick = false;

    InteractionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionSphere"));
    InteractionSphere->SetupAttachment(GetRootComponent());
    InteractionSphere->SetSphereRadius(200.0f);
    InteractionSphere->SetCollisionProfileName(TEXT("Trigger"));

    AbilitySystemComponent = CreateDefaultSubobject<UEmberAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
    AbilitySystemComponent->SetIsReplicated(true);
    AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

void APickupItemActor::BeginPlay()
{
    Super::BeginPlay();

    if (AbilitySystemComponent)
    {
       AbilitySystemComponent->InitAbilityActorInfo(this, this);

       if (InteractAbilityClass)
       {
          FGameplayAbilitySpec AbilitySpec(InteractAbilityClass, 1);
          InteractAbilityHandle = AbilitySystemComponent->GiveAbility(AbilitySpec);
       }
    }
    
    InteractionSphere->OnComponentBeginOverlap.AddDynamic(this, &APickupItemActor::OnInteractionSphereOverlapBegin);
    InteractionSphere->OnComponentEndOverlap.AddDynamic(this, &APickupItemActor::OnInteractionSphereOverlapEnd);
}

void APickupItemActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (InteractionPromptWidget)
    {
       InteractionPromptWidget->RemoveFromParent();
       InteractionPromptWidget = nullptr;
    }
    
    Super::EndPlay(EndPlayReason);
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
    if (LootContents.Num() > 0)
    {
       if (AbilitySystemComponent)
       {
          AbilitySystemComponent->AddLooseGameplayTag(EmberGameplayTags::Ability_Interact_Object);
       }
    }
    else
    {
       Destroy();
    }
}

FEmberInteractionInfo APickupItemActor::GetPreInteractionInfo(const FEmberInteractionQuery& InteractionQuery) const
{
    FEmberInteractionInfo Info = Super::GetPreInteractionInfo(InteractionQuery);
    
    Info.bVisible = true;
    Info.AbilityToGrant = UEmberGameplayAbility_Interact_Pickup::StaticClass();
    
    return Info;
}

UAbilitySystemComponent* APickupItemActor::GetAbilitySystemComponent() const
{
    return AbilitySystemComponent;
}

void APickupItemActor::OnItemAcquired(AActor* InteractingActor)
{
    if (!InteractingActor || !HasAuthority())
    {
       return;
    }

    AEmberPlayerCharacter* PlayerCharacter = Cast<AEmberPlayerCharacter>(InteractingActor);
    if (!PlayerCharacter) return;

    UInventoryManagerComponent* InventoryManager = PlayerCharacter->FindComponentByClass<UInventoryManagerComponent>();
    if (!InventoryManager) return;
    
    TArray<FLootResultData> FailedItems;

    for (const FLootResultData& LootData : LootContents)
    {
       if (LootData.ItemTemplateClass)
       {
          int32 AddedCount = InventoryManager->TryAddItemByRarity(LootData.ItemTemplateClass, LootData.Rarity, LootData.Quantity);
          if (AddedCount < LootData.Quantity)
          {
             FLootResultData Remainder = LootData;
             Remainder.Quantity -= AddedCount;
             if(Remainder.Quantity > 0) FailedItems.Add(Remainder);
          }
       }
    }

    if (FailedItems.IsEmpty())
    {
       ApplyItemAcquisitionEffect(InteractingActor);
       Destroy();
    }
    else
    {
       UE_LOG(LogTemp, Warning, TEXT("Could not acquire all items. Inventory may be full."));
       LootContents = FailedItems;
    }
}


void APickupItemActor::ApplyItemAcquisitionEffect(AActor* TargetActor)
{
    if (!TargetActor || !AbilitySystemComponent || !ItemAcquisitionEffect) return;

    if (UAbilitySystemComponent* TargetASC = TargetActor->FindComponentByClass<UAbilitySystemComponent>())
    {
       FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
       EffectContext.AddSourceObject(this);

       FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(ItemAcquisitionEffect, 1, EffectContext);
       if (SpecHandle.IsValid())
       {
          AbilitySystemComponent->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), TargetASC);
       }
    }
}


void APickupItemActor::OnInteractionSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (!OtherActor || !OtherActor->IsA<APawn>()) return;

    if (AbilitySystemComponent)
    {
       AbilitySystemComponent->AddLooseGameplayTag(EmberGameplayTags::Ability_Interact_Active);
    }
}

void APickupItemActor::OnInteractionSphereOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (!OtherActor || !OtherActor->IsA<APawn>()) return;

    if (AbilitySystemComponent)
    {
       AbilitySystemComponent->RemoveLooseGameplayTag(EmberGameplayTags::Ability_Interact_Active);
    }
}