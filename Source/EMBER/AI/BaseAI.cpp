#include "BaseAI.h"
#include "BaseAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "kismet/GameplayStatics.h"


ABaseAI::ABaseAI()
{ AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));

	if (SightConfig)
	{
		SightConfig->SightRadius = 1000.f;
		SightConfig->LoseSightRadius = 1200.f;
		SightConfig->PeripheralVisionAngleDegrees = 90.f;
		SightConfig->SetMaxAge(5.f);
		SightConfig->AutoSuccessRangeFromLastSeenLocation = 500.f;
		SightConfig->DetectionByAffiliation.bDetectEnemies = true;
		SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
		SightConfig->DetectionByAffiliation.bDetectFriendlies = true;

		AIPerception->ConfigureSense(*SightConfig);
	}

	AIPerception->SetDominantSense(SightConfig->GetSenseImplementation());
	AIPerception->OnPerceptionUpdated.AddDynamic(this, &ABaseAI::OnPerceptionUpdated);
}




void ABaseAI::BeginPlay()
{
	Super::BeginPlay();
}

float ABaseAI::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator,
                          AActor* DamageCauser)
{
	if (!HasAuthority()) return 0;

	float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	if (ActualDamage > 0 && !bIsDie)
	{
		CurrentHP -= ActualDamage;
		if (CurrentHP <= 0.f) OnDeath();
	}
	return ActualDamage;
}

void ABaseAI::Attack(AActor* Target)
{
	UGameplayStatics::ApplyDamage(Target, AttackPower, GetController(), this, UDamageType::StaticClass());
}

void ABaseAI::OnDeath()
{
}

void ABaseAI::OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors)
{
	// 감지된 객체 처리 로직 추가 가능
	for (AActor* Actor : UpdatedActors)
	{
		UE_LOG(LogTemp, Warning, TEXT("Boar perceived: %s"), *Actor->GetName());
	}

}
