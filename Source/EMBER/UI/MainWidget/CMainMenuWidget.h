// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/MainWidget/CMenuWidget.h"
#include "CommonLoadGuard.h"
#include "CommonActionWidget.h"
#include "CommonAnimatedSwitcher.h"
#include "CMainMenuWidget.generated.h"

class UCBaseButton;
class UHorizontalBox;

UCLASS()
class EMBER_API UCMainMenuWidget : public UCMenuWidget
{
	GENERATED_BODY()
public:
	UCMainMenuWidget();
	UCMainMenuWidget(const FObjectInitializer& ObjectInitializer);

	void SetServerList(TArray<FString> ServerNames);
	void SelectIndex(uint32 InIndex);
protected:
	virtual bool Initialize();

private:
	UFUNCTION()
	void SoloServer();
	UFUNCTION()
	void HostServer();

	UFUNCTION()
	void JoinServer();


	UFUNCTION()
	void OpenJoinMenu();

	UFUNCTION()
	void OpenMainMenu();

	UFUNCTION()
	void QuitPressed();

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* SoloButton;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* HostButton;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* JoinButton;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* QuitButton;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* CancelJoinMenuButton;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* ConfirmJoinMenuButton;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UWidget* MainMenu;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UWidget* JoinMenu;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UPanelWidget* ServerList;

private:
	TSubclassOf<UUserWidget> ServerRowClass;
	TOptional<uint32> SelectedIndex;
};
