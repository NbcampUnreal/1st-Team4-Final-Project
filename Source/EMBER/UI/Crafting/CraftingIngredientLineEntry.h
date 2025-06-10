#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CraftingIngredientLineEntry.generated.h"

class UTextBlock;
class UHorizontalBox;

UCLASS()
class EMBER_API UCraftingIngredientLineEntry : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "IngredientLine")
	void SetData(const FText& InName, int32 InOwned, int32 InRequired, bool bHasEnough);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "IngredientLine", meta = (BindWidget))
	TObjectPtr<UTextBlock> IngredientName_Text;

	UPROPERTY(BlueprintReadOnly, Category = "IngredientLine", meta = (BindWidget))
	TObjectPtr<UTextBlock> Quantity_Text;

	UPROPERTY(BlueprintReadOnly, Category = "IngredientLine", meta = (BindWidgetOptional))
	TObjectPtr<UHorizontalBox> LayoutHBox; 
};