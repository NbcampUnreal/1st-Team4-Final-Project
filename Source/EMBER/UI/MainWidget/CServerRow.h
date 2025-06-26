// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CServerRow.generated.h"

class UButton;
/**
 * 
 */
UCLASS()
class EMBER_API UCServerRow : public UUserWidget
{
	GENERATED_BODY()
public:
	void SetUP(class UCMainMenuWidget* InParent, uint32 InIndex);

private:
	UFUNCTION()
	void OnClicked();

public:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> ServerName;

private:
	UPROPERTY(meta = (BinWidget))
	UButton* RowButton;
	UPROPERTY()
	UCMainMenuWidget* Parent;

	uint32 Index;
};
