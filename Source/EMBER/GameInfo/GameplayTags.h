#pragma once

#include "NativeGameplayTags.h"

namespace EmberGameplayTags
{
	// Message
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Message_Initialize_Inventory);

	// Input
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Attack_MainHand);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Interact);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Widget_Inventory);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Widget_CheatManager);
	
	// Ability
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Interact);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Attack);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Attack_1);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Attack_2);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Attack_3);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Widget_Inventory);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Widget_CheatManager); /* Temporary */

	// ItemAttribute
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ItemAttribute_BaseDamage);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ItemAttribute_Defense);
}
