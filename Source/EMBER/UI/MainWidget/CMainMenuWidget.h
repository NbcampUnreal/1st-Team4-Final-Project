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

USTRUCT()
struct FServerData
{
	GENERATED_BODY()

	FString Name;
	uint16 CurrentPlayers;
	uint16 MaxPlayers;
	FString HostUserName;
};

UCLASS()
class EMBER_API UCMainMenuWidget : public UCMenuWidget
{
	GENERATED_BODY()
public:
	UCMainMenuWidget(const FObjectInitializer& ObjectInitializer);

protected:
	virtual bool Initialize();

private:
	UFUNCTION()
	void HostServer();

	UFUNCTION()
	void JoinServer();


	UFUNCTION()
	void OpenHostMenu();

	UFUNCTION()
	void OpenJoinMenu();
	UFUNCTION()
	void OpenMainMenu();

	UFUNCTION()
	void QuitPressed();

public:
	void SetServerList(TArray<FServerData> InServerName);
	void SelectIndex(uint32 InIndex);
	void UpdateChildren();
private:
	UPROPERTY(meta = (BindWidget))
	class UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* QuitButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* CancelJoinMenuButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* ConfirmJoinMenuButton;

	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
	class UWidget* MainMenu;

	UPROPERTY(meta = (BindWidget))
	class UWidget* JoinMenu;
	UPROPERTY(meta = (BindWidget))
	class UWidget* HostMenu;

	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* ServerHostName;
	UPROPERTY(meta = (BindWidget))
	UButton* ConfirmHostMenuButton;
	UPROPERTY(meta = (BindWidget))
	UButton* CancelHostMenuButton;

	UPROPERTY(meta = (BindWidget))
	class UPanelWidget* ServerList;

private:
	TSubclassOf<UUserWidget> ServerRowClass;
	TOptional<uint32> SelectedIndex;
};
