﻿#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFlag.h"
#include "InputActionValue.h"
#include "C_CharacterMovementComponent.generated.h"

// 델리게이트 선언: FVector2D를 파라미터로 받는 동적 멀티캐스트 델리게이트
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveDelegate, FVector2D, MoveVector);

UCLASS()
class EMBER_API UC_CharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere, category = "Move")
	bool bCanMove;
	UPROPERTY(EditAnywhere, category = "Move")
	bool bIsDash;
	//UPROPERTY(EditAnywhere, category = "State")
	class UC_StateComponent* State;
	UPROPERTY(EditAnywhere, category = "Base")
	class ACharacter* OwnerCharacter;
	UPROPERTY(EditAnywhere, category = "Move")
	ESpeedType SpeedType;
protected:	//	재정의
	virtual void BeginPlay() override;
	virtual float GetMaxSpeed() const override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
public:	//	추가
	UFUNCTION(BlueprintCallable)
	bool GetCanMove() const;
	UFUNCTION(BlueprintCallable)
	bool GetCanDash() const;
	UFUNCTION(BlueprintCallable)
	float GetCurrentSpeed() const;
	UFUNCTION(BlueprintCallable)
	void OnMove(const FInputActionValue& Value);
public: 
	UPROPERTY(BlueprintAssignable, Category = "Movement")
	FOnMoveDelegate OnMoveDelegate;
};
