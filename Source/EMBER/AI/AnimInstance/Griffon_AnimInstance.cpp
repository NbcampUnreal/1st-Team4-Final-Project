#include "AI/AnimInstance/Griffon_AnimInstance.h"
#include "KismetAnimationLibrary.h"
#include "AI/Base/BaseAI.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


void UGriffon_AnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
}

void UGriffon_AnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
}


void UGriffon_AnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	 if (ABaseAI* AI = Cast<ABaseAI>(TryGetPawnOwner()))
	 {
	 	FVector Velocity = AI->GetVelocity();
	 	CurrentSpeed = FVector(Velocity.X, Velocity.Y, 0.0f).Size();
	 	CurrentHeight = AI->GetActorLocation().Z;
	 	CurrentDirection = UKismetAnimationLibrary::CalculateDirection(FVector(Velocity.X, Velocity.Y, 0.0f),
																		AI->GetActorRotation());
	 	CurrentFlySpeed = FVector(Velocity.X, Velocity.Y, Velocity.Z).Size();
	 	
	 	if (Controller = Cast<ACAIController>(AI->GetController()))
	 	{
	 		if (Blackboard = Cast<UBlackboardComponent>(Controller->GetBlackboardComponent()))
	 		{
	 			bool Phase2 = Blackboard->GetValueAsBool("IsHarfHP");
	 			if ( AI->GetCharacterMovement()->IsFalling() || Phase2)
	 			{
	 				bIsAirborne = true;
	 				// UE_LOG(LogTemp,Warning,L"%d",AI->GetCharacterMovement()->IsFalling());
	 			}
	 		}
	 	}
	 }

}