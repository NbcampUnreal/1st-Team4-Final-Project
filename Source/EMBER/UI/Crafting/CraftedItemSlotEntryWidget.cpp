#include "UI/Crafting/CraftedItemSlotEntryWidget.h"
#include "Components/SizeBox.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Item/ItemInstance.h"
#include "Item/ItemTemplate.h"
#include "Crafting/CraftingSystem.h"
#include "Player/EmberPlayerCharacter.h"
#include "UI/Data/EmberItemData.h"
#include "UI/Data/EmberUIData.h"


UCraftedItemSlotEntryWidget::UCraftedItemSlotEntryWidget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    CachedItemInstance = nullptr;
    CachedQuantity = 0;
    SizeBox_Root = nullptr; 
    ItemIcon = nullptr;
    QuantityText = nullptr;
}

UCraftingSystem* UCraftedItemSlotEntryWidget::GetCraftingSystem() const
{
    APlayerController* PC = GetOwningPlayer();
    if (PC)
    {
        AEmberPlayerCharacter* PlayerCharacter = Cast<AEmberPlayerCharacter>(PC->GetPawn());
        if (PlayerCharacter)
        {
            return PlayerCharacter->FindComponentByClass<UCraftingSystem>();
        }
    }
    return nullptr;
}

const UItemTemplate* UCraftedItemSlotEntryWidget::GetItemTemplate() const
{
    if (CachedItemInstance)
    {
        const int32 TemplateID = CachedItemInstance->GetItemTemplateID();
        if (TemplateID != INDEX_NONE)
        {
            UE_LOG(LogTemp, Warning, TEXT("UCraftedItemSlotEntryWidget::GetItemTemplate - Returning nullptr for TemplateID %d. UEmberItemData::Get().FindItemTemplateByID() must be fixed to return 'const UItemTemplate*' to resolve C2440 and enable proper functionality."), TemplateID);
        }
    }
    return nullptr;
}

void UCraftedItemSlotEntryWidget::SetSlotData(UItemInstance* InItemInstance, int32 InQuantity)
{
    CachedItemInstance = InItemInstance;
    CachedQuantity = InQuantity;

    const UItemTemplate* Template = GetItemTemplate();
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
    UpdateWidgetAppearance();
}

void UCraftedItemSlotEntryWidget::UpdateWidgetAppearance()
{
    if (ItemIcon)
    {
        ItemIcon->SetVisibility((CachedItemInstance && CachedQuantity > 0) ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed);
    }

    if (QuantityText)
    {
        if (CachedItemInstance && CachedQuantity > 0)
        {
            const UItemTemplate* Template = GetItemTemplate();
            int32 MaxStack = Template ? (Template->MaxStackCount > 0 ? Template->MaxStackCount : 1) : 1;

            if (CachedQuantity > 1 && MaxStack > 1) 
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