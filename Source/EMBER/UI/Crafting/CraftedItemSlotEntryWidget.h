#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CraftedItemSlotEntryWidget.generated.h"

class UImage;
class UTextBlock;
class UItemInstance;
class UItemTemplate;
class UCraftingSystem;
class USizeBox;

UCLASS()
class EMBER_API UCraftedItemSlotEntryWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UCraftedItemSlotEntryWidget(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, Category = "CraftedItemSlot")
    void SetSlotData(UItemInstance* InItemInstance, int32 InQuantity);

protected:
    UPROPERTY(BlueprintReadOnly, Category = "CraftedItemSlot", meta = (BindWidgetOptional))
    TObjectPtr<USizeBox> SizeBox_Root;

    UPROPERTY(BlueprintReadOnly, Category = "CraftedItemSlot", meta = (BindWidgetOptional))
    TObjectPtr<UImage> ItemIcon;

    UPROPERTY(BlueprintReadOnly, Category = "CraftedItemSlot", meta = (BindWidgetOptional))
    TObjectPtr<UTextBlock> QuantityText;

    UPROPERTY(BlueprintReadOnly, Category = "CraftedItemSlot")
    TObjectPtr<UItemInstance> CachedItemInstance;

    UPROPERTY(BlueprintReadOnly, Category = "CraftedItemSlot")
    int32 CachedQuantity;

    UFUNCTION(BlueprintImplementableEvent, Category = "CraftedItemSlot", meta = (DisplayName = "OnDisplayDataUpdated_BP"))
    void K2_OnDisplayDataUpdated();

private:
    const UItemTemplate* GetItemTemplate() const;
    void UpdateWidgetAppearance();
    UCraftingSystem* GetCraftingSystem() const;
};