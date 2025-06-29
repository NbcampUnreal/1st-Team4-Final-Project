﻿#pragma once

#include "NativeGameplayTags.h"

namespace EmberGameplayTags
{
	// Message
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Message_Initialize_MyInventory);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Message_Initialize_OtherInventory);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Message_Initialize_InventoryEquipment);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Message_Initialize_CraftingWidget);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Message_Interaction_Notice);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Message_Interaction_Progress);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Message_ActionHint_Notice);
	
	// Input
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Attack_MainHand);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Interact);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Widget_Inventory);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Widget_CheatManager);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Movement_Move);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Movement_Look);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Movement_Sprint);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Movement_Jump);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Movement_Dash);
	
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_QuickSlot_Weapon_Primary);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_QuickSlot_Utility_Primary);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_QuickSlot_Utility_Secondary);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_QuickSlot_Utility_Tertiary);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_QuickSlot_Utility_Quaternary);
	
	// Ability
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Interact);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Interact_Object);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Attack);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Attack_1);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Attack_2);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Attack_3);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Widget_Inventory);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Widget_CheatManager); /* Temporary */
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Interact_Active);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Logging);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Mining);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_ChangeEquip);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_HitReact);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Jump);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Dash_Check);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Dash_Active);
	
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_QuickSlot_Handle);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_ChangeEquip);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Consume_Item);
	
	
	// ItemAttribute
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ItemAttribute_BaseDamage);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ItemAttribute_Defense);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ItemAttribute_Consumable_Add_Health);

	// Status
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Status_Interact);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Status_ActionHint);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Status_Logging);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Status_Mining);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Status_ChangeEquip);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Status_Attack);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Status_HitReact);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Status_Dash);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Status_Jump);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Status_QuickSlot_Handle);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Status_ChangeEquip);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Status_Consume_Item);

	// Gameplay Event
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GameplayEvent_Montage_Begin);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GameplayEvent_Montage_Tick);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GameplayEvent_Montage_End);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GameplayEvent_Trace);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GameplayEvent_Reward_Item);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GameplayEvent_QuickSlot_Handle);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GameplayEvent_ChangeEquip);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GameplayEvent_Consume_Item);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GameplayEvent_HitReact);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GameplayEvent_Jump);

	// Cooldown
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Cooldown_Dash);
	
}
