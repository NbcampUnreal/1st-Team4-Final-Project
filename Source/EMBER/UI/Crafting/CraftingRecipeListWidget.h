#pragma once

#include "CoreMinimal.h"
#include "CraftingWidget.h"
#include "CraftingRecipeListWidget.generated.h"

UCLASS()
class EMBER_API UCraftingRecipeListWidget : public UCraftingWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Crafting")
	void SetRecipeList(const TArray<class UCraftingRecipeData*>& Recipes);

protected:
	UPROPERTY(meta = (BindWidget))
	class UListView* RecipeListView;
};
