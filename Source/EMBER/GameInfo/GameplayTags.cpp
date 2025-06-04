#include "GameplayTags.h"

namespace EmberGameplayTags
{
	// Message
	UE_DEFINE_GAMEPLAY_TAG(Message_Initialize_Inventory,					"Message.Initialize.Inventory");
	UE_DEFINE_GAMEPLAY_TAG(Message_Initialize_InventoryEquipment,			"Message.Initialize.InventoryEquipment");
	UE_DEFINE_GAMEPLAY_TAG(Message_Interaction_Notice,						"Message.Interaction.Notice");
	UE_DEFINE_GAMEPLAY_TAG(Message_Interaction_Progress,					"Message.Interaction.Progress");
	UE_DEFINE_GAMEPLAY_TAG(Message_ActionHint_Notice,						"Message.ActionHint.Notice");

	// Input
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Attack_MainHand,						"InputTag.Attack.MainHand");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Interact,								"InputTag.Interact");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Widget_Inventory,						"InputTag.Widget.Inventory");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Widget_CheatManager,					"InputTag.Widget.CheatManager");

	// Ability
	UE_DEFINE_GAMEPLAY_TAG(Ability_Interact,								"Ability.Interact");
	UE_DEFINE_GAMEPLAY_TAG(Ability_Interact_Object,							"Ability.Interact.Object");
	UE_DEFINE_GAMEPLAY_TAG(Ability_Attack,									"Ability.Attack");
	UE_DEFINE_GAMEPLAY_TAG(Ability_Attack_1,								"Ability.Attack.1");
	UE_DEFINE_GAMEPLAY_TAG(Ability_Attack_2,								"Ability.Attack.2");
	UE_DEFINE_GAMEPLAY_TAG(Ability_Attack_3,								"Ability.Attack.3");
	UE_DEFINE_GAMEPLAY_TAG(Ability_Widget_Inventory,						"Ability.Widget.Inventory");
	UE_DEFINE_GAMEPLAY_TAG(Ability_Widget_CheatManager,						"Ability.Widget.CheatManager"); /* Temporary */
	UE_DEFINE_GAMEPLAY_TAG(Ability_Interact_Active,							"Ability.Interact.Active");
	UE_DEFINE_GAMEPLAY_TAG(Ability_Logging,									"Ability.Logging");
	UE_DEFINE_GAMEPLAY_TAG(Ability_Mining,									"Ability.Mining");
	
	// ItemAttribute
	UE_DEFINE_GAMEPLAY_TAG(ItemAttribute_BaseDamage,						"ItemAttribute.BaseDamage");
	UE_DEFINE_GAMEPLAY_TAG(ItemAttribute_Defense,							"ItemAttribute.Defense");

	// Status
	UE_DEFINE_GAMEPLAY_TAG(Status_Interact,									"Status.Interact");
	UE_DEFINE_GAMEPLAY_TAG(Status_ActionHint,								"Status.ActionHint");
	UE_DEFINE_GAMEPLAY_TAG(Status_Logging,									"Status.Logging");
	UE_DEFINE_GAMEPLAY_TAG(Status_Mining,									"Status.Mining");

	// Gameplay Event
	UE_DEFINE_GAMEPLAY_TAG(GameplayEvent_Montage_Begin,						"GameplayEvent.Montage.Begin");
	UE_DEFINE_GAMEPLAY_TAG(GameplayEvent_Montage_Tick,						"GameplayEvent.Montage.Tick");
	UE_DEFINE_GAMEPLAY_TAG(GameplayEvent_Montage_End,						"GameplayEvent.Montage.End");
	UE_DEFINE_GAMEPLAY_TAG(GameplayEvent_Trace,								"GameplayEvent.Trace");
}