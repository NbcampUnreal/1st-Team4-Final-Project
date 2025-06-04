// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameData.h"
#include "GameFramework/Actor.h"
#include "CAI_Weapon.generated.h"

UCLASS()
class EMBER_API ACAI_Weapon : public AActor
{
	GENERATED_BODY()
	
public:	
	ACAI_Weapon();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:
	virtual void DoAction();
	virtual void Begin_DoAction();
	virtual void End_DoAction();

private:
	class ACharacter* OwnerCharacter;
	bool bInAction;
	bool bBeginAction;

	TArray<FDamageData> Damage;
};
