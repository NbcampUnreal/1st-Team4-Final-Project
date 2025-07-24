#include "BaseItem.h"
#include "BaseItem.h"
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
	UE_LOG(LogTemp, Warning, TEXT("ABaseItem::Use() called, but not overridden. Actor: %s"), *GetName());
}
