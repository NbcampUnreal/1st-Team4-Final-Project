// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Animation/AnimInstance.h"
#include "EmberMontageSystemComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EMBER_API UEmberMontageSystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UEmberMontageSystemComponent();
protected:
	virtual void BeginPlay() override;
private:
    UFUNCTION(NetMulticast, Reliable)
    void MulticastPlayMontage(UAnimMontage* Montage,float PlayRate = 1.f,FName SectionName = NAME_None);

    UFUNCTION(Server, Reliable, WithValidation)
    void ServerPlayMontage(UAnimMontage* Montage, float PlayRate = 1.f, FName SectionName = NAME_None);
private:
    UPROPERTY()
    USkeletalMeshComponent* MeshComp;
    UPROPERTY()
    UAnimInstance* AnimInstance;
public:
    void PlayMontage(UAnimMontage* Montage, float PlayRate = 1.f,FName SectionName = NAME_None);
};
