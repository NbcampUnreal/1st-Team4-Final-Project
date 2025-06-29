// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonGameInstance.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "UI/MainWidget/MenuInterface.h"
#include "EmberGameInstance.generated.h"

class UCMenuWidget;
/**
 * 
 */
UCLASS()
class EMBER_API UEmberGameInstance : public UGameInstance , public IMenuInterface//public UCommonGameInstance
{
	GENERATED_BODY()
public:
	FORCEINLINE int32 GetConectedPlayerCount() { return ConectedPlayerCount; }
public:
	UEmberGameInstance(const FObjectInitializer& ObjectInitializer);

	virtual void Init();

	UFUNCTION(BlueprintCallable)
	void LoadMenuWidget();

	UFUNCTION(BlueprintCallable)
	void InGameLoadMenu();

	UFUNCTION(Exec)
	void Host(FString InServerName) override;

	UFUNCTION(Exec)
	void Join(uint32 InIndex) override;

public:
	virtual void LoadMainMenu() override;

	virtual void RefreshServerList() override;

	void OnCreateSessionComplete(FName InSessionName, bool bSucess);
	void OnDestroySessionComplete(FName InSessionName, bool bSucess);
	void CreateSession();
	void OnFindSessionsComplete(bool bSucess);
	void OnJoinSessionComplete(FName InSessionName, EOnJoinSessionCompleteResult::Type InResult);

	void StartSession();

	void FOnNetworkFailure(UWorld* InWorld, UNetDriver* InNetDriver, ENetworkFailure::Type InFaulureType, const FString& InErrorString);

private:
	TSubclassOf<class UUserWidget> MenuClass;
	TSubclassOf<class UUserWidget> InGameMenuClass;

	class UCMainMenuWidget* Menu;

	IOnlineSessionPtr SessionInterface;
	TSharedPtr<FOnlineSessionSearch> SessionSearch;
	//FString DesiredServerName;

	int32 ConectedPlayerCount;
	FName CurrentSessionName;

};
