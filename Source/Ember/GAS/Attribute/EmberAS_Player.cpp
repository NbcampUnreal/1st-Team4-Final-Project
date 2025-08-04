#include "GAS/Attribute/EmberAS_Player.h"
#include "GameplayEffectExtension.h"

UEmberAS_Player::UEmberAS_Player()
	:MaxHealth(100.0f), MaxAttackRange(300.0f), AttackRange(100.0f),
	MaxAttackRadius(300.0f), AttackRadius(100.0f), MaxAttackDamage(500.0f),
	AttackDamage(100.0f), MetaDamage(0.0f)
{
	InitHealth(GetMaxHealth());
}

void UEmberAS_Player::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	if (Attribute == GetMetaDamageAttribute())
		NewValue = NewValue < 0.0f ? 0.0f : NewValue;
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
}