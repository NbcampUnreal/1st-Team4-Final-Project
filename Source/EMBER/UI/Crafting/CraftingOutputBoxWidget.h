#pragma once

#include "CoreMinimal.h"
#include "UI/Common/EmberActivatableWidget.h"
#include "Item/ItemInstance.h"
#include "CraftingOutputBoxWidget.generated.h"

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

    UFUNCTION(BlueprintCallable, Category = "CraftingOutput")
    bool TryAddItem(UItemInstance* ItemInstanceToAdd);

    UFUNCTION(BlueprintCallable, Category = "CraftingOutput")
    UItemInstance* RemoveItemFromSlot(int32 FlatSlotIndex);

    UFUNCTION(BlueprintPure, Category = "CraftingOutput")
    bool IsFull() const;

    UFUNCTION(BlueprintPure, Category = "CraftingOutput")
    int32 GetMaxSlots() const;

    UFUNCTION(BlueprintPure, Category = "CraftingOutput")
    const TArray<FCraftingOutputSlotEntry>& GetOutputSlotEntries() const;

    UFUNCTION(BlueprintCallable, Category = "Layout")
    void SetGridDimensions(int32 InNumRows, int32 InNumColumns);

    UPROPERTY(BlueprintAssignable, Category = "CraftingOutput")
    FOnOutputBoxContentsChanged OnContentsChanged;

protected:
    virtual void NativeConstruct() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CraftingOutput|Layout", meta = (ClampMin = "1", UIMin = "1"))
    int32 NumRows;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CraftingOutput|Layout", meta = (ClampMin = "1", UIMin = "1"))
    int32 NumColumns;

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_OutputSlotEntries, Category = "CraftingOutput")
    TArray<FCraftingOutputSlotEntry> OutputSlotEntries;

    UFUNCTION()
    void OnRep_OutputSlotEntries();

    UPROPERTY(EditDefaultsOnly, Category = "CraftingOutput")
    TSubclassOf<UCraftedItemSlotEntryWidget> CraftedItemSlotEntryClass;

    UPROPERTY(BlueprintReadOnly, Category = "CraftingOutput", meta = (BindWidgetOptional))
    TObjectPtr<UUniformGridPanel> OutputSlotsGridPanel;

    UPROPERTY(BlueprintReadOnly, Category = "CraftingOutput", meta = (BindWidgetOptional))
    TObjectPtr<UTextBlock> TitleTextWidget;

private:
    void RefreshSlotsUI_Internal();
    const UItemTemplate* GetTemplateFromInstance(UItemInstance* Instance) const;
};