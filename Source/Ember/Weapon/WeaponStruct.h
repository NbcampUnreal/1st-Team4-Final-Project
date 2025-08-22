// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "WeaponStruct.generated.h"

USTRUCT()
struct FDoActionData
{
	GENERATED_BODY()
public:
	//UPROPERTY(EditAnywhere)
	//UAnimMontage* Montage;
	UPROPERTY(EditAnywhere)
	float PlayRate = 1.0f;
	UPROPERTY(EditAnywhere)
	float Stamina{};
	
	UPROPERTY(EditAnywhere)
	bool bFixedCamera{};
	UPROPERTY(EditAnywhere, Category = "Weapon|SFX")
	USoundBase* AttackSound;
	UPROPERTY(EditAnywhere)
	class UFXSystemAsset* Effect{};
	UPROPERTY(EditAnywhere)
	FVector EffectLocation = FVector::ZeroVector;
	UPROPERTY(EditAnywhere)
	FVector EffectScale = FVector::ZeroVector;
};

UCLASS()
class EMBER_API UWeaponStruct : public UObject
{
	GENERATED_BODY()
};
