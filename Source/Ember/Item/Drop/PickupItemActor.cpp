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
	MeshComponent->SetGenerateOverlapEvents(true);


}
void APickupItemActor::OnPickupBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AEmberCharacter* Character = Cast<AEmberCharacter>(OtherActor);
	if (Character)
	{
		UE_LOG(LogTemp, Warning, TEXT("PickupItem: %s overlapped!"), *GetName());
		Character->AddOverlappingItem(this); // 이 함수는 캐릭터에 직접 구현해야 함
	}
}

void APickupItemActor::OnPickupEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AEmberCharacter* Character = Cast<AEmberCharacter>(OtherActor);
	if (Character)
	{
		Character->RemoveOverlappingItem(this);
	}
}
void APickupItemActor::BeginPlay()
{
	Super::BeginPlay();
	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("[CLIENT] Dropped item appeared: %s"), *GetName());
	}
	
	if (MeshComponent)
	{
		MeshComponent->OnComponentBeginOverlap.AddDynamic(this, &APickupItemActor::OnPickupBeginOverlap);
		MeshComponent->OnComponentEndOverlap.AddDynamic(this, &APickupItemActor::OnPickupEndOverlap);
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
	if (!HasAuthority()) return; // 서버에서만 처리

	AEmberCharacter* Player = Cast<AEmberCharacter>(Picker);
	if (!Player) return;

	FString ItemName;

	// 아이템 처리
	if (LootData.ItemTemplateClass)
	{
		// 퀵슬롯 추가
		if (UQuickSlotComponent* QuickSlot = Player->GetQuickSlotComponent())
		{
			QuickSlot->AddItemToQuickSlot(LootData.ItemTemplateClass, LootData.Quantity);
		}

		// 아이템 이름 가져오기
		const UItemTemplate* Template = LootData.ItemTemplateClass->GetDefaultObject<UItemTemplate>();
		ItemName = Template ? Template->DisplayName.ToString() : TEXT("Unknown Item");
	}
	else if (LootData.RuneTemplateClass)
	{
		const URuneItemTemplate* Template = LootData.RuneTemplateClass->GetDefaultObject<URuneItemTemplate>();
		ItemName = Template ? Template->RuneName.ToString() : TEXT("Unknown Rune");

		Player->TryEquipRune(Template);
	}
	else
	{
		ItemName = TEXT("Unnamed Loot");
	}

	// 공통 로그 출력
	UE_LOG(LogTemp, Warning, TEXT("Picked up: %s x%d"), *ItemName, LootData.Quantity);

	Destroy(); // 서버에서 Destroy → 클라에서도 사라짐
}

void APickupItemActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APickupItemActor, LootData); //  구조체 복제
}
