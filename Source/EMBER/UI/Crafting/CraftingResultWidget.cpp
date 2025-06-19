#include "UI/Crafting/CraftingResultWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Components/VerticalBox.h"
#include "Crafting/CraftingRecipeManager.h"
#include "Item/ItemTemplate.h"
#include "UI/Data/EmberItemData.h"
#include "UI/Crafting/CraftingResultIngredientLineEntry.h"
#include "Crafting/CraftingSystem.h"
#include "Player/EmberPlayerCharacter.h"

UCraftingResultWidget::UCraftingResultWidget(const FObjectInitializer& ObjectInitializer) 
    : Super(ObjectInitializer)
{
    CurrentTargetRecipeRowPtr_EditorOnly = nullptr;
}

void UCraftingResultWidget::NativeConstruct()
{
    Super::NativeConstruct();
}

const UItemTemplate* UCraftingResultWidget::GetTemplateFromRecipeRow(const FCraftingRecipeRow& RecipeRow) const
{
    if (RecipeRow.ItemTemplateClass)
    {
        return RecipeRow.ItemTemplateClass->GetDefaultObject<UItemTemplate>();
    }
    return nullptr;
}

void UCraftingResultWidget::SetRecipeDetails(UCraftingRecipeManager* RecipeManager, const FCraftingRecipeRow& InRecipeRow, const TMap<FGameplayTag, int32>& PlayerOwnedIngredients, int32 CraftingAmount)
{
    if(!RecipeManager) return;
    
    CurrentTargetRecipeRowPtr_EditorOnly = &InRecipeRow;
    const UItemTemplate* OutputTemplate = GetTemplateFromRecipeRow(InRecipeRow);

    if (ResultItemNameText)
    {
        ResultItemNameText->SetText(InRecipeRow.RecipeDisplayName);
    }

    K2_OnUpdateIconAndDescription(OutputTemplate); 

    PopulateIngredientsDisplay(RecipeManager, InRecipeRow, PlayerOwnedIngredients, CraftingAmount);

    bool bIsQualityRecipe = (InRecipeRow.RequiredMainMaterialCount > 0);
    if (InfoTextDisplay)
    {
        InfoTextDisplay->SetText(bIsQualityRecipe ? FText::FromString(TEXT("주재료 필요 (등급 변동 가능)")) : FText::FromString(TEXT("일반 제작 아이템")));
        InfoTextDisplay->SetVisibility(ESlateVisibility::HitTestInvisible);
    }
    SetVisibility(ESlateVisibility::Visible);
}

void UCraftingResultWidget::UpdateRarityDisplay(const FCraftingRecipeRow& TargetRecipeData, const TMap<EItemRarity, float>& InRarityChances)
{
    CurrentRarityChances_Cache = InRarityChances; 

    bool bIsQualityRecipe = (TargetRecipeData.RequiredMainMaterialCount > 0);
    if (!bIsQualityRecipe) 
    {
        if(InfoTextDisplay) InfoTextDisplay->SetText(FText::FromString(TEXT("일반 제작 아이템")));
        return; 
    }

    if(InfoTextDisplay)
    {
        FString DisplayStr = TEXT("예상 제작 등급:\n");
        if (CurrentRarityChances_Cache.Num() > 0)
        {
            for (const auto& Pair : CurrentRarityChances_Cache)
            {
                if (Pair.Value > 0.0001f) 
                {
                    FString RarityName = UEnum::GetDisplayValueAsText(Pair.Key).ToString();
                    DisplayStr += FString::Printf(TEXT("- %s: %.2f%%\n"), *RarityName, Pair.Value * 100.0f);
                }
            }
        }
        else
        {
            DisplayStr += TEXT("- 주재료를 선택하세요.");
        }
        InfoTextDisplay->SetText(FText::FromString(DisplayStr));
    }
}


void UCraftingResultWidget::ClearDetails()
{
    CurrentTargetRecipeRowPtr_EditorOnly = nullptr;
    if (ResultItemNameText) ResultItemNameText->SetText(FText::GetEmpty());
    if (ItemDescriptionText) ItemDescriptionText->SetText(FText::GetEmpty());
    if (InfoTextDisplay) InfoTextDisplay->SetText(FText::GetEmpty());
    if (IngredientsDisplayBox) IngredientsDisplayBox->ClearChildren();
    
    K2_OnUpdateIconAndDescription(nullptr);
    SetVisibility(ESlateVisibility::Collapsed);
}

void UCraftingResultWidget::PopulateIngredientsDisplay(UCraftingRecipeManager* RecipeManager, const FCraftingRecipeRow& RecipeData, const TMap<FGameplayTag, int32>& PlayerOwnedIngredients, int32 CraftingAmount)
{
    if (!IngredientsDisplayBox || !ResultIngredientLineEntryClass || !RecipeManager) return;
    
    IngredientsDisplayBox->ClearChildren();
    IngredientsDisplayBox->SetVisibility(ESlateVisibility::Visible);

    for (const TPair<FGameplayTag, int32>& RequiredIngredientPair : RecipeData.Ingredients)
    {
       const FGameplayTag& IngredientTag = RequiredIngredientPair.Key;
       const int32 TotalRequiredForBatch = RequiredIngredientPair.Value * CraftingAmount;
       const int32 OwnedAmount = PlayerOwnedIngredients.FindRef(IngredientTag); 
       
       UCraftingResultIngredientLineEntry* LineEntryWidget = CreateWidget<UCraftingResultIngredientLineEntry>(this, ResultIngredientLineEntryClass);
       if (LineEntryWidget)
       {
           LineEntryWidget->SetLineData(RecipeManager, IngredientTag, OwnedAmount, TotalRequiredForBatch);
           IngredientsDisplayBox->AddChildToVerticalBox(LineEntryWidget);
       }
    }
}