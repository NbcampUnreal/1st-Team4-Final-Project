#include "BaseAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "EMBER/AI/BaseAI.h"

void ABaseAIController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("BeginPlay"));

	ABaseAI* ControlledAnimal = Cast<ABaseAI>(GetPawn());
	if (!ControlledAnimal) return;
	UBehaviorTree* SelectedBT = nullptr;

	switch (ControlledAnimal->AnimalType)
	{
	case EAnimalType::Crow:
		SelectedBT = CrowBT;
		CurrentBT = CrowBT;
		break;
	case EAnimalType::Passive:
		SelectedBT = PassiveBT;
		CurrentBT = PassiveBT;
		break;
	case EAnimalType::Defensive:
		SelectedBT = DefensiveBT;
		CurrentBT = DefensiveBT;
		break;
	case EAnimalType::Aggressive:
		SelectedBT = AggressiveBT;
		CurrentBT = AggressiveBT;
		break;

	}

	if (UseBlackboard(BlackboardAsset, BlackboardComp) && SelectedBT)
	{
		// 패트롤 포인트를 블랙보드에 저장
		BlackboardComp->SetValueAsObject("PatrolPoint", ControlledAnimal);
		BlackboardComp->SetValueAsInt("PatrolIndex", 0);

		RunBehaviorTree(SelectedBT);

		UE_LOG(LogTemp, Warning, TEXT("BT: %s"), *GetNameSafe(SelectedBT));
	}
}
