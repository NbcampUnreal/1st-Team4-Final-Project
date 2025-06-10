#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CraftingResultIngredientLineEntry.generated.h"

class UTextBlock;
class UHorizontalBox;

UCLASS()
class EMBER_API UCraftingResultIngredientLineEntry : public UUserWidget
{
	GENERATED_BODY()

public:
	UCraftingResultIngredientLineEntry(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, Category = "Ingredient Line Data")
	void SetLineData(const FText& IngredientName, int32 OwnedCount, int32 RequiredCount, bool bHasEnough);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Ingredient Line Data", meta = (BindWidget))
	TObjectPtr<UTextBlock> IngredientNameText;

	UPROPERTY(BlueprintReadOnly, Category = "Ingredient Line Data", meta = (BindWidget))
	TObjectPtr<UTextBlock> QuantityRatioText;
    
	UPROPERTY(BlueprintReadOnly, Category = "Ingredient Line Data", meta = (BindWidgetOptional))
	TObjectPtr<UHorizontalBox> LayoutHorizontalBox;
};