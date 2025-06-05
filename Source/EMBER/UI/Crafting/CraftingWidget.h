#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFlag.h"
#include "UI/Common/EmberActivatableWidget.h"
#include "UI/Crafting/CraftingMainMaterialWidget.h" 
#include "Crafting/CraftingRecipeManager.h"   
#include "UI/Crafting/CraftingRecipeListWidget.h" 
// #include "UI/Crafting/CraftingOutputBoxWidget.h" // 전방 선언으로 대체 또는 필요시 유지
#include "CraftingWidget.generated.h"

class UCraftingRecipeListWidget;
class UCraftingIngredientWidget;
class UCraftingResultWidget;
class UCraftingMainMaterialWidget;
class UWidgetSwitcher;
class UUserWidget;
class ACraftingBuilding; 
class UPanelWidget; 
class UCraftingRecipeListItemData;
class UInventoryManagerComponent;
class UCraftingOutputBoxWidget; // 전방 선언


UCLASS()
class EMBER_API UCraftingWidget : public UEmberActivatableWidget
{
    GENERATED_BODY()

public:
    UCraftingWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

    virtual void NativeConstruct() override;
    virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    void InitializeForStation(ACraftingBuilding* InStationActor, FName OptionalInitialRecipeRowName = NAME_None);

protected:
    void UpdateSelectedRecipe(int32 Direction);
    void ChangeCategory();
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

    UPROPERTY(meta = (BindWidgetOptional))
    TObjectPtr<UPanelWidget> OutputInventoryDisplayContainer; 

    UPROPERTY(EditDefaultsOnly, Category = "Crafting UI")
    TSubclassOf<UCraftingOutputBoxWidget> StationOutputInventoryWidgetClass; 
    
    UPROPERTY(meta = (BindWidgetOptional))
    TObjectPtr<UUserWidget> PlayerInventoryDisplayWidget;

    UPROPERTY(BlueprintReadOnly, Category = "Crafting State")
    EStationType CurrentStationTypeForUI;

    UPROPERTY(BlueprintReadOnly, Category = "Crafting State")
    TArray<FNamedCraftingRecipe> ActiveRecipeList;

private:
    int32 SelectedRecipeIndex = 0;
    int32 CraftAmount = 1;
    TMap<FGameplayTag, int32> CurrentSelectedMainIngredients;
    FName SelectedRecipeName = NAME_None;

    UPROPERTY()
    TObjectPtr<ACraftingBuilding> CurrentStationActorRef;
    
    UPROPERTY()
    TObjectPtr<UCraftingOutputBoxWidget> ActiveOutputInventoryUI;
};