#include "Item/Drop/PickupItemActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Net/UnrealNetwork.h"
#include "Item/ItemTemplate.h"
#include "Item/ItemInstance.h"
#include "Player/EmberPlayerCharacter.h"
#include "Item/Managers/InventoryManagerComponent.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"
#include "UI/Data/EmberItemData.h"

APickupItemActor::APickupItemActor()
{
}

void APickupItemActor::BeginPlay()
{
    Super::BeginPlay();
}

void APickupItemActor::InitializeForLootDrop(TSubclassOf<UItemTemplate> InItemTemplateClass, int32 InQuantity, EItemRarity InRarity)
{
    if (!HasAuthority()) return;
    if (!InItemTemplateClass || InQuantity <= 0)
    {
        Destroy();
        return;
    }

    int32 ItemID = UEmberItemData::Get().FindItemTemplateIDByClass(InItemTemplateClass);
    if (ItemID == INDEX_NONE)
    {
        UE_LOG(LogTemp, Error, TEXT("APickupItemActor::InitializeForLootDrop - Could not find ItemTemplateID for class %s."), *InItemTemplateClass->GetName());
        Destroy();
        return;
    }

    UItemInstance* NewItemInstance = NewObject<UItemInstance>(this);
    if(NewItemInstance)
    {
        NewItemInstance->Init(ItemID, InRarity);
        
        FPickupInfo NewPickupInfo;
        NewPickupInfo.ItemInstance = NewItemInstance;
        
        SetPickupInfo(NewPickupInfo);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("APickupItemActor::InitializeForLootDrop - Failed to create NewItemInstance."));
        Destroy();
    }
}