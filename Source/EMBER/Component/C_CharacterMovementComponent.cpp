#include "C_CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "EnhancedInputSubsystems.h"

void UC_CharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	OwnerCharacter = GetCharacterOwner();
}

void UC_CharacterMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

bool UC_CharacterMovementComponent::GetCanMove() const
{
	return bCanMove;
}

bool UC_CharacterMovementComponent::GetCanDash() const
{
	return bIsDash;
}

float UC_CharacterMovementComponent::GetCurrentSpeed() const
{	
	FVector Speed = Velocity * FVector(1.f, 1.f, 0.f);

	return Speed.Length();
}

float UC_CharacterMovementComponent::GetMaxSpeed() const
{	
	return Super::GetMaxSpeed();
}

void UC_CharacterMovementComponent::OnMove(const FInputActionValue& Value)
{
	FVector2D MoveVector = Value.Get<FVector2D>();

	if (MoveVector.IsNearlyZero())
	{
		return;
	}

	if (CharacterOwner && CharacterOwner->GetController())
	{
		const FRotator Rotation = CharacterOwner->GetControlRotation();
		const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

		const FVector ForwardDirection = CharacterOwner->GetActorForwardVector();
		const FVector RightDirection = CharacterOwner->GetActorRightVector();

		// 이동 입력 적용
		AddInputVector(ForwardDirection * MoveVector.Y);
		AddInputVector(RightDirection * MoveVector.X);
		//OnMoveDelegate.Broadcast(MoveVector);
	}
}
