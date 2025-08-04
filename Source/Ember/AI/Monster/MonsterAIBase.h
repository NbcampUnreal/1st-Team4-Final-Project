// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "MonsterAIBase.generated.h"

class AMonsterAIWeapon;
class UEmberAS_Player;
class UMonsterAbilitySystemComponent;
class UMonsterGameplayEffectComponent;

UCLASS(Abstract, Blueprintable)
class EMBER_API AMonsterAIBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AMonsterAIBase();

protected:
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;
	
public:
	//~ IAbilitySystemInterface interface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UMonsterAbilitySystemComponent* GetMonsterAbilitySystemComponent() const;
	//~ End of IAbilitySystemInterface

public:
	AMonsterAIWeapon* GetWeapon() { return WeaponActor; }

private:
	void InitializeMonsterAI();
	
protected:
	UPROPERTY()
	TObjectPtr<UMonsterAbilitySystemComponent> ASC;

	UPROPERTY()
	TObjectPtr<UEmberAS_Player> AttributeSet;
	
private:
	UPROPERTY()
	TObjectPtr<AMonsterAIWeapon> WeaponActor;
};
