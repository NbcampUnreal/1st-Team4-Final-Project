#include "UI/Crafting/CraftingOutputBoxWidget.h"
#include "Item/Managers/InventoryManagerComponent.h"
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"
#include "Components/TextBlock.h"
#include "UI/Crafting/CraftedItemSlotEntryWidget.h"
#include "Item/ItemInstance.h"
#include "Item/ItemTemplate.h"      // UCraftedItemSlotEntryWidget의 SetSlotData가 ItemInstance를 받으므로 간접적으로 필요할 수 있음
#include "UI/Data/EmberItemData.h" // GetTemplateFromInstance가 있었다면 필요했겠지만, 이제 사용 안 함

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
    RefreshDisplay(); 
}

void UCraftingOutputBoxWidget::NativeDestruct()
{
    if (DataSourceInventoryManager)
    {
        if (DataSourceInventoryManager->OnInventoryEntryChanged.IsBoundToObject(this))
        {
            DataSourceInventoryManager->OnInventoryEntryChanged.RemoveAll(this);
        }
    }
    Super::NativeDestruct();
}

void UCraftingOutputBoxWidget::InitializeDataSource(UInventoryManagerComponent* TargetInventoryManager)
{
    UE_LOG(LogTemp, Warning, TEXT("UCraftingOutputBoxWidget::InitializeDataSource - Called. Current DataSourceInventoryManager: %s, New TargetInventoryManager: %s"),
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
        UE_LOG(LogTemp, Log, TEXT("UCraftingOutputBoxWidget::InitializeDataSource - Bound OnInventoryEntryChanged to new DataSource: %s. Widget: %s"), 
            *DataSourceInventoryManager->GetName(),
            this ? *this->GetName() : TEXT("NULL_WIDGET_SELF_POINTER"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("UCraftingOutputBoxWidget::InitializeDataSource - Initialized with NULL TargetInventoryManager."));
    }
    RefreshDisplay();
}

void UCraftingOutputBoxWidget::OnOutputInventoryChanged(const FIntPoint& ItemSlotPos, UItemInstance* ItemInstance, int32 ItemCount)
{
    UE_LOG(LogTemp, Warning, TEXT(">>>> UCraftingOutputBoxWidget::OnOutputInventoryChanged - FIRED! SlotPos: (X=%d, Y=%d), Item: %s, Count: %d. Refreshing display. <<<<"), 
        ItemSlotPos.X, ItemSlotPos.Y, 
        ItemInstance ? *ItemInstance->GetName() : TEXT("NULL_ItemInstance"), 
        ItemCount);
    RefreshDisplay();
}
void UCraftingOutputBoxWidget::RefreshDisplay()
{
    if (!OutputSlotsGridPanel)
    {
        UE_LOG(LogTemp, Warning, TEXT("UCraftingOutputBoxWidget::RefreshDisplay - OutputSlotsGridPanel is NULL. Check UMG binding."));
        return;
    }
    OutputSlotsGridPanel->ClearChildren();

    if (!DataSourceInventoryManager)
    {
        UE_LOG(LogTemp, Log, TEXT("UCraftingOutputBoxWidget::RefreshDisplay - DataSourceInventoryManager is NULL. Displaying empty."));
        return;
    }
    if (!SlotEntryWidgetClass)
    {
        UE_LOG(LogTemp, Warning, TEXT("UCraftingOutputBoxWidget::RefreshDisplay - SlotEntryWidgetClass is not set in ClassDefaults of WBP_CraftingOutputBox."));
        return;
    }

    const FIntPoint GridDimensions = DataSourceInventoryManager->GetInventorySlotCount(); 
    const TArray<FInventoryEntry>& AllEntries = DataSourceInventoryManager->GetAllEntries();

    UE_LOG(LogTemp, Log, TEXT("UCraftingOutputBoxWidget::RefreshDisplay - Grid: %dx%d, Inventory Entries Count: %d"), GridDimensions.X, GridDimensions.Y, AllEntries.Num());

    // UInventoryManagerComponent의 슬롯 개수만큼 UI 슬롯을 만듭니다.
    // AllEntries 배열은 실제 아이템이 있는 항목만 포함할 수도 있고, 빈 슬롯 데이터도 포함할 수 있습니다.
    // 여기서는 GridDimensions를 기준으로 루프를 돌고, AllEntries에서 해당 인덱스의 데이터를 가져옵니다.
    // UInventoryManagerComponent의 GetAllEntries()가 모든 슬롯(빈 슬롯 포함)에 대한 데이터를 반환한다고 가정합니다.
    // 만약 아니라면, GridDimensions.X * GridDimensions.Y 크기의 루프를 돌면서 각 인덱스에 해당하는 아이템을 가져오는 로직이 필요합니다.
    // 지금은 AllEntries가 모든 슬롯 정보를 순서대로 담고 있다고 가정하고, GridDimensions로 루프를 돕니다.

    int32 MaxSlotsToDisplay = GridDimensions.X * GridDimensions.Y;
    if (AllEntries.Num() != MaxSlotsToDisplay && AllEntries.Num() > 0) // AllEntries가 아이템 있는 것만 반환하는 경우에 대한 방어적 로그
    {
         UE_LOG(LogTemp, Warning, TEXT("UCraftingOutputBoxWidget::RefreshDisplay - AllEntries count (%d) does not match GridDimensions (%dx%d = %d). UI might not reflect all inventory slots if GetAllEntries() only returns non-empty ones."), 
            AllEntries.Num(), GridDimensions.X, GridDimensions.Y, MaxSlotsToDisplay);
    }


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
}