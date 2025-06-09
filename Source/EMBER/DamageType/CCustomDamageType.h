// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameData.h"
#include "GameFramework/DamageType.h"
#include "CCustomDamageType.generated.h"

UCLASS()
class EMBER_API UCCustomDamageType : public UDamageType
{
	GENERATED_BODY()
public:
	FDamageData* DamageDate;
};
