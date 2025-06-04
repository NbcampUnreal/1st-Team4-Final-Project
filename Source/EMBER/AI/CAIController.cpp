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

	//생성자 동적할당 
	Sight = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight"));
	//런타임 동적할당
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
	//GetSenseImplementation 자료형 타입을 넘겨주는 함수
}

void ACAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	AI = Cast<AHumanAIBase>(InPawn);

	//if(AI->GetBehaviorTree() == nullptr)
	if(AI == nullptr)
	{
		UE_LOG(LogTemp, Error, L"AI is null");
		return;
	}

	UBlackboardComponent* bb = GetBlackboardComponent();
	//UseBlackboard(AI->GetBehaviorTree()->GetBlackboardAsset(), bb);
	UseBlackboard(CurrentBT->GetBlackboardAsset(), bb);

	Behavior = Cast<UCBehaviorTreeComponent>(AI->GetComponentByClass(UCBehaviorTreeComponent::StaticClass()));
	Behavior->SetBlackboard(Blackboard);

	//RunBehaviorTree(AI->GetBehaviorTree());
	RunBehaviorTree(CurrentBT);
}

void ACAIController::OnUnPossess()
{
	Super::OnUnPossess();
}

void ACAIController::BeginPlay()
{
	Super::BeginPlay();

	ABaseAI* ControlledAnimal = Cast<ABaseAI>(GetPawn());
	if (!ControlledAnimal) return;
	//UBehaviorTree* SelectedBT = nullptr;

	switch (ControlledAnimal->AnimalType)
	{
	case EAnimalType::Crow:
		//SelectedBT = CrowBT;
		CurrentBT = CrowBT;
		break;
	case EAnimalType::Passive:
		//SelectedBT = PassiveBT;
		CurrentBT = PassiveBT;
		break;
	case EAnimalType::Defensive:
		//SelectedBT = DefensiveBT;
		CurrentBT = DefensiveBT;
		break;
	case EAnimalType::Aggressive:
		//SelectedBT = AggressiveBT;
		CurrentBT = AggressiveBT;
		break;
	case EAnimalType::Griffon:
		//SelectedBT = GriffonBT;
		CurrentBT = GriffonBT;
		break;
	case EAnimalType::Dragon:
		//SelectedBT = DragonBT;
		CurrentBT = DragonBT;
		break;
	case EAnimalType::Human:
		//SelectedBT = HumanBT;
		CurrentBT = HumanBT;
		break;
	}

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
