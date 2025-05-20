#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameplayTagsManager.h"
#include "C_EmberSkillManager.generated.h"

UCLASS()
class EMBER_API UC_EmberSkillManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()
private:
    UPROPERTY()
    TMap<FGameplayTag, class USkillBase*> SkillMap;
public:
    // 스킬 등록
    UFUNCTION(BlueprintCallable, Category = "Skill System")
    void AddSkill(USkillBase* Skill);
    // 태그로 스킬 가져오기
    UFUNCTION(BlueprintCallable, Category = "Skill System")
    USkillBase* GetSkillByTag(FGameplayTag Tag) const;
protected:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
};
