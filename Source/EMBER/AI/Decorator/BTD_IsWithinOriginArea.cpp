#include "BTD_IsWithinOriginArea.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTD_IsWithinOriginArea::UBTD_IsWithinOriginArea()
{
}

bool UBTD_IsWithinOriginArea::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();

	if (!AIController || !BlackboardComponent) return false;

	FVector CurrentLocation = AIController->GetPawn()->GetActorLocation();
	FVector OriginLocation = BlackboardComponent->GetValueAsVector("OriginLocation");
	float Distance = FVector::Dist(CurrentLocation, OriginLocation);

	return Distance <= MaxDistance;
}
