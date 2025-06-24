// Fill out your copyright notice in the Description page of Project Settings.
#include "EmberPlayerCharacter.h"
#include "EngineUtils.h"
#include "AbilitySystemComponent.h"
#include "ArmorComponent.h"
#include "C_CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "C_CharacterMovementComponent.h"
#include "EmberPlayerState.h"
#include "GameData.h"
#include "StatusComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Managers/EquipmentManagerComponent.h"
#include "..\GameInfo/GameplayTags.h"
#include "EnhancedInputSubsystems.h"
#include "Input/EmberEnhancedInputComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Net/UnrealNetwork.h"
#include "NavigationSystem.h"
#include "TimerManager.h"

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

	Tags.Add("Player");
	SetReplicates(true);
}

// Called when the game starts or when spawned
void AEmberPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Error, L"start max hp %f hp %f ", StatusComponent->GetMaxHp(), StatusComponent->GetHp());
	MovementComponent->OnRun();
	if (StatusComponent->GetMaxHp() <= 0.0f)
		StatusComponent->SetMaxHp(100);
	if (StatusComponent->GetMaxStamina() <= 0.0f)
		StatusComponent->SetMaxStamina(100);
	CameraLogicComp->DisableControlRotation();
	APlayerController* playerController = Cast<APlayerController>(GetController());
	if (playerController != nullptr)
	{
		playerController->PlayerCameraManager->ViewPitchMin = PitchRange.X;
		playerController->PlayerCameraManager->ViewPitchMax = PitchRange.Y;
	}

	//TODOS
	if (ArmorComponent != nullptr)
	{
		if (HasAuthority() == true)
		{
			ArmorComponent->InitializeArmorForLateJoiners();
		}
	}
	
	if (HasAuthority())
	{
		StartPassiveTemperatureDrop();
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

void AEmberPlayerCharacter::SetControlRotation(bool bEnable)
{
	if (bEnable)
	{
		CameraLogicComp->EnableControlRotation();
	}
	else
	{
		CameraLogicComp->DisableControlRotation();
	}
}


void AEmberPlayerCharacter::Input_Move(const FInputActionValue& InputActionValue)
{
	const FVector2D MovementVector = InputActionValue.Get<FVector2D>();

	const FRotator MovementRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);

	if (MovementVector.Y != 0.f)
	{
		const FVector ForwardDirection = MovementRotation.RotateVector(FVector::ForwardVector);

		AddMovementInput(ForwardDirection, MovementVector.Y);
	}

	if (MovementVector.X != 0.f)
	{
		const FVector RightDirection = MovementRotation.RotateVector(FVector::RightVector);

		AddMovementInput(RightDirection, MovementVector.X);
	}
}
void AEmberPlayerCharacter::Input_Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

	if (LookAxisVector.X != 0.f)
	{
		AddControllerYawInput(LookAxisVector.X);
	}

	if (LookAxisVector.Y != 0.f)
	{
		AddControllerPitchInput(LookAxisVector.Y);
	}
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
	if (!InputConfigDataAsset)
	{
		return;
	}
	checkf(InputConfigDataAsset, TEXT("Forgot to assign a valid data asset as input config"));

	CharacterInputComponent->InitializePlayerInput(PlayerInputComponent);

	if (!IsLocallyControlled())
	{
		return;
	}
	APlayerController* PC = Cast<APlayerController>(GetController());
	if (!PC)
	{
		return;
	}
	ULocalPlayer* LocalPlayer = PC->GetLocalPlayer();
	if (!LocalPlayer)
	{
		return;
	}
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	Subsystem->AddMappingContext(InputConfigDataAsset->InputMappingContext, 0);

	UEmberEnhancedInputComponent* WarriorInputComponent = CastChecked<UEmberEnhancedInputComponent>(PlayerInputComponent);

	WarriorInputComponent->BindNativeAction(InputConfigDataAsset, EmberGameplayTags::InputTag_Movement_Move, ETriggerEvent::Triggered, this, &ThisClass::Move);
	WarriorInputComponent->BindNativeAction(InputConfigDataAsset, EmberGameplayTags::InputTag_Movement_Look, ETriggerEvent::Triggered, this, &ThisClass::Look);
	WarriorInputComponent->BindNativeAction(InputConfigDataAsset, EmberGameplayTags::InputTag_Movement_Sprint, ETriggerEvent::Triggered, this, &ThisClass::StartSprint);
	WarriorInputComponent->BindNativeAction(InputConfigDataAsset, EmberGameplayTags::InputTag_Movement_Sprint, ETriggerEvent::Completed, this, &ThisClass::StopSprint);
}

UAbilitySystemComponent* AEmberPlayerCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AEmberPlayerCharacter::Move(const FInputActionValue& value)
{
	int fgdfg = 3;
	if (MovementComponent)
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
		MovementComponent->OnSprint();
	}
}

void AEmberPlayerCharacter::StopSprint(const FInputActionValue& value)
{
	if (GetCharacterMovement())
	{
		MovementComponent->OnRun();
	}
}

void AEmberPlayerCharacter::Attack(const FInputActionValue& value)
{
	// EquipmentComponent에서 현재 무기 타입 가져오기
	FAttackData Data = EquipmentManagerComponent->GetAttackInfo();

	if (!Data.Montages)
	{
		MontageComponent->PlayMontage(Data.Montages);
		if (attackint == 2)
		{
			attackint = 0;
			return;
		}
		attackint++;

	}
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

void AEmberPlayerCharacter::OnLeftClick(const FInputActionValue& Value)
{
	static const FGameplayTag LeftClickTag = EmberGameplayTags::InputTag_Attack_MainHand;
	AbilitySystemComponent->TryActivateAbilitiesByTag(FGameplayTagContainer(LeftClickTag));

}

float AEmberPlayerCharacter::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	if (HasAuthority() == false)
		return 0.0f;

	float damage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	if (damage <= 0.0f)
	{
		UE_LOG(LogTemp, Error, L"Damage is 0");
		return damage;
	}

	//StatusComponent->OnRep_Damage(damage);

	DamageData.Causer = DamageCauser;
	DamageData.Character = Cast<ACharacter>(EventInstigator->GetPawn());
	DamageData.Power = damage;
	//FActionDamageEvent* event = (FActionDamageEvent*)&DamageEvent;
	//DamageData.Montage = event->DamageData->Montages;
	//DamageData.PlayRate = event->DamageData->PlayRate;
	MulticastHitted(damage, DamageEvent, EventInstigator, DamageCauser);

	if (UAbilitySystemComponent* EmberASC = GetAbilitySystemComponent())
	{
		FGameplayEventData Payload;
		Payload.EventTag = EmberGameplayTags::GameplayEvent_HitReact;
		Payload.Target = this;

		FScopedPredictionWindow NewScopedWindow(AbilitySystemComponent, true);
		AbilitySystemComponent->HandleGameplayEvent(Payload.EventTag, &Payload);
	}
	
	return damage;
}

void AEmberPlayerCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AEmberPlayerCharacter, DamageData);
}

void AEmberPlayerCharacter::MulticastHitted_Implementation(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	StatusComponent->Damage(DamageData.Power);
	if (StatusComponent->GetHp() <= 0.0f)
	{
		return;
	}

	// 애니메이션 종료시 캐릭터 상태 관리를 위해 GaemplayAbility에서 애니메이션 재생 구현
	/*
	MontageComponent->PlayMontage(EStateType::Hitted);
	if (HasAuthority() == true)
	{
		UE_LOG(LogTemp, Error, L"server hp %f", StatusComponent->GetHp());
	}
	else
	{
		UE_LOG(LogTemp, Error, L"hp %f", StatusComponent->GetHp());
	}
	*/

	if (DamageData.Character != nullptr)
		SetActorRotation(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), DamageData.Character->GetActorLocation()));
}

void AEmberPlayerCharacter::OnRep_Hitted()
{
	if (DamageData.Character != nullptr)
		SetActorRotation(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), DamageData.Character->GetActorLocation()));
}

void AEmberPlayerCharacter::OnDeath()
{
	MontageComponent->PlayMontage(EStateType::Dead);
}

void AEmberPlayerCharacter::EndDeath()
{
	Destroy();
}

void AEmberPlayerCharacter::ApplyWarmingEffect_Implementation()
{
	if (!HasAuthority()) return;
	
	StopPassiveTemperatureDrop();

	GetWorldTimerManager().SetTimer(WarmingTimerHandle, this, &AEmberPlayerCharacter::OnWarmingTick, 1.0f, true, 0.0f);
    
	UE_LOG(LogTemp, Warning, TEXT("Player entered warming zone. Starting warming timer."));
}

void AEmberPlayerCharacter::RemoveWarmingEffect_Implementation()
{
	if (!HasAuthority()) return;

	GetWorldTimerManager().ClearTimer(WarmingTimerHandle);
	
    StartPassiveTemperatureDrop();

	UE_LOG(LogTemp, Warning, TEXT("Player left warming zone. Clearing warming timer."));
}

void AEmberPlayerCharacter::OnWarmingTick()
{
	if (StatusComponent)
	{
		StatusComponent->AddTemperature(WarmingAmountPerSecond);
		UE_LOG(LogTemp, Log, TEXT("Warming tick: Current Temperature is %f"), StatusComponent->GetTemperature());
	}
}

void AEmberPlayerCharacter::StartPassiveTemperatureDrop()
{
	if (!HasAuthority() || GetWorldTimerManager().IsTimerActive(TemperatureDropTimerHandle)) return;

	GetWorldTimerManager().SetTimer(TemperatureDropTimerHandle, this, &AEmberPlayerCharacter::OnTemperatureDropTick, TemperatureDropInterval, true);
	UE_LOG(LogTemp, Warning, TEXT("Starting passive temperature drop."));
}

void AEmberPlayerCharacter::StopPassiveTemperatureDrop()
{
	if (!HasAuthority()) return;

	GetWorldTimerManager().ClearTimer(TemperatureDropTimerHandle);
	UE_LOG(LogTemp, Warning, TEXT("Stopping passive temperature drop."));
}

void AEmberPlayerCharacter::OnTemperatureDropTick()
{
	if (StatusComponent)
	{
		StatusComponent->UseTemperature(TemperatureDropAmount);
		UE_LOG(LogTemp, Log, TEXT("Passive drop tick: Current Temperature is %f"), StatusComponent->GetTemperature());
	}
}
// 금지 구역(Exclusion Zone) 체크 함수
bool AEmberPlayerCharacter::IsInExclusionZone(const FVector& SpawnLocation)
{
	for (TActorIterator<AActor> It(GetWorld()); It; ++It)
	{
		AActor* Actor = *It;
		if (Actor && Actor->ActorHasTag("AIExclusion"))
		{
			// 볼륨(AVolume)일 경우 EncompassesPoint 사용
			if (Actor->IsA(AVolume::StaticClass()))
			{
				AVolume* Volume = Cast<AVolume>(Actor);
				if (Volume && Volume->EncompassesPoint(SpawnLocation))
				{
					return true;
				}
			}
			else
			{
				// 일반 액터면 컴포넌트 바운딩 박스 사용
				FBox Bounds = Actor->GetComponentsBoundingBox();
				if (Bounds.IsInside(SpawnLocation))
				{
					return true;
				}
			}
		}
	}
	return false;
}
bool AEmberPlayerCharacter::IsInBeginnerZone(const FVector& Location)
{
	for (TActorIterator<AActor> It(GetWorld()); It; ++It)
	{
		AActor* Actor = *It;
		if (Actor && Actor->ActorHasTag("BeginnerZone"))
		{
			// 볼륨이면 EncompassesPoint, 일반 액터면 Bounds
			if (Actor->IsA(AVolume::StaticClass()))
			{
				AVolume* Volume = Cast<AVolume>(Actor);
				if (Volume && Volume->EncompassesPoint(Location))
					return true;
			}
			else
			{
				FBox Bounds = Actor->GetComponentsBoundingBox();
				if (Bounds.IsInside(Location))
					return true;
			}
		}
	}
	return false;
}

// AI 스폰 헬퍼 함수
void AEmberPlayerCharacter::SpawnAI(const TArray<TSubclassOf<APawn>>& AIClasses, const FString& AIType, const FVector& PlayerLocation)
{
	if (AIClasses.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s AI 클래스 배열이 비어 있습니다."), *AIType);
		return;
	}

	UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	if (!NavSys || !NavSys->GetMainNavData())
	{
		UE_LOG(LogTemp, Error, TEXT("네비게이션 시스템 오류!"));
		return;
	}

	int32 Index = FMath::RandRange(0, AIClasses.Num() - 1);
	TSubclassOf<APawn> SelectedClass = AIClasses[Index];

	FVector SpawnLocation;
	bool bFoundValidLocation = false;

	for (int32 j = 0; j < MaxAttempts; ++j)
	{
		FNavLocation NavLoc;
		if (NavSys->GetRandomReachablePointInRadius(PlayerLocation, SpawnRadius, NavLoc))
		{
			SpawnLocation = NavLoc.Location;

			if (!IsInExclusionZone(SpawnLocation))
			{
				// 땅 위로 위치 보정 추가
				SpawnLocation = FindGroundLocation(GetWorld(), SpawnLocation);
				bFoundValidLocation = true;
				break;
			}
		}
	}

	if (!bFoundValidLocation)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s AI: 유효한 스폰 위치를 찾지 못했습니다."), *AIType);
		return;
	}

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	APawn* SpawnedEnemy = GetWorld()->SpawnActor<APawn>(
		SelectedClass,
		SpawnLocation,
		FRotator::ZeroRotator,
		SpawnParams
	);

	if (SpawnedEnemy)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s AI 스폰 성공: %s, 위치: %s"),
			*AIType,
			*SpawnedEnemy->GetName(),
			*SpawnLocation.ToString());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s AI 스폰 실패!"), *AIType);
	}
}
// 소스 파일에 구현
FVector AEmberPlayerCharacter::FindGroundLocation(UWorld* World, const FVector& Start, float TraceDistance)
{
	FHitResult Hit;
	FVector TraceStart = Start + FVector(0, 0, 500); // 위에서 시작
	FVector TraceEnd = Start - FVector(0, 0, TraceDistance); // 아래로 쏨

	FCollisionQueryParams Params;
	Params.bTraceComplex = true;
	Params.AddIgnoredActor(this); // 플레이어 캐릭터 무시

	if (World->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, ECC_WorldStatic, Params))
	{
		return Hit.ImpactPoint;
	}
	// 못 찾으면 원래 위치 반환 (안전장치)
	return Start;
}

void AEmberPlayerCharacter::SpawnRandomEnemy()
{
	if (IsInExclusionZone(GetActorLocation()))
	{
		UE_LOG(LogTemp, Log, TEXT("플레이어가 금지 구역 안에 있습니다. AI 스폰 중지."));
		return;
	}

	// 타입별 목표 수 설정
	const int32 TargetAggressiveCount = 7;
	const int32 TargetDefensiveCount = 3;
	const float CountRadius = 1500.0f;

	FVector MyLocation = GetActorLocation();

	// 타입별 카운트
	int32 AggressiveCount = 0;
	int32 DefensiveCount = 0;

	for (TActorIterator<APawn> It(GetWorld()); It; ++It)
	{
		APawn* Pawn = *It;
		if (!Pawn || Pawn == this) continue;

		for (auto& AIClass : AggressiveAIClasses)
		{
			if (Pawn->IsA(AIClass) && FVector::Dist(MyLocation, Pawn->GetActorLocation()) <= CountRadius)
			{
				AggressiveCount++;
				break;
			}
		}
		for (auto& AIClass : DefensiveAIClasses)
		{
			if (Pawn->IsA(AIClass) && FVector::Dist(MyLocation, Pawn->GetActorLocation()) <= CountRadius)
			{
				DefensiveCount++;
				break;
			}
		}
	}

	// 초보자 구역 안이면 선공 AI는 스폰하지 않음
	int32 MissingAggressive = 0;
	int32 MissingDefensive = 0;
	if (IsInBeginnerZone(MyLocation))
	{
		MissingDefensive = FMath::Max(0, TargetAggressiveCount + TargetDefensiveCount - DefensiveCount);
		UE_LOG(LogTemp, Log, TEXT("초보자 구역: 비선공 AI만 %d마리 스폰 시도"), MissingDefensive);
	}
	else
	{
		MissingAggressive = FMath::Max(0, TargetAggressiveCount - AggressiveCount);
		MissingDefensive = FMath::Max(0, TargetDefensiveCount - DefensiveCount);
		UE_LOG(LogTemp, Log, TEXT("일반 구역: 선공 %d, 비선공 %d 스폰 시도"), MissingAggressive, MissingDefensive);
	}

	// 비선공 AI 스폰
	for (int32 i = 0; i < MissingDefensive; ++i)
	{
		SpawnAI(DefensiveAIClasses, TEXT("비선공"), MyLocation);
	}
	// 일반 구역에서만 선공 AI 스폰
	if (!IsInBeginnerZone(MyLocation))
	{
		for (int32 i = 0; i < MissingAggressive; ++i)
		{
			SpawnAI(AggressiveAIClasses, TEXT("선공"), MyLocation);
		}
	}
}

void AEmberPlayerCharacter::DestroyFarAIs()
{
	FVector PlayerLocation = GetActorLocation();
	TArray<APawn*> AIsToDestroy;
	const float CountRadius = 1500.0f;
	// 1. 삭제 대상 AI 수집
	for (TActorIterator<APawn> It(GetWorld()); It; ++It)
	{
		APawn* Pawn = *It;
		if (!Pawn || Pawn == this) continue;

		// 관리 대상 AI인지 확인 (선공/비선공)
		bool bIsOurAI = false;
		for (auto& AIClass : AggressiveAIClasses)
		{
			if (Pawn->IsA(AIClass))
			{
				bIsOurAI = true;
				break;
			}
		}
		if (!bIsOurAI)
		{
			for (auto& AIClass : DefensiveAIClasses)
			{
				if (Pawn->IsA(AIClass))
				{
					bIsOurAI = true;
					break;
				}
			}
		}
		if (!bIsOurAI) continue;

		// 거리 체크
		float Distance = FVector::Dist(PlayerLocation, Pawn->GetActorLocation());
		if (Distance > CountRadius)
		{
			AIsToDestroy.Add(Pawn);
		}
	}

	// 2. 수집된 AI 삭제
	for (APawn* Pawn : AIsToDestroy)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Destroyed: %s (Distance: %.0f)"),
			*Pawn->GetName(),
			FVector::Dist(PlayerLocation, Pawn->GetActorLocation()));
		Pawn->Destroy();
	}
}
