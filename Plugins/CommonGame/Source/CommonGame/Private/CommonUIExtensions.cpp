// Fill out your copyright notice in the Description page of Project Settings.


#include "CommonUIExtensions.h"

#include "GameUIPolicy.h"
#include "GameplayTagContainer.h"
#include "GameUIManagerSubsystem.h"
#include "PrimaryGameLayout.h"

UCommonActivatableWidget* UCommonUIExtensions::PushContentToLayer_ForPlayer(const ULocalPlayer* LocalPlayer, FGameplayTag LayerName, TSubclassOf<UCommonActivatableWidget> WidgetClass)
{
	if (!LocalPlayer || !WidgetClass)
	{
		return nullptr;
	}

	if (UGameUIManagerSubsystem* UIManager = LocalPlayer->GetGameInstance()->GetSubsystem<UGameUIManagerSubsystem>())
	{
		if (UGameUIPolicy* Policy = UIManager->GetCurrentUIPolicy())
		{
			if (UPrimaryGameLayout* RootLayout = Policy->GetRootLayout())
			{
				return RootLayout->PushWidgetToLayerStack(LayerName, WidgetClass);
			}
		}
	}

	return nullptr;
}
