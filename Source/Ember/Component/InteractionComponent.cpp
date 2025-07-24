#include "InteractionComponent.h"
#include "Item/BaseItem.h"
#include "GameFramework/Actor.h"

UInteractionComponent::UInteractionComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UInteractionComponent::Interact(AActor* Interactor)
{
    if (!bCanInteract) return;

    UE_LOG(LogTemp, Log, TEXT("[%s] interacted by %s"), *GetOwner()->GetName(), *Interactor->GetName());
    // InteractComponent.cpp 내부
    if (ABaseItem* Item = Cast<ABaseItem>(GetOwner()))
    {
        Item->Use(Interactor);
    }
    // 기본 동작: 아이템이라면 파괴
    GetOwner()->Destroy();
}
