#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Crafting/CraftingRecipeManager.h"
#include "CraftingListEntryWidget.generated.h"

class UTextBlock;
class UCraftingResultWidget;

UCLASS()
class EMBER_API UCraftingListEntryWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* RecipeNameText;

	void Init(UCraftingRecipeData* InRecipe, UCraftingResultWidget* InResultWidget);

protected:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnClicked();

private:
	UPROPERTY()
	UCraftingRecipeData* Recipe;

	UPROPERTY()
	UCraftingResultWidget* ResultWidget;
};
