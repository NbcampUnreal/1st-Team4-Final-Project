// Fill out your copyright notice in the Description page of Project Settings.


#include "EmberPlayerState.h"

#include "EmberPlayerCharacter.h"
#include "Managers/InventoryManagerComponent.h"

void AEmberPlayerState::Server_AddInventoryItem_Implementation(TSubclassOf<UItemTemplate> InItemTemplateClass, EItemRarity InItemRarity, int32 InItemCount)
{
	if (HasAuthority() == false)
		return;

	if (AEmberPlayerCharacter* EmberCharacter = GetPawn<AEmberPlayerCharacter>())
	{
		if (UInventoryManagerComponent* InventoryManager = EmberCharacter->GetComponentByClass<UInventoryManagerComponent>())
		{
			InventoryManager->TryAddItemByRarity(InItemTemplateClass, InItemRarity, InItemCount);
		}
	}
}
