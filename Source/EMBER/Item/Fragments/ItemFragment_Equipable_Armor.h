// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemFragment_Equipable.h"
#include "ItemFragment_Equipable_Armor.generated.h"

/**
 * 
 */
UCLASS()
class EMBER_API UItemFragment_Equipable_Armor : public UItemFragment_Equipable
{
	GENERATED_BODY()
public:
	UItemFragment_Equipable_Armor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
public:
	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<USkeletalMesh> ArmorMesh;
};
