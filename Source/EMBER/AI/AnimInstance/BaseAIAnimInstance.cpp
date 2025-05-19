// Fill out your copyright notice in the Description page of Project Settings.

#include "AIController.h"          
#include "GameFramework/Pawn.h"    
#include "Animation/AnimInstance.h" 
#include "BaseAIAnimInstance.h"
#include "BehaviorTree/BlackboardComponent.h" 
#include "BaseAIController.h"

void UBaseAIAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	APawn* OwnerPawn = TryGetPawnOwner();
	if (!OwnerPawn) return;
	ABaseAIController* AIController = Cast<ABaseAIController>(OwnerPawn->GetController());
	if (!AIController) return;
	BlackboardComp = AIController->GetBlackboardComponent();
	if (!BlackboardComp) return;
}

void UBaseAIAnimInstance::PlayAttackMontage()
{
	if (AttackMontage)
	{
		Montage_Play(AttackMontage);
	}
}

void UBaseAIAnimInstance::PlayDeathMontage()
{
	if (DeathMontage)
	{
		Montage_Play(DeathMontage);
	}
}
#pragma region Interface

void UBaseAIAnimInstance::SetBlackboardBool(FName KeyName, bool bValue)
{
	BlackboardComp->SetValueAsBool(KeyName, bValue);
}

void UBaseAIAnimInstance::SetBlackboardInt(FName KeyName, int value)
{
	BlackboardComp->SetValueAsInt(KeyName, value);
}

void UBaseAIAnimInstance::SetBlackboardFloat(FName KeyName, float value)
{
	BlackboardComp->SetValueAsFloat(KeyName, value);
}

void UBaseAIAnimInstance::SetBlackboardVector(FName KeyName, FVector value)
{
	BlackboardComp->SetValueAsVector(KeyName, value);
}

void UBaseAIAnimInstance::SetBlackboardObject(FName KeyName, UObject* object)
{
	BlackboardComp->SetValueAsObject(KeyName, object);
}
#pragma endregion