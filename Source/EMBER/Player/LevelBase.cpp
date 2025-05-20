#include "LevelBase.h"
#include "EMBER.h"

ULevelBase::ULevelBase()
{
    EXPMultipler = 1.15;
    Level = 1;
    MaxXP = 100.f;
}

void ULevelBase::LevelUP()
{
    Level++;
    SkillPoint++;
    MaxXP = MaxXP * EXPMultipler;
}

void ULevelBase::AddExp(const int32 Amount)
{
    CurrentXP += Amount;

    while (CurrentXP >= MaxXP)
    {
        CurrentXP -= MaxXP;
        CurrentXP = FMath::Max(CurrentXP, 0.f); // 🔒 XP 음수 방지
        LevelUP();
    }
}

int32 ULevelBase::GetSkillPoint() const
{
	return SkillPoint;
}

void ULevelBase::SetSkillPoint(const int32 Point)
{
	SkillPoint = Point;
}

void ULevelBase::SetCategory(ESkillCategory _Category)
{
    this->Category = _Category;
}
