#include "Item/Drop/PickupItemActor.h"
#include "Character/EmberCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"

APickupItemActor::APickupItemActor()
{
	PrimaryActorTick.bCanEverTick = false;

	bReplicates = true; //  멀티플레이용
	SetReplicateMovement(true);

	// 컴포넌트 초기화
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	CollisionComponent->InitSphereRadius(100.f);
	CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionComponent->SetCollisionObjectType(ECC_WorldDynamic);
	CollisionComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	CollisionComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	CollisionComponent->SetGenerateOverlapEvents(true);
	CollisionComponent->SetIsReplicated(true); //  충돌 컴포넌트도 복제

	RootComponent = CollisionComponent;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComponent->SetupAttachment(RootComponent);
	MeshComponent->SetSimulatePhysics(false);
	MeshComponent->SetEnableGravity(false);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	MeshComponent->SetCollisionObjectType(ECC_WorldDynamic);
	MeshComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	MeshComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	MeshComponent->SetIsReplicated(true);
}

void APickupItemActor::BeginPlay()
{
	Super::BeginPlay();

	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("[CLIENT] Dropped item appeared: %s"), *GetName());
	}
}


void APickupItemActor::InitializeLootDrop(const FLootResultData& InLootData)
{
	LootData = InLootData;

	UStaticMesh* TargetMesh = nullptr;

	if (LootData.ItemTemplateClass)
	{
		const UItemTemplate* TemplateCDO = LootData.ItemTemplateClass->GetDefaultObject<UItemTemplate>();
		if (TemplateCDO)
		{
			TargetMesh = TemplateCDO->ItemMesh;
		}
	}
	else if (LootData.RuneTemplateClass)
	{
		const URuneItemTemplate* RuneCDO = LootData.RuneTemplateClass->GetDefaultObject<URuneItemTemplate>();
		if (RuneCDO)
		{
			TargetMesh = RuneCDO->RuneMesh;
		}
	}

	if (TargetMesh)
	{
		MeshComponent->SetStaticMesh(TargetMesh);
	}
}

void APickupItemActor::OnPickedUp(AActor* Picker)
{
	if (!HasAuthority()) return; //  서버만 처리

	AEmberCharacter* Player = Cast<AEmberCharacter>(Picker);
	if (!Player) return;

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

	// TODO: 인벤토리에 추가하는 로직 필요

	Destroy(); //  서버에서 Destroy하면 클라이언트에서도 사라짐
}

void APickupItemActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APickupItemActor, LootData); //  구조체 복제
}
