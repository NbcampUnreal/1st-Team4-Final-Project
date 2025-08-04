// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "MonsterGameplayAbility.generated.h"

class AMonsterAIBase;
class AAIController;

UCLASS()
class EMBER_API UMonsterGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Lyra|Ability")
	AMonsterAIBase* GetMonsterAIFromActorInfo() const;

	UFUNCTION(BlueprintCallable, Category = "Lyra|Ability")
	AAIController* GetMonsterAIControllerFromActorInfo() const;
};
