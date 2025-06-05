// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI/CAI_Weapon.h"
#include "CAI_Weapon_Wolf.generated.h"

/**
 * 
 */
UCLASS()
class EMBER_API ACAI_Weapon_Wolf : public ACAI_Weapon
{
	GENERATED_BODY()
public:
	FORCEINLINE void EnableCombo() { bEnable = true; }
	FORCEINLINE void DisableCombo(){bEnable = false;}
public:
	ACAI_Weapon_Wolf();

public:
	virtual void DoAction() override;
	virtual void Begin_DoAction() override;
	virtual void End_DoAction() override;

private:
	TArray<ACharacter*> Hitted;

	int32 Index;

	bool bEnable;
	bool bExist;
};
