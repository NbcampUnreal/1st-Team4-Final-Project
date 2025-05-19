// Fill out your copyright notice in the Description page of Project Settings.


#include "EmberAbilitySet.h"

#include "System/AbilitySystem/EmberAbilitySystemComponent.h"
#include "System/AbilitySystem/Abilities/EmberGameplayAbility.h"

void FEmberAbilitySet_GrantedHandles::AddAbilitySpecHandle(const FGameplayAbilitySpecHandle& Handle)
{
	if (Handle.IsValid())
	{
		AbilitySpecHandles.Add(Handle);
	}
}

void FEmberAbilitySet_GrantedHandles::TakeFromAbilitySystem(UEmberAbilitySystemComponent* EmberASC)
{
	if (!EmberASC->IsOwnerActorAuthoritative())
	{
		return;
	}

	for (const FGameplayAbilitySpecHandle& Handle : AbilitySpecHandles)
	{
		if (Handle.IsValid())
		{
			EmberASC->ClearAbility(Handle);
		}
	}

	GrantedAttributeSets.Reset();
}

UEmberAbilitySet::UEmberAbilitySet(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UEmberAbilitySet::GiveToAbilitySystem(UEmberAbilitySystemComponent* EmberASC, FEmberAbilitySet_GrantedHandles* OutGrantedHandles, UObject* SourceObject) const
{
	check(EmberASC);

	if (EmberASC->IsOwnerActorAuthoritative() == false)
	{
		return;
	}
	
	for (int32 AbilityIndex = 0; AbilityIndex < GrantedGameplayAbilities.Num(); ++AbilityIndex)
	{
		const FEmberAbilitySet_GameplayAbility& AbilityToGrant = GrantedGameplayAbilities[AbilityIndex];

		if (!IsValid(AbilityToGrant.Ability))
		{
			continue;
		}

		UEmberGameplayAbility* AbilityCDO = AbilityToGrant.Ability->GetDefaultObject<UEmberGameplayAbility>();

		FGameplayAbilitySpec AbilitySpec(AbilityCDO, AbilityToGrant.AbilityLevel);
		AbilitySpec.SourceObject = SourceObject;
		AbilitySpec.GetDynamicSpecSourceTags().AddTag(AbilityToGrant.InputTag);

		const FGameplayAbilitySpecHandle AbilitySpecHandle = EmberASC->GiveAbility(AbilitySpec);

		if (OutGrantedHandles)
		{
			OutGrantedHandles->AddAbilitySpecHandle(AbilitySpecHandle);
		}
	}
}
