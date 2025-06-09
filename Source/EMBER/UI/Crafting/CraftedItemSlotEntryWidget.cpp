#include "UI/Crafting/CraftedItemSlotEntryWidget.h"
#include "Components/SizeBox.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Item/ItemInstance.h"
#include "Item/ItemTemplate.h"
#include "UI/Data/EmberUIData.h"


UCraftedItemSlotEntryWidget::UCraftedItemSlotEntryWidget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    CachedItemTemplateClass = nullptr;
    CachedRarity = EItemRarity::Common;
    CachedQuantity = 0;
    SizeBox_Root = nullptr; 
    ItemIcon = nullptr;
    QuantityText = nullptr;
}

void UCraftedItemSlotEntryWidget::SetSlotData(TSubclassOf<UItemTemplate> InItemTemplateClass, EItemRarity InRarity, int32 InQuantity)
{
    CachedItemTemplateClass = InItemTemplateClass;
    CachedRarity = InRarity;
    CachedQuantity = InQuantity;
    
    UpdateWidgetAppearance();
}

const UItemTemplate* UCraftedItemSlotEntryWidget::GetItemTemplate() const
{
    if (CachedItemTemplateClass)
    {
        return CachedItemTemplateClass->GetDefaultObject<UItemTemplate>();
    }
    return nullptr;
}

void UCraftedItemSlotEntryWidget::UpdateWidgetAppearance()
{
    const UItemTemplate* Template = GetItemTemplate();
    
    const bool bHasItem = (Template != nullptr && CachedQuantity > 0);

    if (SizeBox_Root)
    {
        FIntPoint UnitInventorySlotSize = UEmberUIData::Get().UnitInventorySlotSize; 
        float TargetSizeX = static_cast<float>(UnitInventorySlotSize.X);
        float TargetSizeY = static_cast<float>(UnitInventorySlotSize.Y);

        if (Template && Template->SlotCount.X > 0 && Template->SlotCount.Y > 0)
        {
            TargetSizeX = Template->SlotCount.X * UnitInventorySlotSize.X;
            TargetSizeY = Template->SlotCount.Y * UnitInventorySlotSize.Y;
        }
        SizeBox_Root->SetWidthOverride(TargetSizeX);
        SizeBox_Root->SetHeightOverride(TargetSizeY);
    }
    
    if (ItemIcon)
    {
        ItemIcon->SetVisibility(bHasItem ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed);

        ItemIcon->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));
    }
    
    if (QuantityText)
    {
        if (bHasItem)
        {
            const int32 MaxStack = Template->MaxStackCount > 0 ? Template->MaxStackCount : 1;
            if (CachedQuantity > 1 || MaxStack > 1) 
            {
                 QuantityText->SetText(FText::AsNumber(CachedQuantity));
                 QuantityText->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
            }
            else 
            {
                QuantityText->SetVisibility(ESlateVisibility::Collapsed);
            }
        }
        else
        {
            QuantityText->SetText(FText::GetEmpty());
            QuantityText->SetVisibility(ESlateVisibility::Collapsed);
        }
    }
    
    K2_OnDisplayDataUpdated();
}