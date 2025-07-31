#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item/LootResultData.h"
#include "PickupItemActor.generated.h"

UCLASS()
class EMBER_API APickupItemActor : public AActor
{
	GENERATED_BODY()

public:
	APickupItemActor();

protected:
	virtual void BeginPlay() override;

public:
	// 드롭 데이터 초기화
	void InitializeLootDrop(const FLootResultData& InLootData);

	// 상호작용 처리용 함수 (예: 플레이어가 줍기)
	UFUNCTION(BlueprintCallable)
	void OnPickedUp(AActor* Picker);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup")
	class USphereComponent* CollisionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup")
	FLootResultData LootData;

	// 희귀도별 이펙트 매핑용 맵
	UPROPERTY(EditDefaultsOnly, Category = "Effect")
	TMap<EItemRarity, UNiagaraSystem*> RarityEffects;


};
