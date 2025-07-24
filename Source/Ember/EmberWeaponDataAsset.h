// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EmberWeaponDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class EMBER_API UWeaponDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	/* 데미지 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon|Stats", meta=(ClampMin="0.0"))
	float Damage = 10.0f;

	/* 쿨다운 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon|Stats", meta=(ClampMin="0.0"))
	float Cooldown = 1.0f;

	/* 공격범위 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon|Stats", meta=(ClampMin="0.0"))
	float AttackRange = 200.0f;

	/* 투사체 스피드 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon|Stats", meta=(EditCondition="Category==EWeaponCategory::Ranged_Bow"))
	float ProjectileSpeed = 2000.0f;

	/* 최대 내구도 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon|Stats", meta=(ClampMin="0.0"))
	float Durability = 100.0f;

	/* 장착 애니메이션 몽타주 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon|Animation")
	UAnimMontage* EquipMontage;

	/* 공격 애니메이션 몽타주 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon|Animation")
	UAnimMontage* AttackMontage;

	/* 공격 사운드 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon|SFX")
	USoundBase* AttackSound;
	
	/* 공격시 스태미너 소모량 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon|Cost", meta=(ClampMin="0.0"))
	float StaminaCost = 5.0f;
};