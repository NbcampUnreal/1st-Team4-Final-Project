// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterInputComponent.h"

#include "EmberEnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "UI/Data/EmberPawnData.h"
#include "Data/EmberInputConfig.h"
#include "GameFramework/PlayerState.h"
#include "System/AbilitySystem/EmberAbilitySystemComponent.h"

UCharacterInputComponent::UCharacterInputComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UCharacterInputComponent::InitializePlayerInput(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	const APlayerController* PC = GetController<APlayerController>();
	check(PC);

	const ULocalPlayer* LP = PC->GetLocalPlayer();
	check(LP);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(Subsystem);
	
	if (const UEmberInputConfig* InputConfig =  UEmberPawnData::Get().InputConfig)
	{
		Subsystem->AddMappingContext(InputConfig->InputMappingContext, 1);

		if (UEmberEnhancedInputComponent* EmberIC = Cast<UEmberEnhancedInputComponent>(PlayerInputComponent))
		{
			TArray<uint32> BindHandles;
			EmberIC->BindAbilityActions(InputConfig, this, &ThisClass::Input_AbilityInputTagStarted, &ThisClass::Input_AbilityInputTagPressed, &ThisClass::Input_AbilityInputTagReleased, /*out*/ BindHandles);
		}
	}
}

void UCharacterInputComponent::Input_AbilityInputTagStarted(FGameplayTag InputTag)
{
	if (const APlayerState* PlayerState = GetPlayerState<APlayerState>())
	{
		if (UEmberAbilitySystemComponent* EmberSC = PlayerState->FindComponentByClass<UEmberAbilitySystemComponent>())
		{
				EmberSC->AbilityInputTagStarted(InputTag);
		}
	}
}

void UCharacterInputComponent::Input_AbilityInputTagPressed(FGameplayTag InputTag)
{
	if (const APlayerState* PlayerState = GetPlayerState<APlayerState>())
	{
		if (UEmberAbilitySystemComponent* EmberSC = PlayerState->FindComponentByClass<UEmberAbilitySystemComponent>())
		{
			EmberSC->AbilityInputTagPressed(InputTag);
		}
	}
}

void UCharacterInputComponent::Input_AbilityInputTagReleased(FGameplayTag InputTag)
{
	if (const APlayerState* PlayerState = GetPlayerState<APlayerState>())
	{
		if (UEmberAbilitySystemComponent* EmberSC = PlayerState->FindComponentByClass<UEmberAbilitySystemComponent>())
		{
			EmberSC->AbilityInputTagReleased(InputTag);
		}
	}
}
