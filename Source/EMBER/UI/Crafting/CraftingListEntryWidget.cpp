#include "UI/Crafting/CraftingListEntryWidget.h"
#include "Item/ItemTemplate.h" 
#include "Components/TextBlock.h"
#include "Components/Border.h"
#include "Components/Image.h"
#include "UI/Crafting/CraftingRecipeListItemData.h" 
#include "Crafting/CraftingRecipeManager.h" 
#include "Crafting/CraftingSystem.h" 
#include "Player/EmberPlayerCharacter.h" 
#include "UI/Data/EmberItemData.h"
#include "Engine/Texture2D.h"

UCraftingListEntryWidget::UCraftingListEntryWidget(const FObjectInitializer& ObjectInitializer) 
    : Super(ObjectInitializer)
{
    CurrentListItemDataInternal = nullptr;
    SelectionHighlightBorder = nullptr;
    RecipeNameText = nullptr;
    RecipeIcon = nullptr;
}

void UCraftingListEntryWidget::NativeConstruct()
{
    Super::NativeConstruct();
}

void UCraftingListEntryWidget::SetCurrentListItemData(UCraftingRecipeListItemData* InData)
{
    CurrentListItemDataInternal = InData;
}

bool UCraftingListEntryWidget::CalculateCraftableStatusInternal(UCraftingRecipeListItemData* InListItemData) const
{
    if (!InListItemData) return false;

    AEmberPlayerCharacter* Player = Cast<AEmberPlayerCharacter>(GetOwningPlayerPawn());
    UCraftingSystem* CraftingSystem = Player ? Player->FindComponentByClass<UCraftingSystem>() : nullptr;
    
    if (CraftingSystem && Player)
    {
       TMap<FGameplayTag, int32> EmptySelectedMainIngredients;
       return CraftingSystem->HasRequiredMaterials(Player, InListItemData->RecipeData, EmptySelectedMainIngredients);
    }
    return false;
}

UTexture2D* UCraftingListEntryWidget::GetIconTextureFromRecipeDataInternal(UCraftingRecipeListItemData* InListItemData) const
{
    if (InListItemData && InListItemData->RecipeData.ItemTemplateClass)
    {
        const UItemTemplate* ItemTemplateCDO = InListItemData->RecipeData.ItemTemplateClass->GetDefaultObject<UItemTemplate>();
        if (ItemTemplateCDO)
        {
            return ItemTemplateCDO->IconTexture;
        }
    }
    return nullptr;
}

void UCraftingListEntryWidget::HandleClick()
{
    if (CurrentListItemDataInternal) 
    {
       OnThisEntryClicked.Broadcast(CurrentListItemDataInternal);
    }
}