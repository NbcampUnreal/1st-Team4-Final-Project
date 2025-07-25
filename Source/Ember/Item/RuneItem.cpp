#include "RuneItem.h"
#include "Character/EmberCharacter.h"
#include "Component/RuneSystemComponent.h" // �� ���� �ý����� ���� �ִٰ� ����

ARuneItem::ARuneItem()
{
    // �� Ÿ�԰� ���ʽ� ��ġ ���� ����
}

void ARuneItem::Use(AActor* User)
{
    if (AEmberCharacter* Character = Cast<AEmberCharacter>(User))
    {
        if (URuneSystemComponent* RuneSystem = Character->FindComponentByClass<URuneSystemComponent>())
        {
            RuneSystem->EquipRune(this); // �ش� �� ���� ó��
            Destroy();
        }
    }
}

FString ARuneItem::GetName() const
{
    return RuneType.ToString();
}
