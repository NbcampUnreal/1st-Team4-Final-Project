#include "UI/Crafting/CraftingOutputBoxWidget.h"
#include "Item/Managers/InventoryManagerComponent.h"
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"
#include "Components/TextBlock.h"
#include "UI/Crafting/CraftedItemSlotEntryWidget.h"
#include "Item/ItemInstance.h"
#include "Item/ItemTemplate.h"      
#include "UI/Data/EmberItemData.h" 

UCraftingOutputBoxWidget::UCraftingOutputBoxWidget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    DataSourceInventoryManager = nullptr;
    OutputSlotsGridPanel = nullptr;
    SlotEntryWidgetClass = nullptr;
    TitleTextWidget = nullptr;
}

void UCraftingOutputBoxWidget::NativeConstruct()
{
    Super::NativeConstruct();
    UE_LOG(LogTemp, Log, TEXT("UCraftingOutputBoxWidget::NativeConstruct for %s - Calling RefreshDisplay."), *GetName());
    RefreshDisplay(); 
}

void UCraftingOutputBoxWidget::NativeDestruct()
{
    if (DataSourceInventoryManager)
    {
        if (DataSourceInventoryManager->OnInventoryEntryChanged.IsBoundToObject(this))
        {
            DataSourceInventoryManager->OnInventoryEntryChanged.RemoveAll(this);
            UE_LOG(LogTemp, Log, TEXT("UCraftingOutputBoxWidget::NativeDestruct - Unbound OnInventoryEntryChanged from DataSource: %s"), *DataSourceInventoryManager->GetName());
        }
    }
    Super::NativeDestruct();
}

void UCraftingOutputBoxWidget::InitializeDataSource(UInventoryManagerComponent* TargetInventoryManager)
{
    UE_LOG(LogTemp, Warning, TEXT("UCraftingOutputBoxWidget::InitializeDataSource for %s - Called. Current DataSource: %s, New Target: %s"),
        *GetName(),
        DataSourceInventoryManager ? *DataSourceInventoryManager->GetName() : TEXT("NULL"),
        TargetInventoryManager ? *TargetInventoryManager->GetName() : TEXT("NULL") );

    if (DataSourceInventoryManager && DataSourceInventoryManager->OnInventoryEntryChanged.IsBoundToObject(this))
    {
        DataSourceInventoryManager->OnInventoryEntryChanged.RemoveAll(this);
        UE_LOG(LogTemp, Log, TEXT("UCraftingOutputBoxWidget::InitializeDataSource - Unbound OnInventoryEntryChanged from old DataSource."));
    }

    DataSourceInventoryManager = TargetInventoryManager;

    if (DataSourceInventoryManager)
    {
        DataSourceInventoryManager->OnInventoryEntryChanged.AddUObject(this, &UCraftingOutputBoxWidget::OnOutputInventoryChanged);
        UE_LOG(LogTemp, Log, TEXT("UCraftingOutputBoxWidget::InitializeDataSource - Bound OnInventoryEntryChanged to new DataSource: %s (Owner: %s). Widget: %s"), 
            *DataSourceInventoryManager->GetName(),
            DataSourceInventoryManager->GetOwner() ? *DataSourceInventoryManager->GetOwner()->GetName() : TEXT("NULL_OWNER"),
            *GetName());
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("UCraftingOutputBoxWidget::InitializeDataSource - Initialized with NULL TargetInventoryManager."));
    }
    RefreshDisplay();
}

void UCraftingOutputBoxWidget::OnOutputInventoryChanged(const FIntPoint& ItemSlotPos, UItemInstance* ItemInstance, int32 ItemCount)
{
    UE_LOG(LogTemp, Warning, TEXT(">>>> UCraftingOutputBoxWidget::OnOutputInventoryChanged for %s - FIRED! SlotPos: (X=%d, Y=%d), Item: %s, Count: %d. Refreshing display. <<<<"), 
        *GetName(),
        ItemSlotPos.X, ItemSlotPos.Y, 
        ItemInstance ? *ItemInstance->GetName() : TEXT("NULL_ItemInstance"), 
        ItemCount);
    RefreshDisplay();
}

void UCraftingOutputBoxWidget::RefreshDisplay()
{
    if (!OutputSlotsGridPanel)
    {
        UE_LOG(LogTemp, Warning, TEXT("UCraftingOutputBoxWidget::RefreshDisplay for %s - OutputSlotsGridPanel is NULL. Check UMG binding."), *GetName());
        return;
    }
    OutputSlotsGridPanel->ClearChildren();

    if (!DataSourceInventoryManager)
    {
        UE_LOG(LogTemp, Log, TEXT("UCraftingOutputBoxWidget::RefreshDisplay for %s - DataSourceInventoryManager is NULL. Displaying empty."), *GetName());
        return;
    }
    if (!SlotEntryWidgetClass)
    {
        UE_LOG(LogTemp, Warning, TEXT("UCraftingOutputBoxWidget::RefreshDisplay for %s - SlotEntryWidgetClass is not set in ClassDefaults."), *GetName());
        return;
    }

    const FIntPoint GridDimensions = DataSourceInventoryManager->GetInventorySlotCount(); 
    const TArray<FInventoryEntry>& AllEntries = DataSourceInventoryManager->GetAllEntries();

    UE_LOG(LogTemp, Log, TEXT("UCraftingOutputBoxWidget::RefreshDisplay for %s - Preparing to display %d entries in a %dx%d grid. DataSource: %s (Owner: %s)"), 
        *GetName(),
        AllEntries.Num(), GridDimensions.X, GridDimensions.Y, 
        *DataSourceInventoryManager->GetName(),
        DataSourceInventoryManager->GetOwner() ? *DataSourceInventoryManager->GetOwner()->GetName() : TEXT("NULL_OWNER"));

    for (int32 Y = 0; Y < GridDimensions.Y; ++Y)
    {
        for (int32 X = 0; X < GridDimensions.X; ++X)
        {
            int32 CurrentFlatIndex = Y * GridDimensions.X + X;
            UCraftedItemSlotEntryWidget* SlotWidgetInstance = CreateWidget<UCraftedItemSlotEntryWidget>(this, SlotEntryWidgetClass);
            if (SlotWidgetInstance)
            {
                if (AllEntries.IsValidIndex(CurrentFlatIndex))
                {
                    const FInventoryEntry& Entry = AllEntries[CurrentFlatIndex];
                    SlotWidgetInstance->SetSlotData(Entry.GetItemInstance(), Entry.GetItemCount());
                    if (Entry.GetItemInstance())
                    {
                         UE_LOG(LogTemp, Verbose, TEXT("UCraftingOutputBoxWidget: Slot (%d,%d) Data: Item Valid, Count: %d"), X, Y, Entry.GetItemCount());
                    }
                }
                else 
                {
                    SlotWidgetInstance->SetSlotData(nullptr, 0);
                }
                UUniformGridSlot* GridSlot = OutputSlotsGridPanel->AddChildToUniformGrid(SlotWidgetInstance, Y, X);
                if(GridSlot)
                {
                    GridSlot->SetHorizontalAlignment(HAlign_Fill); 
                    GridSlot->SetVerticalAlignment(VAlign_Fill);
                }
            }
            else
            {
                UE_LOG(LogTemp, Error, TEXT("UCraftingOutputBoxWidget::RefreshDisplay - Failed to create SlotEntryWidgetClass instance."));
            }
        }
    }
    UE_LOG(LogTemp, Log, TEXT("UCraftingOutputBoxWidget::RefreshDisplay for %s - Finished loop. OutputSlotsGridPanel now has %d children."), *GetName(), OutputSlotsGridPanel->GetChildrenCount());
}