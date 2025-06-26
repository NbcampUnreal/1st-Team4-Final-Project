// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonGameInstance.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "UI/MainWidget/MenuInterface.h"
#include "EmberGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class EMBER_API UEmberGameInstance : public UGameInstance , public IMenuInterface//public UCommonGameInstance
{
	GENERATED_BODY()
public:
	UEmberGameInstance(const FObjectInitializer& ObjectInitializer);
	virtual void Init();

protected:
	UFUNCTION(BlueprintCallable)
	void LoadMenuWidget();

	UFUNCTION(BlueprintCallable)
	void InGameLoadMenu();

	UFUNCTION(Exec)
	void Host() override;

	UFUNCTION(Exec)
	void Join(uint32 InIndex) override;

	virtual void LoadMainMenu() override;

	virtual void RefreshServerList() override;

private:
	void OnCreateSessionComplete(FName SessionName, bool bSuccess);
	void OnDestroySessionComplete(FName SessionName, bool bSuccess);
	void CreateSession();
	void OnFindSessionsComplete(bool bSuccess);
	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bIsRunning;
private:
	TSubclassOf<class UUserWidget> MenuClass;
	TSubclassOf<class UUserWidget> InGameMenuClass;

	class UCMainMenuWidget* Menu;
	IOnlineSessionPtr SessionInterface;
	TSharedPtr<FOnlineSessionSearch> SessionSearch;
};
