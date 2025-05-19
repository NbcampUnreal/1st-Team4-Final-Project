#include "BaseAIAnimInstance.h"
#include "BaseAI.h"
#include "GameFramework/Pawn.h"    
#include "BehaviorTree/BlackboardComponent.h" 
#include "KismetAnimationLibrary.h"

void UBaseAIAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (ABaseAI* AICharacter = Cast<ABaseAI>(TryGetPawnOwner()))
	{
		FVector Velocity = AICharacter->GetVelocity();
		Velocity.Z = 0.0f;

		Speed = Velocity.Size();
		Direction = UKismetAnimationLibrary::CalculateDirection(Velocity, AICharacter->GetActorRotation());
	}
	
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