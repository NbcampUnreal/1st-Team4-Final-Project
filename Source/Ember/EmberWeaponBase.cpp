// Fill out your copyright notice in the Description page of Project Settings.


#include "EmberWeaponBase.h"

// Sets default values
AEmberWeaponBase::AEmberWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Cooldown = 1.0f;
	//Durability = 100.0f;
}

// Called when the game starts or when spawned
void AEmberWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEmberWeaponBase::Attack()
{
	if (!CanAttack())
	{
		return;	
	}

	LastAttackTime = GetWorld()->TimeSeconds; /*  */

	OnAttack();

}
bool AEmberWeaponBase::CanAttack() const
{
	float TimeSinceLast = GetWorld()->TimeSeconds - LastAttackTime;
	return (TimeSinceLast >= Cooldown) && (Cooldown > 0.0f);
}

// Called every frame
void AEmberWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

