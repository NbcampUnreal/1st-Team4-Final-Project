// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class EMBER_API CHelpers
{
public:
	template<typename T>
	static void CreateComponent(TObjectPtr<AActor> InActor, TObjectPtr<T>* OutComponent, FName InName, TObjectPtr<USceneComponent> InParent = nullptr, FName InSocketName = NAME_None)
	{
		*OutComponent = InActor->CreateDefaultSubobject<T>(InName);
		
		if (InParent != nullptr)
		{
			(*OutComponent)->SetupAttachment(InParent, InSocketName);
			return;
		}

		InActor->SetRootComponent(*OutComponent);
	}

	template<typename T>
	static void CreateActorComponent(TObjectPtr<AActor> InActor, TObjectPtr<T>* OutComponent, FName InName)
	{
		*OutComponent = InActor->CreateDefaultSubobject<T>(InName);
	}
};
