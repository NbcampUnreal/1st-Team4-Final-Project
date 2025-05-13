#include "BaseAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "EMBER/AI/BaseAI.h"

void ABaseAIController::BeginPlay()
{
	Super::BeginPlay();

	ABaseAI* ControlledAnimal = Cast<ABaseAI>(GetPawn());
	if (!ControlledAnimal) return;
	UBehaviorTree* SelectedBT = nullptr;

	switch (ControlledAnimal->AnimalType)
	{
	case EAnimalType::Passive:
		SelectedBT = PassiveBT;
		break;
	case EAnimalType::Defensive:
		SelectedBT = DefensiveBT;
		break;
	case EAnimalType::Aggressive:
		SelectedBT = AggressiveBT;
		break;
	}
	
	if (UseBlackboard(BlackboardAsset, BlackboardComp) && SelectedBT)
	{
		// 패트롤 포인트를 블랙보드에 저장
		BlackboardComp->SetValueAsObject("PatrolPoint", ControlledAnimal);
		BlackboardComp->SetValueAsInt("PatrolIndex", 0);

		RunBehaviorTree(SelectedBT);
	}
}
