// Fill out your copyright notice in the Description page of Project Settings.

#include "EquipmentManagerComponent.h"

#include "ArmorComponent.h"
#include "C_StateComponent.h"
#include "EmberPlayerCharacter.h"
#include "EmberPlayerState.h"
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
#include "Fragments/ItemFragment_Equipable_Armor.h"
#include "System/AbilitySystem/EmberAbilitySystemComponent.h"


UEquipmentManagerComponent::UEquipmentManagerComponent(const FObjectInitializer& ObjectInitializer) : Super(
	ObjectInitializer)
{
	SetIsReplicatedByDefault(true);
}

void UEquipmentManagerComponent::BeginPlay()
{
	Super::BeginPlay();
	OwnerCharacter = Cast<ACharacter>(GetOwner());
	if (OwnerCharacter == nullptr)
	{
		UE_LOG(LogTemp, Error, L"Owner Characte is null");
		return;
	}
	ArmorComponent = OwnerCharacter->FindComponentByClass<UArmorComponent>();
	if (ArmorComponent == nullptr)
	{
		UE_LOG(LogTemp, Error, L"Armor Component is null");
		return;
	}
	MontageComponent = OwnerCharacter->FindComponentByClass<UMontageSystemComponent>();
	if (MontageComponent == nullptr)
	{
		UE_LOG(LogTemp, Error, L"Montage Component is null");
		return;
	}
	StateComponent = OwnerCharacter->FindComponentByClass<UC_StateComponent>();
	if (StateComponent == nullptr)
	{
		UE_LOG(LogTemp, Error, L"State Component is null");
		return;
	}
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
	
	if (OwnerCharacter == nullptr)
		return;

	USkeletalMeshComponent* CharacterMeshComponent = OwnerCharacter->GetMesh();
	if (CharacterMeshComponent == nullptr)
		return;

	UItemInstance* ItemInstance = NewObject<UItemInstance>();
	int32 NewItemTemplateID = UEmberItemData::Get().FindItemTemplateIDByClass(ItemTemplateClass);

	EItemRarity RandomItemRarity = (EItemRarity)FMath::RandRange(0, (int32)EItemRarity::Count - 1);
	ItemInstance->Init(NewItemTemplateID, RandomItemRarity);
	
	if (const UItemFragment_Equipable_Attachment* AttachmentFragment = ItemInstance->FindFragmentByClass
		<UItemFragment_Equipable_Attachment> ())
	{
		if (SpawnedWeapon != nullptr)
		{
			SpawnedWeapon->Destroy();
			if (ItemTemplateID == NewItemTemplateID)
			{
				ItemTemplateID = INDEX_NONE;
				return;
			}
		}
		// 아이템 스폰
		const FItemAttachInfo& AttachInfo = AttachmentFragment->ItemAttachInfo;
		if (AttachInfo.SpawnEquipmentClass)
		{
			UWorld* World = GetWorld();
			SpawnedWeapon = World->SpawnActorDeferred<AEquipmentBase>(AttachInfo.SpawnEquipmentClass,
			                                                          FTransform::Identity, OwnerCharacter);
			SpawnedWeapon->Init(NewItemTemplateID, EEquipmentSlotType::Primary_LeftHand);
			SpawnedWeapon->SetActorRelativeTransform(AttachInfo.AttachTransform);
			SpawnedWeapon->AttachToComponent(CharacterMeshComponent, FAttachmentTransformRules::KeepRelativeTransform,
			                                 AttachInfo.AttachSocket);
			SpawnedWeapon->FinishSpawning(FTransform::Identity, true);

			FEquipment Data = AttachmentFragment->GetEquipmentInfo();

			if (Data.DrawMontage)
			{
				if (UMontageSystemComponent* MontageComp = OwnerCharacter->FindComponentByClass
					<UMontageSystemComponent > ()
				)
				{
					MontageComp->PlayMontage(Data.DrawMontage);
				}
			}
		}

		ItemTemplateID = NewItemTemplateID;
	}
	else
	{
		ArmorComponent.Get()->DetermineEquip(ItemTemplate->FindFragmentByClass<UItemFragment_Equipable_Armor>(), NewItemTemplateID);
	}
}

void UEquipmentManagerComponent::Equip(EEquipmentSlotType EquipmentSlotType, UItemInstance* ItemInstance)
{
	check(GetOwner()->HasAuthority());

	if (EquipmentSlotType == EEquipmentSlotType::Count || ItemInstance == nullptr)
		return;

	const UItemFragment_Equipable* EquippableFragment = ItemInstance->FindFragmentByClass<UItemFragment_Equipable>();
	if (EquippableFragment == nullptr)
		return;
	
	if (EquippableFragment->EquipmentType == EEquipmentType::Weapon || EquippableFragment->EquipmentType == EEquipmentType::Utility)
	{
		Equip_HandEquipment(EquipmentSlotType, ItemInstance);
	}
	else if (EquippableFragment->EquipmentType == EEquipmentType::Armor)
	{
		Equip_Armor(ItemInstance);
	}
}

void UEquipmentManagerComponent::Unequip(EEquipmentSlotType EquipmentSlotType, UItemInstance* ItemInstance)
{
	check(GetOwner()->HasAuthority());

	if (EquipmentSlotType == EEquipmentSlotType::Count || ItemInstance == nullptr)
		return;

	const UItemFragment_Equipable* EquippableFragment = ItemInstance->FindFragmentByClass<UItemFragment_Equipable>();
	if (EquippableFragment == nullptr)
		return;
	
	if (EquippableFragment->EquipmentType == EEquipmentType::Weapon || EquippableFragment->EquipmentType == EEquipmentType::Utility)
	{
		Unequip_HandEquipment();
	}
	else if (EquippableFragment->EquipmentType == EEquipmentType::Armor)
	{
		Unequip_Armor(ItemInstance);
	}
}

void UEquipmentManagerComponent::Equip_HandEquipment(EEquipmentSlotType EquipmentSlotType, UItemInstance* ItemInstance)
{
	if (ItemInstance == nullptr)
		return;
	
	const UItemFragment_Equipable_Attachment* AttachmentFragment = ItemInstance->FindFragmentByClass<UItemFragment_Equipable_Attachment>();
	if (AttachmentFragment == nullptr)
		return;

	if (OwnerCharacter == nullptr)
		return;
	
	AEmberPlayerState* EmberPlayerState = Cast<AEmberPlayerState>(OwnerCharacter->GetPlayerState());
	if (EmberPlayerState == nullptr)
		return;

	UEmberAbilitySystemComponent* EmberASC = Cast<UEmberAbilitySystemComponent>(EmberPlayerState->GetAbilitySystemComponent());
	if (EmberASC == nullptr)
		return;
	
	// 손에 장착된 아이템 삭제
	Unequip_HandEquipment();
	
	if (OwnerCharacter->HasAuthority())
	{
		// 이전 아이템 Ability 삭제
		BaseAbilitySetHandles.TakeFromAbilitySystem(EmberASC);

		// 현재 아이템 Ability 적용
		if (const UEmberAbilitySet* BaseAbilitySet = AttachmentFragment->BaseAbilitySet)
		{
			BaseAbilitySet->GiveToAbilitySystem(EmberASC, &BaseAbilitySetHandles,  const_cast<UItemFragment_Equipable_Attachment*>(AttachmentFragment));
		}
	}
	
	// 손에 장착할 아이템 생성
	const FItemAttachInfo& AttachInfo = AttachmentFragment->ItemAttachInfo;
	if (AttachInfo.SpawnEquipmentClass)
	{
		UWorld* World = GetWorld();
		SpawnedHandEquipment = World->SpawnActorDeferred<AEquipmentBase>(AttachInfo.SpawnEquipmentClass,FTransform::Identity, OwnerCharacter);
		SpawnedHandEquipment->Init(ItemInstance->GetItemTemplateID(), EquipmentSlotType);
		SpawnedHandEquipment->SetActorRelativeTransform(AttachInfo.AttachTransform);
		SpawnedHandEquipment->AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, AttachInfo.AttachSocket);
		SpawnedHandEquipment->FinishSpawning(FTransform::Identity, true);
	}

	// TEMP : 임시 코드
	ItemTemplateID = ItemInstance->GetItemTemplateID();
}

void UEquipmentManagerComponent::Equip_Armor(UItemInstance* ItemInstance)
{
	if (ItemInstance == nullptr)
		return;
	
	int32 NewItemTemplateID = ItemInstance->GetItemTemplateID();
	ArmorComponent.Get()->DetermineEquip(ItemInstance->FindFragmentByClass<UItemFragment_Equipable_Armor>(), NewItemTemplateID);
}

void UEquipmentManagerComponent::Unequip_HandEquipment()
{
	if (IsValid(SpawnedHandEquipment))
	{
		SpawnedHandEquipment->Destroy();
	}
}

void UEquipmentManagerComponent::Unequip_Armor(UItemInstance* ItemInstance)
{
	if (ItemInstance == nullptr)
		return;
	
	int32 NewItemTemplateID = ItemInstance->GetItemTemplateID();
	ArmorComponent.Get()->DetermineEquip(ItemInstance->FindFragmentByClass<UItemFragment_Equipable_Armor>(), NewItemTemplateID);
}

void UEquipmentManagerComponent::OnRep_ItemTemplateID(int32 PrevItemTemplateID)
{
	/*if (ItemTemplateID == PrevItemTemplateID)
		return;

	if (OwnerCharacter == nullptr)
		return;

	USkeletalMeshComponent* CharacterMeshComponent = OwnerCharacter->GetMesh();
	if (CharacterMeshComponent == nullptr)
		return;

	const UItemTemplate& ItemTemplate = UEmberItemData::Get().FindItemTemplateByID(ItemTemplateID);

	if (const UItemFragment_Equipable_Attachment* AttachmentFragment = ItemTemplate.FindFragmentByClass<
		UItemFragment_Equipable_Attachment>())
	{
		FEquipment Data = AttachmentFragment->GetEquipmentInfo();

		if (Data.DrawMontage)
		{
			if (UMontageSystemComponent* MontageComp = OwnerCharacter->FindComponentByClass<UMontageSystemComponent>())
			{
				MontageComp->PlayMontage(Data.DrawMontage);
			}
		}
	}*/
}

void UEquipmentManagerComponent::Attack()
{
	// EquipmentComponent에서 현재 무기 타입 가져오기
	FAttackData Data = GetAttackInfo();
	GetMontageIndex();
	if (StateComponent->IsIdleMode() == true && !Data.Montages.IsEmpty())
	{
		StateComponent->SetActionMode();
		MontageComponent->PlayMontage(Data.Montages[Data.MontageIndex]);
	}
}

void UEquipmentManagerComponent::GetMontageIndex() const
{
	
	if (ItemTemplateID == INDEX_NONE)
		return;

	const UItemTemplate& ItemTemplate = UEmberItemData::Get().FindItemTemplateByID(ItemTemplateID);

	if (UItemFragment_Equipable_Weapon* WeaponFragment = ItemTemplate.FindFragmentByClass<
		UItemFragment_Equipable_Weapon>())
	{
		WeaponFragment->IncrementMontageIndex();
	}
}


FAttackData UEquipmentManagerComponent::GetAttackInfo() const
{
	FAttackData AttackInfo;

	if (ItemTemplateID == INDEX_NONE)
		return AttackInfo;

	const UItemTemplate& ItemTemplate = UEmberItemData::Get().FindItemTemplateByID(ItemTemplateID);

	if (UItemFragment_Equipable_Weapon* WeaponFragment = ItemTemplate.FindFragmentByClass<
		UItemFragment_Equipable_Weapon>())
	{
		AttackInfo = WeaponFragment->GetAttackInfo();
	}

	return AttackInfo;
}
