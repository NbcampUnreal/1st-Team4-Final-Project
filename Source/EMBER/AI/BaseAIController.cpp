#include "BaseAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"


void ABaseAIController::BeginPlay()
{
	Super::BeginPlay();
	
		RunBehaviorTree(BehaviorTree);
}
