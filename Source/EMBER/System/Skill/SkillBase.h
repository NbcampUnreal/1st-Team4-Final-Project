#pragma once

#include "EMBER.h"
#include "GameplayTagsManager.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SkillBase.generated.h"
UCLASS()
class EMBER_API USkillBase : public UObject
{
	GENERATED_BODY()
public:
	USkillBase();
public:
    /** 적용될 때 호출됨 */
    virtual void ApplySkill(ACharacter* TargetCharacter) PURE_VIRTUAL(UPassiveSkillBase::ApplySkill);

    /** 제거될 때 호출됨 */
    virtual void RemoveSkill(ACharacter* TargetCharacter) PURE_VIRTUAL(UPassiveSkillBase::RemoveSkill);
protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Skill")
    FName SkillName;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Skill")
    FGameplayTag SkillTag;

public:
    FGameplayTag GetSkillTag() const;
    FName GetSkillName() const;
};
