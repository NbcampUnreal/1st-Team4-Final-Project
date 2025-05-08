#pragma once

#include "CoreMinimal.h"
#include "Player/EmberPlayerCharacter.h"
#include "CraftingRecipe.generated.h"

UCLASS(BlueprintType)
class EMBER_API UCraftingRecipe : public UObject
{
	GENERATED_BODY()

public:
	UCraftingRecipe();

	// 제작할 아이템 이름
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
	FString ItemName;

	// 필요한 재료(재료 이름, 수량)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
	TMap<FString, int32> Ingredients;

	// 최소 제작 레벨
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
	int32 RequiredCraftingLevel;

	// 제작에 걸리는 시간
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
	float CraftingTime;

	// 제작이 가능한지 여부
	UFUNCTION(BlueprintCallable, Category = "Crafting")
	bool bCanCraft(const TMap<FString, int32>& AvailableIngredients, int32 PlayerCraftingLevel) const;
};
