// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerState.h"
#include "EmberPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class EMBER_API AEmberPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	UFUNCTION(Server, Reliable)
	void Server_AddInventoryItem(TSubclassOf<UItemTemplate> InItemTemplateClass, EItemRarity InItemRarity, int32 InItemCount);
};
