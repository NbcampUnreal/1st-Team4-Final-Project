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
#include "Component/MontageComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Component/WeaponComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GAS/EmberAbilitySystemComponent.h"
#include "GAS/Attribute/EmberAS_Player.h"
#include "Item/Drop/PickupItemActor.h"
#include "Utility/EmberGameplayTags.h"

// Sets default values
AEmberCharacter::AEmberCharacter()
{
	//ASC == nullptr;
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
	CHelpers::CreateActorComponent<UMontageComponent>(this, &MontageComponent, "Montage Component");

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

	QuickSlotComponent = CreateDefaultSubobject<UQuickSlotComponent>(TEXT("QuickSlotComponent"));

}
void AEmberCharacter::BeginPlay()
{
	TemperatureLeve = 1.0f;
	Super::BeginPlay();
	MoveComponent->OnWalk();
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

	ASC = Cast< UEmberAbilitySystemComponent>(state->GetAbilitySystemComponent());
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
		as->OnOutOfHealth.AddUObject(this,&AEmberCharacter::Dead);
}


FGenericTeamId AEmberCharacter::GetGenericTeamId() const
{
	return FGenericTeamId((uint8)EGameTeamID::Team1);
}

void AEmberCharacter::Dead(AActor* DamageInstigator, AActor* DamageCauser, const FGameplayEffectSpec* DamageEffectSpec, 
	float DamageMagnitude, float OldValue, float NewValue)
{
	FGameplayEventData Payload;
	Payload.EventTag = EmberGameplayTags::GameplayEvent_Death;
	Payload.Instigator = DamageInstigator;
	Payload.Target = ASC->GetAvatarActor();
	Payload.EventMagnitude = DamageMagnitude;

	ASC->HandleGameplayEvent(Payload.EventTag, &Payload);
}

void AEmberCharacter::SetIgnoreCollision(bool bIgnore)
{
	
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
	EnhancedInput->BindAction(PlayerController->Quick1Action, ETriggerEvent::Started, this, &AEmberCharacter::UseQuickSlot1);
	EnhancedInput->BindAction(PlayerController->Quick2Action, ETriggerEvent::Started, this, &AEmberCharacter::UseQuickSlot2);
	EnhancedInput->BindAction(PlayerController->Quick3Action, ETriggerEvent::Started, this, &AEmberCharacter::UseQuickSlot3);
	EnhancedInput->BindAction(PlayerController->Quick4Action, ETriggerEvent::Started, this, &AEmberCharacter::UseQuickSlot4);
	EnhancedInput->BindAction(PlayerController->Quick5Action, ETriggerEvent::Started, this, &AEmberCharacter::UseQuickSlot5);
	//  여기에서 F키(PickupItem) 바인딩
	EnhancedInput->BindAction(PlayerController->InteractAction, ETriggerEvent::Started, this, &AEmberCharacter::PickupItem);

	SetupGASInputComponent();
}
void AEmberCharacter::UseQuickSlot1() { UseQuickSlot(0); }
void AEmberCharacter::UseQuickSlot2() { UseQuickSlot(1); }
void AEmberCharacter::UseQuickSlot3() { UseQuickSlot(2); }
void AEmberCharacter::UseQuickSlot4() { UseQuickSlot(3); }
void AEmberCharacter::UseQuickSlot5() { UseQuickSlot(4); }

void AEmberCharacter::UseQuickSlot(int32 Index)
{
	if (!QuickSlotComponent) return;

	if (HasAuthority())
	{
		QuickSlotComponent->UseQuickSlot(Index);          // ✅ 네가 만든 함수 재사용
	}
	else
	{
		Server_UseQuickSlot(Index);                       // ✅ 서버로 권한 위임
	}
}

void AEmberCharacter::Server_UseQuickSlot_Implementation(int32 Index)
{
	if (QuickSlotComponent)
		QuickSlotComponent->UseQuickSlot(Index);          // ✅ 서버에서 실행
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
		input->BindAction(PlayerController.Get()->Avoid, ETriggerEvent::Triggered, this, &AEmberCharacter::GASInputPressed, 3);
		input->BindAction(PlayerController.Get()->JumpAction, ETriggerEvent::Completed,this,&AEmberCharacter::GASInputReleased, 3);
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
		FMath::Clamp(TemperatureLeve, 1, 3);
		Count = 0;
	}

	FGameplayEffectContextHandle contextHandle = ASC->MakeEffectContext();
	if (contextHandle.IsValid() == false)
	{
		DebugLogE("contexHandle is not found");
		return;
	}
	contextHandle.AddSourceObject(this);
	FGameplayEffectSpecHandle specHandle = ASC->MakeOutgoingSpec(GETemperature, TemperatureLeve, contextHandle);
	if (specHandle.IsValid())
	{
		ASC->BP_ApplyGameplayEffectSpecToSelf(specHandle);
	}
}

//UAbilitySystemComponent* AEmberCharacter::GetAbilitySystemComponent() const
//{
//	return ASC;
//}

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
void AEmberCharacter::Server_PickupItem_Implementation(APickupItemActor* TargetItem)
{
	if (TargetItem && HasAuthority())
	{
		TargetItem->OnPickedUp(this); // 서버에서만 실행
	}
}
void AEmberCharacter::Server_RequestInteraction_Implementation(UInteractionComponent* TargetInteraction)
{
	if (TargetInteraction)
	{
		TargetInteraction->Interact(this); // 서버에서 다시 실행
	}
}

void AEmberCharacter::PickupItem()
{
	DrawDebugSphere(GetWorld(), PickupSphere->GetComponentLocation(), PickupSphere->GetScaledSphereRadius(), 32, FColor::Green, false, 5.f);

	if (OverlappingItems.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("PickupItem - No overlapping items."));
		return;
	}

	APickupItemActor* FocusedItem = nullptr;
	float BestDot = -1.f;

	const FVector ViewLocation = Camera->GetComponentLocation();
	const FVector ViewDirection = Camera->GetForwardVector();

	for (APickupItemActor* Item : OverlappingItems)
	{
		if (!IsValid(Item)) continue;

		const FVector ToItem = (Item->GetActorLocation() - ViewLocation).GetSafeNormal();
		const float Dot = FVector::DotProduct(ViewDirection, ToItem);

		if (Dot > BestDot)
		{
			BestDot = Dot;
			FocusedItem = Item;
		}
	}

	if (FocusedItem)
	{
		UE_LOG(LogTemp, Warning, TEXT("Requesting pickup of item: %s"), *FocusedItem->GetName());

		// ✅ 서버에 요청
		Server_PickupItem(FocusedItem);

		// ✅ 로컬에서 UI, 사운드 등 처리
		OverlappingItems.Remove(FocusedItem);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PickupItem - No item in focus."));
	}
}


bool AEmberCharacter::TryEquipRune(const URuneItemTemplate* NewRuneTemplate)
{
	if (!RuneSystem || !NewRuneTemplate)
		return false;

	// ✅ 비교 UI 호출
	ShowRuneComparisonUI(NewRuneTemplate);

	return true;
}


void AEmberCharacter::ShowRuneComparisonUI(const URuneItemTemplate* NewRuneTemplate)
{
	if (!NewRuneTemplate || !RuneSystem) return;

	const FRuneStat& NewStat = NewRuneTemplate->RuneStat;
	const FRuneStat& CurrentStat = RuneSystem->GetRuneStatAtSlot(0);

	UE_LOG(LogTemp, Log, TEXT("현재 룬 - Power: %.1f, CDR: %.1f, Element: %s"),
		CurrentStat.Power, CurrentStat.CooldownReduction, *CurrentStat.Element);

	UE_LOG(LogTemp, Log, TEXT("새 룬   - Power: %.1f, CDR: %.1f, Element: %s"),
		NewStat.Power, NewStat.CooldownReduction, *NewStat.Element);

	// UI 연결 예정 지점 (예: Widget에 넘기기)
	//UE_LOG(LogTemp, Warning, TEXT("New Rune Name: %s"), *NewRuneTemplate->RuneName.ToString());
}


UQuickSlotComponent* AEmberCharacter::GetQuickSlotComponent() const
{
	return QuickSlotComponent;
}

void AEmberCharacter::AddOverlappingItem(APickupItemActor* Item)
{
	if (!OverlappingItems.Contains(Item))
	{
		OverlappingItems.Add(Item);
	}
}

void AEmberCharacter::RemoveOverlappingItem(APickupItemActor* Item)
{
	OverlappingItems.Remove(Item);
}
APickupItemActor* AEmberCharacter::GetFocusedPickupItem() const
{
	if (OverlappingItems.Num() == 0) return nullptr;

	const FVector ViewLocation = Camera->GetComponentLocation();
	const FVector ViewDirection = Camera->GetForwardVector();

	APickupItemActor* ClosestItem = nullptr;
	float BestDot = -1.f;

	for (APickupItemActor* Item : OverlappingItems)
	{
		if (!IsValid(Item)) continue;

		const FVector ToItem = (Item->GetActorLocation() - ViewLocation).GetSafeNormal();
		const float Dot = FVector::DotProduct(ViewDirection, ToItem); // 카메라 정면과 얼마나 일치하는지

		if (Dot > BestDot)
		{
			BestDot = Dot;
			ClosestItem = Item;
		}
	}

	return ClosestItem;
}