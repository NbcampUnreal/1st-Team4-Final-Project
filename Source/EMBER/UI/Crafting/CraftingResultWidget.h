#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFlag.h"
#include "UI/Common/EmberActivatableWidget.h"
#include "Crafting/CraftingRecipeManager.h"
#include "CraftingResultWidget.generated.h"

class UTextBlock;
class UImage;
class UVerticalBox;
struct FCraftingRecipeRow;
class UItemTemplate;


UCLASS()
class EMBER_API UCraftingResultWidget : public UEmberActivatableWidget
{
    GENERATED_BODY()

public:
    UCraftingResultWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

    UFUNCTION(BlueprintCallable, Category = "CraftingResult")
    void SetRecipeDetails(const FCraftingRecipeRow& InRecipeRow, const TMap<FGameplayTag, int32>& PlayerOwnedIngredients, int32 CraftingAmount);

    UFUNCTION(BlueprintCallable, Category = "CraftingResult")
    void UpdateRarityDisplay(const FCraftingRecipeRow& TargetRecipeData, const TMap<EItemRarity, float>& InRarityChances);
    
    UFUNCTION(BlueprintCallable, Category = "CraftingResult")
    void ClearDetails();

protected:
    virtual void NativeConstruct() override;

    UPROPERTY(BlueprintReadOnly, Category = "CraftingResult", meta = (BindWidgetOptional))
    TObjectPtr<UTextBlock> ResultItemNameText; 

    UPROPERTY(BlueprintReadOnly, Category = "CraftingResult", meta = (BindWidgetOptional))
    TObjectPtr<UImage> ItemIconDisplay;

    UPROPERTY(BlueprintReadOnly, Category = "CraftingResult", meta = (BindWidgetOptional))
    TObjectPtr<UTextBlock> ItemDescriptionText;

    UPROPERTY(BlueprintReadOnly, Category = "CraftingResult", meta = (BindWidgetOptional))
    TObjectPtr<UTextBlock> InfoTextDisplay; 

    UPROPERTY(BlueprintReadOnly, Category = "CraftingResult", meta = (BindWidgetOptional))
    TObjectPtr<UVerticalBox> IngredientsDisplayBox;

    UFUNCTION(BlueprintImplementableEvent, Category = "CraftingResult", meta = (DisplayName = "OnUpdateIconAndDescription_BP"))
    void K2_OnUpdateIconAndDescription(const UItemTemplate* ItemTemplateData);

private:
    const FCraftingRecipeRow* CurrentTargetRecipeRowPtr; 
    TMap<EItemRarity, float> CurrentRarityChances_Cache; 

    const UItemTemplate* GetTemplateFromID(int32 TemplateID) const;
    void PopulateIngredientsDisplay(const FCraftingRecipeRow& RecipeData, const TMap<FGameplayTag, int32>& PlayerOwnedIngredients, int32 CraftingAmount);
};