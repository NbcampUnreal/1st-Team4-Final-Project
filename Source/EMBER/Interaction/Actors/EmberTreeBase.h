// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EmberWorldInteractable.h"
#include "EmberTreeBase.generated.h"

struct FEmberInteractionQuery;

UCLASS()
class EMBER_API AEmberTreeBase : public AEmberWorldInteractable
{
	GENERATED_BODY()

public:
	AEmberTreeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
