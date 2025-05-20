#include "System/Skill/SkillBase.h"
#include "SkillBase.h"

USkillBase::USkillBase()
{
}

FGameplayTag USkillBase::GetSkillTag() const
{
    return SkillTag;
}

FName USkillBase::GetSkillName() const
{
    return SkillName;
}
