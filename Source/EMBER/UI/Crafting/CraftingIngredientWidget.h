#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UI/Common/EmberActivatableWidget.h"
#include "Crafting/CraftingRecipeManager.h"
#include "CraftingIngredientWidget.generated.h"

class UVerticalBox;
struct FCraftingRecipeRow;

UCLASS()
class EMBER_API UCraftingIngredientWidget : public UEmberActivatableWidget
{
	GENERATED_BODY()

public:
	UCraftingIngredientWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintCallable, Category = "Crafting")
	void UpdateDisplay(const FCraftingRecipeRow& ForRecipe, const TMap<FGameplayTag, int32>& PlayerOwnedIngredients, int32 CraftingAmount);
    
protected:
	UPROPERTY(meta = (BindWidget))
	UVerticalBox* IngredientDisplayBox;
};