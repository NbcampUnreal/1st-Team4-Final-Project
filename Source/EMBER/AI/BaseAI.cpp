#include "BaseAI.h"
#include "BaseAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "kismet/GameplayStatics.h"


ABaseAI::ABaseAI()
{
	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));

	if (SightConfig)
	{
		SightConfig->SightRadius = 1000.f;
		SightConfig->LoseSightRadius = 1200.f;
		SightConfig->PeripheralVisionAngleDegrees = 90.f; //시야각
		SightConfig->SetMaxAge(5.f); //기억시간
		SightConfig->AutoSuccessRangeFromLastSeenLocation = 500.f; //AI가 마지막으로 본 위치에서 500이내에 있을 경우, 자동으로 감지 성공으로 처리
		SightConfig->DetectionByAffiliation.bDetectEnemies = true; //AI가 적을 감지가능
		SightConfig->DetectionByAffiliation.bDetectNeutrals = true; //AI가 중립을 감지가능
		SightConfig->DetectionByAffiliation.bDetectFriendlies = true; //AI가 아군을 감지가능

		AIPerception->ConfigureSense(*SightConfig); //컴포넌트에 시각감각 추가
	}
	
	AIPerception->SetDominantSense(SightConfig->GetSenseImplementation()); //여러 감각중 시각 우선 사용
	AIPerception->OnPerceptionUpdated.AddDynamic(this, &ABaseAI::OnPerceptionUpdated); //감각 업데이트시 OnPerceptionUpdated 함수 호출
}

void ABaseAI::BeginPlay()
{
	Super::BeginPlay();

	AIControllerClass = ABaseAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

float ABaseAI::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
                          AActor* DamageCauser)
{
	if (!HasAuthority()) return 0;

	float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	AAIController* AIController = Cast<AAIController>(GetController());
	if (AIController)
	{
		UBlackboardComponent* BlackboardComponent = AIController->GetBlackboardComponent();
		if (BlackboardComponent)
		{
			BlackboardComponent->SetValueAsBool("IsAttacked", true);
			BlackboardComponent->SetValueAsObject("Attacker", DamageCauser);
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

void ABaseAI::Attack(AActor* Target)
{
	UGameplayStatics::ApplyDamage(Target, AttackPower, GetController(), this, UDamageType::StaticClass());
}

void ABaseAI::OnDeath()
{
}

void ABaseAI::OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors)
{
	// 감지된 객체 처리 로직 추가 가능
	for (AActor* Actor : UpdatedActors)
	{
		UE_LOG(LogTemp, Warning, TEXT("Boar perceived: %s"), *Actor->GetName());
	}

}
