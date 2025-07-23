// Fill out your copyright notice in the Description page of Project Settings.


#include "EmberCharacter.h"
#include "Item/BaseItem.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
// Sets default values
AEmberCharacter::AEmberCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// 스프링암 생성 및 설정
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 300.f; // 카메라 거리
	SpringArm->bUsePawnControlRotation = true; // 마우스로 회전

	// 카메라 생성 및 스프링암에 붙이기
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm); // 스프링암의 끝에 카메라 배치
	Camera->bUsePawnControlRotation = false; // 카메라는 스프링암에 따라감 (직접 회전 X)

	// 캐릭터가 직접 회전하지 않도록
	bUseControllerRotationYaw = false;

	// 기본 이속을 WalkSpeed로 설정
	if (UCharacterMovementComponent* MoveComp = GetCharacterMovement())
	{
		MoveComp->MaxWalkSpeed = WalkSpeed;
		MoveComp->bOrientRotationToMovement = true; // 이동 방향으로 캐릭터 회전
	}
}
void AEmberCharacter::BeginPlay()
{
	Super::BeginPlay();

}

void AEmberCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEmberCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AEmberCharacter::Move);
		EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &AEmberCharacter::Look);
		EnhancedInput->BindAction(AttackAction, ETriggerEvent::Started, this, &AEmberCharacter::Attack);

		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		EnhancedInput->BindAction(SprintAction, ETriggerEvent::Started, this, &AEmberCharacter::StartSprinting);
		EnhancedInput->BindAction(SprintAction, ETriggerEvent::Completed, this, &AEmberCharacter::StopSprinting);

		EnhancedInput->BindAction(PickupAction, ETriggerEvent::Triggered, this, &AEmberCharacter::PickupItem);

	}
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



