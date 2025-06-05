// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EmberWorldInteractable.h"
#include "EmberOreBase.generated.h"

struct FChaosBreakEvent;
class AFieldSystemActor;

UCLASS()
class EMBER_API AEmberOreBase : public AEmberWorldInteractable
{
	GENERATED_BODY()

public:
	AEmberOreBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	virtual void BeginPlay() override;

protected:
	UFUNCTION()
	void HandlePointDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector ShotFromDirection, const UDamageType* DamageType, AActor* DamageCauser);

	UFUNCTION()
	void HandleBreakEvent(const FChaosBreakEvent& BreakEvent);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "Ore")
	TObjectPtr<UChildActorComponent> AnchorField;
	
	UPROPERTY(EditDefaultsOnly, Category = "Ore|ChaosPhsics")
	TObjectPtr<UGeometryCollectionComponent> GeometryCollection;
	
	UPROPERTY(EditDefaultsOnly, Category = "Ore|ChaosPhsics")
	TSubclassOf<AFieldSystemActor> ChaosImpactClass;
};
