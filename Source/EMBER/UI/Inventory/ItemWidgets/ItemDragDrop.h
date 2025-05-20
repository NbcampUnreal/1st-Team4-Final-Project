// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/DragDropOperation.h"
#include "ItemDragDrop.generated.h"

/**
 * 
 */
UCLASS()
class EMBER_API UItemDragDrop : public UDragDropOperation
{
	GENERATED_BODY()

public:
	UItemDragDrop(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
