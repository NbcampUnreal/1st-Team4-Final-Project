// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MonsterAIBase.generated.h"

UCLASS(Abstract)
class EMBER_API AMonsterAIBase : public ACharacter
{
	GENERATED_BODY()

public:
	AMonsterAIBase();

protected:
	virtual void BeginPlay() override;
};
