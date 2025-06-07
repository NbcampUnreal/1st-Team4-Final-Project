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

ABaseAI::ABaseAI()
{
	StatusComponent = CreateDefaultSubobject<UStatusComponent>(TEXT("Status Component"));
	MontageComponent = CreateDefaultSubobject<UMontageSystemComponent>(TEXT("Montage Component"));
	EquipComponent = CreateDefaultSubobject<UEquipmentManagerComponent>(TEXT("Equip Component"));
	AIState = CreateDefaultSubobject<UC_StateComponent>(TEXT("AI State"));
	BehaviorTreeComponent = CreateDefaultSubobject<UCBehaviorTreeComponent>(TEXT("BehaviorTree Component"));
	MoveComponent = CreateDefaultSubobject<UC_CharacterMovementComponent>(TEXT("Move Component"));
	WeaponComponent = CreateDefaultSubobject<UCAIWeaponComponent>(TEXT("Weapon Component"));
	AIControllerClass = ACAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	WalkSpeed = 200.0f;
	RunSpeed = 700.0f;
}

void ABaseAI::BeginPlay()
{
	Super::BeginPlay();

	//if (ACAIController* AIController = Cast<ACAIController>(GetController()))
	//{
	//	BlackboardComp = AIController->GetBlackboardComponent();
	//}
	//ACAIController* Controller = Cast<ACAIController>(GetController());
	// Perception->OnTargetPerceptionUpdated.AddDynamic(this, &ABaseAI::OnTargetPerceptionUpdated);
	SetWalkSpeed();
}

float ABaseAI::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator,
                          AActor* DamageCauser)
{
	if (!HasAuthority()) return 0;
	float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	
	AIState->SetHittdMode();
	if (AAIController* AIController = Cast<AAIController>(GetController()))
	{
		if (UBlackboardComponent* BlackboardComponent = AIController->GetBlackboardComponent())
		{
			BlackboardComponent->SetValueAsBool("IsHit", true);
			BlackboardComponent->SetValueAsObject("TargetActor", DamageCauser);

			if (!BlackboardComponent->GetValueAsBool("IsOriginLocationSet"))
			{
				BlackboardComponent->SetValueAsVector("OriginLocation", GetActorLocation());
				BlackboardComponent->SetValueAsBool("IsOriginLocationSet", true);
			}
		}
	}

	if (ActualDamage > 0 && !bIsDie)
	{
		CurrentHP -= ActualDamage;
		if (CurrentHP <= 0.f) OnDeath();
	}

	return ActualDamage;
}

void ABaseAI::OnAttack()
{
	// if (AAIController* AIController = Cast<AAIController>(GetController()))
	// {
	// 	if (UBlackboardComponent* BlackboardComponent = AIController ? AIController->GetBlackboardComponent() : nullptr)
	// 	{
	// 		AIState->SetActionMode();
	// 		AActor* TargetActor = Cast<AActor>(BlackboardComponent->GetValueAsObject("TargetActor"));
	// 		if (!TargetActor) return;
	//
	// 		FVector AILocation = GetActorLocation();
	// 		FVector TargetLocation = TargetActor->GetActorLocation();
	//
	// 		float HeightDifference = TargetLocation.Z - AILocation.Z;
	//
	// 		if (UBaseAIAnimInstance* AnimInstance = Cast<UBaseAIAnimInstance>(GetMesh()->GetAnimInstance()))
	// 		{
	// 			if (AnimInstance->CurrentSpeed >= RunSpeed)
	// 			{
	// 				AnimInstance->PlayMontage(EAnimActionType::AttackRun, EAnimActionType::AttackNormal);
	// 			}
	// 			else if (HeightDifference > 100.f)
	// 			{
	// 				AnimInstance->PlayMontage(EAnimActionType::AttackJump, EAnimActionType::AttackNormal);
	// 			}
	// 			else
	// 			{
	// 				AnimInstance->PlayMontage(EAnimActionType::AttackNormal, EAnimActionType::AttackNormal);
	// 			}
	// 		}
	// 	}
	// }
}

void ABaseAI::OnDeath()
{
	UE_LOG(LogTemp, Display, TEXT("OnDeath"));

	AIState->SetDeadMode();
	bIsDie = true;

	//퍼셉션 제거
	// Perception->SetSenseEnabled(UAISense_Sight::StaticClass(), false);

	//이동, 애니메이션 제거
	if (GetController())
	{
		GetController()->StopMovement();
	}

	if (UBaseAIAnimInstance* AnimInstance = Cast<UBaseAIAnimInstance>(GetMesh()->GetAnimInstance()))
	{
		SetWalkSpeed();
		AnimInstance->StopAllMontages(0.0f);
	}
	DetachFromControllerPendingDestroy();
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
	if(BehaviorTree == nullptr)
	{
		UE_LOG(LogTemp, Error, L"Behavior Tree is null");
		return nullptr;
	}
	return BehaviorTree;
}

void ABaseAI::SetWalkSpeed()
{
	GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void ABaseAI::SetRunSpeed()
{
	GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
}

void ABaseAI::SetFlySpeed()
{
	GetCharacterMovement()->SetMovementMode(MOVE_Flying);
	GetCharacterMovement()->MaxFlySpeed = FlySpeed;
	GetCharacterMovement()->GravityScale = 0.0f;
}
