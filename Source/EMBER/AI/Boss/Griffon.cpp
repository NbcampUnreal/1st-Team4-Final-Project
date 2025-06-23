#include "AI/Boss/Griffon.h"
#include "CAIController.h"
#include "C_StateComponent.h"
#include "StatusComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "kismet/GameplayStatics.h"

AGriffon::AGriffon()
{
	// PrimaryActorTick.bCanEverTick = true;
}

void AGriffon::BeginPlay()
{
	ABaseAI::BeginPlay();
}

// void AGriffon::Tick(float DeltaTime)
// {
// 	Super::Tick(DeltaTime);
//
// 	if (GetActorLocation().Z > 700.0f)
// 	{
// 		GetCharacterMovement()->Velocity.Z = 0.0f;
// 	}
//
// 	if (GetCharacterMovement()->IsMovingOnGround())
// 	{
// 		GetCharacterMovement()->SetMovementMode(MOVE_Walking);
// 	}
// }

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

//void AGriffon::OnTargetPerceptionUpdated(AActor* UpdatedActor, FAIStimulus Stimulus)
//{
//	Super::OnTargetPerceptionUpdated(UpdatedActor, Stimulus);
//	
//	// SetBlackboardVector("OriginLocation", GetActorLocation());
//}
