#include "Item/Drop/PickupItemActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "NiagaraFunctionLibrary.h" // Niagara 관련 함수들
#include "NiagaraComponent.h"

APickupItemActor::APickupItemActor()
{
	PrimaryActorTick.bCanEverTick = false;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	
	// 물리 및 충돌 설정
	MeshComponent->SetSimulatePhysics(true);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	MeshComponent->SetCollisionObjectType(ECC_PhysicsBody);
	MeshComponent->SetNotifyRigidBodyCollision(true);
	MeshComponent->SetLinearDamping(20.0f); // 속도 감쇠: 높을수록 빨리 멈춤
	MeshComponent->SetAngularDamping(1000.0f); // 회전 감쇠
}

void APickupItemActor::BeginPlay()
{
	Super::BeginPlay();
}

void APickupItemActor::InitializeLootDrop(const FLootResultData& InLootData)
{
	LootData = InLootData;
	

	// 여기서 아이템 외형/색상 등 적용 가능 (예: 희귀도 색상)
	if (!LootData.ItemTemplateClass)
		return;

	const UItemTemplate* TemplateCDO = LootData.ItemTemplateClass->GetDefaultObject<UItemTemplate>();

	// Niagara 이펙트가 설정되어 있을 경우
	if (TemplateCDO && TemplateCDO->DropEffect)
	{
		UNiagaraFunctionLibrary::SpawnSystemAttached(
			TemplateCDO->DropEffect,
			RootComponent,            // 또는 MeshComponent
			NAME_None,
			FVector::ZeroVector,
			FRotator::ZeroRotator,
			EAttachLocation::KeepRelativeOffset,
			true
		);
	}
}

void APickupItemActor::OnPickedUp(AActor* Picker)
{
	// 인벤토리에 추가하거나, 메시 출력 등 로직
	Destroy();
}
