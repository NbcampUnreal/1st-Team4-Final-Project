// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/CAIController.h"

#include "HumanAIBase.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/CBehaviorTreeComponent.h"
#include "Perception/AIPerceptionComponent.h"

ACAIController::ACAIController()
{
	Blackboard = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard"));
	Perception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception"));

	//������ �����Ҵ� 
	Sight = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight"));
	//��Ÿ�� �����Ҵ�
	//NewObject<>()

	Sight->SightRadius = 600.0f;
	Sight->LoseSightRadius = 800.f;
	Sight->PeripheralVisionAngleDegrees = 45;
	Sight->SetMaxAge(2);
	Sight->DetectionByAffiliation.bDetectEnemies = true;
	Sight->DetectionByAffiliation.bDetectFriendlies = false;
	Sight->DetectionByAffiliation.bDetectNeutrals = false;

	Perception->ConfigureSense(*Sight);
	Perception->SetDominantSense(*Sight->GetSenseImplementation());
	//GetSenseImplementation �ڷ��� Ÿ���� �Ѱ��ִ� �Լ�
}

void ACAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	AI = Cast<AHumanAIBase>(InPawn);

	if(AI->GetBehaviorTree() == nullptr)
	{
		UE_LOG(LogTemp, Error, L"BehaviorTree is null");
		return;
	}

	UBlackboardComponent* bb = GetBlackboardComponent();
	UseBlackboard(AI->GetBehaviorTree()->GetBlackboardAsset(), bb);

	Behavior = Cast<UCBehaviorTreeComponent>(AI->GetComponentByClass(UCBehaviorTreeComponent::StaticClass()));
	Behavior->SetBlackboard(Blackboard);

	RunBehaviorTree(AI->GetBehaviorTree());
}

void ACAIController::OnUnPossess()
{
	Super::OnUnPossess();
}

void ACAIController::BeginPlay()
{
	Super::BeginPlay();

	Perception->OnPerceptionUpdated.AddDynamic(this, &ACAIController::OnPerceptionUpdate);
}

void ACAIController::OnPerceptionUpdate(const TArray<AActor*>& UpdatedActors)
{
	TArray<AActor*> actors;
	Perception->GetCurrentlyPerceivedActors(nullptr, actors);

	if (actors.Num() <= 0)
	{
		Blackboard->SetValueAsObject("Target", nullptr);
		return;
	}
	UE_LOG(LogTemp, Error, L"%s", *actors[0]->GetName());
	Blackboard->SetValueAsObject("Target", actors[0]);
}
