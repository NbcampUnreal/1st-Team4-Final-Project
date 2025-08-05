#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayEffectTypes.h"
#include "Component/RuneSystemComponent.h"
#include "NiagaraSystem.h"
#include "RuneItemTemplate.generated.h"

class ARuneItem;
class UGameplayAbility;
class UGameplayEffect;
class UNiagaraSystem;

UCLASS(BlueprintType, Blueprintable)
class EMBER_API URuneItemTemplate : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Rune")
    TSubclassOf<ARuneItem> RuneItemClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Rune")
    TSubclassOf<UGameplayAbility> GrantedAbility;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Rune")
    TSubclassOf<UGameplayEffect> GrantedEffect;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Rune")
    FRuneStat RuneStat;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Rune")
    FText RuneName;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Visual")
    UStaticMesh* RuneMesh;
   
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Rune")
    FText Description;

    // 아이템 외형에 사용할 이펙트 (희귀도에 따라 다를 수 있음)
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Visual")
    UNiagaraSystem* DropEffect;
};
