// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "EmberHUD.generated.h"

/**
 * 
 */
UCLASS()
class EMBER_API AEmberHUD : public AHUD
{
	GENERATED_BODY()

public:
	//~AHUD Overrides
	virtual void BeginPlay() override;
	//~End of AHUD Overrides 
};
