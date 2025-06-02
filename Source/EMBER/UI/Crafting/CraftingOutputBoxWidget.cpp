#include "UI/Crafting/CraftingOutputBoxWidget.h"
#include "UI/Crafting/CraftedItemSlotEntryWidget.h"
#include "Item/ItemInstance.h"
#include "Item/ItemTemplate.h"
#include "Player/EmberPlayerCharacter.h" 
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"
#include "Components/TextBlock.h"      
#include "Net/UnrealNetwork.h"
#include "UI/Data/EmberItemData.h"


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
    RefreshSlotsUI_Internal();
}

const UItemTemplate* UCraftingOutputBoxWidget::GetTemplateFromInstance(UItemInstance* Instance) const
{
    if (Instance)
    {
        const int32 TemplateID = Instance->GetItemTemplateID();
        if (TemplateID != INDEX_NONE)
        {
            UE_LOG(LogTemp, Warning, TEXT("UCraftingOutputBoxWidget::GetTemplateFromInstance - Returning nullptr for TemplateID %d. UEmberItemData::Get().FindItemTemplateByID() must be fixed to return 'const UItemTemplate*' to enable proper functionality."), TemplateID);
        }
    }
    return nullptr;
}

void UCraftingOutputBoxWidget::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(UCraftingOutputBoxWidget, OutputSlotEntries);
}

void UCraftingOutputBoxWidget::RefreshSlotsUI_Internal()
{
    if (!OutputSlotsGridPanel)
    {
        UE_LOG(LogTemp, Warning, TEXT("UCraftingOutputBoxWidget::RefreshSlotsUI_Internal - OutputSlotsGridPanel is NULL."));
        return;
    }
    if (!CraftedItemSlotEntryClass)
    {
        UE_LOG(LogTemp, Warning, TEXT("UCraftingOutputBoxWidget::RefreshSlotsUI_Internal - CraftedItemSlotEntryClass is not set."));
        return;
    }

    OutputSlotsGridPanel->ClearChildren();
    int32 CurrentMaxSlots = GetMaxSlots();
    
    OutputSlotEntries.SetNum(CurrentMaxSlots);

    for (int32 i = 0; i < CurrentMaxSlots; ++i)
    {
        UCraftedItemSlotEntryWidget* EntryWidget = CreateWidget<UCraftedItemSlotEntryWidget>(this, CraftedItemSlotEntryClass);
        if (EntryWidget)
        {
            const FCraftingOutputSlotEntry& SlotEntry = OutputSlotEntries[i];
            EntryWidget->SetSlotData(SlotEntry.ItemInstance, SlotEntry.Quantity);
            
            int32 TargetRow = i / NumColumns;
            int32 TargetColumn = i % NumColumns;
            UUniformGridSlot* GridSlot = OutputSlotsGridPanel->AddChildToUniformGrid(EntryWidget, TargetRow, TargetColumn);
            if(GridSlot)
            {
                GridSlot->SetHorizontalAlignment(HAlign_Center); 
                GridSlot->SetVerticalAlignment(VAlign_Center); 
            }
        }
    }
    OnContentsChanged.Broadcast(); 
}


bool UCraftingOutputBoxWidget::TryAddItem(UItemInstance* ItemInstanceToAdd)
{
    if (!ItemInstanceToAdd) 
    {
        UE_LOG(LogTemp, Warning, TEXT("UCraftingOutputBoxWidget::TryAddItem - ItemInstanceToAdd is NULL."));
        return false;
    }

    const UItemTemplate* TemplateOfItemToAdd = GetTemplateFromInstance(ItemInstanceToAdd);
    int32 MaxStackSize = TemplateOfItemToAdd ? (TemplateOfItemToAdd->MaxStackCount > 0 ? TemplateOfItemToAdd->MaxStackCount : 1) : 1;
    
    bool bItemPlaced = false;
    for (int32 i = 0; i < OutputSlotEntries.Num(); ++i)
    {
        FCraftingOutputSlotEntry& SlotEntry = OutputSlotEntries[i];
        if (SlotEntry.ItemInstance &&
            SlotEntry.ItemInstance->GetItemTemplateID() == ItemInstanceToAdd->GetItemTemplateID() &&
            SlotEntry.ItemInstance->GetItemRarity() == ItemInstanceToAdd->GetItemRarity() && 
            SlotEntry.Quantity < MaxStackSize)
        {
            SlotEntry.Quantity++;
            bItemPlaced = true;
            if (ItemInstanceToAdd->IsValidLowLevel()) ItemInstanceToAdd->MarkAsGarbage();
            break; 
        }
    }

    if (!bItemPlaced)
    {
        int32 EmptySlotIndex = -1;
        for (int32 i = 0; i < OutputSlotEntries.Num(); ++i)
        {
            if (OutputSlotEntries[i].ItemInstance == nullptr || OutputSlotEntries[i].Quantity == 0)
            {
                EmptySlotIndex = i;
                break;
            }
        }

        if (EmptySlotIndex != -1)
        {
            OutputSlotEntries[EmptySlotIndex].ItemInstance = ItemInstanceToAdd;
            OutputSlotEntries[EmptySlotIndex].Quantity = 1;
            bItemPlaced = true;
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("CraftingOutputBoxWidget: Output box is full (no empty or stackable slots). Cannot add new item."));
            if (ItemInstanceToAdd->IsValidLowLevel()) ItemInstanceToAdd->MarkAsGarbage();
            RefreshSlotsUI_Internal(); 
            return false;
        }
    }
    
    if(bItemPlaced) RefreshSlotsUI_Internal();
    return bItemPlaced;
}

UItemInstance* UCraftingOutputBoxWidget::RemoveItemFromSlot(int32 FlatSlotIndex)
{
    UItemInstance* ItemToReturn = nullptr;
    if (OutputSlotEntries.IsValidIndex(FlatSlotIndex))
    {
        FCraftingOutputSlotEntry& SlotEntry = OutputSlotEntries[FlatSlotIndex];

        if (SlotEntry.ItemInstance && SlotEntry.Quantity > 0)
        {
            ItemToReturn = SlotEntry.ItemInstance; 
            SlotEntry.Quantity--;

            if (SlotEntry.Quantity <= 0)
            {
                SlotEntry.ItemInstance = nullptr; 
            }
        }
        else 
        {
            SlotEntry.ItemInstance = nullptr; 
            SlotEntry.Quantity = 0;
        }
        RefreshSlotsUI_Internal();
    }
    return ItemToReturn; 
}

bool UCraftingOutputBoxWidget::IsFull() const
{
    for (const FCraftingOutputSlotEntry& SlotEntry : OutputSlotEntries)
    {
        if (!SlotEntry.ItemInstance) return false; 

        const UItemTemplate* Template = GetTemplateFromInstance(SlotEntry.ItemInstance);
        int32 MaxStack = Template ? (Template->MaxStackCount > 0 ? Template->MaxStackCount : 1) : 1;
        if (SlotEntry.Quantity < MaxStack)
        {
            return false;
        }
    }
    return OutputSlotEntries.Num() >= GetMaxSlots();
}

int32 UCraftingOutputBoxWidget::GetMaxSlots() const
{
    return NumRows * NumColumns;
}

const TArray<FCraftingOutputSlotEntry>& UCraftingOutputBoxWidget::GetOutputSlotEntries() const
{
    return OutputSlotEntries;
}

void UCraftingOutputBoxWidget::OnRep_OutputSlotEntries()
{
    RefreshSlotsUI_Internal();
}

void UCraftingOutputBoxWidget::SetGridDimensions(int32 InNumRows, int32 InNumColumns)
{
    NumRows = FMath::Max(1, InNumRows);
    NumColumns = FMath::Max(1, InNumColumns);
    
    int32 NewMaxSlots = GetMaxSlots();
    if (OutputSlotEntries.Num() > NewMaxSlots)
    {
        UE_LOG(LogTemp, Warning, TEXT("UCraftingOutputBoxWidget::SetGridDimensions - Slot count reduced, excess items might be lost if not handled."));
        OutputSlotEntries.SetNum(NewMaxSlots);
    }
    else if (OutputSlotEntries.Num() < NewMaxSlots)
    {
        OutputSlotEntries.SetNum(NewMaxSlots);
    }

    RefreshSlotsUI_Internal();
}