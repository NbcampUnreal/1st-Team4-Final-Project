// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CMenuWidget.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "CInGameMenu.generated.h"

/**
 * 
 */
UCLASS()
class EMBER_API UCInGameMenu : public UCMenuWidget
{
	GENERATED_BODY()
protected:
	virtual bool Initialize();

private:
	UPROPERTY(meta = (BindWidget))
	class UButton* CancelButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* QuitButton;

	UFUNCTION()
	void CancelPressed();

	UFUNCTION()
	void QuitPressed();
};
