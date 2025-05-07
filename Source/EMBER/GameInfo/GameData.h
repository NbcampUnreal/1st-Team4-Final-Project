#pragma once
#include "CoreMinimal.h"
#include "Sound/SoundCue.h"
#include "NiagaraComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFlag.h"
#include "Animation/AnimMontage.h"
#include "GAmeData.generated.h"

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
    TObjectPtr<UAnimMontage> EquipMontage;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TObjectPtr<UAnimMontage> UnEquipMontage;
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
};