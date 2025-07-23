#include "BaseItem.h"

ABaseItem::ABaseItem()
{
	PrimaryActorTick.bCanEverTick = false;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	RootComponent = ItemMesh;

	// 네트워크 상호작용을 위한 설정
	SetReplicates(true);
}

void ABaseItem::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseItem::Interact(AActor* InteractingActor)
{
	// 여기서 인벤토리 추가나 사운드 등 추가 가능
	UE_LOG(LogTemp, Log, TEXT("%s picked up %s"), *InteractingActor->GetName(), *ItemName.ToString());

	DestroyItem();
}

void ABaseItem::DestroyItem()
{
	Destroy();
}