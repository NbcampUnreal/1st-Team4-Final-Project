#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Math/IntPoint.h"
#include "LootTable.generated.h"

class UItemTemplate;

USTRUCT(BlueprintType)
struct FLootDropItem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Loot")
	TSubclassOf<UItemTemplate> ItemTemplateClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Loot")
	FIntPoint QuantityRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Loot", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float DropChance;

	FLootDropItem()
		: ItemTemplateClass(nullptr)
		, QuantityRange(1, 1)
		, DropChance(1.0f)
	{}
};


USTRUCT(BlueprintType)
struct FMonsterLootProfile : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Loot")
	TArray<FLootDropItem> LootDrops;
};