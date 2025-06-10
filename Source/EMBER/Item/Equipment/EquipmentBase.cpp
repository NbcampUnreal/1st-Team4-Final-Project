// Fill out your copyright notice in the Description page of Project Settings.


#include "EquipmentBase.h"

#include "MontageSystemComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "Fragments/ItemFragment_Equipable_Attachment.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/Character.h"
#include "Managers/EquipmentManagerComponent.h"
#include "UI/Data/EmberItemData.h"

AEquipmentBase::AEquipmentBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bReplicates = true;

	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	ArrowComponent = CreateDefaultSubobject<UArrowComponent>("ArrowComponent");
	ArrowComponent->PrimaryComponentTick.bStartWithTickEnabled = false;
	SetRootComponent(ArrowComponent);
	
	MeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
	MeshComponent->SetCollisionProfileName("Weapon");
	MeshComponent->SetGenerateOverlapEvents(false);
	MeshComponent->SetupAttachment(GetRootComponent());
	MeshComponent->PrimaryComponentTick.bStartWithTickEnabled = false;
	MeshComponent->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::OnlyTickPoseWhenRendered;

	TraceDebugCollision = CreateDefaultSubobject<UBoxComponent>("TraceDebugCollision");
	TraceDebugCollision->SetCollisionProfileName("NoCollision");
	TraceDebugCollision->SetGenerateOverlapEvents(false);
	TraceDebugCollision->SetupAttachment(GetRootComponent());
	TraceDebugCollision->PrimaryComponentTick.bStartWithTickEnabled = false;
}

void AEquipmentBase::Init(int32 InTemplateID, EEquipmentSlotType InEquipmentSlotType)
{
	ItemTemplateID = InTemplateID;
	EquipmentSlotType = InEquipmentSlotType;
}

void AEquipmentBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, ItemTemplateID);
	DOREPLIFETIME(ThisClass, EquipmentSlotType);
}

void AEquipmentBase::ProcessEquip()
{
	ACharacter* OwnerCharacter = Cast<ACharacter>(GetOwner());
	if (OwnerCharacter == nullptr)
		return;

	USkeletalMeshComponent* CharacterMeshComponent = OwnerCharacter->GetMesh();
	if (CharacterMeshComponent == nullptr)
		return;

	const UItemTemplate& ItemTemplate = UEmberItemData::Get().FindItemTemplateByID(ItemTemplateID);
	const UItemFragment_Equipable_Attachment* AttachmentFragment = ItemTemplate.FindFragmentByClass<UItemFragment_Equipable_Attachment>();
	if (AttachmentFragment == nullptr)
		return;

	// TODO : 무기별 애니메이션 블루프린트 변경
	/*if (AttachmentFragment->AnimInstanceClass)
	{
		CharacterMeshComponent->LinkAnimClassLayers(AttachmentFragment->AnimInstanceClass);
	}*/

	// 무기 장착 애니메이션 재생
	FEquipment EquipmentInfo = AttachmentFragment->GetEquipmentInfo();
	if (EquipmentInfo.DrawMontage)
	{
		if (UMontageSystemComponent* MontageComp = OwnerCharacter->FindComponentByClass<UMontageSystemComponent>())
		{
			MontageComp->PlayMontage(EquipmentInfo.DrawMontage);
		}
	}
}

void AEquipmentBase::OnRep_ItemTemplateID()
{
	HandleReplicatedEquipment();
}

void AEquipmentBase::OnRep_EquipmentSlotType()
{
	HandleReplicatedEquipment();
}

void AEquipmentBase::HandleReplicatedEquipment()
{
	if (bInitialized)
		return;
	
	if (ItemTemplateID <= 0 || EquipmentSlotType == EEquipmentSlotType::Count)
		return;

	if (GetOwner() &&
		(EquipmentSlotType == EEquipmentSlotType::Primary_LeftHand ||
		EquipmentSlotType == EEquipmentSlotType::Primary_RightHand ||
		EquipmentSlotType == EEquipmentSlotType::Primary_TwoHand))
	{
		if (UEquipmentManagerComponent* EquipManager = GetOwner()->FindComponentByClass<UEquipmentManagerComponent>())
		{
			EquipManager->SetEquipmentActor(this);
		}
	}
	
	ProcessEquip();
	
	bInitialized = true;
}
