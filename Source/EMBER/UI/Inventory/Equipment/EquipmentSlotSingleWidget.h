// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EquipmentSlotWidget.h"
#include "EquipmentSlotSingleWidget.generated.h"

class UImage;
class UOverlay;

/**
 * 
 */
UCLASS()
class EMBER_API UEquipmentSlotSingleWidget : public UEquipmentSlotWidget
{
	GENERATED_BODY()

public:
	UEquipmentSlotSingleWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	//~UUserWidget Overrides
	virtual void NativePreConstruct() override;
	//~End of UUSerWidget Overrides
	
protected:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UTexture2D> BaseIconTexture;
	
protected:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UOverlay> Overlay_Entry;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UImage> Image_BaseIcon;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UImage> Image_Red;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UImage> Image_Green;

private:
};
