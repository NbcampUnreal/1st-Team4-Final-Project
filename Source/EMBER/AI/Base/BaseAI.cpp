#include "BaseAI.h"

#include "AnimInstance/BaseAIAnimInstance.h"
#include "CAIController.h"
#include "C_CharacterMovementComponent.h"
#include "C_StateComponent.h"
#include "MontageSystemComponent.h"
#include "StatusComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AI/BehaviorTree/CBehaviorTreeComponent.h"
#include "AIComponent/CAIWeaponComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Managers/EquipmentManagerComponent.h"
#include "GameFramework/GameplayMessageSubsystem.h"
#include "Item/Drop/LootTable.h"
#include "Kismet/KismetMathLibrary.h"
#include "Net/UnrealNetwork.h"

ABaseAI::ABaseAI()
{
	StatusComponent = CreateDefaultSubobject<UStatusComponent>(TEXT("Status Component"));
	MontageComponent = CreateDefaultSubobject<UMontageSystemComponent>(TEXT("Montage Component"));
	EquipComponent = CreateDefaultSubobject<UEquipmentManagerComponent>(TEXT("Equip Component"));
	AIState = CreateDefaultSubobject<UC_StateComponent>(TEXT("AI State"));
	BehaviorTreeComponent = CreateDefaultSubobject<UCBehaviorTreeComponent>(TEXT("BehaviorTree Component"));
	AIMoveComponent = CreateDefaultSubobject<UC_CharacterMovementComponent>(TEXT("Move Component"));
	WeaponComponent = CreateDefaultSubobject<UCAIWeaponComponent>(TEXT("Weapon Component"));
	AIControllerClass = ACAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	// WalkSpeed = 200.0f;
	// RunSpeed = 700.0f;
}

void ABaseAI::BeginPlay()
{
	Super::BeginPlay();
	if (WalkSpeed != 0)
		AIMoveComponent->SetWalkSpeed(WalkSpeed);
	if (RunSpeed != 0)
		AIMoveComponent->SetRunSpeed(RunSpeed);
	if (SprintSpeed != 0)
		AIMoveComponent->SetSprintSpeed(SprintSpeed);
	AIState.Get()->SetIdleMode();
	//if (ACAIController* AIController = Cast<ACAIController>(GetController()))
	//{
	//	BlackboardComp = AIController->GetBlackboardComponent();
	//}
	//ACAIController* Controller = Cast<ACAIController>(GetController());
	// Perception->OnTargetPerceptionUpdated.AddDynamic(this, &ABaseAI::OnTargetPerceptionUpdated);
	// SetWalkSpeed();
}

float ABaseAI::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator,
                          AActor* DamageCauser)
{
	if (StatusComponent->GetHp() <= 0.0f)
		return 0;
	if (!HasAuthority()) 
		return 0;
	float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	if(ActualDamage <= 0.0f)
	{
		UE_LOG(LogTemp, Error, L"Damage is 0");
		return ActualDamage;
	}
//TODOS 작업
	DamageData.Causer = DamageCauser;
	DamageData.Character = Cast<ACharacter>(EventInstigator->GetPawn());
	DamageData.Power = ActualDamage;
	//FActionDamageEvent* event = (FActionDamageEvent*)&DamageEvent;
	//if (event->DamageData->Montages != nullptr)
	//	DamageData.Montage = event->DamageData->Montages;
	//if (event->DamageData->PlayRate)
	//	DamageData.PlayRate = event->DamageData->PlayRate;
	AIState->SetHittdMode();
	MulticastHitted(ActualDamage, DamageEvent, EventInstigator, DamageCauser);

	//if (AAIController* AIController = Cast<AAIController>(GetController()))
	//{
	//	if (UBlackboardComponent* BlackboardComponent = AIController->GetBlackboardComponent())
	//	{
	//		// BlackboardComponent->SetValueAsBool("IsHit", true);
	//		BehaviorTreeComponent->SetBlackboard_Object("TargetActor", EventInstigator->GetOwner());
	//		if (!BlackboardComponent->GetValueAsBool("IsOriginLocationSet"))
	//		{
	//			BehaviorTreeComponent->SetBlackboard_Vector("OriginLocation",GetActorLocation());
	//			BehaviorTreeComponent->SetBlackboard_Bool("IsOriginLocationSet", true);
	//		}
	//	}
	//}

   LastDamageCauser = DamageCauser;

	return ActualDamage;
}

UC_CharacterMovementComponent* ABaseAI::GetAIMovement() const
{
	return AIMoveComponent;
}

void ABaseAI::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABaseAI, DamageData);
}

void ABaseAI::MulticastHitted_Implementation(float Damage, FDamageEvent const& DamageEvent,
	AController* EventInstigator, AActor* DamageCauser)
{
	StatusComponent->Damage(DamageData.Power);
	if (StatusComponent->GetHp() <= 0.0f)
	{
		OnDeath();
		return;
	}
	MontageComponent.Get()->PlayMontage(EStateType::Hitted);
	if (HasAuthority() == true)
	{
		UE_LOG(LogTemp, Error, L"server hp %f", StatusComponent->GetHp());
	}
	else
	{
		UE_LOG(LogTemp, Error, L"hp %f", StatusComponent->GetHp());
	}

	if (DamageData.Character != nullptr)
		SetActorRotation(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), DamageData.Character->GetActorLocation()));

}

void ABaseAI::OnRep_Hitted()
{
	if (DamageData.Character != nullptr)
		SetActorRotation(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), DamageData.Character->GetActorLocation()));
}

void ABaseAI::OnDeath()
{
	UE_LOG(LogTemp, Display, TEXT("OnDeath"));

	AIState->SetDeadMode();
	bIsDie = true;

	//퍼셉션 제거
	// Perception->SetSenseEnabled(UAISense_Sight::StaticClass(), false);

	if (HasAuthority())
	{
		FMonsterDiedMessage DeathMessage;
		DeathMessage.MonsterID = this->MonsterID;
		DeathMessage.DeathLocation = this->GetActorLocation();
		DeathMessage.KillerActor = this->LastDamageCauser;

		if (UWorld* World = GetWorld())
		{
			UGameplayMessageSubsystem& MessageSubsystem = UGameplayMessageSubsystem::Get(World);
			FGameplayTag MessageChannel = FGameplayTag::RequestGameplayTag(FName("Event.Monster.Died")); 
			MessageSubsystem.BroadcastMessage(MessageChannel, DeathMessage);
			UE_LOG(LogTemp, Log, TEXT("[SERVER] ABaseAI: Broadcasted FMonsterDiedMessage for %s"), *MonsterID.ToString());
		}
	}

	//이동, 애니메이션 제거
	if (GetController())
	{
		GetController()->StopMovement();
	}

	MontageComponent->PlayMontage(EStateType::Dead);
	//if (UBaseAIAnimInstance* AnimInstance = Cast<UBaseAIAnimInstance>(GetMesh()->GetAnimInstance()))
	//{
	//	// SetWalkSpeed();
	//	AnimInstance->StopAllMontages(0.0f);
	//}
	DetachFromControllerPendingDestroy();
}

void ABaseAI::EndDeath()
{
	WeaponComponent->DestroyWeapon();
	Destroy();
}

//void ABaseAI::OnTargetPerceptionUpdated(AActor* UpdatedActor, FAIStimulus Stimulus)
//{
//	//TODOS 원상복귀 해야될 수 있음
//	ACAIController* BaseAIController = Cast<ACAIController>(Cast<AAIController>(GetController()));
//	if (BaseAIController == nullptr)
//		BaseAIController = Cast<ACAIController>(GetController());
//	//ABaseAIController* BaseAIController = Cast<ABaseAIController>(Cast<AAIController>(GetController()));
//	BlackboardComp = BaseAIController->GetBlackboardComponent();
//}

UBehaviorTree* ABaseAI::GetBehaviorTree() const
{
	if (BehaviorTree == nullptr)
	{
		UE_LOG(LogTemp, Error, L"Behavior Tree is null");
		return nullptr;
	}
	return BehaviorTree;
}