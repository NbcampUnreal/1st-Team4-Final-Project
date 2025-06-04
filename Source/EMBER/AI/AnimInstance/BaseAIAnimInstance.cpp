#include "BaseAIAnimInstance.h"
#include "BaseAI.h"
#include "KismetAnimationLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"

void UBaseAIAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	ABaseAI* AICharacter = Cast<ABaseAI>(TryGetPawnOwner());
	if (!AICharacter) return;
	ABaseAIController* AIController = Cast<ABaseAIController>(AICharacter->GetController());
	if (!AIController) return;

	for (uint8 i = 0; i < static_cast<uint8>(EAnimActionType::MAX); ++i)
	{
		EAnimActionType ActionType = static_cast<EAnimActionType>(i);

		if (!AnimSectionMap.Contains(ActionType))
		{
			AnimSectionMap.Add(ActionType, FName("Default"));
		}
	}
}

void UBaseAIAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (ABaseAI* AICharacter = Cast<ABaseAI>(TryGetPawnOwner()))
	{
		FVector Velocity = AICharacter->GetVelocity();
		bIsAirborne = AICharacter->GetCharacterMovement()->IsFalling();

		CurrentSpeed = FVector(Velocity.X, Velocity.Y, 0.0f).Size();
		CurrentHeight = AICharacter->GetActorLocation().Z;
		CurrentDirection = UKismetAnimationLibrary::CalculateDirection(FVector(Velocity.X, Velocity.Y, 0.0f),
		                                                               AICharacter->GetActorRotation());
	}
}

void UBaseAIAnimInstance::PlayMontage()
{
	UAnimMontage* MontageToPlay = nullptr;
	EAnimActionType FinalType = DesiredActionType;

	if (AnimSectionMap.Contains(DesiredActionType))
	{
		MontageToPlay = GetMontageToPlay(DesiredActionType);
	}
	else if (AnimSectionMap.Contains(FallbackActionType))
	{
		MontageToPlay = GetMontageToPlay(FallbackActionType);
		FinalType = FallbackActionType;
	}

	if (!MontageToPlay) return;

	Montage_Play(MontageToPlay);
	Montage_JumpToSection(AnimSectionMap[FinalType], MontageToPlay);
}

// void UBaseAIAnimInstance::PlayStateMontage()
// {
// 	UAnimMontage* PlayingMontage = GetMontageToPlay();
// 	UE_LOG(LogTemp, Warning, TEXT("Montage: %s"), *UEnum::GetValueAsString(AnimalState));
// 	if (PlayingMontage)
// 	{
// 		UE_LOG(LogTemp,Error, TEXT("Montage: %s"), *PlayingMontage->GetName());
// 		Montage_Play(PlayingMontage);
// 	}
// }

UAnimMontage* UBaseAIAnimInstance::GetMontageToPlay(EAnimActionType ActionType) const
{
	switch (ActionType)
	{
	case EAnimActionType::Idle:
		return IdleMontage;

	case EAnimActionType::Death:
		return DeathMontage;
		
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

// UAnimMontage* UBaseAIAnimInstance::GetMontageToPlay()
// {
// 	switch (AnimalState)
// 	{
// 	case EAnimalState::Idle:
// 		return IdleMontage;
// 	case EAnimalState::Death:
// 		return DeathMontage;
// 	case EAnimalState::Attack:
// 		return AttackMontage;
// 	case EAnimalState::Hit:
// 		return HitMontage;
//
// 	default:
// 		return nullptr;
// 	}
// }
