// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "EmberAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class EMBER_API UEmberAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UEmberAbilitySystemComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
public:
	void AbilityInputTagStarted(const FGameplayTag& InputTag);
	void AbilityInputTagPressed(const FGameplayTag& InputTag);
	void AbilityInputTagReleased(const FGameplayTag& InputTag);

public:
	void ProcessAbilityInput(float DeltaTime, bool bGamePaused);
	void ClearAbilityInput();
	
//~UAbilitySystemComponent Overrides
public:
	virtual void InitAbilityActorInfo(AActor* InOwnerActor, AActor* InAvatarActor) override;
	
protected:
	virtual void AbilitySecInputStarted(FGameplayAbilitySpec& Spec);
	virtual void AbilitySpecInputPressed(FGameplayAbilitySpec& Spec) override;
	virtual void AbilitySpecInputReleased(FGameplayAbilitySpec& Spec) override;
//~End of UAbilitySystemComponent Overrides

protected:
	void TryActivateAbilitiesOnSpawn();
	
protected:
	TArray<FGameplayAbilitySpecHandle> InputStartedSpecHandles;
	TArray<FGameplayAbilitySpecHandle> InputPressedSpecHandles;
	TArray<FGameplayAbilitySpecHandle> InputReleasedSpecHandles;
	TArray<FGameplayAbilitySpecHandle> InputHeldSpecHandles;
};
