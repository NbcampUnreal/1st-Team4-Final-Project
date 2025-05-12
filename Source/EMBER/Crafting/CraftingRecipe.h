#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CraftingRecipe.generated.h"

UCLASS(BlueprintType, EditInlineNew)
class EMBER_API UCraftingRecipe : public UObject
{
    GENERATED_BODY()

public:
    UCraftingRecipe();

    // 제작될 아이템 이름 (예: "양손검")
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
    FString ItemName;

    // 필요한 재료와 수량 (예: { "나무": 1, "끈": 1, "주재료": 2 })
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
    TMap<FString, int32> Ingredients;

    // 최소 제작 레벨 (예: 5)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
    int32 RequiredCraftingLevel;

    // 제작에 걸리는 시간 (초, 예: 10.0)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
    float CraftingTime;

    // 제작 가능한지 검사    
    UFUNCTION(BlueprintCallable, Category = "Crafting")
    bool CanCombine(const TMap<FString, int32>& AvailableIngredients, int32 PlayerCraftingLevel) const;
};
