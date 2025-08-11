#include "RuneSystemComponent.h"
#include "Character/EmberCharacter.h"
#include "Weapon/EmberWeaponBase.h"
#include "AbilitySystemComponent.h"       //  GAS 컴포넌트 정의
#include "Item/RuneItem.h"                     //  ARuneItem 정의
#include "Character/EmberCharacter.h"     //  캐릭터 참조
#include "Item/RuneItem.h"

URuneSystemComponent::URuneSystemComponent()
{
    PrimaryComponentTick.bCanEverTick = false;

    RuneSlots.SetNum(MaxRuneSlots);
}

bool URuneSystemComponent::EquipRune(ARuneItem* NewRune, int32 SlotIndex)
{
    if (!NewRune || !RuneSlots.IsValidIndex(SlotIndex)) return false;

    FRuneSlot& Slot = RuneSlots[SlotIndex];

    // 기존 룬 제거
    if (Slot.Rune)
    {
        RemoveRune(SlotIndex); // 내부적으로 Ability / Effect 제거
    }

    if (AEmberCharacter* OwnerChar = Cast<AEmberCharacter>(GetOwner()))
    {
        if (UAbilitySystemComponent* ASC = OwnerChar->GetASC())
        {
            Slot.Rune = NewRune;

            if (NewRune->GetGrantedAbility())
            {
                FGameplayAbilitySpec Spec(NewRune->GetGrantedAbility(), 1);
                Slot.AbilityHandle = ASC->GiveAbility(Spec);
            }

            if (NewRune->GetGrantedEffect())
            {
                FGameplayEffectContextHandle Context = ASC->MakeEffectContext();
                Slot.EffectHandle = ASC->ApplyGameplayEffectToSelf(
                    NewRune->GetGrantedEffect()->GetDefaultObject<UGameplayEffect>(), 1, Context);
            }

            UE_LOG(LogTemp, Log, TEXT("Rune equipped in slot %d: %s"), SlotIndex, *NewRune->GetName());
            return true;
        }
    }

    return false;
}



void URuneSystemComponent::RemoveRune(int32 SlotIndex)
{
    if (!RuneSlots.IsValidIndex(SlotIndex)) return;

    FRuneSlot& Slot = RuneSlots[SlotIndex];

    if (!Slot.Rune) return;

    if (AEmberCharacter* OwnerChar = Cast<AEmberCharacter>(GetOwner()))
    {
        UAbilitySystemComponent* ASC = OwnerChar->GetASC();
        if (ASC)
        {
            if (Slot.AbilityHandle.IsValid())
            {
                ASC->ClearAbility(Slot.AbilityHandle);
            }

            if (Slot.EffectHandle.IsValid())
            {
                ASC->RemoveActiveGameplayEffect(Slot.EffectHandle);
            }
        }
    }

    UE_LOG(LogTemp, Log, TEXT("Rune removed from slot %d: %s"), SlotIndex, *Slot.Rune->GetName());

    Slot = FRuneSlot(); // 슬롯 초기화 (Rune=nullptr, 핸들 비움)
}


ARuneItem* URuneSystemComponent::GetRune(int32 SlotIndex) const
{
    return RuneSlots.IsValidIndex(SlotIndex) ? RuneSlots[SlotIndex].Rune : nullptr;
}

FRuneStat URuneSystemComponent::GetRuneStatAtSlot(int32 SlotIndex) const
{
    if (!RuneSlots.IsValidIndex(SlotIndex)) return FRuneStat();

    const FRuneSlot& Slot = RuneSlots[SlotIndex];
    return (Slot.Rune != nullptr) ? Slot.Rune->GetRuneStat() : FRuneStat();
}

bool URuneSystemComponent::IsBetterRune(int32 SlotIndex, const ARuneItem* NewRune) const
{
    if (!NewRune || !RuneSlots.IsValidIndex(SlotIndex)) return false;

    const FRuneSlot& ExistingSlot = RuneSlots[SlotIndex];

    if (!ExistingSlot.Rune)
    {
        // 빈 슬롯이면 무조건 새 룬이 낫다
        return true;
    }

    const FRuneStat& OldStat = ExistingSlot.Rune->GetRuneStat();
    const FRuneStat& NewStat = NewRune->GetRuneStat();

    return NewStat.Power > OldStat.Power; // 단순 Power 비교 기준
}
