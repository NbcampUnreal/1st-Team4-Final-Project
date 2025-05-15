// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "HoverWidget.generated.h"

UCLASS()
class EMBER_API UHoverWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UHoverWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
