#include "AI/PassiveAI.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"

APassiveAI::APassiveAI()
{
	AnimalType = EAnimalType::Passive;

	RunPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("RunPerception"));
	RunSightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("RunSightConfig"));


	if (RunSightConfig)
	{
		RunSightConfig->SightRadius = 1000.f;
		RunSightConfig->LoseSightRadius = 1200.f;
		RunSightConfig->PeripheralVisionAngleDegrees = 90.f; //시야각
		RunSightConfig->SetMaxAge(5.f); //기억시간
		RunSightConfig->AutoSuccessRangeFromLastSeenLocation = 500.f; //AI가 마지막으로 본 위치에서 500이내에 있을 경우, 자동으로 감지 성공으로 처리
		RunSightConfig->DetectionByAffiliation.bDetectEnemies = true; //AI가 적을 감지가능
		RunSightConfig->DetectionByAffiliation.bDetectNeutrals = true; //AI가 중립을 감지가능
		RunSightConfig->DetectionByAffiliation.bDetectFriendlies = false; //아군 감지할 필요가 없음

		RunPerception->ConfigureSense(*RunSightConfig); //컴포넌트에 시각감각 추가
	}
	ClosestActor = nullptr;
	BlackboardComp = nullptr;
	EnemyActors = TArray<AActor*>();
}

void APassiveAI::BeginPlay()
{
	Super::BeginPlay();
	RunPerception->OnPerceptionUpdated.AddDynamic(this, &APassiveAI::OnRunPerceptionUpdate);
	GetWorld()->GetTimerManager().SetTimer(UpdateDistanceTimer, this, &APassiveAI::UpdateClosestActorTimer, 1.0f, true);
}

void APassiveAI::UpdateClosestActorTimer()
{
	if (EnemyActors.Num() == 0)
	{
		ClosestActor = nullptr;
		return;
	}

	AActor* NewClosestActor = nullptr;
	float ClosestDistance = FLT_MAX;

	for (AActor* Enemy : EnemyActors)
	{
		float Distance = FVector::Dist(Enemy->GetActorLocation(), this->GetActorLocation());

		if (Distance < ClosestDistance)
		{
			ClosestDistance = Distance;
			NewClosestActor = Enemy;
		}
	}

	ClosestActor = NewClosestActor;
	if (ClosestActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Closest Actor Updated: %s at distance %f"), *ClosestActor->GetName(),
		       ClosestDistance);
	}
}

void APassiveAI::OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors)
{
	Super::OnPerceptionUpdated(UpdatedActors);
	EnemyActors = UpdatedActors;
	if (UpdatedActors.Num() == 0)
	{
		ClosestActor = nullptr;
		BlackboardComp->SetValueAsObject(TEXT("TargetActor"), nullptr);
		BlackboardComp->SetValueAsBool(TEXT("IsDetected"), false);
		return;
	}
	AAIController* AIController = Cast<AAIController>(GetController());
	if (!AIController) return;

	BlackboardComp = AIController->GetBlackboardComponent();
	if (!BlackboardComp) return;

	BlackboardComp->SetValueAsObject(TEXT("TargetActor"), ClosestActor);
	BlackboardComp->SetValueAsBool(TEXT("IsDetected"), true);
}

void APassiveAI::OnRunPerceptionUpdate(const TArray<AActor*>& UpdatedActors)
{
	AAIController* AIController = Cast<AAIController>(GetController());
	if (!AIController) return;

	BlackboardComp = AIController->GetBlackboardComponent();
	if (!BlackboardComp) return;

	BlackboardComp->SetValueAsBool(TEXT("IsNear"), true);
}
