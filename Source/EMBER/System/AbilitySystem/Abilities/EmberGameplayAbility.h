// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "EmberGameplayAbility.generated.h"

class UEmberLocalPlayer;
class AEmberPlayerCharacter;
class AEmberPlayerController;

UENUM(BlueprintType)
enum class EEmberAbilityActivationPolicy : uint8
{
	Manual,
	
	// Try to activate the ability when the input is triggered.
	OnInputTriggered,

	// Continually try to activate the ability while the input is active.
	WhileInputActive,

	// Try to activate the ability when an avatar is assigned.
	OnSpawn
};

UCLASS()
class EMBER_API UEmberGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UEmberGameplayAbility(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable, Category = "Ember|Ability")
	AEmberPlayerCharacter* GetEmberCharacterFromActorInfo() const;

	UFUNCTION(BlueprintCallable, Category = "Ember|Ability")
	AEmberPlayerController* GetEmberPlayerControllerFromActorInfo() const;

	UFUNCTION(BlueprintCallable, Category = "Ember|Ability")
	UEmberLocalPlayer* GetEmberLocalPlayerFromActorInfo() const;
	
	EEmberAbilityActivationPolicy GetActivationPolicy() const { return ActivationPolicy; }
	
protected:
	// Defines how this ability is meant to activate.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ember|Ability Activation")
	EEmberAbilityActivationPolicy ActivationPolicy;
};
