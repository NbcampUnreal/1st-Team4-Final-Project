#include "AI/AnimInstance/Griffon_AnimInstance.h"
#include "KismetAnimationLibrary.h"
#include "SceneRenderTargetParameters.h"
#include "AI/Base/BaseAI.h"
#include "GameFramework/CharacterMovementComponent.h"



void UGriffon_AnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
}

void UGriffon_AnimInstance::NativeUpdateAnimation(float DeltaSeconds)
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

		CurrentFlySpeed = FVector(Velocity.X, Velocity.Y, Velocity.Z).Size();
	}

	

	
}
