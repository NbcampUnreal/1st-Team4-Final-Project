#include "RuneItem.h"
#include "Character/EmberCharacter.h"
#include "Component/RuneSystemComponent.h" // 룬 장착 시스템이 따로 있다고 가정

ARuneItem::ARuneItem()
{
    // 룬 타입과 보너스 수치 설정 가능
}

void ARuneItem::Use(AActor* User)
{
    if (AEmberCharacter* Character = Cast<AEmberCharacter>(User))
    {
        if (URuneSystemComponent* RuneSystem = Character->FindComponentByClass<URuneSystemComponent>())
        {
            RuneSystem->EquipRune(this); // 해당 룬 장착 처리
            Destroy();
        }
    }
}
