// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/CAI_Weapon.h"

#include "GameFramework/Character.h"

// Sets default values
ACAI_Weapon::ACAI_Weapon()
{
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACAI_Weapon::BeginPlay()
{
	Super::BeginPlay();
	OwnerCharacter = Cast<ACharacter>(GetOwner());
}

// Called every frame
void ACAI_Weapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACAI_Weapon::DoAction()
{
	bInAction = true;
}

void ACAI_Weapon::Begin_DoAction()
{
	bBeginAction = true;
}

void ACAI_Weapon::End_DoAction()
{
	bInAction = false;
	bBeginAction = false;
}

