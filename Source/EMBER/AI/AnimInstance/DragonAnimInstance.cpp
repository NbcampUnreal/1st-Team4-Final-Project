#include "AI/AnimInstance/DragonAnimInstance.h"
#include "Boss/Dragon.h"
#include "GameFramework/CharacterMovementComponent.h"

void UDragonAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
}

void UDragonAnimInstance::AnimNotify_SpawnSpit()
{
	if (ADragon* Dragon = Cast<ADragon>(TryGetPawnOwner()))
	{
		Dragon->SpawnSpit();
	}
}

void UDragonAnimInstance::AnimNotify_Fly()
{
	if (ADragon* Dragon = Cast<ADragon>(TryGetPawnOwner()))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Fly Notify"));

		Dragon->LaunchCharacter(FVector(0.f, 0.f, Dragon->GetLaunchZPower()), false, true);
	}
}

void UDragonAnimInstance::AnimNotify_Land()
{
	if (ADragon* Dragon = Cast<ADragon>(TryGetPawnOwner()))
	{
		Dragon->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	}
}

