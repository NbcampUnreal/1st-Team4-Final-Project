// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "EmberAbilitySet.generated.h"

struct FGameplayAbilitySpecHandle;
class UEmberAbilitySystemComponent;
class UEmberGameplayAbility;
class UAttributeSet;

USTRUCT(BlueprintType)
struct FEmberAbilitySet_GameplayAbility
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UEmberGameplayAbility> Ability;
	
	UPROPERTY(EditDefaultsOnly)
	int32 AbilityLevel = 1;
	
	UPROPERTY(EditDefaultsOnly, Meta = (Categories = "InputTag"))
	FGameplayTag InputTag;
};

USTRUCT(BlueprintType)
struct FEmberAbilitySet_GrantedHandles
{
	GENERATED_BODY()

public:
	void AddAbilitySpecHandle(const FGameplayAbilitySpecHandle& Handle);
	void TakeFromAbilitySystem(UEmberAbilitySystemComponent* EmberASC);

protected:
	UPROPERTY()
	TArray<FGameplayAbilitySpecHandle> AbilitySpecHandles;
	
	UPROPERTY()
	TArray<TObjectPtr<UAttributeSet>> GrantedAttributeSets;
};

UCLASS(BlueprintType, Const)
class EMBER_API UEmberAbilitySet : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UEmberAbilitySet(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	void GiveToAbilitySystem(UEmberAbilitySystemComponent* LyraASC, FEmberAbilitySet_GrantedHandles* OutGrantedHandles, UObject* SourceObject = nullptr) const;
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Gameplay Abilities")
	TArray<FEmberAbilitySet_GameplayAbility> GrantedGameplayAbilities;
};
