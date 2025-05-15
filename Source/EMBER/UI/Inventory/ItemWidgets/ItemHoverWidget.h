// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UI/Inventory/Widgets/HoverWidget.h"
#include "ItemHoverWidget.generated.h"

UCLASS()
class EMBER_API UItemHoverWidget : public UHoverWidget
{
	GENERATED_BODY()

public:
	UItemHoverWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
