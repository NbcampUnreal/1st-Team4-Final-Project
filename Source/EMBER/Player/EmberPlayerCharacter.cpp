// Fill out your copyright notice in the Description page of Project Settings.
#include "EmberPlayerCharacter.h"
#include "C_CameraComponent.h"
#include "EmberPlayerController.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "C_CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AEmberPlayerCharacter::AEmberPlayerCharacter(const FObjectInitializer& Init)
    : Super(Init.SetDefaultSubobjectClass<UC_CharacterMovementComponent>
    (ACharacter::CharacterMovementComponentName))
{
    PrimaryActorTick.bCanEverTick = false;
    SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArmComp->SetupAttachment(RootComponent);
    SpringArmComp->TargetArmLength = 300.0f;
    SpringArmComp->bUsePawnControlRotation = true;

    CameraLogicComp = CreateDefaultSubobject<UC_CameraComponent>(TEXT("CameraLogic"));

    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    CameraComponent->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
    CameraComponent->bUsePawnControlRotation = false;
}

// Called when the game starts or when spawned
void AEmberPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AEmberPlayerCharacter::PostInitializeComponents()
{
    Super::PostInitializeComponents();
    MovementComponent = Cast<UC_CharacterMovementComponent>(GetCharacterMovement());
}

// Called every frame
void AEmberPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEmberPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    
if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        if (AEmberPlayerController* PlayerController = Cast<AEmberPlayerController>(GetController()))
        {
            if (PlayerController->MoveAction)
            {
                EnhancedInput->BindAction(
                    PlayerController->MoveAction,
                    ETriggerEvent::Triggered,
                    this,
                    &AEmberPlayerCharacter::Move
                );
            }
            
            if (PlayerController->LookAction)
            {
                EnhancedInput->BindAction(
                    PlayerController->LookAction,
                    ETriggerEvent::Triggered,
                    this,
                    &AEmberPlayerCharacter::Look
                );
            }
            
            if (PlayerController->SprintAction)
            {
                EnhancedInput->BindAction(
                    PlayerController->SprintAction,
                    ETriggerEvent::Triggered, 
                    this, 
                    &AEmberPlayerCharacter::StartSprint
                );
                EnhancedInput->BindAction(
                    PlayerController->SprintAction, 
                    ETriggerEvent::Completed, 
                    this, 
                    &AEmberPlayerCharacter::StopSprint
                );
            }    
        }
    }
}

void AEmberPlayerCharacter::Move(const FInputActionValue& value)
{

    //MovementComponent->OnMove(value);
    
    /*
    if (!Controller) return;
    const FVector2D MoveInput = value.Get<FVector2D>();
    if (!FMath::IsNearlyZero(MoveInput.X))
    {
        AddMovementInput(GetActorForwardVector(), MoveInput.X);
    }

    if (!FMath::IsNearlyZero(MoveInput.Y))
    {
        AddMovementInput(GetActorRightVector(), MoveInput.Y);
    }
    */
    if(MovementComponent)
        MovementComponent->OnMove(value);
}

void AEmberPlayerCharacter::Look(const FInputActionValue& value)
{   
    CameraLogicComp->OnLook(value);
}

void AEmberPlayerCharacter::StartSprint(const FInputActionValue& value)
{
    if (GetCharacterMovement())
    {
        //GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
    }
}

void AEmberPlayerCharacter::StopSprint(const FInputActionValue& value)
{
    if (GetCharacterMovement())
    {
        //GetCharacterMovement()->MaxWalkSpeed = NormalSpeed;
    }
}