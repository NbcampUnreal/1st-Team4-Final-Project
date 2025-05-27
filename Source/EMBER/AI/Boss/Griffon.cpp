// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Boss/Griffon.h"

#include "GameFramework/CharacterMovementComponent.h"

AGriffon::AGriffon()
{
	AnimalType = EAnimalType::Griffon;
	WalkSpeed = 250.f;
	RunSpeed = 750.f;
	FlySpeed = 1200.0f;
	PrimaryActorTick.bCanEverTick = true;
}

void AGriffon::BeginPlay()
{
	ABaseAI::BeginPlay();
}

void AGriffon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetActorLocation().Z > 500.0f)
	{
		GetCharacterMovement()->Velocity.Z = 0.0f;
	}
}

void AGriffon::OnTargetPerceptionUpdated(AActor* UpdatedActor, FAIStimulus Stimulus)
{
	Super::OnTargetPerceptionUpdated(UpdatedActor, Stimulus);
	
	if (Stimulus.WasSuccessfullySensed())
	{
		UCharacterMovementComponent* MovementComp = GetCharacterMovement();
		if (MovementComp)
		{
			SetFlySpeed();
			MovementComp->GravityScale = 0.0f; // 중력 제거
			MovementComp->MaxFlySpeed = FlySpeed; // 비행 속도 설정

			GetCharacterMovement()->StopMovementImmediately();
			
			LaunchCharacter(FVector(0,0,100),false,true);
			MovementComp->SetMovementMode(MOVE_Flying); // Launch 후 비행 모드 유지
		}
	}
}

