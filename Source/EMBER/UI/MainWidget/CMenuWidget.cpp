// Fill out your copyright notice in the Description page of Project Settings.


#include "CMenuWidget.h"

void UCMenuWidget::Setup()
{
	AddToViewport();

	TObjectPtr<UWorld> world = GetWorld();
	if (ensure(world != nullptr) == false)
		return;

	TObjectPtr<APlayerController> playerController = world->GetFirstPlayerController();
	if (ensure(playerController != nullptr) == false)
		return;

	FInputModeUIOnly input;
	input.SetWidgetToFocus(TakeWidget());
	input.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	playerController->SetInputMode(input);
	playerController->bShowMouseCursor = true;
}

void UCMenuWidget::Teardown()
{
	RemoveFromViewport();

	TObjectPtr<UWorld> world = GetWorld();
	if (ensure(world != nullptr) == false)
		return;

	TObjectPtr<APlayerController> playerController = world->GetFirstPlayerController();
	if (ensure(playerController != nullptr) == false)
		return;

	FInputModeGameOnly input;

	playerController->SetInputMode(input);
	playerController->bShowMouseCursor = false;
}

void UCMenuWidget::SetMenuInterface(TObjectPtr<IMenuInterface> InMenuInterface)
{
	MenuInterface = InMenuInterface;
}
