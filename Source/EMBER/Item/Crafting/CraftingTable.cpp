#include "CraftingTable.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Player/EmberPlayerCharacter.h"
#include "../Crafting/CraftingSystem.h"

ACraftingTable::ACraftingTable()
{
	PrimaryActorTick.bCanEverTick = true;

	TableMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TableMesh"));
	RootComponent = TableMesh;

	InteractionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("InteractionBox"));
	InteractionBox->SetupAttachment(RootComponent);
	InteractionBox->SetBoxExtent(FVector(100.f, 100.f, 50.f));
	InteractionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	InteractionBox->SetCollisionResponseToAllChannels(ECR_Ignore);
	InteractionBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
}

void ACraftingTable::BeginPlay()
{
	Super::BeginPlay();
}

void ACraftingTable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACraftingTable::OnInteract(AActor* Interactor)
{
	AEmberPlayerCharacter* Player = Cast<AEmberPlayerCharacter>(Interactor);
	if (Player)
	{
		UCraftingSystem* CraftingSystem = Player->FindComponentByClass<UCraftingSystem>();
		if (CraftingSystem)
		{
			// 실제 아이템명은 상황에 맞게 변경
			CraftingSystem->StartCrafting(Player, TEXT("TestItem"));
		}
	}
}
