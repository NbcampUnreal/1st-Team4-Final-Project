#include "BaseAIAnimInstance.h"
#include "BaseAI.h"
#include "GameFramework/Pawn.h"    
#include "BehaviorTree/BlackboardComponent.h" 
#include "KismetAnimationLibrary.h"

void UBaseAIAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	APawn* OwnerPawn = TryGetPawnOwner();
	if (!OwnerPawn) return;
	ABaseAIController* AIController = Cast<ABaseAIController>(OwnerPawn->GetController());
	if (!AIController) return;
	BlackboardComp = AIController->GetBlackboardComponent();
	if (!BlackboardComp) return;
}

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
}

void UBaseAIAnimInstance::PlayMontage(EAnimActionType Desired, EAnimActionType Fallback)
{
	UAnimMontage* MontageToPlay = nullptr;
	EAnimActionType FinalType = Desired;

	if (AnimSectionMap.Contains(Desired))
	{
		MontageToPlay = GetMontageToPlay(Desired);
	}
	else if (AnimSectionMap.Contains(Fallback))
	{
		MontageToPlay = GetMontageToPlay(Fallback);
		FinalType = Fallback;
	}

	if (!MontageToPlay) return;

	Montage_Play(MontageToPlay);
	Montage_JumpToSection(AnimSectionMap[FinalType], MontageToPlay);
}

void UBaseAIAnimInstance::PlayMontage()
{
	UAnimMontage* MontageToPlay = GetMontageToPlay();
	if (!MontageToPlay) return;
	
	Montage_Play(MontageToPlay);
}

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

UAnimMontage* UBaseAIAnimInstance::GetMontageToPlay()
{
	switch (AnimalState)
	{
		case EAnimalState::Idle:
			return IdleMontage;
		case EAnimalState::Death:
			return DeathMontage;
		
		default:
			return nullptr;
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