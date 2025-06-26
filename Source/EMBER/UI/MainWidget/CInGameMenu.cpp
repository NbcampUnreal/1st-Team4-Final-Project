// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainWidget/CInGameMenu.h"

#include "Components/Button.h"

bool UCInGameMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(CancelButton != nullptr)) return false;
	CancelButton->OnClicked.AddDynamic(this, &UCInGameMenu::CancelPressed);

	if (!ensure(QuitButton != nullptr)) return false;
	QuitButton->OnClicked.AddDynamic(this, &UCInGameMenu::QuitPressed);

	return true;
}

void UCInGameMenu::CancelPressed()
{
	Teardown();
}


void UCInGameMenu::QuitPressed()
{
	if (MenuInterface != nullptr) {
		Teardown();
		MenuInterface->LoadMainMenu();
	}
}
