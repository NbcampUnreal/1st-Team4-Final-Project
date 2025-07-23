// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EmberWeaponBase.generated.h"

UCLASS()
class EMBER_API AEmberWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEmberWeaponBase();
	
	/* 기본 데미지 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon|Stats")
	float Damage;

	/* 공격 쿨다운 (초) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon|Stats")
	float Cooldown;

	/*  내구도 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon|Stats")
	float Durability;

	/* 애님몽타주 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon|Animation")
	UAnimMontage* EquipMontage;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	float LastAttackTime; /* 쿨타임 체크용 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Weapon|Components")
	USkeletalMeshComponent* MeshComp;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
