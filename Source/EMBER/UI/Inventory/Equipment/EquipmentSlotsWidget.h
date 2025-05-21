// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "EquipmentSlotsWidget.generated.h"

class UCommonVisibilitySwitcher;
class UItemInstance;
class UItemSlotWidget;
class UEquipmentSlotWeaponWidget;
class UEquipmentSlotSingleWidget;
class UEquipManagerComponent;
class UEquipmentManagerComponent;
/**
 * 
 */
UCLASS()
class EMBER_API UEquipmentSlotsWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UEquipmentSlotsWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	//~UUserWidget Overrides
	virtual void NativeOnInitialized() override;
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	//~End of UUserWidget Overrides
protected:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UEquipmentSlotWeaponWidget> Widget_Weapon_Primary;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UEquipmentSlotWeaponWidget> Widget_Weapon_Secondary;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UEquipmentSlotSingleWidget> Widget_Armor_Head;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UEquipmentSlotSingleWidget> Widget_Armor_Chest;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UEquipmentSlotSingleWidget> Widget_Armor_Legs;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UEquipmentSlotSingleWidget> Widget_Armor_Hand;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UEquipmentSlotSingleWidget> Widget_Armor_Foot;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UEquipmentSlotSingleWidget> Widget_Utility_Primary;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UEquipmentSlotSingleWidget> Widget_Utility_Secondary;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UEquipmentSlotSingleWidget> Widget_Utility_Tertiary;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UEquipmentSlotSingleWidget> Widget_Utility_Quaternary;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_Weapon_Primary;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_Weapon_Secondary;
};
