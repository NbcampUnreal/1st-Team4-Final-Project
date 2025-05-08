#include "CraftingSystem.h"
#include "TimerManager.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Player/EmberPlayerCharacter.h" 

UCraftingSystem::UCraftingSystem()
{
}

void UCraftingSystem::StartCrafting(AEmberPlayerCharacter* Player, const FString& ItemName, float ProcessTime)
{
	if (!Player)
		return;

	if (ProcessingAnimation)
	{
		Player->PlayAnimMontage(ProcessingAnimation);
	}

	FTimerHandle ProcessTimer;
	GetWorld()->GetTimerManager().SetTimer(ProcessTimer, [this, Player, ItemName]()
	{
		// 인벤토리 컴포넌트를 사용해 아이템 추가  
		 /* if (Player->GetInventoryComponent()) 
		 {
			Player->GetInventoryComponent()->AddItem(ItemName);
		 } */
	}, ProcessTime, false);
}

// 플레이어 인벤토리, 주변 상자 검색
TMap<FString, int32> UCraftingSystem::AggregateIngredients(AEmberPlayerCharacter* Player)
{
	TMap<FString, int32> AggregatedIngredients;

	// 캐릭터 인벤토리에서 재료 정보를 가져오기
	/* if (Player->GetInventoryComponent())
	{
		AggregatedIngredients = Player->GetInventoryComponent()->GetIngredients();
	} */

	// 플레이어가 '상자 재료 활용' 능력 있다면, 주변 상자에서 재료를 검색해 추가
	/* if (Player->bHasAbilityToUseNearbyIngredients())  
	{
		TMap<FString, int32> NearbyIngredients = SearchNearbyChestsForIngredients(Player);
		for (const auto& Pair : NearbyIngredients)
		{
			int32* FoundQuantity = AggregatedIngredients.Find(Pair.Key);
			if (FoundQuantity)
			{
				*FoundQuantity += Pair.Value;
			}
			else
			{
				AggregatedIngredients.Add(Pair.Key, Pair.Value);
			}
		}
	} */

	return AggregatedIngredients;
}

// 주변 상자에 재료 검색
TMap<FString, int32> UCraftingSystem::SearchNearChestsIngredients(AEmberPlayerCharacter* Player)
{
	TMap<FString, int32> FoundIngredients;

	TArray<AActor*> OverlappedActors;
	float SearchRadius = 500.0f;  // 검색 범위
	FVector PlayerLocation = Player->GetActorLocation();
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	TArray<AActor*> ActorsToIgnore; // 무시할 액터가 있다면 추가

	UKismetSystemLibrary::SphereOverlapActors(
		GetWorld(),
		PlayerLocation,
		SearchRadius,
		ObjectTypes,
		nullptr,           // 특정 클래스 필터가 없다면 nullptr
		ActorsToIgnore,
		OverlappedActors
	);

	for (AActor* Actor : OverlappedActors)
	{
		if (Actor->ActorHasTag("Chest"))
		{
			// 상자에서 재료 정보를 가져오는 함수 호출 
			// TMap<FString, int32> ChestIngredients = Cast<ACraftingChest>(Actor)->GetChestIngredients();
		}
	}

	return FoundIngredients;
}