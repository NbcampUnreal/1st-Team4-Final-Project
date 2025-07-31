// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterAbilitySystemComponent.h"

UMonsterAbilitySystemComponent::UMonsterAbilitySystemComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UMonsterAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UMonsterAbilitySystemComponent::TryActivateAbilityByTag(const FGameplayTag& GameplayTag)
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
