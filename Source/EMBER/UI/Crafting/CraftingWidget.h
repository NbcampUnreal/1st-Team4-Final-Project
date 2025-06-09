#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFlag.h"
#include "UI/Common/EmberActivatableWidget.h"
#include "UI/Crafting/CraftingMainMaterialWidget.h" 
#include "Crafting/CraftingRecipeManager.h"   
#include "UI/Crafting/CraftingRecipeListWidget.h" 
#include "CraftingWidget.generated.h"

class UCraftingRecipeListWidget;
class UCraftingIngredientWidget;
class UCraftingResultWidget;
class UCraftingMainMaterialWidget;
class UWidgetSwitcher;
class UUserWidget;
class ACraftingBuilding; 
class UCraftingRecipeListItemData;
class UCraftingOutputBoxWidget;
class UItemInstance;


UCLASS()
class EMBER_API UCraftingWidget : public UEmberActivatableWidget
{
    GENERATED_BODY()

public:
    UCraftingWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;
    virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    void InitializeForStation(ACraftingBuilding* InStationActor, FName OptionalInitialRecipeRowName = NAME_None);

protected:
    void UpdateSelectedRecipe(int32 Direction);
    void AdjustCraftAmount(int32 Delta);
    void RefreshAll();
    void ClearSelectedMainIngredients();
    void PopulateActiveRecipeList();

    UFUNCTION()
    void AttemptCraftCurrentRecipe();
    
    UFUNCTION()
    void HandleRecipeSelectedFromList(UCraftingRecipeListItemData* SelectedItemData);
    
    UFUNCTION()
    void HandleMainMaterialSelectionChanged(const FSelectedIngredientsMapWrapper& SelectedIngredientsWrapper);

protected:
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UCraftingRecipeListWidget> RecipeListWidget;

    UPROPERTY(meta = (BindWidgetOptional))
    TObjectPtr<UWidgetSwitcher> CenterContentSwitcher;

    UPROPERTY(meta = (BindWidgetOptional)) 
    TObjectPtr<UCraftingIngredientWidget> GeneralRecipeIngredientsWidget; 

    UPROPERTY(meta = (BindWidgetOptional))
    TObjectPtr<UCraftingMainMaterialWidget> MainMaterialSelectorWidget;
    
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UCraftingResultWidget> SelectedRecipeDisplayWidget; 
    
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UCraftingOutputBoxWidget> CraftingOutputBoxWidget;
    
    UPROPERTY(meta = (BindWidgetOptional))
    TObjectPtr<UUserWidget> PlayerInventoryDisplayWidget;

    UPROPERTY(BlueprintReadOnly, Category = "Crafting State")
    EStationType CurrentStationTypeForUI;

    UPROPERTY(BlueprintReadOnly, Category = "Crafting State")
    TArray<FNamedCraftingRecipe> ActiveRecipeList;

private:
    int32 SelectedRecipeIndex;
    int32 CraftAmount;
    TMap<FGameplayTag, int32> CurrentSelectedMainIngredients;
    FName SelectedRecipeName;

    UPROPERTY()
    TObjectPtr<ACraftingBuilding> CurrentStationActorRef;
};