#pragma once

#include "EMBER.h"
#include "CoreMinimal.h"
#include "LevelBase.generated.h"

UCLASS()
class EMBER_API ULevelBase : public UObject
{
	GENERATED_BODY()
public:
    ULevelBase();
protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CurrentXP;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxXP;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Level;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    ESkillCategory Category;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SkillPoint;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float EXPMultipler;
protected:
    UFUNCTION()
    void LevelUP();
public:
    UFUNCTION(BlueprintCallable)
    void AddExp(const int32 Amount);
    UFUNCTION(BlueprintCallable)
    int32 GetSkillPoint() const;
    UFUNCTION(BlueprintCallable)
    void SetSkillPoint(const int32 Point);
    UFUNCTION(BlueprintCallable)
    void SetCategory(ESkillCategory _Category);
};
