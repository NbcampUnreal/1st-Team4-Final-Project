#pragma once

#include "CoreMinimal.h"
#include "AI/BaseAIAnimInstance.h"
#include "Deer_AnimInstance.generated.h"


UCLASS()
class EMBER_API UDeer_AnimInstance : public UBaseAIAnimInstance
{
	GENERATED_BODY()
	UDeer_AnimInstance();

public:
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
};
