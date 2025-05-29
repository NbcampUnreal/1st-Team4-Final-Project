#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFlag.h"
#include "UI/Common/EmberActivatableWidget.h"
#include "UI/Crafting/CraftingMainMaterialWidget.h"
#include "Crafting/CraftingRecipeManager.h"
#include "CraftingWidget.generated.h"

class UCraftingRecipeListWidget;
class UCraftingIngredientWidget;
class UCraftingResultWidget;
struct FCraftingRecipeRow;
class UCraftingMainMaterialWidget;

UCLASS()
class EMBER_API UCraftingWidget : public UEmberActivatableWidget
{
    GENERATED_BODY()

public:
    UCraftingWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

    virtual void NativeConstruct() override;
    virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    void InitializeForStation(EStationType InStationType, FName OptionalInitialRecipeRowName = NAME_None);

protected:
    void UpdateSelectedRecipe(int32 Direction);
    void ChangeCategory();
    void AdjustCraftAmount(int32 Delta);
    void RefreshAll();
    void ClearSelectedMainIngredients();
    void PopulateActiveRecipeList();

    UFUNCTION()
    void OnCraftButtonPressed();

    UFUNCTION()
    void HandleRecipeSelectedFromList(const FCraftingRecipeRow& SelectedRecipeRow);
    
    UFUNCTION()
    void HandleMainMaterialSelectionChanged(const FSelectedIngredientsMapWrapper& SelectedIngredientsWrapper);


protected:
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UCraftingRecipeListWidget> RecipeListWidget;

    UPROPERTY(meta = (BindWidgetOptional))
    TObjectPtr<class UWidgetSwitcher> CenterPaneSwitcher;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UCraftingIngredientWidget> IngredientWidget; 

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UCraftingResultWidget> ResultWidget;

    UPROPERTY(meta = (BindWidgetOptional))
    TObjectPtr<UCraftingMainMaterialWidget> MainMaterialSelectorWidget;

    UPROPERTY(BlueprintReadOnly, Category = "Crafting State")
    EStationType CurrentStationTypeForUI;

    UPROPERTY(BlueprintReadOnly, Category = "Crafting State")
    TArray<FCraftingRecipeRow> ActiveRecipeList;

private:
    int32 SelectedRecipeIndex = 0;
    int32 CraftAmount = 1;

    TMap<FGameplayTag, int32> CurrentSelectedMainIngredients;
};