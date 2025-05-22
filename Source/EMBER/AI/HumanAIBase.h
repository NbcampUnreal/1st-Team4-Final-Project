// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseAI.h"
#include "GameFramework/Character.h"
#include "HumanAIBase.generated.h"

class UC_StateComponent;
UCLASS()
class EMBER_API AHumanAIBase : public ABaseAI
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHumanAIBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Stat")
	TObjectPtr<UC_StateComponent> StateComponent;
};
