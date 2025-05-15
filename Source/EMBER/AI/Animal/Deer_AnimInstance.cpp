// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Animal/Deer_AnimInstance.h"

#include "AIController.h"
#include "BaseAIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UDeer_AnimInstance::UDeer_AnimInstance()
{
	bIsIdle = true;
	bIsEat = false;
	bIsLook = false;
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
	APawn* OwningActor = Cast<APawn>(GetOwningActor());
	ABaseAIController* Controller = Cast<ABaseAIController>(OwningActor->GetController());
	Controller->GetBlackboardComponent()->SetValueAsBool("IsRest", false);
	
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

void UDeer_AnimInstance::Server_OnNotifyEatFinish_Implementation()
{
	Multicast_OnNotifyEatFinish_Implementation();
}

void UDeer_AnimInstance::Multicast_OnNotifyEatFinish_Implementation()
{
	AAIController* AIController = Cast<AAIController>(Cast<APawn>(GetOwningActor())->GetController());
	AIController->GetBlackboardComponent()->SetValueAsBool("IsRest", false);

	bIsEat = false;
	bIsIdle = true;
}
