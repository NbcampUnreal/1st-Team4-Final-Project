﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "C_CameraComponent.h"
#include "GameData.h"
#include "GenericTeamAgentInterface.h"
#include "Input/CharacterInputComponent.h"
#include "Component/MontageSystemComponent.h"
#include "Input/Data/EmberInputConfig.h"
#include "Interaction/EmberTemperature.h"
#include "EmberPlayerCharacter.generated.h"

class UEmberAbilitySystemComponent;
class UStatusComponent;
class UEquipmentManagerComponent;
class USpringArmComponent;
class UCameraComponent;
class UC_CharacterMovementComponent;
class UAbilitySystemComponent;
class UCharacterInputComponent;
class UGameplayAbility;
struct FInputActionValue;


UCLASS()
class EMBER_API AEmberPlayerCharacter : public ACharacter, public IAbilitySystemInterface, public IGenericTeamAgentInterface, public IEmberTemperature
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEmberPlayerCharacter(const FObjectInitializer& Init);
	
	virtual void ApplyWarmingEffect_Implementation() override;
	virtual void RemoveWarmingEffect_Implementation() override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCameraComponent* CameraComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UC_CharacterMovementComponent* MovementComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UC_CameraComponent* CameraLogicComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStatusComponent* StatusComponent;
		UPROPERTY(VisibleAnywhere)
	TObjectPtr<UMontageSystemComponent> MontageComponent;
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	FVector2D PitchRange = FVector2D(-50, 50);
	UFUNCTION()
	void Move(const FInputActionValue& value);
	UFUNCTION()
	void Look(const FInputActionValue& value);
	UFUNCTION()
	void StartSprint(const FInputActionValue& value);
	UFUNCTION()
	void StopSprint(const FInputActionValue& value);
	UFUNCTION()
	void Attack(const FInputActionValue& value);

	UFUNCTION(BlueprintCallable, Category = "Status")
	float GetMaxHP() const;

	UFUNCTION(BlueprintCallable, Category = "Status")
	float GetMaxStamina() const;

	UFUNCTION(BlueprintCallable, Category = "Status")
	float GetCurrentHP() const;

	UFUNCTION(BlueprintCallable, Category = "Status")
	float GetCurrentStamina() const;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual FGenericTeamId GetGenericTeamId() const override { return FGenericTeamId(TeamID); }

public:
	//~IAbilitySystemInterface Overrides
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~End of IAbilitySystemInterface Overrides
	void SetAbilitySystemComponent(UAbilitySystemComponent* InASC) { AbilitySystemComponent = InASC; }
	
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	void InitAbilityActorInfo();

	//TODOS
	virtual void PostNetInit() override;

	void SetControlRotation(bool bEnable);
	
private:

	FTimerHandle TemperatureDropTimerHandle;

	UPROPERTY(EditDefaultsOnly, Category = "Temperature")
	float TemperatureDropAmount;

	UPROPERTY(EditDefaultsOnly, Category = "Temperature")
	float TemperatureDropInterval;
    
	void OnTemperatureDropTick();
	void StartPassiveTemperatureDrop();
	void StopPassiveTemperatureDrop();
	
	FTimerHandle WarmingTimerHandle;

	UPROPERTY(EditAnywhere, Category = "Temperature")
	float WarmingAmountPerSecond;

	void OnWarmingTick();
	
	UPROPERTY()
	TObjectPtr<UCharacterInputComponent> CharacterInputComponent;

	UPROPERTY()
	TObjectPtr<UEquipmentManagerComponent> EquipmentManagerComponent;
	
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<class UArmorComponent> ArmorComponent;

#pragma region Inputs

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData", meta = (AllowPrivateAccess = "true"))
	UEmberInputConfig* InputConfigDataAsset;

	void Input_Move(const FInputActionValue& InputActionValue);
	void Input_Look(const FInputActionValue& InputActionValue);

#pragma endregion

private:
	UPROPERTY(EditDefaultsOnly, Category = "Team")
	uint8 TeamID = 1;


protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Abilities", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UGameplayAbility> LeftClickAbilityClass;

	UFUNCTION()
	void OnLeftClick(const FInputActionValue& Value);
public:
	virtual float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator,
		AActor* DamageCauser) override;

protected:
	int attackint = 0;

	float NormalSpeed = 200.0f;
	float SprintSpeed = 350.0f;

	
private:
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;
	UFUNCTION(NetMulticast, Reliable)
	void MulticastHitted(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser);
	UFUNCTION()
	void OnRep_Hitted();
	UFUNCTION(BlueprintCallable)
	void OnDeath();
public:
	void EndDeath();

private:
	UPROPERTY(ReplicatedUsing = "OnRep_Hitted")
	FDamagesData DamageData;
};
