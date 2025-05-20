#pragma once
#include "CoreMinimal.h"
#include "Sound/SoundCue.h"
#include "NiagaraComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFlag.h"
#include "Animation/AnimMontage.h"
#include "../System/Skill/SkillBase.h"
#include "Engine/Texture2D.h"
#include "GameplayTagsManager.h"
#include "GAmeData.generated.h"

USTRUCT(BlueprintType)
struct FLineColor
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FLinearColor Default;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxDefaultOpacity;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FLinearColor LinearColor;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxPurchasedOpacity;
};
USTRUCT(BlueprintType)
struct FSkillConnectionData
{
    GENERATED_BODY()

    // 이 연결이 향하는 스킬 노드
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag TargetSkillTag;

    // 이 연결선의 색상 정보
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FLineColor LineColor;
};
USTRUCT(BlueprintType)
struct FSkillNodeData
{
    GENERATED_BODY()
    // 아이콘 이미지
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TObjectPtr<UTexture2D> Icon;
    // 스킬명 (표시용 이름)
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText SkillName;
    // 제목 (간단히 문자열로)
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Title;
    // 설명
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Description;
    // 속한 카테고리
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    ESkillCategory Category;
    // 선행 조건 (해당 태그가 해제되어야 함)
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FGameplayTag> RequiredSkill;
    // 이 스킬이 열면 활성화 가능한 노드들
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FGameplayTag> UnlockSkill;
    // 실제 태그 ID
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag SkillTag;
    // 연결선 노드 (후속 노드 목록)
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FSkillConnectionData> ConnectionSkill;
    // TargetNode
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<class UEmberSkillNode*> NextNodes; // UMG에서 직접 드래그해서 연결
    // 해제 여부
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bUnlocked = false;
};
USTRUCT(BlueprintType)
struct FSkillCategoryData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    ESkillCategory Category;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    int32 Level = 1;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    float CurrentXP = 0.0f;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    float MaxXP = 100.0f;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    int32 SkillPoint = 0;
};

USTRUCT(BlueprintType)
struct FEffectData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect")
    EEffectType EffectType;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect", meta = (EditCondition = "EffectType == EEffectType::Niagara", EditConditionHides))
    TObjectPtr<UNiagaraSystem> NiagaraSystem;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect", meta = (EditCondition = "EffectType == EEffectType::Particle", EditConditionHides))
    TObjectPtr<UParticleSystem> ParticleSystem;
};

USTRUCT(BlueprintType)
struct FSound2D
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TObjectPtr<USoundWave> Sound; // 2D 사운드 에셋

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Volume; // 볼륨

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Pitch; // 피치
};

USTRUCT(BlueprintType)
struct FParryData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PlayRate;	//공격속도
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FEffectData HitEffect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FSound2D HitSound;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<TObjectPtr<UAnimMontage>> Montages;
};

USTRUCT(BlueprintType)
struct FEquipment
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float PlayRate;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FSound2D EquipSound;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TObjectPtr<UAnimMontage> HolsterMontage;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TObjectPtr<UAnimMontage> DrawMontage;
};

USTRUCT(BlueprintType)
struct FDamageData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Damage;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float PlayRate;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FEffectData HitEffect;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FSound2D HitSound;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<TObjectPtr<UAnimMontage>> Montages;
};

USTRUCT(BlueprintType)
struct FAttackData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float PlayRate;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FEffectData AttackEffect;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FSound2D AttackSound;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<TObjectPtr<UAnimMontage>> Montages;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MontageIndex;
};

USTRUCT(BlueprintType)
struct FCharacterStatus
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CurrentHP;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxHP;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CurrentStamina;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxStamina;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CurrentTemperature;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxTemperature;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CurrentFatigueLevel;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxFatigueLevel;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CurrentWeight;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxWeight;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CurrentEnergy;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxEnergy;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CurrentPhysicalStrength;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxPhysicalStrength;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CurrentDexterity;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxDexterity;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CurrentXP;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxXP;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Level;
public:
    float GetCurrentHP() const;
    float GetMaxHP() const;
    float GetCurrentStamina() const;
    float GetMaxStamina() const;
    float GetCurrentTemperature() const;
    float GetMaxTemperature() const;
    float GetCurrentFatigueLevel() const;
    float GetMaxFatigueLevel() const;
    float GetCurrentWeight() const;
    float GetMaxWeight() const;
    float GetCurrentEnergy() const;
    float GetMaxEnergy() const;
    float GetCurrentPhysicalStrength() const;
    float GetMaxPhysicalStrength() const;
    float GetCurrentDexterity() const;
    float GetMaxDexterity() const;
    float GetCurrentXP() const;
    float GetMaxXP() const;
    int32 GetLevel() const;
public:
    void SetCurrentHP(const float Amount);
    void SetMaxHP(const float Amount);
    void SetCurrentStamina(const float Amount);
    void SetMaxStamina(const float Amount);
    void SetCurrentTemperature(const float Amount);
    void SetMaxTemperature(const float Amount);
    void SetCurrentFatigueLevel(const float Amount);
    void SetMaxFatigueLevel(const float Amount);
    void SetCurrentWeight(const float Amount);
    void SetMaxWeight(const float Amount);
    void SetCurrentEnergy(const float Amount);
    void SetMaxEnergy(const float Amount);
    void SetCurrentPhysicalStrength(const float Amount);
    void SetMaxPhysicalStrength(const float Amount);
    void SetCurrentDexterity(const float Amount);
    void SetMaxDexterity(const float Amount);
    void SetCurrentXP(const float Amount);
    void SetMaxXP(const float Amount);
    void LevelUp(const int32 Amount);
};