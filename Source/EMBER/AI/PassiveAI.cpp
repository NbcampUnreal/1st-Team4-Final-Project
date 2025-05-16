#include "AI/PassiveAI.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig.h"
#include "DrawDebugHelpers.h"
#include "BehaviorTree/BehaviorTree.h"

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

	float RunSightRadius = 1000.f;
	FColor RunCircleColor = FColor::Red; // ✅ 초록색 원

	DrawDebugSphere(GetWorld(), AIPosition, RunSightRadius, 32, RunCircleColor, false, -1.0f, 0); // ✅ -1.0f로 계속 유지
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
		BlackboardComp->SetValueAsObject(TEXT("TargetActor"), ClosestActor);
		UE_LOG(LogTemp, Warning, TEXT("Closest Actor Updated: %s at distance %f"), *ClosestActor->GetName(),
		       ClosestDistance);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Null Character"));
	}
}

void APassiveAI::OnTargetPerceptionUpdated(AActor* UpdatedActor, FAIStimulus Stimulus)
{
	Super::OnTargetPerceptionUpdated(UpdatedActor, Stimulus);

	AAIController* AIController = Cast<AAIController>(GetController());
	if (!AIController) return;
	BlackboardComp = AIController->GetBlackboardComponent();
	if (!BlackboardComp) return;
	ABaseAIController* BaseAIController = Cast<ABaseAIController>(AIController);
	UBehaviorTreeComponent* BehaviorComp = Cast<UBehaviorTreeComponent>(
		BaseAIController->GetComponentByClass(UBehaviorTreeComponent::StaticClass()));

	if (Stimulus.WasSuccessfullySensed() && UpdatedActor->Tags.Contains(FName("Player")))
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Detect"));

		EnemyActors.Add(UpdatedActor);
		bIsDetect = true;
		CheckDetection();
		BlackboardComp->SetValueAsBool(TEXT("IsDetected"), true);
		BlackboardComp->SetValueAsObject(TEXT("TargetActor"), ClosestActor);

		BehaviorComp->RestartTree();
	}
	else if (!Stimulus.WasSuccessfullySensed())
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
			BehaviorComp->RestartTree();
		}
	}
}

void APassiveAI::OnRunPerceptionUpdate(AActor* UpdatedActor, FAIStimulus Stimulus)
{
	AAIController* AIController = Cast<AAIController>(GetController());
	if (!AIController) return;
	BlackboardComp = AIController->GetBlackboardComponent();
	if (!BlackboardComp) return;
	ABaseAIController* BaseAIController = Cast<ABaseAIController>(AIController);
	UBehaviorTreeComponent* BehaviorComp = Cast<UBehaviorTreeComponent>(
		BaseAIController->GetComponentByClass(UBehaviorTreeComponent::StaticClass()));

	TArray<AActor*> NearEnemies;

	if (Stimulus.WasSuccessfullySensed() && UpdatedActor->Tags.Contains(FName("Player")))
	{
		NearEnemies.Add(UpdatedActor);
		BlackboardComp->SetValueAsBool(TEXT("IsNear"), true);

		if (UAnimInstance* AnimInstance = this->GetMesh()->GetAnimInstance())
		{
			AnimInstance->StopAllMontages(0.1f); // ✅ 블렌드 아웃 후 모든 몽타주 중지
		}
	}
	else if (!Stimulus.WasSuccessfullySensed() && NearEnemies.Num() == 0)
	{
		BlackboardComp->SetValueAsBool(TEXT("IsNear"), false);
	}
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