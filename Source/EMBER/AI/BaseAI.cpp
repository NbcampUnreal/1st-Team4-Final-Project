#include "BaseAI.h"
#include "BaseAIController.h"
#include "Perception/AIPerceptionComponent.h"
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
		SightConfig->SetMaxAge(5.f); //기억시간
		SightConfig->AutoSuccessRangeFromLastSeenLocation = 500.f; //AI가 마지막으로 본 위치에서 500이내에 있을 경우, 자동으로 감지 성공으로 처리
		SightConfig->DetectionByAffiliation.bDetectEnemies = true; //AI가 적을 감지가능
		SightConfig->DetectionByAffiliation.bDetectNeutrals = true; //AI가 중립을 감지가능
		SightConfig->DetectionByAffiliation.bDetectFriendlies = true; //AI가 아군을 감지가능

		AIPerception->ConfigureSense(*SightConfig); //컴포넌트에 시각감각 추가
	}

	AIControllerClass = ABaseAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	
}

void ABaseAI::BeginPlay()
{
	Super::BeginPlay();
	AIPerception->SetDominantSense(SightConfig->GetSenseImplementation()); //여러 감각중 시각 우선 사용
	AIPerception->OnPerceptionUpdated.AddDynamic(this, &ABaseAI::OnPerceptionUpdated); //감각 업데이트시 OnPerceptionUpdated 함수 호출
}

float ABaseAI::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator,
                          AActor* DamageCauser)
{
	if (!HasAuthority()) return 0;

	float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

<<<<<<< Updated upstream
=======
	AAIController* AIController = Cast<AAIController>(GetController());
	if (AIController)
	{
		UBlackboardComponent* BlackboardComponent = AIController->GetBlackboardComponent();
		if (BlackboardComponent)
		{
			BlackboardComponent->SetValueAsBool("IsHit", true);
			BlackboardComponent->SetValueAsObject("TargetActor", DamageCauser);
			BlackboardComponent->SetValueAsVector("OriginLocation", GetActorLocation());
		}
	}
	
>>>>>>> Stashed changes
	if (ActualDamage > 0 && !bIsDie)
	{
		CurrentHP -= ActualDamage;
		if (CurrentHP <= 0.f) OnDeath();
	}
	return ActualDamage;
}

void ABaseAI::Attack(AActor* Target)
{
	UGameplayStatics::ApplyDamage(Target, AttackPower, GetController(), this, UDamageType::StaticClass());
}

void ABaseAI::OnDeath()
{
}

void ABaseAI::OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors)
{
}

