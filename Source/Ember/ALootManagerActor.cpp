// Fill out your copyright notice in the Description page of Project Settings.


#include "ALootManagerActor.h"
#include "Kismet/GameplayStatics.h"

ALootManagerActor::ALootManagerActor()
{
	PrimaryActorTick.bCanEverTick = false;

	// 1. 루트 컴포넌트 생성
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(Root);

	// 2. LootDropManagerComponent 생성 및 부착
	LootDropComponent = CreateDefaultSubobject<ULootDropManagerComponent>(TEXT("LootDropComponent"));

	

}

void ALootManagerActor::BeginPlay()
{
	Super::BeginPlay();
	
	PrimaryActorTick.bCanEverTick = false;

	// 타이머를 이용해 1초 후에 SimulateDeath 호출
	GetWorld()->GetTimerManager().SetTimer(
		SimulateDeathTimerHandle,
		this,
		&ALootManagerActor::SimulateDeath,
		1.0f,
		false
	);
}

void ALootManagerActor::SimulateDeath()
{
	FMonsterDiedMessage Message;
	Message.MonsterID = TEXT("Test");  // DataTable의 RowName과 일치해야 함
	Message.DeathLocation = GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("SimulateDeath() called"));
	
	// 올바른 인터페이스 방식으로 호출
	if (this->GetClass()->ImplementsInterface(ULootableInterface::StaticClass()))
	{
		UE_LOG(LogTemp, Warning, TEXT("[ALootManagerActor] Executing NotifyMonsterDied via Execute_"));

		ILootableInterface::Execute_NotifyMonsterDied(this, Message);
	}

	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to cast to ILootableInterface"));
	}
}


void ALootManagerActor::NotifyMonsterDied_Implementation(const FMonsterDiedMessage& Message)
{
	if (LootDropComponent)
	{
		// Execute_NotifyMonsterDied(LootDropComponent, Message); << 작동 안 함
		UE_LOG(LogTemp, Warning, TEXT("[ALootManagerActor] Calling LootDropComponent->HandleMonsterDied"));
		LootDropComponent->HandleMonsterDied(Message); // 직접 호출

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("LootDropComponent is null"));
	}
}

