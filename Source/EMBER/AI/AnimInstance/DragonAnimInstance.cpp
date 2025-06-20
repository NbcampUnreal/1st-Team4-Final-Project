#include "AI/AnimInstance/DragonAnimInstance.h"
#include "Boss/Dragon.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Task/BTT_DragonAttack.h"

void UDragonAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Dragon = Cast<ADragon>(TryGetPawnOwner());
}

void UDragonAnimInstance::AnimNotify_SpawnSpit()
{
	if (Dragon)
	{
		Dragon->SpawnSpit();
	}
}

void UDragonAnimInstance::AnimNotify_Fly()
{
	if (Dragon)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Fly Notify"));
		Dragon->LaunchCharacter(FVector(0.f, 0.f, Dragon->GetLaunchZPower()), false, true);
	}
}

void UDragonAnimInstance::AnimNotify_Land()
{
	if (Dragon)
	{
		Dragon->GetCharacterMovement()->GravityScale = 1.f;
	}
}

void UDragonAnimInstance::AnimNotify_LandEnd()
{
	if (Dragon && Dragon->GetController())
	{
		if (UBTT_DragonAttack* Task = Cast<UBTT_DragonAttack>(Dragon->GetCurrentAttackTask()))
		{
			Task->ForceFinishTask();
		}
	}
}

