#include "BaseItem.h"
#include "Character/EmberCharacter.h"
#include "Item/Drop/PickupItemActor.h"
#include "Component/InteractionComponent.h"
#include "Components/StaticMeshComponent.h"


ABaseItem::ABaseItem()
{
	PrimaryActorTick.bCanEverTick = false;
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	RootComponent = ItemMesh;

	InteractionComp = CreateDefaultSubobject<UInteractionComponent>(TEXT("InteractionComponent"));

	// 네트워크 상호작용을 위한 설정
	SetReplicates(true);
}
void ABaseItem::Use(AActor* User)
{
	if (AEmberCharacter* Character = Cast<AEmberCharacter>(User))
	{
		// 먼저 이 아이템이 PickupItemActor인지 확인
		if (APickupItemActor* PickupItem = Cast<APickupItemActor>(this))
		{
			if (Character->HasAuthority())
			{
				// 서버라면 바로 처리
				PickupItem->OnPickedUp(Character);
			}
			else
			{
				// 클라이언트라면 서버에 요청
				Character->Server_PickupItem(PickupItem);
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Use() called on non-pickup item."));
		}
	}
}
