#pragma once

#include "CoreMinimal.h"
#include "AnimInstance/BaseAIAnimInstance.h"
#include "Deer_AnimInstance.generated.h"


UCLASS()
class EMBER_API UDeer_AnimInstance : public UBaseAIAnimInstance
{
	GENERATED_BODY()
	UDeer_AnimInstance();

public:
	void PlayTurnMontage(bool direction);
	UFUNCTION()
	void OnTurnMontageEnded(UAnimMontage* Montage, bool bInterrupted);
	
	UFUNCTION(BlueprintCallable)
	void AnimNotify_IdleFinish();
	UFUNCTION(Server, Reliable)
	void Server_OnNotifyIdleFinish();
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_OnNotifyIdleFinish();
	
	UFUNCTION(BlueprintCallable)
	void AnimNotify_LookFinish();
	UFUNCTION(Server, Reliable)
	void Server_OnNotifyLookFinish();
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_OnNotifyLookFinish();
	
	UFUNCTION(BlueprintCallable)
	void AnimNotify_EatFinish();
	UFUNCTION(Server, Reliable)
	void Server_OnNotifyEatFinish();
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_OnNotifyEatFinish();

	UPROPERTY(BlueprintReadWrite, Category = "Animation")
	bool bIsIdle;
	UPROPERTY(BlueprintReadWrite, Category = "Animation")
	bool bIsEat;
	UPROPERTY(BlueprintReadWrite, Category = "Animation")
	bool bIsLook;

virtual void SetBlackboardBool(FName KeyName, bool bValue) override;
	
	UPROPERTY(BlueprintReadWrite, Category = "Animation")
	UAnimMontage* LeftTurnMontage;

	UPROPERTY(BlueprintReadWrite, Category = "Animation")
	UAnimMontage* RightTurnMontage;

	UPROPERTY(BlueprintReadWrite, Category = "Animation")
	UAnimMontage* AroundMontage;
	
	void StopMontage();
	
	FTimerHandle TurnMontageTimer;
};
