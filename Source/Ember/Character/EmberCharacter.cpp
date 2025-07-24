#include "EmberCharacter.h"

#include <assert.h>
#include <Utility/CHelpers.h>

#include "Utility/CLog.h"
#include "AbilitySystemComponent.h"
#include "EmberPlayerController.h"
#include "EmberPlayerState.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "Component/CustomCameraComponent.h"
#include "Component/CustomMoveComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
// Sets default values
AEmberCharacter::AEmberCharacter()
{
	ASC == nullptr;
	PrimaryActorTick.bCanEverTick = true;

	// 스프링암 생성 및 설정
	CHelpers::CreateComponent(this, &SpringArm, "SpringArm", RootComponent);
	SpringArm->TargetArmLength = 300.f; // 카메라 거리
	SpringArm->bUsePawnControlRotation = true; // 마우스로 회전

	// 카메라 생성 및 스프링암에 붙이기
	CHelpers::CreateComponent(this, &Camera,"Camera", SpringArm);
	Camera->bUsePawnControlRotation = false; // 카메라는 스프링암에 따라감 (직접 회전 X)

	CHelpers::CreateActorComponent(this, &MoveComponent, "Movement Component");
	CHelpers::CreateActorComponent(this, &CameraComponent, "Camera Component");

	// 캐릭터가 직접 회전하지 않도록
	bUseControllerRotationYaw = false;

	// 기본 이속을 WalkSpeed로 설정
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	GetCharacterMovement()->bOrientRotationToMovement = true;// 이동 방향으로 캐릭터 회전
}
void AEmberCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AEmberCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	TObjectPtr<AEmberPlayerState> state = GetPlayerState<AEmberPlayerState>();
	if (state == nullptr)
	{
		DebugLogE("player state is null");
		return;
	}

	ASC = state->GetAbilitySystemComponent();
	if (ASC == nullptr)
	{
		DebugLogE("ASC is null");
		return;
	}
	ASC->InitAbilityActorInfo(state,this);

	for (const auto& gameAbility : GameAbilities)
	{
		FGameplayAbilitySpec spec(gameAbility.Value);
		spec.InputID = gameAbility.Key;
		ASC->GiveAbility(spec);
	}
	
	SetupGASInputComponent();
}


void AEmberCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEmberCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (EnhancedInput == nullptr)
	{
		DebugLogE("Enhanced Input is null");
		return;
	}
	PlayerController = Cast<AEmberPlayerController>(GetController());
	if (PlayerController == nullptr)
	{
		DebugLogE("PlayerController is null");
		return;
	}
	EnhancedInput->BindAction(PlayerController.Get()->MoveAction, ETriggerEvent::Triggered, MoveComponent.Get(), &UCustomMoveComponent::Move);
	EnhancedInput->BindAction(PlayerController.Get()->LookAction, ETriggerEvent::Triggered, CameraComponent.Get(), &UCustomCameraComponent::Look);
	//EnhancedInput->BindAction(AttackAction, ETriggerEvent::Started, this, &AEmberCharacter::Attack);

	SetupGASInputComponent();
}

void AEmberCharacter::SetupGASInputComponent()
{
	if (IsValid(ASC) && IsValid(InputComponent))
	{
		UEnhancedInputComponent* input = Cast<UEnhancedInputComponent>(InputComponent);
		if (input == nullptr)
		{
			DebugLogE("input is null");
			return;
		}
		input->BindAction(PlayerController.Get()->JumpAction, ETriggerEvent::Triggered,this,&AEmberCharacter::GASInputPressed,0);
		input->BindAction(PlayerController.Get()->JumpAction, ETriggerEvent::Completed,this,&AEmberCharacter::GASInputReleased, 0);
		input->BindAction(PlayerController.Get()->SprintAction,ETriggerEvent::Triggered,this, &AEmberCharacter::GASInputPressed,1);
		input->BindAction(PlayerController.Get()->SprintAction,ETriggerEvent::Completed,this, &AEmberCharacter::GASInputReleased,1);
	}
}

void AEmberCharacter::GASInputPressed(int32 Input)
{
	FGameplayAbilitySpec* spec = ASC->FindAbilitySpecFromInputID(Input);
	if (spec == nullptr)
	{
		DebugLogE("spec is null");
		return;
	}

	spec->InputPressed = true;

	if (spec->IsActive() == true)
		ASC->AbilitySpecInputPressed(*spec);
	else
		ASC->TryActivateAbility(spec->Handle);
}

void AEmberCharacter::GASInputReleased(int32 Input)
{
	FGameplayAbilitySpec* spec = ASC->FindAbilitySpecFromInputID(Input);
	if (spec == nullptr)
	{
		DebugLogE("spec is null");
		return;
	}
	
	spec->InputPressed = false;
	if (spec->IsActive() == true)
		ASC->AbilityLocalInputReleased(Input);
}

UAbilitySystemComponent* AEmberCharacter::GetAbilitySystemComponent() const
{
	return ASC;
}

void AEmberCharacter::Attack()
{
	UE_LOG(LogTemp, Warning, TEXT("Attack triggered!"));
}
