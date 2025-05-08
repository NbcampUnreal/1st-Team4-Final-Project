// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFlag.h"
#include "Item/ItemTemplate.h"
#include "UObject/Object.h"
#include "ItemFragment_Equipable.generated.h"

/**
 * 
 */
UCLASS(Abstract, Const)
class EMBER_API UItemFragment_Equipable : public UItemFragment
{
	GENERATED_BODY()

public:
	UItemFragment_Equipable(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	EEquipmentType EquipmentType = EEquipmentType::Count;
};
