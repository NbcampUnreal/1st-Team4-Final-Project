// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CMenuWidget.generated.h"

class IMenuInterface;
/**
 * 
 */
UCLASS()
class EMBER_API UCMenuWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void Setup();
	void Teardown();
	void SetMenuInterface(IMenuInterface* InMenuInterface);

protected:
	IMenuInterface* MenuInterface;
};
