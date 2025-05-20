#include "C_EmberSkillManager.h"
#include "SkillBase.h"
void UC_EmberSkillManager::AddSkill(USkillBase* Skill)
{
	if(Skill && Skill->GetSkillTag().IsValid())
		SkillMap.Add(Skill->GetSkillTag(), Skill);
}

USkillBase* UC_EmberSkillManager::GetSkillByTag(FGameplayTag Tag) const
{
	if (!SkillMap.IsEmpty() && SkillMap[Tag] != nullptr)
		return SkillMap[Tag];

	return nullptr;
}

void UC_EmberSkillManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}
