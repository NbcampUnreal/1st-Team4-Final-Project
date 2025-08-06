// Fill out your copyright notice in the Description page of Project Settings.


#include "EmberCharacter.h"

#include "AI/MonsterAIController.h"
#include "Item/BaseItem.h"
#include "Item/RuneItem.h"
#include "assert.h"
#include "Utility/CHelpers.h"
#include "Utility/CLog.h"
#include "AbilitySystemComponent.h"
#include "EmberPlayerController.h"
#include "EmberPlayerState.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "Component/CustomCameraComponent.h"
#include "Component/CustomMoveComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Component/WeaponComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GAS/Attribute/EmberAS_Player.h"
#include "Item/Drop/PickupItemActor.h"

// Sets default values
AEmberCharacter::AEmberCharacter()
{
	ASC == nullptr;
	PrimaryActorTick.bCanEverTick = true;

	CHelpers::CreateComponent(this, &SpringArm, "SpringArm", RootComponent);
	SpringArm->TargetArmLength = 300.f; // ī�޶� �Ÿ�
	SpringArm->bUsePawnControlRotation = true; // ���콺�� ȸ��
	SpringArm->bDoCollisionTest = false;
	
	CHelpers::CreateComponent(this, &Camera,"Camera", SpringArm);
	Camera->bUsePawnControlRotation = false; // ī�޶�� �������Ͽ� ���� (���� ȸ�� X)

	CHelpers::CreateActorComponent(this, &MoveComponent, "Movement Component");
	CHelpers::CreateActorComponent(this, &CameraComponent, "Camera Component");
	CHelpers::CreateActorComponent(this, &WeaponComponent, "Weapon Component");

	bUseControllerRotationYaw = false;
	
	GetCharacterMovement()->bOrientRotationToMovement = true;// �̵� �������� ĳ���� ȸ��

	PickupSphere = CreateDefaultSubobject<USphereComponent>(TEXT("PickupSphere"));
	PickupSphere->SetupAttachment(RootComponent);
	PickupSphere->SetSphereRadius(200.f); // 원하는 감지 반경 설정
	PickupSphere->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	PickupSphere->SetGenerateOverlapEvents(true);
	PickupSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	PickupSphere->SetCollisionObjectType(ECC_WorldDynamic);
	PickupSphere->SetCollisionResponseToAllChannels(ECR_Ignore);
	PickupSphere->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap); // 추가
	PickupSphere->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore); // 필요 시 무시
}
void AEmberCharacter::BeginPlay()
{
	TemperatureLeve = 1.0f;
	Super::BeginPlay();
	MoveComponent->OnWalk();

	PickupSphere->OnComponentBeginOverlap.AddDynamic(this, &AEmberCharacter::OnPickupBeginOverlap);
	PickupSphere->OnComponentEndOverlap.AddDynamic(this, &AEmberCharacter::OnPickupEndOverlap);
	DrawDebugSphere(GetWorld(), PickupSphere->GetComponentLocation(), PickupSphere->GetScaledSphereRadius(), 32, FColor::Green, false, 5.f);

}

void AEmberCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	TObjectPtr<APlayerController> controller = CastChecked<APlayerController>(NewController);
	controller->ConsoleCommand(TEXT("showdebug abilitysystem"));
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

	for (const TSubclassOf<UGameplayAbility>& inputAbility : InputAbilities)
	{
		FGameplayAbilitySpec spec(inputAbility);
		ASC->GiveAbility(spec);
	}
	for (const auto& gameAbility : GameAbilities)
	{
		FGameplayAbilitySpec spec(gameAbility.Value);
		spec.InputID = gameAbility.Key;
		ASC->GiveAbility(spec);
	}
	
	SetupGASInputComponent();
	UEmberAS_Player* as = Cast<UEmberAS_Player>(state->GetAttributeSet());
	if (as != nullptr)
		as->OnHitPlayer.AddDynamic(this,&AEmberCharacter::HitPlayer);
}


FGenericTeamId AEmberCharacter::GetGenericTeamId() const
{
	return FGenericTeamId((uint8)EGameTeamID::Team1);
}

void AEmberCharacter::HitPlayer()
{
	AEmberPlayerState* state = Cast<AEmberPlayerState>(GetPlayerState());
	UEmberAS_Player* as = Cast<UEmberAS_Player>(state->GetAttributeSet());
	if (as->GetHealth() <= 0)
		Dead();
	else
		PlayAnimMontage(montage);
}

void AEmberCharacter::Dead()
{
	Destroy();
}

void AEmberCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEmberCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (!EnhancedInput)
	{
		DebugLogE("Enhanced Input is null");
		return;
	}

	PlayerController = Cast<AEmberPlayerController>(GetController());
	if (!PlayerController)
	{
		DebugLogE("PlayerController is null");
		return;
	}

	// 일반 액션 바인딩
	EnhancedInput->BindAction(PlayerController->MoveAction, ETriggerEvent::Triggered, MoveComponent.Get(), &UCustomMoveComponent::Move);
	EnhancedInput->BindAction(PlayerController->LookAction, ETriggerEvent::Triggered, CameraComponent.Get(), &UCustomCameraComponent::Look);

	// ✅ 여기에서 F키(PickupItem) 바인딩
	EnhancedInput->BindAction(PlayerController->InteractAction, ETriggerEvent::Started, this, &AEmberCharacter::PickupItem);

	// GAS 입력 제거: 일반 방식이므로 아래 2줄 삭제 또는 주석처리
	// EnhancedInput->BindAction(PlayerController->InteractAction, ETriggerEvent::Triggered, this, &AEmberCharacter::GASInputPressed, 2);
	// EnhancedInput->BindAction(PlayerController->InteractAction, ETriggerEvent::Completed, this, &AEmberCharacter::GASInputReleased, 2);
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
		input->BindAction(PlayerController.Get()->AttackAction, ETriggerEvent::Triggered, this, &AEmberCharacter::GASInputPressed, 2);
	}
}

void AEmberCharacter::GASInputPressed(int32 Input)
{
	UE_LOG(LogTemp, Warning, TEXT("=== GASInputPressed Called, Input: %d ==="), Input);

	FGameplayAbilitySpec* spec = ASC->FindAbilitySpecFromInputID(Input);
	if (spec != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Spec Found, IsActive: %s"), spec->IsActive() ? TEXT("True") : TEXT("False"));
		UE_LOG(LogTemp, Warning, TEXT("InputPressed was: %s"), spec->InputPressed ? TEXT("True") : TEXT("False"));

		spec->InputPressed = true;
		if (spec->IsActive() == true)
		{
			UE_LOG(LogTemp, Warning, TEXT("Calling AbilitySpecInputPressed"));
			ASC->AbilitySpecInputPressed(*spec);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Calling TryActivateAbility"));
			ASC->TryActivateAbility(spec->Handle);
		}
	}
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

void AEmberCharacter::DamageTemperature()
{
	Count++;
	if (MaxCount == Count)
	{
		TemperatureLeve++;
		FMath::Clamp(TemperatureLeve,1,3);
		Count = 0;
	}

	FGameplayEffectContextHandle contextHandle = ASC->MakeEffectContext();
	if (contextHandle.IsValid() == false)
	{
		DebugLogE("contexHandle is not found");
		return;
	}
	contextHandle.AddSourceObject(this);
	FGameplayEffectSpecHandle specHandle = ASC->MakeOutgoingSpec(GETemperature,TemperatureLeve,contextHandle);
	if (specHandle.IsValid())
	{
		ASC->BP_ApplyGameplayEffectSpecToSelf(specHandle);
	}
}

UAbilitySystemComponent* AEmberCharacter::GetAbilitySystemComponent() const
{
	return ASC;
}

void AEmberCharacter::Attack()
{
	UE_LOG(LogTemp, Warning, TEXT("Attack triggered!"));
}

//void AEmberCharacter::PickupItem()
//{
//	FVector Start = Camera->GetComponentLocation() + Camera->GetForwardVector() * 30.f;
//	FRotator ControlRot = GetControlRotation();
//	FVector Direction = ControlRot.Vector();
//	float Distance = InteractDistance;
//	FVector End = Start + Direction * Distance;
//	float ActualDist = FVector::Distance(Start, End);
//
//	// 디버그 로그
//	UE_LOG(LogTemp, Warning, TEXT("==== PickupItem Debug ===="));
//	UE_LOG(LogTemp, Warning, TEXT("Start         : %s"), *Start.ToString());
//	UE_LOG(LogTemp, Warning, TEXT("End           : %s"), *End.ToString());
//	UE_LOG(LogTemp, Warning, TEXT("Direction     : %s"), *Direction.ToString());
//	UE_LOG(LogTemp, Warning, TEXT("Control Rot   : %s"), *ControlRot.ToString());
//	UE_LOG(LogTemp, Warning, TEXT("Actual Length : %.2f"), ActualDist);
//
//	// 시각적 디버그
//	DrawDebugDirectionalArrow(GetWorld(), Start, End, 150.0f, FColor::Red, false, 5.0f, 0, 3.0f);
//	DrawDebugSphere(GetWorld(), Start, 10.f, 12, FColor::Green, false, 5.0f);
//	DrawDebugSphere(GetWorld(), End, 10.f, 12, FColor::Blue, false, 5.0f);
//
//	// 라인트레이스
//	FHitResult HitResult;
//	FCollisionQueryParams Params;
//	Params.AddIgnoredActor(this);
//	if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, Params))
//	{
//		AActor* HitActor = HitResult.GetActor();
//		UE_LOG(LogTemp, Warning, TEXT("LineTrace HIT!"));
//		if (HitActor)
//		{
//			UE_LOG(LogTemp, Warning, TEXT("Hit Actor     : %s"), *HitActor->GetName());
//		}
//		else
//		{
//			UE_LOG(LogTemp, Warning, TEXT("Hit Actor     : nullptr"));
//		}
//		UE_LOG(LogTemp, Warning, TEXT("Impact Point  : %s"), *HitResult.ImpactPoint.ToString());
//		UE_LOG(LogTemp, Warning, TEXT("Impact Normal : %s"), *HitResult.ImpactNormal.ToString());
//		UE_LOG(LogTemp, Warning, TEXT("Hit Bone Name : %s"), *HitResult.BoneName.ToString());
//
//		// 룬인지 먼저 체크
//		if (ARuneItem* Rune = Cast<ARuneItem>(HitActor))
//		{
//			UE_LOG(LogTemp, Warning, TEXT("==> Rune Interacted: %s"), *Rune->GetName());
//			Rune->Use(this); // 내부에서 TryEquipRune 호출
//		}
//		// 일반 아이템
//		else if (ABaseItem* Item = Cast<ABaseItem>(HitActor))
//		{
//			UE_LOG(LogTemp, Warning, TEXT("==> Base Item Interacted: %s"), *Item->GetName());
//			Item->Use(this);
//		}
//		else if (APickupItemActor* Pickup = Cast<APickupItemActor>(HitActor))
//		{
//			UE_LOG(LogTemp, Warning, TEXT("==> PickupItemActor Interacted: %s"), *Pickup->GetName());
//			Pickup->OnPickedUp(this); // 캐릭터 넘겨서 처리
//		}
//	}
//	else
//	{
//		UE_LOG(LogTemp, Warning, TEXT("LineTrace MISS — nothing hit."));
//	}
//}
void AEmberCharacter::PickupItem()
{
	DrawDebugSphere(GetWorld(), PickupSphere->GetComponentLocation(), PickupSphere->GetScaledSphereRadius(), 32, FColor::Green, false, 5.f);
	if (OverlappingItems.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("PickupItem - No overlapping items."));
		return;
	}

	// 가장 가까운 아이템 선택
	APickupItemActor* ClosestItem = nullptr;
	float MinDistSq = TNumericLimits<float>::Max();
	FVector MyLoc = GetActorLocation();

	for (APickupItemActor* Item : OverlappingItems)
	{
		if (!IsValid(Item)) continue;

		float DistSq = FVector::DistSquared(MyLoc, Item->GetActorLocation());
		if (DistSq < MinDistSq)
		{
			MinDistSq = DistSq;
			ClosestItem = Item;
		}
	}

	if (ClosestItem)
	{
		UE_LOG(LogTemp, Warning, TEXT("Picking up item: %s"), *ClosestItem->GetName());
		ClosestItem->OnPickedUp(this);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PickupItem - No valid closest item found."));
	}
}

bool AEmberCharacter::TryEquipRune(ARuneItem* NewRune)
{
	if (!RuneSystem || !NewRune)
		return false;

	// 비어 있는 슬롯 먼저 탐색
	for (int32 i = 0; i < RuneSystem->GetMaxRuneSlots(); ++i)
	{
		if (!RuneSystem->GetRune(i))
		{
			return RuneSystem->EquipRune(NewRune, i);
		}
	}

	// 빈 슬롯 없으면 비교해서 교체 가능한지 확인
	for (int32 i = 0; i < RuneSystem->GetMaxRuneSlots(); ++i)
	{
		if (RuneSystem->IsBetterRune(i, NewRune))
		{
			return RuneSystem->EquipRune(NewRune, i);
		}
	}

	UE_LOG(LogTemp, Log, TEXT("[Character] No slot available or new rune is not better."));
	return false;
}

void AEmberCharacter::OnPickupBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("OnPickupBeginOverlap Called with %s"), *OtherActor->GetName());

	if (APickupItemActor* Item = Cast<APickupItemActor>(OtherActor))
	{
		if (!OverlappingItems.Contains(Item))
		{
			OverlappingItems.Add(Item);
			UE_LOG(LogTemp, Warning, TEXT("PickupItem: %s overlapped!"), *Item->GetName());
		}
	}
}

void AEmberCharacter::OnPickupEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (APickupItemActor* Item = Cast<APickupItemActor>(OtherActor))
	{
		OverlappingItems.Remove(Item);
		// UI 제거 처리 등
	}
}
