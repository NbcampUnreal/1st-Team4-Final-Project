// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "EMBER.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SkillBase.h"
#include "C_EmberSkillComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EMBER_API UC_EmberSkillComponent : public UActorComponent
{
	GENERATED_BODY()
public:	
	UC_EmberSkillComponent();

protected:
	virtual void BeginPlay() override;

protected:
    /** 장착된 스킬 목록 */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated)    
    TArray<class USkillBase*> EquippedSkills;
public:
    /** 스킬 추가 */
    UFUNCTION(BlueprintCallable)
    void AddSkill(class USkillBase* Skill);

    /** 스킬 제거 */
    UFUNCTION(BlueprintCallable)
    void RemoveSkill(class USkillBase* Skill);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
