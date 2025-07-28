#include "RuneSystemComponent.h"
#include "Character/EmberCharacter.h"
#include "EmberWeaponBase.h"
#include "Item/RuneItem.h"

URuneSystemComponent::URuneSystemComponent()
{
    PrimaryComponentTick.bCanEverTick = false;

    // �ʱ�ȭ
    EquippedRunes.SetNum(MaxRuneSlots);
}

bool URuneSystemComponent::EquipRune(ARuneItem* NewRune)
{
    if (!NewRune) return false;

    // ����ִ� ���Կ� ����
    for (int32 i = 0; i < EquippedRunes.Num(); ++i)
    {
        if (!EquippedRunes[i])
        {
            EquippedRunes[i] = NewRune;

            // �� ȿ�� ������ ���⼭ (ex. �ɷ�ġ ����)
            UE_LOG(LogTemp, Log, TEXT("Rune equipped in slot %d: %s"), i, *NewRune->GetName());
            return true;
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("No empty rune slots available."));

    if (AEmberCharacter* OwnerChar = Cast<AEmberCharacter>(GetOwner()))
    {
        //if (AEmberWeaponBase* Weapon = Cast<AEmberWeaponBase>(OwnerChar->GetCurrentWeapon()))
        {
            //AEmberWeaponBase* Weapon; /* 이거 지우고 위에꺼 활성화.캐릭터 쪽에 들고있는 무기 가져오는 함수 추가해야함 */
            //Weapon->ApplyRune(NewRune);
        }
    }
    return false;
}

void URuneSystemComponent::RemoveRune(int32 SlotIndex)
{
    if (EquippedRunes.IsValidIndex(SlotIndex) && EquippedRunes[SlotIndex])
    {
        UE_LOG(LogTemp, Log, TEXT("Rune removed from slot %d: %s"), SlotIndex, *EquippedRunes[SlotIndex]->GetName());
        EquippedRunes[SlotIndex] = nullptr;

        // ȿ�� ���ŵ� �ʿ��ϸ� ���⿡ �߰�
    }
}

ARuneItem* URuneSystemComponent::GetRune(int32 SlotIndex) const
{
    return EquippedRunes.IsValidIndex(SlotIndex) ? EquippedRunes[SlotIndex] : nullptr;
}
