#pragma once

#include "CoreMinimal.h"
#include "Math/IntPoint.h" // FIntPoint 사용을 위해 추가
#include "UI/Common/EmberActivatableWidget.h"
#include "Item/ItemInstance.h" 
#include "CraftingOutputBoxWidget.generated.h"

class UInventoryManagerComponent;
class UUniformGridPanel;
class UCraftedItemSlotEntryWidget;
class UItemTemplate;
class UTextBlock;

USTRUCT(BlueprintType)
struct FCraftingOutputSlotEntry 
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "OutputSlot")
    TObjectPtr<UItemInstance> ItemInstance;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "OutputSlot")
    int32 Quantity;

    FCraftingOutputSlotEntry() : ItemInstance(nullptr), Quantity(0) {}
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOutputBoxContentsChanged);

UCLASS()
class EMBER_API UCraftingOutputBoxWidget : public UEmberActivatableWidget
{
    GENERATED_BODY()

public:
    UCraftingOutputBoxWidget(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, Category = "Crafting Output Display")
    void InitializeDataSource(UInventoryManagerComponent* TargetInventoryManager);

protected:
    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;

    UPROPERTY(BlueprintReadOnly, Category = "Crafting Output Display", meta = (BindWidgetOptional))
    TObjectPtr<UTextBlock> TitleTextWidget;

    UPROPERTY(BlueprintReadOnly, Category = "Crafting Output Display", meta = (BindWidget))
    TObjectPtr<UUniformGridPanel> OutputSlotsGridPanel;

    UPROPERTY(EditDefaultsOnly, Category = "Crafting Output Display|UI")
    TSubclassOf<UCraftedItemSlotEntryWidget> SlotEntryWidgetClass;

private:
    UFUNCTION()
    void OnOutputInventoryChanged(const FIntPoint& ItemSlotPos, UItemInstance* ItemInstance, int32 ItemCount);

    void RefreshDisplay();

    UPROPERTY()
    TObjectPtr<UInventoryManagerComponent> DataSourceInventoryManager;
};