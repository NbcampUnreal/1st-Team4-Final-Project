// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Data/EmberUIData.h"

#include "System/EmberAssetManager.h"

const UEmberUIData& UEmberUIData::Get()
{
	return UEmberAssetManager::Get().GetUIData();
}
