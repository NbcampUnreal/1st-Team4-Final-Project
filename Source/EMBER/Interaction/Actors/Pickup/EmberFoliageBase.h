// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EmbeInteractionActorBase.h"
#include "GameFramework/Actor.h"
#include "EmberFoliageBase.generated.h"

class AEmbeInteractionActorBase;
class UItemTemplate;

UCLASS()
class EMBER_API AEmberFoliageBase : public AEmbeInteractionActorBase
{
	GENERATED_BODY()
public:
	AEmberFoliageBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	virtual void BeginPlay() override;
};
