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
	MeshComponent->SetSimulatePhysics(false);               // 물리 시뮬레이션 OFF
	MeshComponent->SetEnableGravity(false);                 // 중력 적용 X
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly); // 물리 충돌 무효
	MeshComponent->SetCollisionObjectType(ECC_WorldDynamic);
	MeshComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	MeshComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap); // 캐릭터와는 겹치기만
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
