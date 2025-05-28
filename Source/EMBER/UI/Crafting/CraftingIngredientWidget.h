#pragma once

#include "CoreMinimal.h"
#include "CraftingWidget.h"
#include "CraftingIngredientWidget.generated.h"

class UVerticalBox;

UCLASS()
class EMBER_API UCraftingIngredientWidget : public UCraftingWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Crafting")
	void SetIngredientData(const TMap<FString, int32>& Ingredients);
    
protected:
	UPROPERTY(meta = (BindWidget))
	class UVerticalBox* IngredientSelectionBox;
};
