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
	
	if(distance < ActionRange || (AttackCount == 3 && distance > MeleeRange))
	{
		if (AttackCount == 3)
		{
			if (distance <= MeleeRange)
			{
				AIState->SetComboAttackMode();
			}
			else
			{
				AIState->SetSpitAttackMode();
			}

			Weapon->ResetAttackStack();
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

	// FVector OriginLocation = Controller->GetBlackboardComponent()->GetValueAsVector("OriginLocation");
	// FVector TargetLocation = Target->GetActorLocation();
	// float Distance = FVector::Dist(OriginLocation, TargetLocation);
	// if (Distance >= 3000.0f)
	// {
	// 	UE_LOG(LogTemp, Error, L"Distance is too Far in Service");
	// 	AIState->SetIdleMode();
	// 	return;
	// }

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

