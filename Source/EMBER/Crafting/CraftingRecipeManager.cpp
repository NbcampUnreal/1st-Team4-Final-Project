#include "Crafting/CraftingRecipeManager.h"
#include "Item/ItemTemplate.h"
#include "UI/Data/EmberItemData.h"

const FCraftingRecipeRow* UCraftingRecipeManager::GetRecipeRowByOutputItemID(int32 TemplateID) const
{
    if (!RecipeDataTable || TemplateID == INDEX_NONE)
    {
        return nullptr;
    }

    TArray<FName> RowNames = RecipeDataTable->GetRowNames();
    for (const FName& RowName : RowNames)
    {
        FCraftingRecipeRow* Row = RecipeDataTable->FindRow<FCraftingRecipeRow>(RowName, TEXT(""));
        if (Row && Row->ItemTemplateClass)
        {
            int32 OutputIDFromClass = UEmberItemData::Get().FindItemTemplateIDByClass(Row->ItemTemplateClass);
            if (OutputIDFromClass != INDEX_NONE && OutputIDFromClass == TemplateID)
            {
                return Row;
            }
        }
    }
    return nullptr;
}

void UCraftingRecipeManager::GetAllRecipeRows(TArray<FCraftingRecipeRow*>& OutRows) const
{
    OutRows.Empty();
    if (!RecipeDataTable)
    {
        return;
    }
    
    FString ContextString; 
    RecipeDataTable->GetAllRows(ContextString, OutRows);
}

FGameplayTag UCraftingRecipeManager::GetMaterialTagForItem(int32 ItemTemplateID) const
{
    const FGameplayTag* FoundTag = ItemIDToMaterialTagMap.Find(ItemTemplateID);
    if (FoundTag)
    {
        return *FoundTag;
    }
    return FGameplayTag::EmptyTag;
}