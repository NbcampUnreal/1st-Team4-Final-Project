#include "UI/Crafting/CraftingResultWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Components/VerticalBox.h"
#include "Crafting/CraftingRecipeManager.h"
#include "Item/ItemTemplate.h"
#include "UI/Data/EmberItemData.h"


UCraftingResultWidget::UCraftingResultWidget(const FObjectInitializer& ObjectInitializer) 
    : Super(ObjectInitializer)
{
    CurrentTargetRecipeRowPtr = nullptr;
    ResultItemNameText = nullptr;
    ItemIconDisplay = nullptr;
    ItemDescriptionText = nullptr;
    InfoTextDisplay = nullptr;
    IngredientsDisplayBox = nullptr;
}

void UCraftingResultWidget::NativeConstruct()
{
    Super::NativeConstruct();
}

const UItemTemplate* UCraftingResultWidget::GetTemplateFromID(int32 TemplateID) const
{
    if (TemplateID != INDEX_NONE)
    {
        UE_LOG(LogTemp, Warning, TEXT("UCraftingResultWidget::GetTemplateFromID - Returning nullptr for TemplateID %d. UEmberItemData::Get().FindItemTemplateByID() must be fixed by your teammate to return 'const UItemTemplate*' and handle invalid IDs safely to resolve C2440 and enable proper functionality (icon, description, etc.)."), TemplateID);
    }
    return nullptr;
}

void UCraftingResultWidget::SetRecipeDetails(const FCraftingRecipeRow& InRecipeRow, const TMap<FGameplayTag, int32>& PlayerOwnedIngredients, int32 CraftingAmount)
{
    CurrentTargetRecipeRowPtr = &InRecipeRow;
    const UItemTemplate* OutputTemplate = nullptr;

    if (ResultItemNameText)
    {
        ResultItemNameText->SetText(InRecipeRow.RecipeDisplayName);
    }
    int32 ItemTemplateID = UEmberItemData::Get().FindItemTemplateIDByClass(InRecipeRow.ItemTemplateClass);
    const UItemTemplate& ItemTemplate = UEmberItemData::Get().FindItemTemplateByID(ItemTemplateID);
    
    K2_OnUpdateIconAndDescription(OutputTemplate);

    PopulateIngredientsDisplay(InRecipeRow, PlayerOwnedIngredients, CraftingAmount);

    bool bIsQualityRecipe = (InRecipeRow.RequiredMainMaterialCount > 0);
    if (InfoTextDisplay)
    {
        if (!bIsQualityRecipe)
        {
            InfoTextDisplay->SetText(FText::FromString(TEXT("일반 제작 아이템")));
            InfoTextDisplay->SetVisibility(ESlateVisibility::HitTestInvisible);
        }
        else
        {
            InfoTextDisplay->SetText(FText::FromString(TEXT("주재료 필요 (등급 변동 가능)"))); 
            InfoTextDisplay->SetVisibility(ESlateVisibility::HitTestInvisible);
        }
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
                    DisplayStr += FString::Printf(TEXT("- %s: %.2f%%\n"), *UEnum::GetValueAsString(Pair.Key), Pair.Value * 100.0f);
                }
            }
        }
        else
        {
             DisplayStr += TEXT("- 주재료를 선택하세요.");
        }
        InfoTextDisplay->SetText(FText::FromString(DisplayStr));
        InfoTextDisplay->SetVisibility(ESlateVisibility::HitTestInvisible);
    }
}


void UCraftingResultWidget::ClearDetails()
{
    CurrentTargetRecipeRowPtr = nullptr;
    if (ResultItemNameText) ResultItemNameText->SetText(FText::GetEmpty());
    if (ItemDescriptionText) ItemDescriptionText->SetText(FText::GetEmpty());
    if (InfoTextDisplay) InfoTextDisplay->SetText(FText::GetEmpty());
    if (IngredientsDisplayBox) IngredientsDisplayBox->ClearChildren();
    
    K2_OnUpdateIconAndDescription(nullptr);
    SetVisibility(ESlateVisibility::Collapsed);
}

void UCraftingResultWidget::PopulateIngredientsDisplay(const FCraftingRecipeRow& RecipeData, const TMap<FGameplayTag, int32>& PlayerOwnedIngredients, int32 CraftingAmount)
{
    if (!IngredientsDisplayBox) return;
    IngredientsDisplayBox->ClearChildren();

    if (RecipeData.RecipeDisplayName.IsEmpty() || CraftingAmount <= 0) return;

    bool bIsGeneralCraft = (RecipeData.RequiredMainMaterialCount == 0);
    if (!bIsGeneralCraft) 
    {
        IngredientsDisplayBox->SetVisibility(ESlateVisibility::Collapsed);
        return;
    }
    IngredientsDisplayBox->SetVisibility(ESlateVisibility::Visible);

    for (const TPair<FGameplayTag, int32>& RequiredIngredientPair : RecipeData.Ingredients)
    {
       UTextBlock* IngredientLineText = NewObject<UTextBlock>(this);
       if (IngredientLineText)
       {
          const FGameplayTag& IngredientTag = RequiredIngredientPair.Key;
          const int32 RequiredPerItem = RequiredIngredientPair.Value;
          const int32 TotalRequiredForBatch = RequiredPerItem * CraftingAmount;
          const int32 OwnedAmount = PlayerOwnedIngredients.FindRef(IngredientTag); 
          
          FString MaterialName = IngredientTag.GetTagName().ToString();
          
          FString DisplayText = FString::Printf(TEXT("%s: %d / %d"), *MaterialName, OwnedAmount, TotalRequiredForBatch);
          IngredientLineText->SetText(FText::FromString(DisplayText));

          if (OwnedAmount < TotalRequiredForBatch)
          {
              IngredientLineText->SetColorAndOpacity(FSlateColor(FLinearColor::Red));
          }
          else
          {
              IngredientLineText->SetColorAndOpacity(FSlateColor(FLinearColor::White)); 
          }
          IngredientsDisplayBox->AddChild(IngredientLineText);
       }
    }
}