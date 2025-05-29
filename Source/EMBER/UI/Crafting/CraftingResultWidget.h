#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFlag.h"
#include "UI/Common/EmberActivatableWidget.h"
#include "Crafting/CraftingRecipeManager.h"
#include "CraftingResultWidget.generated.h"

class UTextBlock;
class UButton;
class UVerticalBox;
struct FCraftingRecipeRow;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnResultCraftActionRequestedSignature);

UCLASS()
class EMBER_API UCraftingResultWidget : public UEmberActivatableWidget
{
    GENERATED_BODY()

public:
    UCraftingResultWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    void UpdateRarityChances(const TMap<EItemRarity, float>& InRarityChances);

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    void RefreshRarityPreview();

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    void SetTargetRecipe(const FCraftingRecipeRow& InRecipeRow);

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    void SetProvidedIngredients(const TMap<FGameplayTag, int32>& InIngredients);

    UPROPERTY(BlueprintAssignable, Category = "Crafting")
    FOnResultCraftActionRequestedSignature OnCraftActionRequested;

protected:
    virtual void NativeConstruct() override;

    UFUNCTION()
    void OnCraftButtonClicked();

protected:
    UPROPERTY(meta = (BindWidget))
    UTextBlock* ResultText; 

    UPROPERTY(meta = (BindWidget))
    UButton* CraftButton;

    UPROPERTY(BlueprintReadOnly, Category = "Crafting Display", meta = (BindWidgetOptional))
    UTextBlock* ResultItemNameText;
    
    UPROPERTY(BlueprintReadOnly, Category = "Crafting Display", meta = (BindWidgetOptional))
    UVerticalBox* PlayerIngredientsDisplayBox;

private:
    const FCraftingRecipeRow* CurrentTargetRecipeRowPtr; 
    
    TMap<FGameplayTag, int32> CurrentProvidedIngredients;
    TMap<EItemRarity, float> CurrentRarityChances;
};