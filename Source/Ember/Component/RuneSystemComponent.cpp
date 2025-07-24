#include "RuneSystemComponent.h"
#include "Item/RuneItem.h"

URuneSystemComponent::URuneSystemComponent()
{
    PrimaryComponentTick.bCanEverTick = false;

    // 초기화
    EquippedRunes.SetNum(MaxRuneSlots);
}

bool URuneSystemComponent::EquipRune(ARuneItem* NewRune)
{
    if (!NewRune) return false;

    // 비어있는 슬롯에 장착
    for (int32 i = 0; i < EquippedRunes.Num(); ++i)
    {
        if (!EquippedRunes[i])
        {
            EquippedRunes[i] = NewRune;

            // 룬 효과 적용은 여기서 (ex. 능력치 증가)
            UE_LOG(LogTemp, Log, TEXT("Rune equipped in slot %d: %s"), i, *NewRune->GetName());

            return true;
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("No empty rune slots available."));
    return false;
}

void URuneSystemComponent::RemoveRune(int32 SlotIndex)
{
    if (EquippedRunes.IsValidIndex(SlotIndex) && EquippedRunes[SlotIndex])
    {
        UE_LOG(LogTemp, Log, TEXT("Rune removed from slot %d: %s"), SlotIndex, *EquippedRunes[SlotIndex]->GetName());
        EquippedRunes[SlotIndex] = nullptr;

        // 효과 제거도 필요하면 여기에 추가
    }
}

ARuneItem* URuneSystemComponent::GetRune(int32 SlotIndex) const
{
    return EquippedRunes.IsValidIndex(SlotIndex) ? EquippedRunes[SlotIndex] : nullptr;
}
