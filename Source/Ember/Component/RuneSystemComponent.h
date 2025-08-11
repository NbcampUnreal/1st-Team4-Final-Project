#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayAbilitySpec.h"
#include "GameplayEffectTypes.h"

class ARuneItem;

#include "RuneSystemComponent.generated.h"

// ·é ½½·Ô ±¸Á¶Ã¼
USTRUCT(BlueprintType)
struct FRuneSlot
{
    GENERATED_BODY()

    UPROPERTY()
    TObjectPtr<ARuneItem> Rune;

    UPROPERTY()
    FGameplayAbilitySpecHandle AbilityHandle;

    UPROPERTY()
    FActiveGameplayEffectHandle EffectHandle;

    FRuneSlot()
        : Rune(nullptr)
        , AbilityHandle()
        , EffectHandle()
    {
    }
};

// ·é ½ºÅÈ ±¸Á¶Ã¼
USTRUCT(BlueprintType)
struct FRuneStat
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Power;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CooldownReduction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Element;

    bool operator==(const FRuneStat& Other) const
    {
        return FMath::IsNearlyEqual(Power, Other.Power)
            && FMath::IsNearlyEqual(CooldownReduction, Other.CooldownReduction)
            && Element == Other.Element;
    }

    bool IsBetterThan(const FRuneStat& Other) const
    {
        if (Power > Other.Power)
            return true;
        if (FMath::IsNearlyEqual(Power, Other.Power) && CooldownReduction > Other.CooldownReduction)
            return true;

        return false;
    }
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class EMBER_API URuneSystemComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    URuneSystemComponent();

    UFUNCTION(BlueprintCallable, Category = "Rune")
    bool EquipRune(ARuneItem* NewRune, int32 SlotIndex);

    UFUNCTION(BlueprintCallable, Category = "Rune")
    void RemoveRune(int32 SlotIndex);

    UFUNCTION(BlueprintPure, Category = "Rune")
    ARuneItem* GetRune(int32 SlotIndex) const;

    FRuneStat GetRuneStatAtSlot(int32 SlotIndex) const;

    bool IsBetterRune(int32 SlotIndex, const ARuneItem* NewRune) const;
    UFUNCTION(BlueprintPure, Category = "Rune")
    int32 GetMaxRuneSlots() const { return MaxRuneSlots; }
protected:
    UPROPERTY(EditAnywhere, Category = "Rune")
    int32 MaxRuneSlots = 1;

    UPROPERTY()
    TArray<FRuneSlot> RuneSlots;
};
