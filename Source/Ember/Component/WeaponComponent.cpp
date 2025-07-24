#include "Component/WeaponComponent.h"

#include "GameFramework/Character.h"
#include "Utility/CLog.h"

UWeaponComponent::UWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	
}

void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	OwnerCharacter = Cast<ACharacter>(GetOwner());
	if (OwnerCharacter == nullptr)
	{
		DebugLogE("Owner Character is null");
		return;
	}

	if (WeaponAsset == nullptr)
	{
		DebugLogE("Weapon Data is null");
		return;
	}
	WeaponAsset->Beginplay(OwnerCharacter);
}

void UWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

