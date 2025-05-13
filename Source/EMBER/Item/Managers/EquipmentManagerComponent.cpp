// Fill out your copyright notice in the Description page of Project Settings.

#include "EquipmentManagerComponent.h"

#include "GameFlag.h"
#include "ItemInstance.h"
#include "ItemTemplate.h"
#include "Equipment/EquipmentBase.h"
#include "Fragments/ItemFragment_Equipable_Weapon.h"
#include "GameFramework/Character.h"
#include "Net/UnrealNetwork.h"
#include "System/EmberAssetManager.h"
#include "UI/Data/EmberItemData.h"
#include "MontageSystemComponent.h"
UEquipmentManagerComponent::UEquipmentManagerComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SetIsReplicatedByDefault(true);
}

void UEquipmentManagerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, ItemTemplateID);
}

void UEquipmentManagerComponent::AddEquipment(EWeaponSlotType WeaponSlotType, TSubclassOf<UItemTemplate> ItemTemplateClass)
{
	if (WeaponSlotType == EWeaponSlotType::Count || ItemTemplateClass == nullptr)
		return;

	const UItemTemplate* ItemTemplate = ItemTemplateClass.GetDefaultObject();
	if (ItemTemplate == nullptr)
		return;
	
	ACharacter* OwnerCharacter = Cast<ACharacter>(GetOwner());
	if (OwnerCharacter == nullptr)
		return;

	USkeletalMeshComponent* CharacterMeshComponent = OwnerCharacter->GetMesh();
	if (CharacterMeshComponent == nullptr)
		return;

	if (SpawnedWeapon)
	{
		SpawnedWeapon->Destroy();
	}
	
	UItemInstance* ItemInstance = NewObject<UItemInstance>();
	int32 NewItemTemplateID = UEmberItemData::Get().FindItemTemplateIDByClass(ItemTemplateClass);
	EItemRarity RandomItemRarity = (EItemRarity)FMath::RandRange(0, (int32)EItemRarity::Count - 1);
	ItemInstance->Init(NewItemTemplateID, RandomItemRarity);

	
	if (const UItemFragment_Equipable_Attachment* AttachmentFragment = ItemInstance->FindFragmentByClass<UItemFragment_Equipable_Attachment>())
	{
		// 아이템 스폰
		const FItemAttachInfo& AttachInfo = AttachmentFragment->ItemAttachInfo;
		if (AttachInfo.SpawnEquipmentClass)
		{
			UWorld* World = GetWorld();
			SpawnedWeapon = World->SpawnActorDeferred<AEquipmentBase>(AttachInfo.SpawnEquipmentClass, FTransform::Identity, OwnerCharacter);
			SpawnedWeapon->SetActorRelativeTransform(AttachInfo.AttachTransform);
			SpawnedWeapon->AttachToComponent(CharacterMeshComponent, FAttachmentTransformRules::KeepRelativeTransform, AttachInfo.AttachSocket);
			SpawnedWeapon->FinishSpawning(FTransform::Identity, true);

			FEquipment Data = AttachmentFragment->GetEquipmentInfo();

			if (Data.DrawMontage)
			{
				if (UMontageSystemComponent* MontageComp = OwnerCharacter->FindComponentByClass<UMontageSystemComponent>())
				{
					MontageComp->PlayMontage(Data.DrawMontage);
				}
			}
		}
	}

	ItemTemplateID = NewItemTemplateID;
}

void UEquipmentManagerComponent::OnRep_ItemTemplateID(int32 PrevItemTemplateID)
{
	if (ItemTemplateID == PrevItemTemplateID)
		return;

	ACharacter* OwnerCharacter = Cast<ACharacter>(GetOwner());
	if (OwnerCharacter == nullptr)
		return;

	USkeletalMeshComponent* CharacterMeshComponent = OwnerCharacter->GetMesh();
	if (CharacterMeshComponent == nullptr)
		return;

	const UItemTemplate& ItemTemplate = UEmberItemData::Get().FindItemTemplateByID(ItemTemplateID);

	if (const UItemFragment_Equipable_Attachment* AttachmentFragment = ItemTemplate.FindFragmentByClass<UItemFragment_Equipable_Attachment>())
	{
		FEquipment Data = AttachmentFragment->GetEquipmentInfo();

		if (Data.DrawMontage)
		{
			if (UMontageSystemComponent* MontageComp = OwnerCharacter->FindComponentByClass<UMontageSystemComponent>())
			{
				MontageComp->PlayMontage(Data.DrawMontage);
			}
		}
	}
}

FAttackData UEquipmentManagerComponent::GetAttackInfo() const
{
	FAttackData AttackInfo;

	if (ItemTemplateID == INDEX_NONE)
		return AttackInfo;
	
	const UItemTemplate& ItemTemplate = UEmberItemData::Get().FindItemTemplateByID(ItemTemplateID);

	if (UItemFragment_Equipable_Weapon* WeaponFragment = ItemTemplate.FindFragmentByClass<UItemFragment_Equipable_Weapon>())
	{
		AttackInfo = WeaponFragment->GetAttackInfo();
		WeaponFragment->IncrementMontageIndex();
	}

	return AttackInfo;
}
