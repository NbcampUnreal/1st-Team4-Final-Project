#include "AI/Animal/Fox.h"
#include "AI/AnimInstance/FoxAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "UniversalObjectLocators/AnimInstanceLocatorFragment.h"

AFox::AFox()
{
	AttackPower = 1.f;
	WalkSpeed = 150.f;
	RunSpeed = 600.f;
}
