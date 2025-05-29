#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Crafting/CraftingRecipeManager.h"
#include "CraftingRecipeListItemData.generated.h"

UCLASS(BlueprintType)
class EMBER_API UCraftingRecipeListItemData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="RecipeData")
	FCraftingRecipeRow RecipeData;
};