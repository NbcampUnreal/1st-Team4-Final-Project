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
	virtual bool IsSupportedForNetworking() const override { return true; }
	//~End of UObject Overrides

public:
	void Init(int32 InItemTemplateID, EItemRarity InItemRarity);

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AddOrRemoveStatTagStack(FGameplayTag StatTag, int32 StackCount);
	
public:
	UFUNCTION(BlueprintCallable)
	int32 GetItemTemplateID() const { return ItemTemplateID; }

	UFUNCTION(BlueprintCallable)
	EItemRarity GetItemRarity() const { return ItemRarity; }

public:
	UFUNCTION(BlueprintCallable, BlueprintPure="false", meta=(DeterminesOutputType="FragmentClass"))
	const UItemFragment* FindFragmentByClass(TSubclassOf<UItemFragment> FragmentClass) const;

	template <typename FragmentClass>
	const FragmentClass* FindFragmentByClass() const
	{
		return (FragmentClass*)FindFragmentByClass(FragmentClass::StaticClass());
	}
	
private:
	UPROPERTY(Replicated)
	int32 ItemTemplateID = INDEX_NONE;

	UPROPERTY(Replicated)
	EItemRarity ItemRarity = EItemRarity::Common;
};
