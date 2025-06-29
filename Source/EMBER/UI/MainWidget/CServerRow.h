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
	void Setup(class UCMainMenuWidget* InParent, uint32 InIndex);
private:
	UFUNCTION()
	void OnClicked();

protected:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

public:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ServerName;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* HostUser;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ConnectionFraction;
	UPROPERTY(BlueprintReadOnly)
	bool bSelected = false;
private:
	UPROPERTY(meta = (BindWidget))
	UButton* RowButton;
	UPROPERTY()
	UCMainMenuWidget* Parent;
	uint32 Index;
	UPROPERTY(EditAnywhere)
	bool bHeader;

};
