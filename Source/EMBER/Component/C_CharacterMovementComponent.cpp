#include "C_CharacterMovementComponent.h"
#include "C_StateComponent.h"
#include "GameFramework/Character.h"
#include "EnhancedInputSubsystems.h"

void UC_CharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	OwnerCharacter = GetCharacterOwner();

	UC_StateComponent* StateCom = Cast<UC_StateComponent>(GetOwner()->FindComponentByClass<UC_StateComponent>());
	State = StateCom;
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
	return Speed[(int32)CurrentSpeedType];
}

void UC_CharacterMovementComponent::EnableMove()
{
	bCanMove = true;
}

void UC_CharacterMovementComponent::DisableMove()
{
	bCanMove = false;
}

float UC_CharacterMovementComponent::GetMaxSpeed() const
{	
	return Super::GetMaxSpeed();
}

void UC_CharacterMovementComponent::OnMove(const FInputActionValue& Value)
{
	if (bCanMove == false)
		return;
	FVector2D MoveVector = Value.Get<FVector2D>();

	if (MoveVector.IsNearlyZero())
	{
		return;
	}

	if (OwnerCharacter && OwnerCharacter->GetController())
	{
		const FRotator Rotation = OwnerCharacter->GetControlRotation();
		const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		
		// 이동 입력 적용
		AddInputVector(ForwardDirection * MoveVector.Y);
		AddInputVector(RightDirection * MoveVector.X);
		//OnMoveDelegate.Broadcast(MoveVector);
	}
}

void UC_CharacterMovementComponent::OnJump()
{
	OwnerCharacter->Jump();
}

void UC_CharacterMovementComponent::OnSprint()
{
	SetSpeed(ESpeedType::Sprint);
}

void UC_CharacterMovementComponent::OnRun()
{
	SetSpeed(ESpeedType::Run);
}

void UC_CharacterMovementComponent::OnWarlk()
{
	SetSpeed(ESpeedType::Walk);
}

void UC_CharacterMovementComponent::SetSpeed(ESpeedType SpeedType)
{
	CurrentSpeedType = SpeedType;
	MaxWalkSpeed = Speed[(int32)CurrentSpeedType];
}
