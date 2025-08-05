#include "Item/Drop/PickupItemActor.h"
#include "Character/EmberCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "NiagaraFunctionLibrary.h" // Niagara 관련 함수들
#include "NiagaraComponent.h"

APickupItemActor::APickupItemActor()
{
	PrimaryActorTick.bCanEverTick = false;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));

	CollisionComponent->InitSphereRadius(100.f);
	CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionComponent->SetCollisionObjectType(ECC_WorldDynamic);
	CollisionComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	CollisionComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	CollisionComponent->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	CollisionComponent->SetGenerateOverlapEvents(true);

	RootComponent = CollisionComponent;

	MeshComponent->SetupAttachment(RootComponent); // 충돌 위에 메쉬 배치
	MeshComponent->SetSimulatePhysics(false);
	MeshComponent->SetEnableGravity(false);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	MeshComponent->SetCollisionObjectType(ECC_WorldDynamic);
	MeshComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	MeshComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
}

void APickupItemActor::BeginPlay()
{
	Super::BeginPlay();
}

void APickupItemActor::InitializeLootDrop(const FLootResultData& InLootData)
{
	LootData = InLootData;

	UStaticMesh* TargetMesh = nullptr;

	// 아이템 메시 가져오기
	if (LootData.ItemTemplateClass)
	{
		const UItemTemplate* TemplateCDO = LootData.ItemTemplateClass->GetDefaultObject<UItemTemplate>();
		if (TemplateCDO)
		{
			TargetMesh = TemplateCDO->ItemMesh;
		}
	}
	// 룬 메시 가져오기
	else if (LootData.RuneTemplateClass)
	{
		const URuneItemTemplate* RuneCDO = LootData.RuneTemplateClass->GetDefaultObject<URuneItemTemplate>();
		if (RuneCDO)
		{
			TargetMesh = RuneCDO->RuneMesh;
		}
	}

	// 메시 적용
	if (TargetMesh)
	{
		MeshComponent->SetStaticMesh(TargetMesh);
	}
}



void APickupItemActor::OnPickedUp(AActor* Picker)
{
	if (!Picker) return;

	AEmberCharacter* Player = Cast<AEmberCharacter>(Picker);
	if (!Player) return;

	// 아이템 처리
	FString ItemName;

	if (LootData.ItemTemplateClass)
	{
		const UItemTemplate* Template = LootData.ItemTemplateClass->GetDefaultObject<UItemTemplate>();
		ItemName = Template ? Template->DisplayName.ToString() : TEXT("Unknown Item");
	}
	else if (LootData.RuneTemplateClass)
	{
		const URuneItemTemplate* Template = LootData.RuneTemplateClass->GetDefaultObject<URuneItemTemplate>();
		ItemName = Template ? Template->RuneName.ToString() : TEXT("Unknown Rune");
	}
	else
	{
		ItemName = TEXT("Unnamed Loot");
	}

	UE_LOG(LogTemp, Warning, TEXT("Picked up: %s x%d"), *ItemName, LootData.Quantity);


	Destroy();
}
