#include "GAS/Attribute/EmberAS_Player.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UEmberAS_Player::UEmberAS_Player()
	:MaxHealth(100.0f), MaxAttackRange(300.0f), AttackRange(100.0f),
	MaxAttackRadius(300.0f), AttackRadius(100.0f), MaxAttackDamage(500.0f),
	AttackDamage(100.0f), MetaDamage(0.0f)
{
	InitHealth(GetMaxHealth());

	bOutOfHealth = false;
	PreviousHealth = 0.f;
}

void UEmberAS_Player::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Health, COND_None, REPNOTIFY_Always);
}

void UEmberAS_Player::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	if (Attribute == GetMetaDamageAttribute())
		NewValue = NewValue < 0.0f ? 0.0f : NewValue;

	PreviousHealth = GetHealth();
}

void UEmberAS_Player::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	float minimumHealth = 0.0f;
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		UE_LOG(LogTemp,Log,TEXT("Health : %f"), GetHealth());
		SetHealth(FMath::Clamp(GetHealth(), minimumHealth, GetMaxHealth()));
	}
	else if (Data.EvaluatedData.Attribute == GetMetaDamageAttribute())
	{
		UE_LOG(LogTemp,Log,TEXT("Damge : %f"), GetMetaDamage());
		SetHealth(FMath::Clamp(GetHealth() - GetMetaDamage(), 0.0f, GetMaxHealth()));
		SetMetaDamage(0.0f);
	}

	/* 체력 변경 감지 */
	const FGameplayEffectContextHandle& EffectContext = Data.EffectSpec.GetEffectContext();
	AActor* Instigator = EffectContext.GetOriginalInstigator();
	AActor* Causer = EffectContext.GetEffectCauser();

	if (HasHealthChanged())
	{
		OnHealthChanged.Broadcast(Instigator, Causer, &Data.EffectSpec, Data.EvaluatedData.Magnitude, PreviousHealth, GetHealth());
	}

	if (IsDead())
	{
		OnOutOfHealth.Broadcast(Instigator, Causer, &Data.EffectSpec, Data.EvaluatedData.Magnitude, PreviousHealth, GetHealth());
	}
	
	bOutOfHealth = (GetHealth() <= 0.0f);
}

void UEmberAS_Player::OnRep_Health(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Health, OldValue);

	const float CurrentHealth = GetHealth();
	const float EstimatedMagnitude = CurrentHealth - OldValue.GetCurrentValue();
	
	OnHealthChanged.Broadcast(nullptr, nullptr, nullptr, EstimatedMagnitude, OldValue.GetCurrentValue(), CurrentHealth);

	if (IsDead())
	{
		OnOutOfHealth.Broadcast(nullptr, nullptr, nullptr, EstimatedMagnitude, OldValue.GetCurrentValue(), CurrentHealth);
	}
	
	bOutOfHealth = (CurrentHealth <= 0.0f);
}

bool UEmberAS_Player::HasHealthChanged() const
{
	return !FMath::IsNearlyEqual(GetHealth(), PreviousHealth);
}

bool UEmberAS_Player::IsDead() const
{
	return (GetHealth() <= 0.0f) && bOutOfHealth == false;
}
