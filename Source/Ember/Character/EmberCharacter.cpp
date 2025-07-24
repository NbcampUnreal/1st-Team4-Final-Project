// Fill out your copyright notice in the Description page of Project Settings.


#include "EmberCharacter.h"

#include "AI/MonsterAIController.h"
#include "Item/BaseItem.h"

#include <assert.h>
#include <Utility/CHelpers.h>

#include "Utility/CLog.h"
#include "AbilitySystemComponent.h"
#include "EmberPlayerController.h"
#include "EmberPlayerState.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
// Sets default values
AEmberCharacter::AEmberCharacter()
{
	ASC == nullptr;
	PrimaryActorTick.bCanEverTick = true;

	// �������� ���� �� ����
	CHelpers::CreateComponent(this, &SpringArm, "SpringArm", RootComponent);
	SpringArm->TargetArmLength = 300.f; // ī�޶� �Ÿ�
	SpringArm->bUsePawnControlRotation = true; // ���콺�� ȸ��

	// ī�޶� ���� �� �������Ͽ� ���̱�
	CHelpers::CreateComponent(this, &Camera,"Camera", SpringArm);
	Camera->bUsePawnControlRotation = false; // ī�޶�� �������Ͽ� ���� (���� ȸ�� X)

	// ĳ���Ͱ� ���� ȸ������ �ʵ���
	bUseControllerRotationYaw = false;

	// �⺻ �̼��� WalkSpeed�� ����
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	GetCharacterMovement()->bOrientRotationToMovement = true;// �̵� �������� ĳ���� ȸ��
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


FGenericTeamId AEmberCharacter::GetGenericTeamId() const
{
	return FGenericTeamId((uint8)EGameTeamID::Team1);
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
	EnhancedInput->BindAction(PlayerController.Get()->MoveAction, ETriggerEvent::Triggered, this, &AEmberCharacter::Move);
	EnhancedInput->BindAction(PlayerController.Get()->LookAction, ETriggerEvent::Triggered, this, &AEmberCharacter::Look);
	//EnhancedInput->BindAction(AttackAction, ETriggerEvent::Started, this, &AEmberCharacter::Attack);

	//EnhancedInput->BindAction(SprintAction, ETriggerEvent::Started, this, &AEmberCharacter::StartSprinting);
	//EnhancedInput->BindAction(SprintAction, ETriggerEvent::Completed, this, &AEmberCharacter::StopSprinting);

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

void AEmberCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	if (Controller != nullptr)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AEmberCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	AddControllerYawInput(LookAxisVector.X);
	AddControllerPitchInput(LookAxisVector.Y);
}

void AEmberCharacter::Attack()
{
	UE_LOG(LogTemp, Warning, TEXT("Attack triggered!"));
}

void AEmberCharacter::StartSprinting()
{
	if (UCharacterMovementComponent* MoveComp = GetCharacterMovement())
	{
		MoveComp->MaxWalkSpeed = SprintSpeed;
	}
}

void AEmberCharacter::StopSprinting()
{
	if (UCharacterMovementComponent* MoveComp = GetCharacterMovement())
	{
		MoveComp->MaxWalkSpeed = WalkSpeed;
	}
}

void AEmberCharacter::PickupItem()
{
	FVector Start = Camera->GetComponentLocation();
	FRotator ControlRot = GetControlRotation();
	FVector Direction = ControlRot.Vector();
	float Distance = InteractDistance;
	FVector End = Start + Direction * Distance;
	float ActualDist = FVector::Distance(Start, End);
	// 디버그 로그
	UE_LOG(LogTemp, Warning, TEXT("==== PickupItem Debug ===="));
	UE_LOG(LogTemp, Warning, TEXT("Start         : %s"), *Start.ToString());
	UE_LOG(LogTemp, Warning, TEXT("End           : %s"), *End.ToString());
	UE_LOG(LogTemp, Warning, TEXT("Direction     : %s"), *Direction.ToString());
	UE_LOG(LogTemp, Warning, TEXT("Control Rot   : %s"), *ControlRot.ToString());
	UE_LOG(LogTemp, Warning, TEXT("Actual Length : %.2f"), ActualDist);
	// 시각적 디버그
	DrawDebugDirectionalArrow(GetWorld(), Start, End, 150.0f, FColor::Red, false, 5.0f, 0, 3.0f);
	DrawDebugSphere(GetWorld(), Start, 10.f, 12, FColor::Green, false, 5.0f);
	DrawDebugSphere(GetWorld(), End, 10.f, 12, FColor::Blue, false, 5.0f);
	// 라인트레이스
	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, Params))
	{
		AActor* HitActor = HitResult.GetActor();
		UE_LOG(LogTemp, Warning, TEXT("LineTrace HIT!"));
		if (HitActor)
		{
			UE_LOG(LogTemp, Warning, TEXT("Hit Actor     : %s"), *HitActor->GetName());
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Hit Actor     : nullptr"));
		}
		UE_LOG(LogTemp, Warning, TEXT("Impact Point  : %s"), *HitResult.ImpactPoint.ToString());
		UE_LOG(LogTemp, Warning, TEXT("Impact Normal : %s"), *HitResult.ImpactNormal.ToString());
		UE_LOG(LogTemp, Warning, TEXT("Hit Bone Name : %s"), *HitResult.BoneName.ToString());
		// 아이템 상호작용
		if (ABaseItem* Item = Cast<ABaseItem>(HitActor))
		{
			Item->Interact(this);
			UE_LOG(LogTemp, Warning, TEXT("Item Interacted: %s"), *Item->GetName());
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("LineTrace MISS — nothing hit."));
	}
}

