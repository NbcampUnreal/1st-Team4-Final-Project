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

	//Skill
	/*
	* 	Survival UMETA(DisplayName = "Survival"),
		Gather UMETA(DisplayName = "Gather"),
		Slaughter UMETA(DisplayName = "Slaughter"),
		Crafting UMETA(DisplayName = "Crafting"),
		Cook UMETA(DisplayName = "Cook")
	*/
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Skill);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Skill_Survival);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Skill_Survival_TestSkill);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Skill_Gather);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Skill_Gather_TestSkill);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Skill_Slaughter);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Skill_Slaughter_TestSkill);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Skill_Crafting);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Skill_Crafting_TestSkill);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Skill_Cook);
	EMBER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Skill_Cook_TestSkill);
}
