// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GenericTeamAgentInterface.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "EmberCharacter.generated.h"

class UWeaponComponent;

UCLASS()
class EMBER_API AEmberCharacter : public ACharacter, public IAbilitySystemInterface, public IGenericTeamAgentInterface
{
	GENERATED_BODY()
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TObjectPtr<class USpringArmComponent> SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TObjectPtr<class UCameraComponent> Camera;

	UPROPERTY(VisibleAnywhere, Category = Component)
	TObjectPtr<class UCustomMoveComponent> MoveComponent;
	UPROPERTY(VisibleAnywhere, Category = Component)
	TObjectPtr<class UCustomCameraComponent> CameraComponent;
	UPROPERTY(VisibleAnywhere, Category = Component)
	TObjectPtr<UWeaponComponent> WeaponComponent;

	//GAS
	UPROPERTY(EditAnywhere, Category = "GAS")
	TObjectPtr<UAbilitySystemComponent> ASC;
	UPROPERTY(EditAnywhere, Category = "GAS")
	TMap<int32, TSubclassOf<class UGameplayAbility>> GameAbilities;

public:
	AEmberCharacter();

protected:
	virtual void BeginPlay() override;
	UFUNCTION()
	void Attack();
	
void PickupItem();
	
	UPROPERTY(EditAnywhere, Category = "Interaction")
	float InteractDistance = 300.0f;
	UPROPERTY(EditAnywhere, Category = "Interaction")
	bool bDrawInteractionDebug = true;

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

public:
	//~ IGenericTeamAgentInterface interface
	virtual FGenericTeamId GetGenericTeamId() const override;
	//~ End of IGenericTeamAgentInterface interface
	
private:
	TObjectPtr<class AEmberPlayerController> PlayerController;
};
