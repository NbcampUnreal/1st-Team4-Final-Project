// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "C_CharacterStateComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EMBER_API UC_CharacterStateComponent : public UActorComponent
{
	GENERATED_BODY()
public:	
	UC_CharacterStateComponent();
protected:	//	재정의
	virtual void BeginPlay() override;
private:

};
