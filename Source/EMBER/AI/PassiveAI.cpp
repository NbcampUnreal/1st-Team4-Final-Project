#include "AI/PassiveAI.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"

APassiveAI::APassiveAI()
{
	RunPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("RunPerception"));
	RunSightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));


	if (RunSightConfig)
	{
		RunSightConfig->SightRadius = 1000.f;
		RunSightConfig->LoseSightRadius = 1200.f;
		RunSightConfig->PeripheralVisionAngleDegrees = 90.f; //시야각
		RunSightConfig->SetMaxAge(5.f); //기억시간
		RunSightConfig->AutoSuccessRangeFromLastSeenLocation = 500.f; //AI가 마지막으로 본 위치에서 500이내에 있을 경우, 자동으로 감지 성공으로 처리
		RunSightConfig->DetectionByAffiliation.bDetectEnemies = true; //AI가 적을 감지가능
		RunSightConfig->DetectionByAffiliation.bDetectNeutrals = true; //AI가 중립을 감지가능
		RunSightConfig->DetectionByAffiliation.bDetectFriendlies = true; //AI가 아군을 감지가능

		RunPerception->ConfigureSense(*RunSightConfig); //컴포넌트에 시각감각 추가
	}
}

void APassiveAI::BeginPlay()
{
	Super::BeginPlay();
	RunPerception->SetDominantSense(RunSightConfig->GetSenseImplementation());
	RunPerception->OnPerceptionUpdated.AddDynamic(this, &APassiveAI::OnRunPerceptionUpdate);
}

void APassiveAI::OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors)
{
	AAIController* AIController = Cast<AAIController>(GetController());
	if (!AIController) return;

	UBlackboardComponent* BlackboardComp = AIController->GetBlackboardComponent();
	if (!BlackboardComp) return;

	BlackboardComp->SetValueAsBool(TEXT("IsDetected"), true);
}

void APassiveAI::OnRunPerceptionUpdate(const TArray<AActor*>& UpdatedActors)
{
	AAIController* AIController = Cast<AAIController>(GetController());
	if (!AIController) return;

	UBlackboardComponent* BlackboardComp = AIController->GetBlackboardComponent();
	if (!BlackboardComp) return;

	BlackboardComp->SetValueAsBool(TEXT("IsNear"), true);
	
}
