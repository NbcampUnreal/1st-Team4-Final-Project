#include "Crafting/CraftingRecipe.h"

UCraftingRecipe::UCraftingRecipe()
	: ItemName(TEXT("DefaultItem"))
	, RequiredCraftingLevel(1)
	, CraftingTime(5.0f)
{
	
}

bool UCraftingRecipe::bCanCraft(const TMap<FString, int32>& AvailableIngredients, int32 PlayerCraftingLevel) const
{
	// 플레이어 제작 레벨 검사 
	if (PlayerCraftingLevel < RequiredCraftingLevel)
	{
		return false;
	}

	// 필요한 재료 검사
	for (const TPair<FString, int32>& Required : Ingredients)
	{
		const int32* AvailableQuantity = AvailableIngredients.Find(Required.Key);
		if (!AvailableQuantity || *AvailableQuantity < Required.Value)
		{
			return false;
		}
	}

	return true;
}
