// Fill out your copyright notice in the Description page of Project Settings.


#include "EmberAbilitySystemComponent.h"

UEmberAbilitySystemComponent::UEmberAbilitySystemComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UEmberAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UEmberAbilitySystemComponent::TryActivateAbilityByTag(const FGameplayTag& GameplayTag)
{
	if (GetOwner()->HasAuthority() == false)
		return false;
	
	bool bSuccess = false;
	
	if (GameplayTag.IsValid())
	{
		for (const FGameplayAbilitySpec& AbilitySpec : ActivatableAbilities.Items)
		{
			if (AbilitySpec.Ability && (AbilitySpec.DynamicAbilityTags.HasTagExact(GameplayTag)))
			{
				bSuccess |= TryActivateAbility(AbilitySpec.Handle, true);
			}
		}
	}

	return bSuccess;
}
