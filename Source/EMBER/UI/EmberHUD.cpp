// Fill out your copyright notice in the Description page of Project Settings.


#include "EmberHUD.h"

#include "CommonUIExtensions.h"
#include "System/EmberAssetManager.h"

void AEmberHUD::BeginPlay()
{
	Super::BeginPlay();

	const FEmberHUDInfo& EmberHUDInfo = UEmberUIData::Get().EmberHUDInfo;

	if (APlayerController* PlayerController = GetOwningPlayerController())
	{
		if (ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(PlayerController->Player))
		{
			UCommonUIExtensions::PushContentToLayer_ForPlayer(LocalPlayer, EmberHUDInfo.HUDWidgetTag, EmberHUDInfo.HUDWidgetClass);
		}
	}
}
