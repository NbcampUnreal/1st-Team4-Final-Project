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
#include "Component/RuneSystemComponent.h"
#include "Components/SphereComponent.h"
#include "Component/LootDropManagerComponent.h"
#include "EmberCharacter.generated.h"


class UGameplayEffect;
class UGameplayAbility;
class UWeaponComponent;

UCLASS()
class EMBER_API AEmberCharacter : public ACharacter, public IAbilitySystemInterface, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	AEmberCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UAbilitySystemComponent* GetASC() const { return ASC; }
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	/* 팀 설정 */
		//~| IGenericTeamAgentInterface interface
	virtual FGenericTeamId GetGenericTeamId() const override;
	//~ End of IGenericTeamAgentInterface interface
	void PickupItem();
	//룬 장착용 함수
	UFUNCTION(BlueprintCallable, Category = "Rune")
	bool TryEquipRune(class ARuneItem* NewRune);
	
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
	TArray< TSubclassOf<UGameplayAbility >> InputAbilities;

	UPROPERTY(EditAnywhere, Category = "GAS")
	TSubclassOf<UGameplayEffect> GETemperature;
	UPROPERTY(EditAnywhere, Category = "GAS|TemperaturLevel")
	float TemperatureLeve = 1.0f;
	UPROPERTY(EditAnywhere, Category = "GAS|TemperaturLevel")
	int32 MaxCount = 10.0f;
	int32 Count;


protected:
	virtual void BeginPlay() override;
	UFUNCTION()
	void Attack();
	void SetupGASInputComponent();
	void GASInputPressed(int32 Input);
	void GASInputReleased(int32 Input);
	UPROPERTY()
	TArray<APickupItemActor*> OverlappingItems;
	UFUNCTION()
	void OnPickupBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnPickupEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	// 룬 시스템 선언
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<URuneSystemComponent> RuneSystem;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup")
	USphereComponent* PickupSphere;
	UPROPERTY(EditAnywhere, Category = "Interaction")
	float InteractDistance = 500.0f;
	UPROPERTY(EditAnywhere, Category = "Interaction")
	bool bDrawInteractionDebug = true;

	void DamageTemperature();

	
private:
	TObjectPtr<class AEmberPlayerController> PlayerController;

	FTimerHandle Timer;
};
