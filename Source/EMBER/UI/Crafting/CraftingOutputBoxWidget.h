#pragma once

#include "CoreMinimal.h"
#include "UI/Common/EmberActivatableWidget.h"
#include "Item/ItemInstance.h"
#include "CraftingOutputBoxWidget.generated.h"

class UWrapBox; 
class UItemTemplate;


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
    UItemInstance* RemoveItemFromSlot(int32 SlotIndex);

    UFUNCTION(BlueprintPure, Category = "CraftingOutput")
    bool IsFull() const;

    UFUNCTION(BlueprintPure, Category = "CraftingOutput")
    int32 GetMaxSlots() const;

    UFUNCTION(BlueprintPure, Category = "CraftingOutput")
    const TArray<FCraftingOutputSlotEntry>& GetOutputSlotEntries() const;

    UPROPERTY(BlueprintAssignable, Category = "CraftingOutput")
    FOnOutputBoxContentsChanged OnContentsChanged;

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CraftingOutput", meta = (ClampMin = "1", ClampMax = "20"))
    int32 MaxOutputSlots;

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_OutputSlotEntries, Category = "CraftingOutput")
    TArray<FCraftingOutputSlotEntry> OutputSlotEntries;

    UFUNCTION()
    void OnRep_OutputSlotEntries();

    UFUNCTION(BlueprintImplementableEvent, Category = "CraftingOutput", meta = (DisplayName = "OnUpdateOutputBoxUI_BP"))
    void K2_UpdateOutputBoxUI(); 

private:
    const UItemTemplate* GetTemplateFromInstance(UItemInstance* Instance) const;
};