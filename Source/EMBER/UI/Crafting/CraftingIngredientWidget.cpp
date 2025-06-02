#include "UI/Crafting/CraftingIngredientWidget.h"
#include "Components/VerticalBox.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/TextBlock.h"
#include "GameplayTagContainer.h"
#include "Crafting/CraftingRecipeManager.h"
#include "Item/ItemTemplate.h"

UCraftingIngredientWidget::UCraftingIngredientWidget(const FObjectInitializer& ObjectInitializer) 
    : Super(ObjectInitializer)
{
}

void UCraftingIngredientWidget::UpdateDisplay(const FCraftingRecipeRow& ForRecipe, const TMap<FGameplayTag, int32>& PlayerOwnedIngredients, int32 CraftingAmount)
{
    if (!IngredientDisplayBox)
    {
       return;
    }
    IngredientDisplayBox->ClearChildren();

    if (ForRecipe.RecipeDisplayName.IsEmpty() || CraftingAmount <= 0) 
    {
        return;
    }

    for (const TPair<FGameplayTag, int32>& RequiredIngredientPair : ForRecipe.Ingredients)
    {
       UHorizontalBox* HBox = NewObject<UHorizontalBox>(this);
       if (!HBox) continue;

       const FGameplayTag& IngredientTag = RequiredIngredientPair.Key;
       const int32 RequiredPerItem = RequiredIngredientPair.Value;
       const int32 TotalRequiredForBatch = RequiredPerItem * CraftingAmount;
       const int32 OwnedAmount = PlayerOwnedIngredients.FindRef(IngredientTag);

       FString MaterialDisplayNameStr = IngredientTag.GetTagName().ToString();
       const UItemTemplate* IngredientItemTemplate = nullptr; 
       
       UTextBlock* NameText = NewObject<UTextBlock>(HBox);
       if (NameText)
       {
           NameText->SetText(FText::FromString(MaterialDisplayNameStr));
           UHorizontalBoxSlot* NameSlot = HBox->AddChildToHorizontalBox(NameText);
           if(NameSlot)
           {
               NameSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill)); 
               NameSlot->SetHorizontalAlignment(HAlign_Left);
               NameSlot->SetVerticalAlignment(VAlign_Center);
               NameSlot->SetPadding(FMargin(0.f, 2.f, 5.f, 2.f));
           }
       }

       UTextBlock* QuantityText = NewObject<UTextBlock>(HBox);
       if (QuantityText)
       {
           FString QuantityStr = FString::Printf(TEXT("%d / %d"), OwnedAmount, TotalRequiredForBatch);
           QuantityText->SetText(FText::FromString(QuantityStr));
           if (OwnedAmount < TotalRequiredForBatch)
           {
               QuantityText->SetColorAndOpacity(FSlateColor(FLinearColor::Red));
           }
           else
           {
               QuantityText->SetColorAndOpacity(FSlateColor(FLinearColor::White)); 
           }
           UHorizontalBoxSlot* QuantitySlot = HBox->AddChildToHorizontalBox(QuantityText);
           if(QuantitySlot)
           {
               QuantitySlot->SetSize(FSlateChildSize(ESlateSizeRule::Automatic)); 
               QuantitySlot->SetHorizontalAlignment(HAlign_Right);
               QuantitySlot->SetVerticalAlignment(VAlign_Center);
           }
       }
       IngredientDisplayBox->AddChild(HBox);
    }
}