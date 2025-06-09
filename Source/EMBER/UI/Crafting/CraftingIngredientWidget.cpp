#include "UI/Crafting/CraftingIngredientWidget.h"
#include "Components/VerticalBox.h"
#include "GameplayTagContainer.h"
#include "Crafting/CraftingRecipeManager.h"
#include "Item/ItemTemplate.h"
#include "UI/Data/EmberItemData.h" 
#include "UI/Crafting/CraftingIngredientLineEntry.h"

UCraftingIngredientWidget::UCraftingIngredientWidget(const FObjectInitializer& ObjectInitializer) 
    : Super(ObjectInitializer)
{
    IngredientLineEntryWidgetClass = nullptr;
}

void UCraftingIngredientWidget::UpdateDisplay(const FCraftingRecipeRow& ForRecipe, const TMap<FGameplayTag, int32>& PlayerOwnedIngredients, int32 CraftingAmount)
{
    if (!IngredientDisplayBox)
    {
       return;
    }
    IngredientDisplayBox->ClearChildren();

    if (!IngredientLineEntryWidgetClass)
    {
        UE_LOG(LogTemp, Warning, TEXT("UCraftingIngredientWidget::UpdateDisplay - IngredientLineEntryWidgetClass is not set in Class Defaults."));
        return;
    }

    if (ForRecipe.RecipeDisplayName.IsEmpty() || CraftingAmount <= 0) 
    {
        return;
    }

    for (const TPair<FGameplayTag, int32>& RequiredIngredientPair : ForRecipe.Ingredients)
    {
       const FGameplayTag& IngredientTag = RequiredIngredientPair.Key;
       const int32 RequiredPerItem = RequiredIngredientPair.Value;
       const int32 TotalRequiredForBatch = RequiredPerItem * CraftingAmount;
       const int32 OwnedAmount = PlayerOwnedIngredients.FindRef(IngredientTag);

       FString MaterialDisplayNameStr = IngredientTag.GetTagName().ToString();

       UCraftingIngredientLineEntry* EntryWidget = CreateWidget<UCraftingIngredientLineEntry>(this, IngredientLineEntryWidgetClass);
       if (EntryWidget)
       {
           EntryWidget->SetData(FText::FromString(MaterialDisplayNameStr), OwnedAmount, TotalRequiredForBatch, (OwnedAmount >= TotalRequiredForBatch));
           IngredientDisplayBox->AddChildToVerticalBox(EntryWidget);
       }
       else
       {
            UE_LOG(LogTemp, Error, TEXT("UCraftingIngredientWidget::UpdateDisplay - Failed to create IngredientLineEntryWidget."));
       }
    }
}