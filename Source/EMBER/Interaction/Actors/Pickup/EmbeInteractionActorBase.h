// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interaction/Actors/EmberWorldPickupable.h"
#include "EmbeInteractionActorBase.generated.h"

class UItemTemplate;
class USphereComponent;

UCLASS()
class EMBER_API AEmbeInteractionActorBase : public AEmberWorldPickupable
{
	GENERATED_BODY()

public:
	AEmbeInteractionActorBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<USphereComponent> PickupCollision;

	UPROPERTY(EditDefaultsOnly, Category = "PickupableItemBase|Info")
	TSubclassOf<UItemTemplate> ItemTemplateClass;
};
