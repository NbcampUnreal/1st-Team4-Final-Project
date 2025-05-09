// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "InventorySlotsWidget.generated.h"

class UInventorySlotWidget;
class UInventoryValidWidget;
class UTextBlock;
class UOverlay;
class UUniformGridPanel;
class UCanvasPanel;
class UUniformGridPanel;

/**
 * 
 */
UCLASS()
class EMBER_API UInventorySlotsWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UInventorySlotsWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	//~UUserWidget Overrides
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	//~End of UUserWidget Overrides

private:
	UFUNCTION(BlueprintCallable)
	void ConstructUI();
	void DestructUI();
	
public:
	UPROPERTY(EditAnywhere)
	FText TitleText;

private:
	UPROPERTY()
	TArray<TObjectPtr<UInventorySlotWidget>> SlotWidgets;

	UPROPERTY()
	TArray<TObjectPtr<UInventoryValidWidget>> ValidWidgets;
	
private:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> Text_Title;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UOverlay> Overlay_Slots;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UUniformGridPanel> GridPanel_Slots;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCanvasPanel> CanvasPanel_Entries;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UUniformGridPanel> GridPanel_ValidSlots;
};
