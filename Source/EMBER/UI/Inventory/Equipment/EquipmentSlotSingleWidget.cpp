// Fill out your copyright notice in the Description page of Project Settings.


#include "EquipmentSlotSingleWidget.h"

#include "Components/Image.h"

UEquipmentSlotSingleWidget::UEquipmentSlotSingleWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
}

void UEquipmentSlotSingleWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (Image_BaseIcon)
	{
		Image_BaseIcon->SetBrushFromTexture(BaseIconTexture, true);
	}
}
