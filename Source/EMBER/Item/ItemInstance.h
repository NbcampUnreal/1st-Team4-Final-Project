// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFlag.h"
#include "UObject/Object.h"
#include "ItemInstance.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class EMBER_API UItemInstance : public UObject
{
	GENERATED_BODY()

public:
	UItemInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	//~UObject overrides
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	//~End of UObject Overrides
	
public:
	UFUNCTION(BlueprintCallable)
	int32 GetItemTemplateID() const { return ItemTemplateID; }

	UFUNCTION(BlueprintCallable)
	EItemRarity GetItemRarity() const { return ItemRarity; }
	
private:
	UPROPERTY(Replicated)
	int32 ItemTemplateID = INDEX_NONE;

	UPROPERTY(Replicated)
	EItemRarity ItemRarity = EItemRarity::Poor;
};
