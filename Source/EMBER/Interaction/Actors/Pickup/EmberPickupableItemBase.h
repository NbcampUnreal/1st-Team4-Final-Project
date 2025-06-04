// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EmberWorldPickupable.h"
#include "EmberPickupableItemBase.generated.h"

class USphereComponent;

UCLASS()
class EMBER_API AEmberPickupableItemBase : public AEmberWorldPickupable
{
	GENERATED_BODY()

public:
	AEmberPickupableItemBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<USphereComponent> PickupCollision;
};
