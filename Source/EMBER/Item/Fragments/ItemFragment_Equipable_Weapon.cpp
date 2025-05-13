// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemFragment_Equipable_Weapon.h"

UItemFragment_Equipable_Weapon::UItemFragment_Equipable_Weapon(const FObjectInitializer& FObjectInitializer) : Super(FObjectInitializer)
{
	EquipmentType = EEquipmentType::Weapon;
}

void UItemFragment_Equipable_Weapon::IncrementMontageIndex()
{
	if (AttackInfo.Montages.Num() > 0)
	{
		int32 Index = AttackInfo.MontageIndex+1;
		AttackInfo.MontageIndex = AttackInfo.Montages.Num() % Index;
	}
}

FAttackData UItemFragment_Equipable_Weapon::GetAttackInfo() const
{
	return AttackInfo;
}
