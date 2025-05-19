// Fill out your copyright notice in the Description page of Project Settings.

#include "ItemInstance.h"

#include "GameplayTagContainer.h"
#include "Net/UnrealNetwork.h"
#include "UI/Data/EmberItemData.h"
#include "ItemTemplate.h"

UItemInstance::UItemInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UItemInstance::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	UObject::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, ItemTemplateID);
	DOREPLIFETIME(ThisClass, ItemRarity);
}

void UItemInstance::Init(int32 InItemTemplateID, EItemRarity InItemRarity)
{
	if (InItemTemplateID <= INDEX_NONE || InItemRarity == EItemRarity::Count)
		return;

	ItemTemplateID = InItemTemplateID;
	ItemRarity = InItemRarity;

	const UItemTemplate& ItemTemplate = UEmberItemData::Get().FindItemTemplateByID(ItemTemplateID);
	for (const UItemFragment* Fragment : ItemTemplate.Fragments)
	{
		if (Fragment)
		{
			Fragment->OnInstanceCreated(this);
		}
	}
}

void UItemInstance::AddOrRemoveStatTagStack(FGameplayTag StatTag, int32 StackCount)
{
	AttributeContainer.AddOrRemoveStack(StatTag, StackCount);
}

const UItemFragment* UItemInstance::FindFragmentByClass(TSubclassOf<UItemFragment> FragmentClass) const
{
	if (ItemTemplateID > INDEX_NONE && FragmentClass)
	{
		const UItemTemplate& ItemTemplate = UEmberItemData::Get().FindItemTemplateByID(ItemTemplateID);
		return ItemTemplate.FindFragmentByClass(FragmentClass);
	}
	return nullptr;
}
