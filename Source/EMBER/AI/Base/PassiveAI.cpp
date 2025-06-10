#include "AI/Base/PassiveAI.h"
#include "C_StateComponent.h"
#include "AI/AnimInstance/BaseAIAnimInstance.h"
#include "BehaviorTree/BehaviorTree.h"

APassiveAI::APassiveAI()
{
	ClosestActor = nullptr;
	EnemyActors = TArray<AActor*>();
	ClosestDistanceBoundary = 1000.0f;
	ClosestDistance = FLT_MAX;
}

void APassiveAI::BeginPlay()
{
	ABaseAI::BeginPlay();
}

//void APassiveAI::OnTargetPerceptionUpdated(AActor* UpdatedActor, FAIStimulus Stimulus)
//{
//	Super::OnTargetPerceptionUpdated(UpdatedActor, Stimulus);
//	
//	if (Stimulus.WasSuccessfullySensed() && UpdatedActor->Tags.Contains(FName("Player")))
//	{
//		UE_LOG(LogTemp, Warning, TEXT("Player Detect"));
//
//		EnemyActors.Add(UpdatedActor);
//		//TODOS State�� �����ϴ� �ٸ� �ڵ�� ��ü�ؾ��ҵ�?
//		//AIState->SetDetectMode();
//		CheckDetection(true);
//
//		float DistanceToTarget = FVector::Dist(UpdatedActor->GetActorLocation(), GetActorLocation());
//		bool bIsNear = (DistanceToTarget <= ClosestDistanceBoundary);
//
//		if (bIsNear)
//		{
//			if (UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance())
//			{
//				AnimInstance->StopAllMontages(0.1f);
//			}
//		}
//		// SetBlackboardBool(TEXT("IsNear"), bIsNear);
//		// SetBlackboardBool(TEXT("IsDetected"), true);
//		// SetBlackboardObject(TEXT("TargetActor"), UpdatedActor);
//	}
//	else if (!Stimulus.WasSuccessfullySensed() && UpdatedActor->Tags.Contains(FName("Player")))
//	{
//		AIState->SetIdleMode();
//		//TODOS State�� �����ϴ� �ٸ� �ڵ�� ��ü�ؾ��ҵ�?
//		//if (AnimalType == EAnimalType::Passive)
//		{
//			EnemyActors.Remove(UpdatedActor);
//			if (EnemyActors.Num() == 0)
//			{
//				UE_LOG(LogTemp, Warning, TEXT("Zero Actor"));
//				CheckDetection(false);
//				ClosestActor = nullptr;
//				// SetBlackboardObject(TEXT("TargetActor"), nullptr);
//				// SetBlackboardBool(TEXT("IsDetected"), false);
//				// SetBlackboardBool(TEXT("IsNear"), false);
//			}
//		}
//	}
//}

void APassiveAI::UpdateClosestActorTimer()
{
	if (EnemyActors.Num() == 0 )//&& AnimalType == EAnimalType::Passive)
	{
		ClosestActor = nullptr;
		ClosestDistance = FLT_MAX;
		return;
	}

	for (AActor* Enemy : EnemyActors)
	{
		if (!Enemy->Tags.Contains(FName("Player"))) continue;
		FVector MyLocation = this->GetActorLocation();
		FVector EnemyLocation = Enemy->GetActorLocation();

		MyLocation.Z = 0;
		EnemyLocation.Z = 0;

		float Distance = FVector::Dist(MyLocation, EnemyLocation);

		if (Distance < ClosestDistanceBoundary)
		{
			// SetBlackboardBool("IsNear", true);
		}
		else if (Distance >= ClosestDistanceBoundary) //&& AnimalType == EAnimalType::Passive)
		{
			// SetBlackboardBool("IsNear", false);
		}
		if (Distance < ClosestDistance)
		{
			ClosestDistance = Distance;
			ClosestActor = Enemy;
			// SetBlackboardObject(TEXT("TargetActor"), ClosestActor);
			UE_LOG(LogTemp, Warning, TEXT("Closest Actor Updated: %s at distance %f"), *ClosestActor->GetName(),
			       ClosestDistance);
		}
	}
}

void APassiveAI::CheckDetection(bool IsDetect)
{
	if (IsDetect)
	{
		if (!GetWorld()->GetTimerManager().IsTimerActive(UpdateDistanceTimer))
		{
			GetWorld()->GetTimerManager().SetTimer(UpdateDistanceTimer, this, &APassiveAI::UpdateClosestActorTimer,
			                                       1.0f, true);
			UE_LOG(LogTemp, Warning, TEXT("Timer Started"));
		}
	}
	else
	{
		GetWorld()->GetTimerManager().ClearTimer(UpdateDistanceTimer);
		UE_LOG(LogTemp, Warning, TEXT("Timer Stopped"));
	}
}

float APassiveAI::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
                             AActor* DamageCauser)
{
	AIState->SetHittdMode();
	UBaseAIAnimInstance* AnimInstance = Cast<UBaseAIAnimInstance>(GetMesh()->GetAnimInstance());
	ClosestActor = DamageCauser;
	UE_LOG(LogTemp, Warning, TEXT("%f Damage!!"), DamageAmount);
	return Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
}

void APassiveAI::OnDeath()
{
	Super::OnDeath();
	CheckDetection(false);
}
