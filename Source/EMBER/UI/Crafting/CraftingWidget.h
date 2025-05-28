#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFlag.h"
#include "../Common/EmberActivatableWidget.h"
#include "CraftingWidget.generated.h"

class UCraftingRecipeListWidget;
class UCraftingIngredientWidget;
class UCraftingResultWidget;
class UCraftingRecipeData;

UCLASS()
class EMBER_API UCraftingWidget : public UEmberActivatableWidget
{
	GENERATED_BODY()

public:
	UCraftingWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual void NativeConstruct() override;
	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;

protected:
	void UpdateSelectedRecipe(int32 Direction);
	void ChangeCategory();
	void AdjustCraftAmount(int32 Delta);
	void RefreshAll();
	void ClearSelectedMainIngredients();

	UFUNCTION()
	void OnCraftButtonPressed();

protected:
	UPROPERTY(meta = (BindWidget))
	UCraftingRecipeListWidget* RecipeListWidget;

	UPROPERTY(meta = (BindWidget))
	UCraftingIngredientWidget* IngredientWidget;

	UPROPERTY(meta = (BindWidget))
	UCraftingResultWidget* ResultWidget;

	UPROPERTY(EditAnywhere)
	TArray<UCraftingRecipeData*> WeaponRecipes;

	UPROPERTY(EditAnywhere)
	TArray<UCraftingRecipeData*> ClothingRecipes;

private:
	int32 SelectedRecipeIndex = 0;
	int32 CraftAmount = 1;
	bool bIsWeaponCategory = true;

	TMap<FGameplayTag, int32> CurrentSelectedMainIngredients;
};