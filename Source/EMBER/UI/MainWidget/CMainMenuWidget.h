// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/MainWidget/CMenuWidget.h"
#include "CMainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class EMBER_API UCMainMenuWidget : public UCMenuWidget
{
	GENERATED_BODY()
public:
	UCMainMenuWidget();
	UCMainMenuWidget(const FObjectInitializer& ObjectInitializer);

	void SetServerList(TArray<FString> InServerName);

protected:
	virtual bool Initialize() override;

private:
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
	class UPanelWidget* ServerList;
private:
	TSubclassOf<UUserWidget> ServerRowClass;
};
