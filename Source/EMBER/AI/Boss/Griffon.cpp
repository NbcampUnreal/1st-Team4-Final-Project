#include "AI/Boss/Griffon.h"
#include "CAIController.h"
#include "StatusComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

AGriffon::AGriffon()
{
	// PrimaryActorTick.bCanEverTick = true;
}

void AGriffon::BeginPlay()
{
	ABaseAI::BeginPlay();
}

float AGriffon::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
                           class AController* EventInstigator, AActor* DamageCauser)
{
	float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	if (ACAIController* AIController = Cast<ACAIController>(GetController()))
	{
		UBlackboardComponent* BlackboardComponent = Cast<UBlackboardComponent>(AIController->GetBlackboardComponent());
		if (!BlackboardComponent->GetValueAsBool("IsHalfHP"))
		{
			if (StatusComponent->GetHp() < (StatusComponent->GetMaxHp() / 2))
			{
				if (!BlackboardComponent->GetValueAsBool("IsHalfHP"))
				BlackboardComponent->SetValueAsBool("IsHalfHP", true);
				BlackboardComponent->SetValueAsInt("RandomPattern", 3);
			}
		}
	}
	
	return ActualDamage;
}