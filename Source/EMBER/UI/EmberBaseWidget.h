// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EmberBaseWidget.generated.h"

DECLARE_DELEGATE(FEmberCallback)

UCLASS()
class EMBER_API UEmberBaseWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY()
	bool bIsDestroyed = false;
protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
public:
	static void DelayUntilWidgetReady(TWeakObjectPtr<UUserWidget> Context,
		TWeakObjectPtr<UWidget> Target,
		FEmberCallback Callback,
		int32 MaxRetries = 10);
	static void DelayUntilAllWidgetsReady(TWeakObjectPtr<UUserWidget> Context,
		const TArray<TWeakObjectPtr<UWidget>>& Targets,
		FEmberCallback Callback,
		int32 MaxRetries = 10);

	static bool IsWidgetReadyForGeometryAccess(UWidget* Widget);
	bool IsWidgetReadyForGeometryAccess() const;
	FVector2D GetGeometryAbsolutePosition() const;
	UFUNCTION(BlueprintCallable, Category = "UI|SafeAccess")
	bool IsDestroyed() const;
};
