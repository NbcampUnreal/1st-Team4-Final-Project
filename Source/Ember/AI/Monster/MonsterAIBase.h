// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "MonsterAIBase.generated.h"

class AMonsterAIWeapon;
class UEmberAS_Player;
class UHealthComponent;
class UMonsterAbilitySystemComponent;
class UMonsterGameplayEffectComponent;

UCLASS(Abstract, Blueprintable)
class EMBER_API AMonsterAIBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AMonsterAIBase();
	
public:
	//~ IAbilitySystemInterface interface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UMonsterAbilitySystemComponent* GetMonsterAbilitySystemComponent() const;
	//~ End of IAbilitySystemInterface

public:
	AMonsterAIWeapon* GetWeapon() { return WeaponActor; }

protected:
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

	UFUNCTION()
	virtual void HandleHealthChanged(UHealthComponent* InHealthComponent, float OldValue, float NewValue, AActor* DamageInstigator);

	
private:
	void InitializeMonsterAI();
	void OnDeath();
	void DisableMovementAndCollision();
	
protected:
	UPROPERTY()
	TObjectPtr<UMonsterAbilitySystemComponent> ASC;

	UPROPERTY()
	TObjectPtr<UEmberAS_Player> AttributeSet;

	UPROPERTY()
	TObjectPtr<UHealthComponent> HealthComponent;
	
private:
	UPROPERTY()
	TObjectPtr<AMonsterAIWeapon> WeaponActor;
};
