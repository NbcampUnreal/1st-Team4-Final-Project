// Fill out your copyright notice in the Description page of Project Settings.
#include "EmberPlayerCharacter.h"

#include "ArmorComponent.h"
#include "C_CameraComponent.h"
#include "EmberPlayerController.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "C_CharacterMovementComponent.h"
#include "EmberPlayerState.h"
#include "GameData.h"
#include "StatusComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Managers/EquipmentManagerComponent.h"

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

    EquipmentManagerComponent = CreateDefaultSubobject<UEquipmentManagerComponent>(TEXT("EquipmentManager"));
    CharacterInputComponent = CreateDefaultSubobject<UCharacterInputComponent>(TEXT("CharacterInput"));

    MontageComponent = CreateDefaultSubobject<UMontageSystemComponent>(TEXT("MontageComponent"));
    StatusComponent = CreateDefaultSubobject<UStatusComponent>(TEXT("StatusComponent"));
    ArmorComponent = CreateDefaultSubobject<UArmorComponent>(TEXT("ArmorComponent"));
    StatusComponent = CreateDefaultSubobject<UStatusComponent>(TEXT("SatatusComponent"));

    Tags.Add("Player");
}

// Called when the game starts or when spawned
void AEmberPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
    
    StatusComponent->SetMaxHp(100);
    StatusComponent->SetMaxStamina(100);
    CameraLogicComp->DisableControlRotation();
    APlayerController* playerController = Cast<APlayerController>(GetController());
    if(playerController != nullptr)
    {
        playerController->PlayerCameraManager->ViewPitchMin = PitchRange.X;
        playerController->PlayerCameraManager->ViewPitchMax = PitchRange.Y;
    }
    
    //TODOS
    if(ArmorComponent != nullptr)
    {
	    if(HasAuthority() == true)
	    {
            ArmorComponent->InitializeArmorForLateJoiners();
	    }
    }
}

void AEmberPlayerCharacter::PostInitializeComponents()
{
    Super::PostInitializeComponents();
    MovementComponent = Cast<UC_CharacterMovementComponent>(GetCharacterMovement());
}

void AEmberPlayerCharacter::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);
    
    InitAbilityActorInfo();
}

void AEmberPlayerCharacter::OnRep_PlayerState()
{
    Super::OnRep_PlayerState();
    
    InitAbilityActorInfo();
    if (ArmorComponent != nullptr)
        ArmorComponent->InitializeArmorForLateJoiners();
}

void AEmberPlayerCharacter::InitAbilityActorInfo()
{
    AEmberPlayerState* EmberPlayerState = GetPlayerState<AEmberPlayerState>();
    check(EmberPlayerState);
    EmberPlayerState->InitAbilitySystemComponent();
    AbilitySystemComponent = EmberPlayerState->GetAbilitySystemComponent();
}

void AEmberPlayerCharacter::PostNetInit()
{
	Super::PostNetInit();
    UE_LOG(LogTemp, Warning, L"PostNetInit Call");
    if (ArmorComponent != nullptr)
        ArmorComponent->InitializeArmorForLateJoiners();
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
            if (PlayerController->AttackAction)
            {
                EnhancedInput->BindAction(
                    PlayerController->AttackAction,
                    ETriggerEvent::Started, 
                    this, 
                    &AEmberPlayerCharacter::Attack
                );
            }
            if (PlayerController->MoveAction)
            {
                EnhancedInput->BindAction(
                    PlayerController->JumpAction,
                    ETriggerEvent::Started,
                    this,
                    &AEmberPlayerCharacter::Jump
                );
            }
        }
    }

    CharacterInputComponent->InitializePlayerInput(PlayerInputComponent);
}

void AEmberPlayerCharacter::Move(const FInputActionValue& value)
{
    
    if(MovementComponent)
    {
        MovementComponent->OnMove(value);
    }
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

void AEmberPlayerCharacter::Attack(const FInputActionValue& value)
{
    // EquipmentComponent에서 현재 무기 타입 가져오기
    FAttackData Data = EquipmentManagerComponent->GetAttackInfo();

    if (!Data.Montages.IsEmpty())
    {
        MontageComponent->PlayMontage(Data.Montages[Data.MontageIndex]);
    }
}

void AEmberPlayerCharacter::StartJump(const FInputActionValue& value)
{
    Jump();
}
float AEmberPlayerCharacter::GetMaxHP() const
{
    if (StatusComponent)
    {
        return StatusComponent->GetMaxHp();
    }
    return 0.f;
}

float AEmberPlayerCharacter::GetMaxStamina() const
{
    if (StatusComponent)
    {
        return StatusComponent->GetMaxStamina();
    }
    return 0.f;
}
float AEmberPlayerCharacter::GetCurrentHP() const
{
    if (StatusComponent)
    {
        return StatusComponent->GetHp();
    }
    return 0.f;
}

float AEmberPlayerCharacter::GetCurrentStamina() const
{
    if (StatusComponent)
    {
        return StatusComponent->GetStamina();
    }
    return 0.f;
}