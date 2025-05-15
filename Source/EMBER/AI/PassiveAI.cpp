#include "AI/PassiveAI.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig.h"
#include "DrawDebugHelpers.h"

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
	PrimaryActorTick.bCanEverTick = true;
}

void APassiveAI::Tick(float DeltaTime)
{
		FVector AIPosition = GetActorLocation();
		float SightRadius = 2000.f;
		FColor CircleColor = FColor::Green; // ✅ 초록색 원

		DrawDebugSphere(GetWorld(), AIPosition, SightRadius, 32, CircleColor, false, -1.0f, 0); // ✅ -1.0f로 계속 유지
}


void APassiveAI::BeginPlay()
{
	Super::BeginPlay();
	RunPerception->OnTargetPerceptionUpdated.AddDynamic(this, &APassiveAI::OnRunPerceptionUpdate);
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
		if (!Enemy->Tags.Contains(FName("Player"))) continue;
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

void APassiveAI::OnTargetPerceptionUpdate(AActor* UpdatedActor, FAIStimulus Stimulus)
{
	Super::OnTargetPerceptionUpdated(UpdatedActor, Stimulus);
	if (Stimulus.WasSuccessfullySensed()&&UpdatedActor->Tags.Contains(FName("Player")))
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Detect"));
		AAIController* AIController = Cast<AAIController>(GetController());
		if (!AIController) return;

		BlackboardComp = AIController->GetBlackboardComponent();
		if (!BlackboardComp) return;

		bIsDetect = true;
		CheckDetection();
		BlackboardComp->SetValueAsObject(TEXT("TargetActor"), ClosestActor);
		BlackboardComp->SetValueAsBool(TEXT("IsDetected"), true);
		EnemyActors.Add(UpdatedActor);
	}
	else if (Stimulus.IsExpired())
	{
			EnemyActors.Remove(UpdatedActor);
		if (EnemyActors.Num() == 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("Zero Actor"));
			bIsDetect = false;
			CheckDetection();
			ClosestActor = nullptr;
			BlackboardComp->SetValueAsObject(TEXT("TargetActor"), nullptr);
			BlackboardComp->SetValueAsBool(TEXT("IsDetected"), false);
			return;
		}
	}
}

void APassiveAI::OnRunPerceptionUpdate(AActor* UpdatedActor, FAIStimulus Stimulus)
{
	UE_LOG(LogTemp, Warning, TEXT("OnRunPerceptionUpdate"));

	AAIController* AIController = Cast<AAIController>(GetController());
	if (!AIController) return;

	BlackboardComp = AIController->GetBlackboardComponent();
	if (!BlackboardComp) return;

	BlackboardComp->SetValueAsBool(TEXT("IsNear"), true);
}

void APassiveAI::CheckDetection()
{
	if (bIsDetect)
	{
		if (!GetWorld()->GetTimerManager().IsTimerActive(UpdateDistanceTimer))
		{
			GetWorld()->GetTimerManager().SetTimer(UpdateDistanceTimer, this, &APassiveAI::UpdateClosestActorTimer,
			                                       1.0f, true);
			UE_LOG(LogTemp, Warning, TEXT("Timer Started"));
		}
	}
	else
	{
		GetWorld()->GetTimerManager().ClearTimer(UpdateDistanceTimer);
		UE_LOG(LogTemp, Warning, TEXT("Timer Stopped"));
	}
}
