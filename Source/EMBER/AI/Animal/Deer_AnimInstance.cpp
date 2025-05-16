// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Animal/Deer_AnimInstance.h"
#include "AIController.h"
#include "AI/BaseAI.h"
#include "Animation/AnimMontage.h"
#include "BehaviorTree/BlackboardComponent.h"

UDeer_AnimInstance::UDeer_AnimInstance()
{
	bIsIdle = true;
	bIsEat = false;
	bIsLook = false;
}

void UDeer_AnimInstance::PlayTurnMontage(bool direction)
{
	UAnimMontage* TurnMontage;
	if (direction)
	{
		TurnMontage = LeftTurnMontage;
		Montage_Play(LeftTurnMontage);
	}
	else
	{
		TurnMontage = RightTurnMontage;
		Montage_Play(RightTurnMontage);
	}

	FOnMontageEnded EndDelegate;
	EndDelegate.BindUFunction(this, FName("OnTurnMontageEnded"));
	Montage_SetEndDelegate(EndDelegate, TurnMontage);
}

void UDeer_AnimInstance::OnTurnMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	StopAllMontages(0.1f);
	//Montage_Play(AroundMontage);
}

void UDeer_AnimInstance::AnimNotify_IdleFinish()
{
	UE_LOG(LogTemp, Display, TEXT("OnNotifyIdleFinish"));
	Server_OnNotifyIdleFinish_Implementation();
}

void UDeer_AnimInstance::Server_OnNotifyIdleFinish_Implementation()
{
	Multicast_OnNotifyIdleFinish_Implementation();
}

void UDeer_AnimInstance::Multicast_OnNotifyIdleFinish_Implementation()
{
	bIsIdle = false;
	bIsLook = true;
}

void UDeer_AnimInstance::AnimNotify_LookFinish()
{
	Server_OnNotifyLookFinish_Implementation();
}

void UDeer_AnimInstance::Server_OnNotifyLookFinish_Implementation()
{
	Multicast_OnNotifyLookFinish_Implementation();
}

void UDeer_AnimInstance::Multicast_OnNotifyLookFinish_Implementation()
{
	bIsLook = false;
	bIsEat = true;
}

void UDeer_AnimInstance::AnimNotify_EatFinish()
{
	Server_OnNotifyEatFinish_Implementation();
}

void UDeer_AnimInstance::StopMontage()
{
	StopAllMontages(0.1f); // ✅ 블렌드 아웃(0.1초) 후 애니메이션 중지
}

void UDeer_AnimInstance::Server_OnNotifyEatFinish_Implementation()
{
	Multicast_OnNotifyEatFinish_Implementation();
}

void UDeer_AnimInstance::Multicast_OnNotifyEatFinish_Implementation()
{
	if (AAIController* AIController = Cast<AAIController>(Cast<APawn>(GetOwningActor())->GetController()))
	{
		AIController->GetBlackboardComponent()->SetValueAsBool("IsRest", false);
	}
	bIsEat = false;
	bIsIdle = true;
}
