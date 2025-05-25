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
	BlackboardComp = nullptr;

}

void ABaseAI::BeginPlay()
{
	Super::BeginPlay();
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
			BlackboardComponent->SetValueAsVector("OriginLocation", GetActorLocation());
		}
	}

	if (ActualDamage > 0 && !bIsDie)
	{
		CurrentHP -= ActualDamage;
		if (CurrentHP <= 0.f) OnDeath();
	}
	
	return ActualDamage;
}

void ABaseAI::OnDeath()
{
	if (UBaseAIAnimInstance* AnimInstance = Cast<UBaseAIAnimInstance>(GetMesh()->GetAnimInstance()))
	{
		AnimInstance->PlayDeathMontage();
	}
}

void ABaseAI::OnAttack()
{
	if (UBaseAIAnimInstance* AnimInstance = Cast<UBaseAIAnimInstance>(GetMesh()->GetAnimInstance()))
	{
		AnimInstance->PlayAttackMontage();
	}
}

void ABaseAI::OnTargetPerceptionUpdated(AActor* UpdatedActor, FAIStimulus Stimulus)
{
	ABaseAIController* BaseAIController = Cast<ABaseAIController>(Cast<AAIController>(GetController()));
	BlackboardComp = BaseAIController->GetBlackboardComponent();
}

#pragma region Interface

void ABaseAI::SetWalkSpeed()
{
	GetCharacterMovement()->MaxWalkSpeed=WalkSpeed;
}

void ABaseAI::SetRunSpeed()
{
	GetCharacterMovement()->MaxWalkSpeed=RunSpeed;
}

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