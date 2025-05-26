#include "AI/PassiveAI.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig.h"
#include "BehaviorTree/BehaviorTree.h"

APassiveAI::APassiveAI()
{
	AnimalType = EAnimalType::Passive;
	ClosestActor = nullptr;
	EnemyActors = TArray<AActor*>();
	ClosestDistanceBoundary = 1000.0f;
}

void APassiveAI::BeginPlay()
{
	Super::BeginPlay();
}

void APassiveAI::OnTargetPerceptionUpdated(AActor* UpdatedActor, FAIStimulus Stimulus)
{
	Super::OnTargetPerceptionUpdated(UpdatedActor, Stimulus);

	ABaseAIController* BaseAIController = Cast<ABaseAIController>(Cast<AAIController>(GetController()));
	UBehaviorTreeComponent* BehaviorComp = Cast<UBehaviorTreeComponent>(
		BaseAIController->GetComponentByClass(UBehaviorTreeComponent::StaticClass()));

	if (Stimulus.WasSuccessfullySensed() && UpdatedActor->Tags.Contains(FName("Player")))
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Detect"));

		EnemyActors.Add(UpdatedActor);
		bIsDetect = true;
		CheckDetection();
		SetBlackboardBool(TEXT("IsDetected"), true);
		SetBlackboardObject(TEXT("TargetActor"), UpdatedActor);

		float DistanceToTarget = FVector::Dist(UpdatedActor->GetActorLocation(), GetActorLocation());
		bool bIsNear = (DistanceToTarget <= ClosestDistanceBoundary);
		
		SetBlackboardBool(TEXT("IsNear"), bIsNear);
		UE_LOG(LogTemp, Warning, TEXT("DistanceToTarget: %f"), DistanceToTarget);
		
		if (bIsNear)
		{
			if (UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance())
			{
				AnimInstance->StopAllMontages(0.1f);
			}
		}
	}
	else if (!Stimulus.WasSuccessfullySensed())
	{
		EnemyActors.Remove(UpdatedActor); //모든 캐릭터가 다 사라지므로 추후 수정필요
		if (EnemyActors.Num() == 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("Zero Actor"));
			bIsDetect = false;
			CheckDetection();
			ClosestActor = nullptr;
			SetBlackboardObject(TEXT("TargetActor"), nullptr);
			SetBlackboardBool(TEXT("IsDetected"), false);
			SetBlackboardBool(TEXT("IsNear"), false);
		}
	}
}

void APassiveAI::UpdateClosestActorTimer()
{
	if (EnemyActors.Num() == 0)
	{
		ClosestActor = nullptr;
		return;
	}

	float ClosestDistance = FLT_MAX;

	for (AActor* Enemy : EnemyActors)
	{
		if (!Enemy->Tags.Contains(FName("Player"))) continue;
		float Distance = FVector::Dist(Enemy->GetActorLocation(), this->GetActorLocation());

		if (Distance < ClosestDistanceBoundary)
		{
			SetBlackboardBool("IsNear", true);
		}
		else
		{
			SetBlackboardBool("IsNear", false);
		}
		if (Distance < ClosestDistance)
		{
			ClosestDistance = Distance;
			ClosestActor = Enemy;
		}
	}

	if (ClosestActor)
	{
		SetBlackboardObject(TEXT("TargetActor"), ClosestActor);
		UE_LOG(LogTemp, Warning, TEXT("Closest Actor Updated: %s at distance %f"), *ClosestActor->GetName(),
			   ClosestDistance);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Null Character"));
	}
}

void APassiveAI::CheckDetection()
{
	if (bIsDetect)
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
	SetBlackboardBool("IsHit", true);
	ClosestActor = DamageCauser;
	UE_LOG(LogTemp, Warning, TEXT("%f Damage!!"),DamageAmount);
	return Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
}

void APassiveAI::OnDeath()
{
	Super::OnDeath();
	bIsDetect = false;
	CheckDetection();
}
