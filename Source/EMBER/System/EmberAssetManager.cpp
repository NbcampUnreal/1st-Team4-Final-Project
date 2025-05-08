// Fill out your copyright notice in the Description page of Project Settings.


#include "System/EmberAssetManager.h"

UEmberAssetManager::UEmberAssetManager()
{
}

void UEmberAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	GetUIData();
	GetItemData();
}

UEmberAssetManager& UEmberAssetManager::Get()
{
	check(GEngine);

	if (UEmberAssetManager* Singleton = Cast<UEmberAssetManager>(GEngine->AssetManager))
	{
		return *Singleton;
	}
	
	return *NewObject<UEmberAssetManager>();
}

const UEmberUIData& UEmberAssetManager::GetUIData()
{
	return GetOrLoadTypedGameData<UEmberUIData>(UIDataPath);
}

const UEmberItemData& UEmberAssetManager::GetItemData()
{
	return GetOrLoadTypedGameData<UEmberItemData>(ItemDataPath);
}

UPrimaryDataAsset* UEmberAssetManager::LoadGameDataOfClass(TSubclassOf<UPrimaryDataAsset> DataClass, const TSoftObjectPtr<UPrimaryDataAsset>& DataClassPath, FPrimaryAssetType PrimaryAssetType)
{
	UPrimaryDataAsset* Asset = nullptr;

	if (DataClassPath.IsNull())
		return nullptr;
	
	if (GIsEditor)
	{
		Asset = DataClassPath.LoadSynchronous();
		LoadPrimaryAssetsWithType(PrimaryAssetType);
	}
	else
	{
		TSharedPtr<FStreamableHandle> Handle = LoadPrimaryAssetsWithType(PrimaryAssetType);
		if (Handle.IsValid())
		{
			Handle->WaitUntilComplete(0.0f, false);
			Asset = Cast<UPrimaryDataAsset>(Handle->GetLoadedAsset());
		}
	}

	if (Asset)
	{
		GameDataMap.Add(DataClass, Asset);
	}

	return Asset;
}
