// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Animal/Rabbit.h"

#include "AI/NavigationSystemBase.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ARabbit::ARabbit()
{
	MaxHP = 100;
	WalkSpeed = 150.f;
	RunSpeed = 450.f;
}

void ARabbit::OnDeath()
{
	Super::OnDeath();
	UE_LOG(LogTemp, Warning, TEXT("Rabbit Death"));
	
	GetMesh()->SetSimulatePhysics(true);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}