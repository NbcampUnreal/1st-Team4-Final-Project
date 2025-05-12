// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "GameFramework/GameplayMessageSubsystem.h"
#include "InventorySlotsWidget.generated.h"

class UInventorySlotWidget;
class UInventoryValidWidget;
class UInventoryEntryWidget;
class UItemInstance;
class UInventoryManagerComponent;
class UTextBlock;
class UOverlay;
class UUniformGridPanel;
class UCanvasPanel;


USTRUCT(BlueprintType)
struct FInventoryInitializeMessage
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UInventoryManagerComponent> InventoryManager;
};

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
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	//~End of UUserWidget Overrides

private:
	UFUNCTION(BlueprintCallable)
	void ConstructUI(FGameplayTag Channel, const FInventoryInitializeMessage& Message);
	void DestructUI();
	void OnInventoryEntryChanged(const FIntPoint& InItemSlotPos, UItemInstance* InItemInstance, int32 InItemCount);
	
public:
	UPROPERTY(EditAnywhere, meta=(Categories="Message"))
	FGameplayTag MessageChannelTag;
	
	UPROPERTY(EditAnywhere)
	FText TitleText;

private:
	UPROPERTY()
	TArray<TObjectPtr<UInventorySlotWidget>> SlotWidgets;

	UPROPERTY()
	TArray<TObjectPtr<UInventoryEntryWidget>> EntryWidgets;
	
	UPROPERTY()
	TArray<TObjectPtr<UInventoryValidWidget>> ValidWidgets;

	UPROPERTY()
	TObjectPtr<UInventoryManagerComponent> InventoryManager;
	
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

private:
	FDelegateHandle EntryChangedDelegateHandle;
	FGameplayMessageListenerHandle MessageListenerHandle;
};
