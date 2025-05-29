#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UI/Common/EmberActivatableWidget.h"
#include "CraftingIngredientWidget.generated.h"

class UVerticalBox;

UCLASS()
class EMBER_API UCraftingIngredientWidget : public UEmberActivatableWidget
{
	GENERATED_BODY()

public:
	UCraftingIngredientWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintCallable, Category = "Crafting")
	void SetIngredientData(const TMap<FGameplayTag, int32>& Ingredients);
    
protected:
	UPROPERTY(meta = (BindWidget))
	UVerticalBox* IngredientDisplayBox;
};