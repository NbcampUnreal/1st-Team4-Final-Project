// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "MonsterAbilitySystemComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class EMBER_API UMonsterAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UMonsterAbilitySystemComponent();

protected:
	virtual void BeginPlay() override;

public:
	bool TryActivateAbilityByTag(const FGameplayTag& GameplayTag);
};
