// Fill out your copyright notice in the Description page of Project Settings.


#include "EmberPlayerController.h"
#include "EnhancedInputSubsystems.h"

AEmberPlayerController::AEmberPlayerController()
	: InputMappingContext(nullptr),
	  MoveAction(nullptr),
	  LookAction(nullptr),
	  SprintAction(nullptr)
{
}

void AEmberPlayerController::BeginPlay()
{
	Super::BeginPlay();
 
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (InputMappingContext)
			{
				Subsystem->AddMappingContext(InputMappingContext, 0);
			}
		}
	}
}