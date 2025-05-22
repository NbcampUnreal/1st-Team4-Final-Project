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

		CurrentSpeed = Velocity.Size();
		CurrentDirection = UKismetAnimationLibrary::CalculateDirection(Velocity, AICharacter->GetActorRotation());
	}
	
	APawn* OwnerPawn = TryGetPawnOwner();
	if (!OwnerPawn) return;
	ABaseAIController* AIController = Cast<ABaseAIController>(OwnerPawn->GetController());
	if (!AIController) return;
	BlackboardComp = AIController->GetBlackboardComponent();
	if (!BlackboardComp) return;
}

void UBaseAIAnimInstance::PlayMontage(EAnimActionType ActionType)
{
	UAnimMontage* MontageToPlay = GetMontageToPlay(ActionType);
	if (!MontageToPlay || !AnimSectionMap.Contains(ActionType)) return;

	Montage_Play(MontageToPlay);
	Montage_JumpToSection(AnimSectionMap[ActionType], MontageToPlay);
}

void UBaseAIAnimInstance::PlayDeathMontage()
{
	if (DeathMontage)
	{
		Montage_Play(DeathMontage);
	}
}
#pragma region Interface

UAnimMontage* UBaseAIAnimInstance::GetMontageToPlay(EAnimActionType ActionType) const
{
	switch (ActionType)
	{
	case EAnimActionType::AttackNormal:
	case EAnimActionType::AttackRun:
	case EAnimActionType::AttackJump:
		return AttackMontage;

	case EAnimActionType::HitFront:
	case EAnimActionType::HitLeft:
	case EAnimActionType::HitRight:
		return HitMontage;

	default:
		return nullptr;
	}
}

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