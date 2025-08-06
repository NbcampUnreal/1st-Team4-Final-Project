#include "GAS/Attribute/EmberAS_Player.h"

#include <string>

#include "GameplayEffectExtension.h"
#include "Utility/CLog.h"

UEmberAS_Player::UEmberAS_Player()
	:MaxHealth(100.0f), MaxAttackRange(300.0f), AttackRange(50.0f),
	MaxAttackRadius(300.0f), AttackRadius(50.0f), MaxAttackDamage(500.0f),
	AttackDamage(10.0f), MetaDamage(0.0f), MaxPlayerTemperature(100.0f),
	MaxDamageTemperature(100.0f), DamageTemperature(1.0f)
{
	InitHealth(GetMaxHealth());
	InitPlayerTemperature(GetMaxPlayerTemperature());
}

void UEmberAS_Player::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	if (Attribute == GetMetaDamageAttribute())
		NewValue = NewValue < 0.0f ? 0.0f : NewValue;
	else if (Attribute == GetMetaTemperatureAttribute())
		NewValue = NewValue < 0.0f ? 0.0f : NewValue;
}

void UEmberAS_Player::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	bool bHit{};
	float minimumHealth = 0.0f;
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		bHit = true;
		UE_LOG(LogTemp,Log,TEXT("Health : %f"), GetHealth());
		SetHealth(FMath::Clamp(GetHealth(), minimumHealth, GetMaxHealth()));
	}
	else if (Data.EvaluatedData.Attribute == GetMetaDamageAttribute())
	{
		bHit = true;
		UE_LOG(LogTemp,Log,TEXT("Damge : %f"), GetMetaDamage());
		SetHealth(FMath::Clamp(GetHealth() - GetMetaDamage(), 0.0f, GetMaxHealth()));
		SetMetaDamage(0.0f);
	}
	else if (Data.EvaluatedData.Attribute == GetMetaTemperatureAttribute())
	{
		DebugLogE(FString::Printf(TEXT("TemperatureAttribute : %f"), GetPlayerTemperature()));
		SetPlayerTemperature(FMath::Clamp(GetPlayerTemperature() - GetMetaTemperature(), minimumHealth, GetMaxPlayerTemperature()));
		SetMetaTemperature(0.0f);
	}

	if (bHit == true)
		if (OnHitPlayer.IsBound() == true)
			OnHitPlayer.Broadcast();
}