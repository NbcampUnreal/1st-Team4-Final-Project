#include "BaseAI.h"

#include "BaseAIAnimInstance.h"
#include "BaseAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "kismet/GameplayStatics.h"


ABaseAI::ABaseAI()
{
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
}

void ABaseAI::BeginPlay()
{
	Super::BeginPlay();
	AIPerception->OnTargetPerceptionUpdated.AddDynamic(this, &ABaseAI::OnTargetPerceptionUpdated);
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

void ABaseAI::PlayAttackAnimation()
{
	if (UBaseAIAnimInstance* AnimInstance = Cast<UBaseAIAnimInstance>(GetMesh()->GetAnimInstance()))
	{
		AnimInstance->PlayAttackMontage();
	}
}

void ABaseAI::OnDeath()
{
}

void ABaseAI::OnTargetPerceptionUpdated(AActor* UpdatedActor, FAIStimulus Stimulus)
{
}


