#include "UI/Crafting/CraftingIngredientLineEntry.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Components/HorizontalBox.h"
#include "Crafting/CraftingRecipeManager.h"
#include "Item/ItemTemplate.h"
#include "Styling/SlateColor.h"

void UCraftingIngredientLineEntry::SetData(UCraftingRecipeManager* RecipeManager, FGameplayTag IngredientTag, int32 InOwned, int32 InRequired)
{
    if (!RecipeManager || !IngredientTag.IsValid() || InRequired <= 0)
    {
        SetVisibility(ESlateVisibility::Collapsed);
        return;
    }
    
    SetVisibility(ESlateVisibility::SelfHitTestInvisible);

    TSubclassOf<UItemTemplate> RepItemTemplateClass = RecipeManager->GetRepresentativeItemForTag(IngredientTag);
    if (RepItemTemplateClass)
    {
        const UItemTemplate* ItemTemplateCDO = RepItemTemplateClass->GetDefaultObject<UItemTemplate>();
        if (ItemTemplateCDO)
        {
            if (IngredientIcon)
            {
                IngredientIcon->SetBrushFromTexture(ItemTemplateCDO->IconTexture, true);
                IngredientIcon->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
            }

            if (IngredientName_Text)
            {
                IngredientName_Text->SetText(ItemTemplateCDO->DisplayName);
            }
        }
    }
    else
    {
        if (IngredientIcon)
        {
            IngredientIcon->SetVisibility(ESlateVisibility::Collapsed);
        }
        if (IngredientName_Text)
        {
            IngredientName_Text->SetText(FText::FromName(IngredientTag.GetTagName()));
        }
    }

    if (Quantity_Text)
    {
        FString QuantityString = FString::Printf(TEXT("%d / %d"), InOwned, InRequired);
        Quantity_Text->SetText(FText::FromString(QuantityString));

        const FLinearColor ColorToSet = (InOwned >= InRequired) ? FLinearColor::White : FLinearColor::Red;
        Quantity_Text->SetColorAndOpacity(FSlateColor(ColorToSet));
    }
}