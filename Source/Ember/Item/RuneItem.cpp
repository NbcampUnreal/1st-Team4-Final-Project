#include "RuneItem.h"
#include "Template/RuneItemTemplate.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Character/EmberCharacter.h"
#include "Component/RuneSystemComponent.h"

ARuneItem::ARuneItem()
{
    // Constructor에서 특이점 없으면 생략 가능
}

void ARuneItem::Use(AActor* User)
{
    if (AEmberCharacter* Character = Cast<AEmberCharacter>(User))
    {
        const URuneItemTemplate* Template = GetRuneTemplate();

        if (Template && Character->TryEquipRune(Template))
        {
            Destroy(); // 장착 성공 시 제거
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("[RuneItem] Failed to equip rune."));
        }
    }
}
void ARuneItem::InitializeFromTemplate(URuneItemTemplate* InTemplate)
{
    if (!InTemplate) return;

    TemplateAsset = InTemplate;

    // GAS 관련
    GrantedAbility = InTemplate->GrantedAbility;
    GrantedEffect = InTemplate->GrantedEffect;
    RuneStat = InTemplate->RuneStat;

    // 이름/설명
    RuneName = InTemplate->RuneName;
    Description = InTemplate->Description;

    // 이펙트 생성 (옵션)
    if (InTemplate->DropEffect)
    {
        UNiagaraComponent* NiagaraComp = UNiagaraFunctionLibrary::SpawnSystemAttached(
            InTemplate->DropEffect,
            GetRootComponent(),
            NAME_None,
            FVector::ZeroVector,
            FRotator::ZeroRotator,
            EAttachLocation::SnapToTargetIncludingScale,
            true);

        DropEffectComponent = NiagaraComp;
    }

    UE_LOG(LogTemp, Log, TEXT("[RuneItem] Initialized: %s"), *RuneName.ToString());
}

FString ARuneItem::GetName() const
{
    return GetNameSafe(this->GetClass());
}
