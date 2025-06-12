// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EmberPickupableItemBase.h"
#include "GameFramework/Actor.h"
#include "EmberFoliageBase.generated.h"

class AEmberPickupableItemBase;
class UItemTemplate;

UCLASS()
class EMBER_API AEmberFoliageBase : public AEmberPickupableItemBase
{
	GENERATED_BODY()
public:
	AEmberFoliageBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	//~AActor Overrides
	virtual void BeginPlay() override;
	//~End of AActor Overrides
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "FoliageBase|Info")
	TSubclassOf<UItemTemplate> ItemTemplateClass;
};
