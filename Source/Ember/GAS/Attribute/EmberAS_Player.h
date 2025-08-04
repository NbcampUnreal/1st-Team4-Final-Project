#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "EmberAS_Player.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class EMBER_API UEmberAS_Player : public UAttributeSet
{
	GENERATED_BODY()
public:
	UEmberAS_Player();

	ATTRIBUTE_ACCESSORS(UEmberAS_Player,MaxHealth);
	ATTRIBUTE_ACCESSORS(UEmberAS_Player,Health);
	ATTRIBUTE_ACCESSORS(UEmberAS_Player, MaxAttackRange);
	ATTRIBUTE_ACCESSORS(UEmberAS_Player, AttackRange);
	ATTRIBUTE_ACCESSORS(UEmberAS_Player, MaxAttackRadius);
	ATTRIBUTE_ACCESSORS(UEmberAS_Player, AttackRadius);
	ATTRIBUTE_ACCESSORS(UEmberAS_Player, MaxAttackDamage);
	ATTRIBUTE_ACCESSORS(UEmberAS_Player, AttackDamage)
	ATTRIBUTE_ACCESSORS(UEmberAS_Player, MetaDamage)

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	//virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;
	//virtual bool PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;;

protected:
	UPROPERTY(BlueprintReadOnly, Category="HP", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxHealth;
	UPROPERTY(BlueprintReadOnly, Category="HP", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Health;
	UPROPERTY(BlueprintReadOnly, Category="Attack", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxAttackRange;
	UPROPERTY(BlueprintReadOnly, Category = "Attack", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData AttackRange;
	UPROPERTY(BlueprintReadOnly, Category = "Attack", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxAttackRadius;
	UPROPERTY(BlueprintReadOnly, Category = "Attack", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData AttackRadius;
	UPROPERTY(BlueprintReadOnly, Category = "Attack", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxAttackDamage;
	UPROPERTY(BlueprintReadOnly, Category = "Attack", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData AttackDamage;
	UPROPERTY(BlueprintReadOnly, Category = "Attack", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MetaDamage;
};
