#include "Ember/AI/BaseAI.h"
#include "kismet/GameplayStatics.h"


ABaseAI::ABaseAI()
{
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
