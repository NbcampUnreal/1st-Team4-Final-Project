#include "BaseAI.h"

#include "AnimInstance/BaseAIAnimInstance.h"
#include "BaseAIController.h"
#include "MontageSystemComponent.h"
#include "StatusComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Managers/EquipmentManagerComponent.h"


ABaseAI::ABaseAI()
{
	StatusComponent = CreateDefaultSubobject<UStatusComponent>(TEXT("Status Component"));
	MontageComponent = CreateDefaultSubobject<UMontageSystemComponent>(TEXT("Montage Component"));
	EquipComponent = CreateDefaultSubobject<UEquipmentManagerComponent>(TEXT("Equip Component"));
	AnimalState = EAnimalState::Idle;
	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));

	if (SightConfig)
	{
		SightConfig->SightRadius = 2000.f;
		SightConfig->LoseSightRadius = 2400.f;
		SightConfig->PeripheralVisionAngleDegrees = 90.f; //시야각
		SightConfig->SetMaxAge(0.f); //기억시간
		SightConfig->AutoSuccessRangeFromLastSeenLocation = 0.f; //AI가 마지막으로 본 위치에서 0이내에 있을 경우, 자동으로 감지 성공으로 처리
		SightConfig->DetectionByAffiliation.bDetectEnemies = true; //AI가 적을 감지가능
		SightConfig->DetectionByAffiliation.bDetectNeutrals = true; //AI가 중립을 감지가능
		SightConfig->DetectionByAffiliation.bDetectFriendlies = true; //AI가 아군을 감지가능

		AIPerception->ConfigureSense(*SightConfig); //컴포넌트에 시각감각 추가
	}

	AIControllerClass = ABaseAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	AIPerception->SetDominantSense(SightConfig->GetSenseImplementation()); //여러 감각중 시각 우선 사용

	WalkSpeed = 200.0f;
	RunSpeed = 700.0f;
}

void ABaseAI::BeginPlay()
{
	Super::BeginPlay();

	if (ABaseAIController* AIController = Cast<ABaseAIController>(GetController()))
	{
		BlackboardComp = AIController->GetBlackboardComponent();
	}

	AIPerception->OnTargetPerceptionUpdated.AddDynamic(this, &ABaseAI::OnTargetPerceptionUpdated);
	SetWalkSpeed();
}

float ABaseAI::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator,
                          AActor* DamageCauser)
{
	if (!HasAuthority()) return 0;
	float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

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
	if (AAIController* AIController = Cast<AAIController>(GetController()))
	{
		if (UBlackboardComponent* BlackboardComponent = AIController ? AIController->GetBlackboardComponent() : nullptr)
		{
			AActor* TargetActor = Cast<AActor>(BlackboardComponent->GetValueAsObject("TargetActor"));
			if (!TargetActor) return;

			FVector AILocation = GetActorLocation();
			FVector TargetLocation = TargetActor->GetActorLocation();

			float HeightDifference = TargetLocation.Z - AILocation.Z;

			if (UBaseAIAnimInstance* AnimInstance = Cast<UBaseAIAnimInstance>(GetMesh()->GetAnimInstance()))
			{
				if (AnimInstance->CurrentSpeed >= RunSpeed)
				{
					AnimInstance->PlayMontage(EAnimActionType::AttackRun, EAnimActionType::AttackNormal);
				}
				else if (HeightDifference > 100.f)
				{
					AnimInstance->PlayMontage(EAnimActionType::AttackJump, EAnimActionType::AttackNormal);
				}
				else
				{
					AnimInstance->PlayMontage(EAnimActionType::AttackNormal, EAnimActionType::AttackNormal);
				}
			}
		}
	}
}

void ABaseAI::OnDeath()
{
	UE_LOG(LogTemp, Display, TEXT("OnDeath"));

	bIsDie = true;

	//퍼셉션 제거
	AIPerception->SetSenseEnabled(UAISense_Sight::StaticClass(), false);

	//이동, 애니메이션 제거
	if (GetController())
	{
		GetController()->StopMovement();
	}

	if (UBaseAIAnimInstance* AnimInstance = Cast<UBaseAIAnimInstance>(GetMesh()->GetAnimInstance()))
	{
		AnimalState = EAnimalState::Death;
		AnimInstance->StopAllMontages(0.0f);
		AnimInstance->AnimalState = EAnimalState::Death;
		AnimInstance->PlayMontage();
	}
	DetachFromControllerPendingDestroy();
}

void ABaseAI::OnTargetPerceptionUpdated(AActor* UpdatedActor, FAIStimulus Stimulus)
{
	ABaseAIController* BaseAIController = Cast<ABaseAIController>(Cast<AAIController>(GetController()));
	BlackboardComp = BaseAIController->GetBlackboardComponent();
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
}

#pragma region Interface

void ABaseAI::SetBlackboardBool(FName KeyName, bool bValue)
{
	BlackboardComp->SetValueAsBool(KeyName, bValue);
}

void ABaseAI::SetBlackboardInt(FName KeyName, int value)
{
	BlackboardComp->SetValueAsInt(KeyName, value);
}

void ABaseAI::SetBlackboardFloat(FName KeyName, float value)
{
	BlackboardComp->SetValueAsFloat(KeyName, value);
}

void ABaseAI::SetBlackboardVector(FName KeyName, FVector value)
{
	BlackboardComp->SetValueAsVector(KeyName, value);
}

void ABaseAI::SetBlackboardObject(FName KeyName, UObject* object)
{
	BlackboardComp->SetValueAsObject(KeyName, object);
}
#pragma endregion
