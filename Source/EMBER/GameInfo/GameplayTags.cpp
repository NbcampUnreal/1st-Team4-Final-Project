#include "GameplayTags.h"

namespace EmberGameplayTags
{
	// Message
	UE_DEFINE_GAMEPLAY_TAG(Message_Initialize_MyInventory,					"Message.Initialize.Inventory");

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

	//	Skill
	UE_DEFINE_GAMEPLAY_TAG(Skill, "Skill");
	UE_DEFINE_GAMEPLAY_TAG(Skill_Survival, "Skill.Survival");
	UE_DEFINE_GAMEPLAY_TAG(Skill_Survival_TestSkill, "Skill.Survival.TestSkill");
	UE_DEFINE_GAMEPLAY_TAG(Skill_Gather, "Skill.Gather");
	UE_DEFINE_GAMEPLAY_TAG(Skill_Gather_TestSkill, "Skill.Gather.TestSkill");
	UE_DEFINE_GAMEPLAY_TAG(Skill_Slaughter, "Skill.Slaughter");
	UE_DEFINE_GAMEPLAY_TAG(Skill_Slaughter_TestSkill, "Skill.Slaughter.TestSkill");
	UE_DEFINE_GAMEPLAY_TAG(Skill_Crafting, "Skill.Crafting");
	UE_DEFINE_GAMEPLAY_TAG(Skill_Crafting_TestSkill, "Skill.Crafting.TestSkill");
	UE_DEFINE_GAMEPLAY_TAG(Skill_Cook, "Skill.Cook");
	UE_DEFINE_GAMEPLAY_TAG(Skill_Cook_TestSkill, "Skill.Cook.TestSkill");
}