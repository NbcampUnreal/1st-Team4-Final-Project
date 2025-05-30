#include "UI/Crafting/CraftingOutputBoxWidget.h"
#include "Item/ItemInstance.h"
#include "Item/ItemTemplate.h"
#include "Net/UnrealNetwork.h"

const UItemTemplate* UCraftingOutputBoxWidget::GetTemplateFromInstance(UItemInstance* Instance) const
{
    if (Instance)
    {
        UE_LOG(LogTemp, Warning, TEXT("GetTemplateFromInstance: Needs proper implementation to fetch UItemTemplate from UItemInstance."));
    }
    return nullptr; 
}


UCraftingOutputBoxWidget::UCraftingOutputBoxWidget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    MaxOutputSlots = 5;
}

void UCraftingOutputBoxWidget::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(UCraftingOutputBoxWidget, OutputSlotEntries);
}

bool UCraftingOutputBoxWidget::TryAddItem(UItemInstance* ItemInstanceToAdd)
{
    if (!ItemInstanceToAdd) return false;

    const UItemTemplate* TemplateOfItemToAdd = GetTemplateFromInstance(ItemInstanceToAdd);
    if (!TemplateOfItemToAdd)
    {
        UE_LOG(LogTemp, Warning, TEXT("TryAddItem: Could not get ItemTemplate for item being added. Stacking might not work correctly. Defaulting to MaxStackCount of 1."));
    }
    
    int32 MaxStackSize = TemplateOfItemToAdd ? (TemplateOfItemToAdd->MaxStackCount > 0 ? TemplateOfItemToAdd->MaxStackCount : 1) : 1;

    for (int32 i = 0; i < OutputSlotEntries.Num(); ++i)
    {
        FCraftingOutputSlotEntry& SlotEntry = OutputSlotEntries[i];
        if (SlotEntry.ItemInstance &&
            SlotEntry.ItemInstance->GetItemTemplateID() == ItemInstanceToAdd->GetItemTemplateID() &&
            SlotEntry.ItemInstance->GetItemRarity() == ItemInstanceToAdd->GetItemRarity() && 
            SlotEntry.Quantity < MaxStackSize)
        {
            SlotEntry.Quantity++;
            UE_LOG(LogTemp, Log, TEXT("CraftingOutputBoxWidget: Item stacked in slot %d. New quantity: %d"), i, SlotEntry.Quantity);
            OnContentsChanged.Broadcast();
            K2_UpdateOutputBoxUI();
            return true;
        }
    }

    if (OutputSlotEntries.Num() < MaxOutputSlots)
    {
        FCraftingOutputSlotEntry NewSlotEntry;
        NewSlotEntry.ItemInstance = ItemInstanceToAdd;
        NewSlotEntry.Quantity = 1;
        OutputSlotEntries.Add(NewSlotEntry);
        UE_LOG(LogTemp, Log, TEXT("CraftingOutputBoxWidget: Item added to new slot. Total slots used: %d"), OutputSlotEntries.Num());
        OnContentsChanged.Broadcast();
        K2_UpdateOutputBoxUI();
        return true;
    }

    UE_LOG(LogTemp, Warning, TEXT("CraftingOutputBoxWidget: Output box is full and no existing stack available. Cannot add item."));
    return false;
}

UItemInstance* UCraftingOutputBoxWidget::RemoveItemFromSlot(int32 SlotIndex)
{
    if (OutputSlotEntries.IsValidIndex(SlotIndex))
    {
        UItemInstance* ItemToReturn = nullptr;
        FCraftingOutputSlotEntry& SlotEntry = OutputSlotEntries[SlotIndex];

        if (SlotEntry.ItemInstance && SlotEntry.Quantity > 0)
        {
            ItemToReturn = SlotEntry.ItemInstance;
            SlotEntry.Quantity--;

            if (SlotEntry.Quantity <= 0)
            {
                OutputSlotEntries.RemoveAt(SlotIndex); 
            }
            UE_LOG(LogTemp, Log, TEXT("CraftingOutputBoxWidget: Item (or part of stack) removed from slot %d. Remaining quantity in slot: %d"), SlotIndex, SlotEntry.Quantity);
        }
        else if(SlotEntry.Quantity <= 0) 
        {
             OutputSlotEntries.RemoveAt(SlotIndex);
        }
        
        OnContentsChanged.Broadcast();
        K2_UpdateOutputBoxUI();
        return ItemToReturn;
    }
    return nullptr;
}

bool UCraftingOutputBoxWidget::IsFull() const
{
    if (OutputSlotEntries.Num() < MaxOutputSlots) return false;

    const UItemTemplate* LastAttemptedTemplate = nullptr; 
    EItemRarity LastAttemptedRarity = EItemRarity::Common;
    if (OutputSlotEntries.Num() > 0 && OutputSlotEntries.Last().ItemInstance) {
    }


    for (const FCraftingOutputSlotEntry& SlotEntry : OutputSlotEntries)
    {
        if (SlotEntry.ItemInstance)
        {
            const UItemTemplate* Template = GetTemplateFromInstance(SlotEntry.ItemInstance);
            int32 MaxStack = Template ? (Template->MaxStackCount > 0 ? Template->MaxStackCount : 1) : 1;
            if (SlotEntry.Quantity < MaxStack)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return OutputSlotEntries.Num() >= MaxOutputSlots;
}

int32 UCraftingOutputBoxWidget::GetMaxSlots() const
{
    return MaxOutputSlots;
}

const TArray<FCraftingOutputSlotEntry>& UCraftingOutputBoxWidget::GetOutputSlotEntries() const
{
    return OutputSlotEntries;
}

void UCraftingOutputBoxWidget::OnRep_OutputSlotEntries()
{
    K2_UpdateOutputBoxUI();
}