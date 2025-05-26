#include "GameplayTags.h"

namespace EmberGameplayTags
{
	// Message
	UE_DEFINE_GAMEPLAY_TAG(Message_Initialize_Inventory,					"Message.Initialize.Inventory");
	UE_DEFINE_GAMEPLAY_TAG(Message_Initialize_InventoryEquipment,			"Message.Initialize.InventoryEquipment");

	// Input
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Attack_MainHand,						"InputTag.Attack.MainHand");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Interact,								"InputTag.Interact");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Widget_Inventory,						"InputTag.Widget.Inventory");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Widget_CheatManager,					"InputTag.Widget.CheatManager");

	// Ability
	UE_DEFINE_GAMEPLAY_TAG(Ability_Interact,								"Ability.Interact");
	UE_DEFINE_GAMEPLAY_TAG(Ability_Attack,									"Ability.Attack");
	UE_DEFINE_GAMEPLAY_TAG(Ability_Attack_1,								"Ability.Attack.1");
	UE_DEFINE_GAMEPLAY_TAG(Ability_Attack_2,								"Ability.Attack.2");
	UE_DEFINE_GAMEPLAY_TAG(Ability_Attack_3,								"Ability.Attack.3");
	UE_DEFINE_GAMEPLAY_TAG(Ability_Widget_Inventory,						"Ability.Widget.Inventory");
	UE_DEFINE_GAMEPLAY_TAG(Ability_Widget_CheatManager,						"Ability.Widget.CheatManager"); /* Temporary */

	// ItemAttribute
	UE_DEFINE_GAMEPLAY_TAG(ItemAttribute_BaseDamage,						"ItemAttribute.BaseDamage");
	UE_DEFINE_GAMEPLAY_TAG(ItemAttribute_Defense,							"ItemAttribute.Defense");
}