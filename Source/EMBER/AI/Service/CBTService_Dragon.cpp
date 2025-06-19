#include "AI/Service/CBTService_Dragon.h"
#include "AI/CAIController.h"
#include "AI/Boss/Dragon.h"
#include "AIComponent/CAIWeaponComponent.h"
#include "BehaviorTree/CBehaviorTreeComponent.h"
#include "AIWeapon/CAI_Weapon.h"
#include "BehaviorTree/BlackboardComponent.h"

UCBTService_Dragon::UCBTService_Dragon()
{
	Interval = 1.0f;
	RandomDeviation = 0.0f;
}

void UCBTService_Dragon::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	TObjectPtr<ACAIController> Controller = Cast<ACAIController>(OwnerComp.GetOwner());
	if(Controller.Get() == nullptr)
	{
		UE_LOG(LogTemp, Error, L"Controller is null");
		return;
	}
	TObjectPtr<ADragon> AI = Cast<ADragon>(Controller->GetPawn());
	if (AI.Get() == nullptr)
	{
		UE_LOG(LogTemp, Error, L"AI is null");
		return;
	}

	TObjectPtr<UCBehaviorTreeComponent> AIState = Cast<UCBehaviorTreeComponent>(AI->GetComponentByClass(UCBehaviorTreeComponent::StaticClass()));
	if (AIState.Get() == nullptr)
	{
		UE_LOG(LogTemp, Error, L"AIstate is null");
		return;
	}

	// TObjectPtr<UDragonBehaviorTreeComponent> DragonAttackState = Cast<UDragonBehaviorTreeComponent>(AI->GetComponentByClass(UDragonBehaviorTreeComponent::StaticClass()));
	// if (DragonAttackState.Get() == nullptr)
	// {
	// 	UE_LOG(LogTemp, Error, L"DragonAttackState is null");
	// 	return;
	// }

	TObjectPtr<UCAIWeaponComponent> WeaponComponent = Cast<UCAIWeaponComponent>(AI->GetComponentByClass(UCAIWeaponComponent::StaticClass()));
	if (WeaponComponent.Get() == nullptr)
	{
		UE_LOG(LogTemp, Error, L"WeaponComponent is null");
		return;
	}

	TObjectPtr<ACAI_Weapon> Weapon = WeaponComponent->GetDoAction();
	if (Weapon.Get() == nullptr)
	{
		UE_LOG(LogTemp, Error, L"Weapon is null");
		return;
	}

	TObjectPtr<UBlackboardComponent> Blackboard = Controller->GetBlackboardComponent();
	if (Blackboard.Get() == nullptr)
	{
		UE_LOG(LogTemp, Error, L"Blackboard is null");
		return;
	}
	
	//Target이 없으면 Patrol
	TObjectPtr<ACharacter> Target = AIState->GetTarget(); 
	if(Target == nullptr)
	{
		AIState->SetPatrolMode();
		return;
	}
	
	//Target과 가까우면 AttackMode
	float distance = AI.Get()->GetDistanceTo(Target);
	int32 AttackCount = Weapon->GetAttackStack();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green,FString::Printf(TEXT("Distance: %.1f | AttackCount: %d"), distance, AttackCount));
	
	if(distance < ActionRange || (AttackCount >= 3 && distance > MeleeRange))
	{
		AIState->SetActionMode();
		
		if (AttackCount >= 3)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("Special Attack Block"));

			if (distance <= MeleeRange)
			{
				GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("Combo Attack Triggered"));

				AIState->SetComboAttackMode();
			}
			else
			{
				GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, TEXT("Spit Attack Triggered"));

				AIState->SetSpitAttackMode();
			}

			if (AIState->IsComboAttack() || AIState->IsSpitAttack())
			{
				Weapon->ResetAttackStack();
			}
		}
		else
		{
			AIState->SetNormalAttackMode();
			int32 RandomValue = FMath::RandRange(0,2);
			Blackboard->SetValueAsInt("NormalAttackIdx", RandomValue);
		}
	}
	else
	{
		AIState->SetChaseMode();
	}

#if WITH_EDITOR
	DrawDebugSphere(
		GetWorld(),
		AI->GetActorLocation(),
		ActionRange,
		32,
		FColor::Blue,
		false,
		-1.f,
		0,
		2.f
	);

	DrawDebugSphere(
		GetWorld(),
		AI->GetActorLocation(),
		MeleeRange,
		32,
		FColor::Red,
		false,
		-1.f,
		0,
		2.f
	);
#endif
}



