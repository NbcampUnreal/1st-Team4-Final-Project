#include "Component/C_EmberSkillComponent.h"
#include "SkillBase.h"
#include "Skill/Manager/C_EmberSkillManager.h"
#include "GameFramework/Character.h"

UC_EmberSkillComponent::UC_EmberSkillComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UC_EmberSkillComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UC_EmberSkillComponent::AddSkill(USkillBase* Skill)
{
    //UnlockedSkills.AddUnique(Skill->GetSkillTag());
    //if (ACharacter* Character = Cast<ACharacter>(GetOwner()))
    //{
    //    Skill->ApplySkill(Character);
    //}
}

void UC_EmberSkillComponent::RemoveSkill(USkillBase* Skill)
{
    //if (EquippedSkills.Remove(Skill->GetSkillTag()) > 0)
    //{
    //    if (ACharacter* Character = Cast<ACharacter>(GetOwner()))
    //    {
    //        Skill->RemoveSkill(Character);
    //    }
    //}
}

void UC_EmberSkillComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
