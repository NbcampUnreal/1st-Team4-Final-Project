#include "UI/Crafting/CraftingOutputBoxWidget.h"
#include "UI/Crafting/CraftedItemSlotEntryWidget.h"
#include "Item/ItemInstance.h"
#include "Item/ItemTemplate.h"
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"
#include "Components/TextBlock.h"      

UCraftingOutputBoxWidget::UCraftingOutputBoxWidget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    NumRows = 1;
    NumColumns = 5; 
    CraftedItemSlotEntryClass = nullptr;
    OutputSlotsGridPanel = nullptr;
    TitleTextWidget = nullptr;
}

void UCraftingOutputBoxWidget::NativeConstruct()
{
    Super::NativeConstruct();
    RefreshSlotsUI();
}

const UItemTemplate* UCraftingOutputBoxWidget::GetTemplateFromClass(TSubclassOf<UItemTemplate> InClass) const
{
    if (InClass)
    {
        return InClass->GetDefaultObject<UItemTemplate>();
    }
    return nullptr;
}

void UCraftingOutputBoxWidget::RefreshSlotsUI()
{
    if (!OutputSlotsGridPanel)
    {
        UE_LOG(LogTemp, Warning, TEXT("UCraftingOutputBoxWidget::RefreshSlotsUI - OutputSlotsGridPanel is NULL. Check UMG binding."));
        return;
    }
    if (!CraftedItemSlotEntryClass)
    {
        UE_LOG(LogTemp, Warning, TEXT("UCraftingOutputBoxWidget::RefreshSlotsUI - SlotEntryWidgetClass is not set in ClassDefaults."));
        return;
    }

    OutputSlotsGridPanel->ClearChildren();
    
    const int32 CurrentMaxSlots = GetMaxSlots();
    
    OutputSlotEntries.SetNum(CurrentMaxSlots);

    UE_LOG(LogTemp, Log, TEXT("UCraftingOutputBoxWidget::RefreshSlotsUI - Array size is now %d. Populating grid..."), OutputSlotEntries.Num());

    for (int32 i = 0; i < OutputSlotEntries.Num(); ++i)
    {
        UCraftedItemSlotEntryWidget* EntryWidget = CreateWidget<UCraftedItemSlotEntryWidget>(this, CraftedItemSlotEntryClass);
        if (EntryWidget)
        {
            const FCraftingOutputSlotEntry& SlotEntry = OutputSlotEntries[i];
            EntryWidget->SetSlotData(SlotEntry.ItemTemplateClass, SlotEntry.Rarity, SlotEntry.Quantity);
            
            const int32 TargetRow = i / NumColumns;
            const int32 TargetColumn = i % NumColumns;
            UUniformGridSlot* GridSlot = OutputSlotsGridPanel->AddChildToUniformGrid(EntryWidget, TargetRow, TargetColumn);
            if(GridSlot)
            {
                GridSlot->SetHorizontalAlignment(HAlign_Fill); 
                GridSlot->SetVerticalAlignment(VAlign_Fill); 
            }
        }
    }
    OnContentsChanged.Broadcast(); 
}

bool UCraftingOutputBoxWidget::TryAddItem(TSubclassOf<UItemTemplate> InItemTemplateClass, EItemRarity InRarity, int32 InQuantity)
{
    if (!InItemTemplateClass || InQuantity <= 0) return false;

    const UItemTemplate* TemplateOfItemToAdd = InItemTemplateClass->GetDefaultObject<UItemTemplate>();
    if(!TemplateOfItemToAdd) return false;
    
    const int32 MaxStackSize = TemplateOfItemToAdd->MaxStackCount > 0 ? TemplateOfItemToAdd->MaxStackCount : 1;
    
    int32 RemainingQuantity = InQuantity;

    UE_LOG(LogTemp, Log, TEXT("TryAddItem: Attempting to add %s. Checking %d slots."), *InItemTemplateClass->GetName(), OutputSlotEntries.Num());

    if (MaxStackSize > 1)
    {
        for (int32 i = 0; i < OutputSlotEntries.Num(); ++i)
        {
            FCraftingOutputSlotEntry& SlotEntry = OutputSlotEntries[i];
            if (SlotEntry.ItemTemplateClass == InItemTemplateClass && SlotEntry.Rarity == InRarity && SlotEntry.Quantity < MaxStackSize)
            {
                int32 CanAddAmount = FMath::Min(RemainingQuantity, MaxStackSize - SlotEntry.Quantity);
                SlotEntry.Quantity += CanAddAmount;
                RemainingQuantity -= CanAddAmount;
                if (RemainingQuantity <= 0) break;
            }
        }
    }
    
    if (RemainingQuantity > 0)
    {
        for (int32 i = 0; i < OutputSlotEntries.Num(); ++i)
        {
            FCraftingOutputSlotEntry& SlotEntry = OutputSlotEntries[i];

            UE_LOG(LogTemp, Log, TEXT("TryAddItem: Checking Slot [%d]. ItemTemplateClass: %s, Quantity: %d."), 
                i, 
                SlotEntry.ItemTemplateClass ? *SlotEntry.ItemTemplateClass->GetName() : TEXT("NULL"), 
                SlotEntry.Quantity);
            
            if (SlotEntry.ItemTemplateClass == nullptr || SlotEntry.Quantity == 0)
            {
                UE_LOG(LogTemp, Warning, TEXT("TryAddItem: Found an empty slot at index %d! Placing item."), i);
                SlotEntry.ItemTemplateClass = InItemTemplateClass;
                SlotEntry.Rarity = InRarity;
                
                int32 CanAddAmount = FMath::Min(RemainingQuantity, MaxStackSize);
                SlotEntry.Quantity = CanAddAmount;
                RemainingQuantity -= CanAddAmount;

                if (RemainingQuantity <= 0) break;
            }
        }
    }

    RefreshSlotsUI();
    
    if (RemainingQuantity > 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("CraftingOutputBoxWidget: Output box is full. Could not add all items (%d remaining)."), RemainingQuantity);
        return false;
    }

    UE_LOG(LogTemp, Log, TEXT("TryAddItem: Successfully added item(s)."));
    return true;
}

TSubclassOf<UItemTemplate> UCraftingOutputBoxWidget::GetItemTemplateClassFromSlot(int32 FlatSlotIndex, EItemRarity& OutRarity, int32& OutQuantity)
{
    OutRarity = EItemRarity::Common;
    OutQuantity = 0;

    if (OutputSlotEntries.IsValidIndex(FlatSlotIndex))
    {
        const FCraftingOutputSlotEntry& SlotEntry = OutputSlotEntries[FlatSlotIndex];
        OutRarity = SlotEntry.Rarity;
        OutQuantity = SlotEntry.Quantity;
        return SlotEntry.ItemTemplateClass;
    }
    return nullptr;
}

void UCraftingOutputBoxWidget::ClearSlot(int32 FlatSlotIndex)
{
    if (OutputSlotEntries.IsValidIndex(FlatSlotIndex))
    {
        OutputSlotEntries[FlatSlotIndex] = FCraftingOutputSlotEntry();
        RefreshSlotsUI();
    }
}

bool UCraftingOutputBoxWidget::IsFull() const
{
    for (const FCraftingOutputSlotEntry& SlotEntry : OutputSlotEntries)
    {
        if (!SlotEntry.ItemTemplateClass) return false; 
        
        const UItemTemplate* Template = GetTemplateFromClass(SlotEntry.ItemTemplateClass);
        if (!Template) continue;
        
        const int32 MaxStack = Template->MaxStackCount > 0 ? Template->MaxStackCount : 1;
        if (SlotEntry.Quantity < MaxStack)
        {
            return false;
        }
    }
    return true; 
}

int32 UCraftingOutputBoxWidget::GetMaxSlots() const
{
    return NumRows * NumColumns;
}

void UCraftingOutputBoxWidget::SetGridDimensions(int32 InNumRows, int32 InNumColumns)
{
    NumRows = FMath::Max(1, InNumRows);
    NumColumns = FMath::Max(1, InNumColumns);
    RefreshSlotsUI();
}