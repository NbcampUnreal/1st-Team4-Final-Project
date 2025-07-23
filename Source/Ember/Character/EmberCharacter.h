// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "EmberCharacter.generated.h"

UCLASS()
class EMBER_API AEmberCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TObjectPtr<class USpringArmComponent> SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TObjectPtr<class UCameraComponent> Camera;

	// Sprint ฐüทร
	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float WalkSpeed = 300.f;

	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float SprintSpeed = 600.f;

	//GAS
	UPROPERTY(EditAnywhere, Category = "GAS")
	TObjectPtr<UAbilitySystemComponent> ASC;
	UPROPERTY(EditAnywhere, Category = "GAS")
	TMap<int32, TSubclassOf<class UGameplayAbility>> GameAbilities;
public:
	AEmberCharacter();

protected:
	virtual void BeginPlay() override;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	UFUNCTION()
	void Attack();

	void StartSprinting();
	void StopSprinting();

public:
	virtual void PossessedBy(AController* NewController) override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	void SetupGASInputComponent();
	void GASInputPressed(int32 Input);
	void GASInputReleased(int32 Input);

public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

private:
	TObjectPtr<class AEmberPlayerController> PlayerController;
};
