// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EmberWorldInteractable.h"
#include "EmberOreBase.generated.h"

UCLASS()
class EMBER_API AEmberOreBase : public AEmberWorldInteractable
{
	GENERATED_BODY()

public:
	AEmberOreBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
