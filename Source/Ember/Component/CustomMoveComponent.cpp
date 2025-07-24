// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/CustomMoveComponent.h"

#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "Utility/CLog.h"

// Sets default values for this component's properties
UCustomMoveComponent::UCustomMoveComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	OwnerCharacter = Cast<ACharacter>(GetOwner());
	if (OwnerCharacter == nullptr)
	{
		DebugLogE("Owner Character is null");
		return;
	}
}


// Called when the game starts
void UCustomMoveComponent::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void UCustomMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UCustomMoveComponent::Move(const FInputActionValue& Value)
{
	FVector2D moveVector = Value.Get<FVector2D>();
	if (OwnerCharacter->GetController() == nullptr)
	{
		DebugLogE("controller is null");
		return;
	}

	const FRotator rotation = OwnerCharacter->GetController()->GetControlRotation();
	const FRotator yaw(0,rotation.Yaw,0);
	const FVector foward = FRotationMatrix(yaw).GetUnitAxis(EAxis::X);
	const FVector right = FRotationMatrix(yaw).GetUnitAxis(EAxis::Y);

	OwnerCharacter->AddMovementInput(foward,moveVector.Y);
	OwnerCharacter->AddMovementInput(right,moveVector.X);
}

void UCustomMoveComponent::Look(const FInputActionValue& Value)
{
}

