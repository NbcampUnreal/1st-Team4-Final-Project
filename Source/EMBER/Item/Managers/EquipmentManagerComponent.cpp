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
	
	const UItemFragment_Equipable_Weapon* WeaponFragment = ItemTemplate->FindFragmentByClass<UItemFragment_Equipable_Weapon>();
	if (WeaponFragment == nullptr)
		return;

	ACharacter* OwnerCharacter = Cast<ACharacter>(GetOwner());
	if (OwnerCharacter == nullptr)
		return;

	USkeletalMeshComponent* CharacterMeshComponent = OwnerCharacter->GetMesh();
	if (CharacterMeshComponent == nullptr)
		return;
	
	UItemInstance* ItemInstance = NewObject<UItemInstance>();
	int32 NewItemTemplateID = UEmberItemData::Get().FindItemTemplateIDByClass(ItemTemplateClass);
	EItemRarity RandomItemRarity = (EItemRarity)FMath::RandRange(0, (int32)EItemRarity::Count - 1);
	ItemInstance->Init(NewItemTemplateID, RandomItemRarity);

	// 아이템 스폰
	const UItemFragment_Equipable_Attachment* AttachmentFragment = ItemInstance->FindFragmentByClass<UItemFragment_Equipable_Attachment>();
	const FItemAttachInfo& AttachInfo = AttachmentFragment->ItemAttachInfo;
	if (AttachInfo.SpawnEquipmentClass)
	{
		UWorld* World = GetWorld();
		AEquipmentBase* NewWeaponActor = World->SpawnActorDeferred<AEquipmentBase>(AttachInfo.SpawnEquipmentClass, FTransform::Identity, OwnerCharacter);
		NewWeaponActor->SetActorRelativeTransform(AttachInfo.AttachTransform);
		NewWeaponActor->AttachToComponent(CharacterMeshComponent, FAttachmentTransformRules::KeepRelativeTransform, AttachInfo.AttachSocket);
		NewWeaponActor->FinishSpawning(FTransform::Identity, true);
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
		UAnimMontage* EquipMontage = UEmberAssetManager::GetAssetByPath<UAnimMontage>(AttachmentFragment->EquipMontage);
		OwnerCharacter->PlayAnimMontage(EquipMontage);
	}
}

UAnimMontage* UEquipmentManagerComponent::GetAttackAnimMontage()
{
	if (ItemTemplateID == INDEX_NONE)
		return nullptr;
	
	const UItemTemplate& ItemTemplate = UEmberItemData::Get().FindItemTemplateByID(ItemTemplateID);

	if (const UItemFragment_Equipable_Weapon* WeaponFragment = ItemTemplate.FindFragmentByClass<UItemFragment_Equipable_Weapon>())
	{
		return UEmberAssetManager::GetAssetByPath<UAnimMontage>(WeaponFragment->AttackMontage);
	}

	return nullptr;
}
