﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameData.h"
#include "Components/ControllerComponent.h"
#include "ItemManagerComponent.generated.h"

class UInventoryManagerComponent;
class UInventoryEquipmentManagerComponent;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class EMBER_API UItemManagerComponent : public UControllerComponent
{
	GENERATED_BODY()

public:
	UItemManagerComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(Server, Reliable, BlueprintCallable)
	void Server_InventoryToInventory(UInventoryManagerComponent* FromInventoryManager, const FIntPoint& FromItemSlotPos, UInventoryManagerComponent* ToInventoryManager, const FIntPoint& ToItemSlotPos);

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void Server_InventoryToEquipment(UInventoryManagerComponent* FromInventoryManager, const FIntPoint& FromItemSlotPos, UInventoryEquipmentManagerComponent* ToInventoryEquipmentManager, EEquipmentSlotType ToEquipmentSlotType);
	
	UFUNCTION(Server, Reliable, BlueprintCallable)
	void Server_EquipmentToInventory(UInventoryEquipmentManagerComponent* FromEquipmentManager, EEquipmentSlotType FromEquipmentSlotType, UInventoryManagerComponent* ToInventoryManager, const FIntPoint& ToItemSlotPos);
	
	UFUNCTION(Server, Reliable, BlueprintCallable)
	void Server_EquipmentToEquipment(UInventoryEquipmentManagerComponent* FromEquipmentManager, EEquipmentSlotType FromEquipmentSlotType, UInventoryEquipmentManagerComponent* ToEquipmentManager, EEquipmentSlotType ToEquipmentSlotType);
};
