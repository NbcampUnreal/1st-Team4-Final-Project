// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/AssetManager.h"
#include "UI/Data/EmberItemData.h"
#include "UI/Data/EmberUIData.h"

#include "EmberAssetManager.generated.h"

/**
 * 
 */
UCLASS(Config=Game)
class EMBER_API UEmberAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	UEmberAssetManager();
	
protected:
	//~UAssetManager Overrides
	virtual void StartInitialLoading() override;
	//~End of UAssetManager Overrides

public:
	static UEmberAssetManager& Get();
	
	const UEmberUIData& GetUIData();
	const UEmberItemData& GetItemData();

protected:
	UPrimaryDataAsset* LoadGameDataOfClass(TSubclassOf<UPrimaryDataAsset> DataClass, const TSoftObjectPtr<UPrimaryDataAsset>& DataClassPath, FPrimaryAssetType PrimaryAssetType);
	
	template <typename GameDataClass>
	const GameDataClass& GetOrLoadTypedGameData(const TSoftObjectPtr<GameDataClass>& DataPath)
	{
		if (TObjectPtr<UPrimaryDataAsset> const * pResult = GameDataMap.Find(GameDataClass::StaticClass()))
		{
			return *CastChecked<GameDataClass>(*pResult);
		}
		
		return *CastChecked<const GameDataClass>(LoadGameDataOfClass(GameDataClass::StaticClass(), DataPath, GameDataClass::StaticClass()->GetFName()));
	}
	
protected:
	UPROPERTY(Config)
	TSoftObjectPtr<UEmberUIData> UIDataPath;

	UPROPERTY(Config)
	TSoftObjectPtr<UEmberItemData> ItemDataPath;

	UPROPERTY(Transient)
	TMap<TObjectPtr<UClass>, TObjectPtr<UPrimaryDataAsset>> GameDataMap;
};