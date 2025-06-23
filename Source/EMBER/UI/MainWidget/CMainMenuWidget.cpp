// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainWidget/CMainMenuWidget.h"

#include "MenuInterface.h"
#include "Components/PanelWidget.h"

UCMainMenuWidget::UCMainMenuWidget()
{
}

UCMainMenuWidget::UCMainMenuWidget(const FObjectInitializer& ObjectInitializer)
{
	//ConstructorHelpers::FClassFinder<UUserWidget> ServerRowBPClass(TEXT("/Game/MenuSystem/WBP_ServerRow"));
	//if (!ensure(ServerRowBPClass.Class != nullptr)) return;

	//ServerRowClass = ServerRowBPClass.Class;
}

void UCMainMenuWidget::SetServerList(TArray<FString> InServerName)
{
	TObjectPtr<UWorld> world = GetWorld();
	if (ensure(world != nullptr) == false)
		return;

	//ServerList.Get()->ClearChildren();

	/*for (const FString& serverName : InServerName)
	{
		UServerRow* row = CreateWidget<UServerRow>(world, ServerRowClass);
		if (!ensure(row != nullptr))
			return;

		row->ServerName->SetText(FText::FromString(serverName));

		ServerList->AddChild(row);
	}*/
}

bool UCMainMenuWidget::Initialize()
{
	bool success = Super::Initialize();
	if (success == false)
		return false;
	return false;
}

void UCMainMenuWidget::HostServer()
{
	if (ensure(MenuInterface != nullptr) == false)
		return;

	MenuInterface.Get()->Host();
}

void UCMainMenuWidget::JoinServer()
{
	if (ensure(MenuInterface != nullptr) == false)
		return;

	MenuInterface->Join("");
}

void UCMainMenuWidget::OpenJoinMenu()
{
	//if (ensure(MenuSwitcher != nullptr) == false)
	//	return;

}

void UCMainMenuWidget::OpenMainMenu()
{
}

void UCMainMenuWidget::QuitPressed()
{
}
