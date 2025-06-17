#include "Item/Drop/PickupItemActor.h"
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/PlayerController.h"
#include "ItemInstance.h"
#include "ItemTemplate.h"
#include "Fragments/ItemFragment_Equipable.h"
#include "UI/Data/EmberItemData.h"

APickupItemActor::APickupItemActor()
{
 
}

void APickupItemActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME_CONDITION(APickupItemActor, LootContent, COND_None);
}

void APickupItemActor::InitializeLootPouch(const FLootResultData& InLootData)
{
    if (HasAuthority())
    {
       LootContent = InLootData;

    	if (IsNetMode(NM_ListenServer))
    		OnRep_LootContents();
    }
}

void APickupItemActor::OnRep_LootContents()
{
	UItemInstance* ItemInstance = NewObject<UItemInstance>();
	ItemInstance->Init(LootContent.ItemTemplateClass, LootContent.Rarity, LootContent.Quantity);
	PickupInfo.ItemInstance = ItemInstance;

	int32 ItemID = UEmberItemData::Get().FindItemTemplateIDByClass(LootContent.ItemTemplateClass);
	const UItemTemplate& ItemTemplate = UEmberItemData::Get().FindItemTemplateByID(ItemID);
	
	InteractionInfo.Title = ItemTemplate.DisplayName;
}