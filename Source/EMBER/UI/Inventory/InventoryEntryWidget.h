// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ItemWidgets/ItemEntryWidget.h"
#include "InventoryEntryWidget.generated.h"

class USizeBox;
class UItemInstance;
class UInventorySlotsWidget;

UCLASS()
class EMBER_API UInventoryEntryWidget : public UItemEntryWidget
{
	GENERATED_BODY()

public:
	UInventoryEntryWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	void Init(UInventorySlotsWidget* InSlotsWidget, UItemInstance* InItemInstance, int32 InItemCount);

private:
	UPROPERTY()
	TObjectPtr<UInventorySlotsWidget> SlotsWidget;

private:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<USizeBox> SizeBox_Root;
};
