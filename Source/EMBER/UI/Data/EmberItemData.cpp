// Fill out your copyright notice in the Description page of Project Settings.


#include "EmberItemData.h"

#include "Item/Fragments/ItemFragment_Equipable_Armor.h"
#include "Item/Fragments/ItemFragment_Equipable_Weapon.h"
#include "System/EmberAssetManager.h"
#include "UObject/ObjectSaveContext.h"


const UEmberItemData& UEmberItemData::Get()
{
	return UEmberAssetManager::Get().GetItemData();
}

void UEmberItemData::PreSave(FObjectPreSaveContext SaveContext)
{
	Super::PreSave(SaveContext);

	ItemTemplateIDToClass.KeySort([](const int32 A, const int32 B)
	{
		return A < B;
	});

	ItemTemplateClassToID.Empty();

	for (const auto& Pair : ItemTemplateIDToClass)
	{
		ItemTemplateClassToID.Emplace(Pair.Value, Pair.Key);

		const UItemTemplate* ItemTemplate = Pair.Value.GetDefaultObject();
		if (const UItemFragment_Equipable_Weapon* WeaponFragment = ItemTemplate->FindFragmentByClass<UItemFragment_Equipable_Weapon>())
		{
			if (WeaponFragment->WeaponType != EWeaponType::Unarmed)
			{
				WeaponItemTemplateClasses.Add(Pair.Value);
			}
		}
		else if (ItemTemplate->FindFragmentByClass<UItemFragment_Equipable_Armor>())
		{
			ArmorItemTemplateClasses.Add(Pair.Value);
		}
	}
}
