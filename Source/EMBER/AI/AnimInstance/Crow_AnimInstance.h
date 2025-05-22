// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI/AnimInstance/BaseAIAnimInstance.h"
#include "Crow_AnimInstance.generated.h"

UENUM(BlueprintType)
enum class ECrowState:uint8
{
	Eating UMETA(DisplayName = "Eating"),
	Looking UMETA(DisplayName = "Looking"),
	Scretching UMETA(DisplayName = "Scratching"),
	Stretching UMETA(DisplayName = "Stretching"),
};

UCLASS()
class EMBER_API UCrow_AnimInstance : public UBaseAIAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AnimNotify_EndEat();
	
	UFUNCTION(BlueprintCallable)
	void AnimNotify_EndLook();
	
	UFUNCTION(BlueprintCallable)
	void AnimNotify_EndScratching();

	UFUNCTION(BlueprintCallable)
	void AnimNotify_EndStretching();




	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
	ECrowState CrowState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
	float Crow_WalkSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
	float Crow_FlySpeed;
};
