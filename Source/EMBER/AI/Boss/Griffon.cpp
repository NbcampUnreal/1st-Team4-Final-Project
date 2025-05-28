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

	if (GetActorLocation().Z > 1000.0f)
	{
		GetCharacterMovement()->Velocity.Z = 0.0f;
	}
}

void AGriffon::OnTargetPerceptionUpdated(AActor* UpdatedActor, FAIStimulus Stimulus)
{
	Super::OnTargetPerceptionUpdated(UpdatedActor, Stimulus);

	if (Stimulus.WasSuccessfullySensed() && UpdatedActor->Tags.Contains(FName("Player")))
	{
		UCharacterMovementComponent* MovementComp = GetCharacterMovement();
		if (MovementComp)
		{
			SetFlySpeed();
			GetCharacterMovement()->StopMovementImmediately();
			LaunchCharacter(FVector(0, 0, 700), false, true);
		}

		SetBlackboardVector("OriginLocation", GetActorLocation());
	}
}
