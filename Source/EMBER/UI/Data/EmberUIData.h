// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DataAsset.h"
#include "EmberUIData.generated.h"

class UInventorySlotWidget;
class UInventoryValidWidget;

UCLASS()
class EMBER_API UEmberUIData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:	
	static const UEmberUIData& Get();
	
public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UInventorySlotWidget> InventorySlotWidgetClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UInventoryValidWidget> InventoryValidWidgetClass;
	
	UPROPERTY(EditDefaultsOnly)
	FIntPoint UnitInventorySlotSize = FIntPoint::ZeroValue;
};
