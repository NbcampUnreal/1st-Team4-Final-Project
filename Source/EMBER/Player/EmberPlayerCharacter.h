// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "C_CameraComponent.h"
#include "GenericTeamAgentInterface.h"
#include "Input/CharacterInputComponent.h"
#include "Component/MontageSystemComponent.h"
#include "EmberPlayerCharacter.generated.h"

class UStatusComponent;
class UEquipmentManagerComponent;
class USpringArmComponent;
class UCameraComponent;
class UC_CharacterMovementComponent;
class UAbilitySystemComponent;
class UCharacterInputComponent;

struct FInputActionValue;
UCLASS()

class EMBER_API AEmberPlayerCharacter : public ACharacter
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEmberPlayerCharacter(const FObjectInitializer& Init);	

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
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStatusComponent* StatusComponent;
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
	UFUNCTION()
	void StartJump(const FInputActionValue& value);

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

protected:
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	void InitAbilityActorInfo();

	//TODOS
	virtual void PostNetInit() override;
public:
	virtual FGenericTeamId GetGenericTeamId() const override { return FGenericTeamId(TeamID); }
private:
	UPROPERTY()
	TObjectPtr<UCharacterInputComponent> CharacterInputComponent;

	UPROPERTY()
	TObjectPtr<UEquipmentManagerComponent> EquipmentManagerComponent;
	
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UMontageSystemComponent> MontageComponent;

	UPROPERTY()
	TObjectPtr<class UArmorComponent> ArmorComponent;
};
