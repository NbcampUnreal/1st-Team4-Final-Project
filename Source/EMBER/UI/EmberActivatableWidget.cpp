// Fill out your copyright notice in the Description page of Project Settings.


#include "EmberActivatableWidget.h"

UEmberActivatableWidget::UEmberActivatableWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

TOptional<FUIInputConfig> UEmberActivatableWidget::GetDesiredInputConfig() const
{
	switch (InputConfig)
	{
	case EEmberWidgetInputMode::GameAndUI:
		return FUIInputConfig(ECommonInputMode::All, GameMouseCaptureMode);
	case EEmberWidgetInputMode::Game:
		return FUIInputConfig(ECommonInputMode::Game, GameMouseCaptureMode);
	case EEmberWidgetInputMode::UI:
		return FUIInputConfig(ECommonInputMode::Menu, EMouseCaptureMode::NoCapture);
	case EEmberWidgetInputMode::Default:
	default:
		return TOptional<FUIInputConfig>();
	}
}
