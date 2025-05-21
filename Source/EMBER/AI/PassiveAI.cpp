#include "AI/PassiveAI.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig.h"
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
	EnemyActors = TArray<AActor*>();
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

	float ClosestDistance = FLT_MAX;

	for (AActor* Enemy : EnemyActors)
	{
		if (!Enemy->Tags.Contains(FName("Player"))) continue;
		float Distance = FVector::Dist(Enemy->GetActorLocation(), this->GetActorLocation());

		if (Distance < ClosestDistance)
		{
			ClosestDistance = Distance;
			ClosestActor = Enemy;
		}
	}

	if (ClosestActor)
	{
		SetBlackboardObject(TEXT("TargetActor"), ClosestActor);
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
	
	ABaseAIController* BaseAIController = Cast<ABaseAIController>(Cast<AAIController>(GetController()));
	UBehaviorTreeComponent* BehaviorComp = Cast<UBehaviorTreeComponent>(
	BaseAIController->GetComponentByClass(UBehaviorTreeComponent::StaticClass()));
	
	if (Stimulus.WasSuccessfullySensed() && UpdatedActor->Tags.Contains(FName("Player")))
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Detect"));

		EnemyActors.Add(UpdatedActor);
		bIsDetect = true;
		CheckDetection();
		SetBlackboardBool(TEXT("IsDetected"), true);
		SetBlackboardObject(TEXT("TargetActor"), ClosestActor);

		BehaviorComp->RestartTree();
	}
	else if (!Stimulus.WasSuccessfullySensed())
	{
		EnemyActors.Remove(UpdatedActor); //모든 캐릭터가 다 사라지므로 추후 수정필요
		if (EnemyActors.Num() == 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("Zero Actor"));
			bIsDetect = false;
			CheckDetection();
			ClosestActor = nullptr;
			SetBlackboardObject(TEXT("TargetActor"), nullptr);
			SetBlackboardBool(TEXT("IsDetected"), false);
			BehaviorComp->RestartTree();
		}
	}
}

float APassiveAI::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	SetBlackboardBool("IsHit", true);
	UE_LOG(LogTemp, Warning, TEXT("Hit!!"));
	return Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
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
		SetBlackboardBool(TEXT("IsNear"), true);

		if (UAnimInstance* AnimInstance = this->GetMesh()->GetAnimInstance())
		{
			AnimInstance->StopAllMontages(0.1f); // 블렌드 아웃 후 모든 몽타주 중지
		}
	}
	else if (!Stimulus.WasSuccessfullySensed() && NearEnemies.Num() == 0)
	{
		SetBlackboardBool(TEXT("IsNear"), false);
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