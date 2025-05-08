// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Animation/AnimInstance.h"
#include "Net/UnrealNetwork.h"
#include "MontageSystemComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EMBER_API UMontageSystemComponent : public UActorComponent
{
	GENERATED_BODY()
public:	
	UMontageSystemComponent();
protected:
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
public:
	/** Montage 재생 요청 (클라이언트 호출) */
	UFUNCTION(BlueprintCallable, Category = "Animation")
	void RequestPlayMontage(UAnimMontage* Montage, float PlayRate = 1.0f, FName SectionName = NAME_None);

	/** 서버에서 몽타주 재생하기 (실제 재생 함수) */
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerPlayMontage(UAnimMontage* Montage, float PlayRate, FName SectionName);

	/** 모든 클라이언트에게 몽타주 재생 명령 broadcast */
	UFUNCTION(NetMulticast, Reliable)
	void MulticastPlayMontage(UAnimMontage* Montage, float PlayRate, FName SectionName);
protected:
	/** 현재 재생 중인 애니메이션 인스턴스 */
	UAnimInstance* AnimInstance;

	UPROPERTY(Replicated)
	UAnimMontage* CurrentMontage;
public:
	void OnMontageEnded(UAnimMontage* Montage, bool bInterrupted);
	// 네트워크 요청 함수
	bool ValidateRequestPlayMontage(UAnimMontage* Montage, float PlayRate, FName SectionName);
};
