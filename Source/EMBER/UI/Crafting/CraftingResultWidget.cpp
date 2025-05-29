#include "UI/Crafting/CraftingResultWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/VerticalBox.h"
#include "Crafting/CraftingRecipeManager.h"
#include "Item/ItemTemplate.h"


UCraftingResultWidget::UCraftingResultWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    CurrentTargetRecipeRowPtr = nullptr;
}

void UCraftingResultWidget::NativeConstruct()
{
    Super::NativeConstruct();
    if (CraftButton)
    {
        CraftButton->OnClicked.AddDynamic(this, &UCraftingResultWidget::OnCraftButtonClicked);
    }
}

void UCraftingResultWidget::OnCraftButtonClicked()
{
    OnCraftActionRequested.Broadcast();
}

void UCraftingResultWidget::UpdateRarityChances(const TMap<EItemRarity, float>& InRarityChances)
{
    CurrentRarityChances = InRarityChances;

    if(ResultText)
    {
        FString DisplayStr = TEXT("제작 성공 시 예상 등급:\n");
        if (CurrentRarityChances.Num() == 0 && CurrentTargetRecipeRowPtr && CurrentTargetRecipeRowPtr->RequiredMainMaterialCount == 0)
        {
             DisplayStr += FString::Printf(TEXT("- %s: 100.00%%\n"), *UEnum::GetValueAsString(EItemRarity::Common));
        }
        else
        {
            for (const auto& Pair : CurrentRarityChances)
            {
                if (Pair.Value > 0.0001f) 
                {
                    DisplayStr += FString::Printf(TEXT("- %s: %.2f%%\n"), *UEnum::GetValueAsString(Pair.Key), Pair.Value * 100.0f);
                }
            }
        }
        ResultText->SetText(FText::FromString(DisplayStr));
    }
}

void UCraftingResultWidget::RefreshRarityPreview()
{
    UpdateRarityChances(CurrentRarityChances);
}

void UCraftingResultWidget::SetTargetRecipe(const FCraftingRecipeRow& InRecipeRow)
{
    CurrentTargetRecipeRowPtr = &InRecipeRow;

    if (ResultItemNameText)
    {
        ResultItemNameText->SetText(InRecipeRow.RecipeDisplayName);
    }
    RefreshRarityPreview(); 
}

void UCraftingResultWidget::SetProvidedIngredients(const TMap<FGameplayTag, int32>& InIngredients)
{
    CurrentProvidedIngredients = InIngredients;

    if (PlayerIngredientsDisplayBox)
    {
        PlayerIngredientsDisplayBox->ClearChildren();
        for (const TPair<FGameplayTag, int32>& IngredientPair : CurrentProvidedIngredients)
        {
            UTextBlock* IngredientLine = NewObject<UTextBlock>(this);
            if (IngredientLine)
            {
                FString MatName = IngredientPair.Key.GetTagName().ToString(); 
                FString Line = FString::Printf(TEXT("%s: %d개 보유"), *MatName, IngredientPair.Value);
                IngredientLine->SetText(FText::FromString(Line));
                PlayerIngredientsDisplayBox->AddChildToVerticalBox(IngredientLine);
            }
        }
    }
}