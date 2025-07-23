// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GenericTeamAgentInterface.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "EmberCharacter.generated.h"

UCLASS()
class EMBER_API AEmberCharacter : public ACharacter, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEmberCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class UCameraComponent* Camera;

	// Input Actions
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* LookAction;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* JumpAction;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* AttackAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* PickupAction;
	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float WalkSpeed = 300.f;

	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float SprintSpeed = 600.f;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* SprintAction;

	void StartSprinting();
	void StopSprinting();

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	UFUNCTION()
	void Attack();
	// ������ �ݱ� �Լ�
	void PickupItem();
	// Sprint ����



	// ��ȣ�ۿ� �Ÿ�
	UPROPERTY(EditAnywhere, Category = "Interaction")
	float InteractDistance = 300.0f;
	UPROPERTY(EditAnywhere, Category = "Interaction")
	bool bDrawInteractionDebug = true;

/* 팀 설정 */
public:
	//~ IGenericTeamAgentInterface interface
	virtual FGenericTeamId GetGenericTeamId() const override;
	//~ End of IGenericTeamAgentInterface interface
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


};
