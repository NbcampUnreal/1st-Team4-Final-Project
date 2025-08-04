// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterAIBase.h"
#include "AI/MonsterAIController.h"
#include "AI/AbilitySystem/MonsterAbilitySystemComponent.h"
#include "AI/AbilitySystem/MonsterGameplayEffectComponent.h"
#include "AI/AbilitySystem/Abilities/MonsterGameplayAbility.h"
#include "AI/Data/MonsterAIData.h"
#include "AI/Data/MonsterAITemplate.h"
#include "AI/Weapon/MonsterAIWeapon.h"
#include "MonsterAIAttributeSet.h"
#include "GAS/Attribute/EmberAS_Player.h"

AMonsterAIBase::AMonsterAIBase()
{
	AIControllerClass = AMonsterAIController::StaticClass();

	ASC = CreateDefaultSubobject<UMonsterAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	ASC->SetIsReplicated(true);
	ASC->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<UEmberAS_Player>(TEXT("AttributeSet"));
}

void AMonsterAIBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	ASC->InitAbilityActorInfo(this, this);
}

void AMonsterAIBase::BeginPlay()
{
	Super::BeginPlay();
	
	if (HasAuthority())
	{
		InitializeMonsterAI();
	}
}

UMonsterAbilitySystemComponent* AMonsterAIBase::GetMonsterAbilitySystemComponent() const
{
	return Cast<UMonsterAbilitySystemComponent>(ASC);
}

void AMonsterAIBase::InitializeMonsterAI()
{
	const UMonsterAITemplate& MonsterAITemplate = UMonsterAIData::Get().FindMonsterAITemplateByClass(GetClass());

	/* Create Weapon */
	if (MonsterAITemplate.WeaponClass)
	{
		UWorld* World = GetWorld();
		WeaponActor = World->SpawnActorDeferred<AMonsterAIWeapon>(MonsterAITemplate.WeaponClass, FTransform::Identity, this);
		WeaponActor->SetActorRelativeTransform(MonsterAITemplate.WeaponAttachTransform);
		WeaponActor->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, MonsterAITemplate.WeaponAttachSocket);
		WeaponActor->FinishSpawning(FTransform::Identity, true);
	}

	/* Grant Ability*/
	if (ASC)
	{
		for (const FEmberAbilitySet_GameplayAbility& AbilityToGrant : MonsterAITemplate.GrantedGameplayAbilities)
		{
			if (!IsValid(AbilityToGrant.Ability))
				continue;	
			
			UMonsterGameplayAbility* AbilityCDO = AbilityToGrant.Ability->GetDefaultObject<UMonsterGameplayAbility>();

			FGameplayAbilitySpec AbilitySpec(AbilityCDO, 1);
			AbilitySpec.SourceObject = this;
			AbilitySpec.DynamicAbilityTags.AddTag(AbilityToGrant.GameplayTag);

			ASC->GiveAbility(AbilitySpec);
		}
	}
}

UAbilitySystemComponent* AMonsterAIBase::GetAbilitySystemComponent() const
{
	return ASC;
}
