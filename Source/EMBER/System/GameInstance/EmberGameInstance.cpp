// Fill out your copyright notice in the Description page of Project Settings.


#include "EmberGameInstance.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "OnlineSessionSettings.h"
#include "Online/OnlineSessionNames.h"
#include "UI/MainWidget/CMainMenuWidget.h"

#define SETTING_PORT FName(TEXT("PORT"))
const static FName SESSION_NAME = TEXT("My Session Game");

UEmberGameInstance::UEmberGameInstance(const FObjectInitializer& ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/Loby/Widget/WBP_OnlineMenu"));
	if (!ensure(MenuBPClass.Class != nullptr)) return;

	MenuClass = MenuBPClass.Class;

	/*ConstructorHelpers::FClassFinder<UUserWidget> InGameMenuBPClass(TEXT("/Game/MenuSystem/WBP_InGameMenu"));
	if (!ensure(InGameMenuBPClass.Class != nullptr)) return;

	InGameMenuClass = InGameMenuBPClass.Class;*/
}

void UEmberGameInstance::Init()
{
	IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get();
	if (Subsystem != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Found subsystem %s"), *Subsystem->GetSubsystemName().ToString());
		SessionInterface = Subsystem->GetSessionInterface();
		if (SessionInterface.IsValid()) {
			SessionInterface->OnCreateSessionCompleteDelegates.AddUObject(this, &UEmberGameInstance::OnCreateSessionComplete);
			SessionInterface->OnDestroySessionCompleteDelegates.AddUObject(this, &UEmberGameInstance::OnCreateSessionComplete);
			SessionInterface->OnFindSessionsCompleteDelegates.AddUObject(this, &UEmberGameInstance::OnFindSessionsComplete);
			SessionInterface->OnJoinSessionCompleteDelegates.AddUObject(this, &UEmberGameInstance::OnJoinSessionComplete);
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Found no subsystem"));
	}
}

void UEmberGameInstance::LoadMenuWidget()
{
	if (!ensure(MenuClass != nullptr)) return;

	Menu = CreateWidget<UCMainMenuWidget>(this, MenuClass);
	if (!ensure(Menu != nullptr)) return;

	Menu->Setup();

	Menu->SetMenuInterface(this);
}

void UEmberGameInstance::InGameLoadMenu()
{
	if (!ensure(InGameMenuClass != nullptr)) return;

	UCMenuWidget* menu = CreateWidget<UCMenuWidget>(this, InGameMenuClass);
	if (!ensure(menu != nullptr)) return;

	menu->Setup();

	menu->SetMenuInterface(this);
}


void UEmberGameInstance::Host()
{
	if (SessionInterface.IsValid())
	{
		
		auto ExistingSession = SessionInterface->GetNamedSession(SESSION_NAME);
		if (ExistingSession != nullptr)
		{
			SessionInterface->DestroySession(SESSION_NAME);
		}
		else
		{
			CreateSession();
		}
	}
}

void UEmberGameInstance::OnDestroySessionComplete(FName SessionName, bool Success)
{
	if (Success) {
		CreateSession();
	}
}

void UEmberGameInstance::CreateSession()
{

	if (SessionInterface.IsValid()) {
		FOnlineSessionSettings SessionSettings;
		SessionSettings.bIsLANMatch = false;
		SessionSettings.NumPublicConnections = 2;
		SessionSettings.bShouldAdvertise = true;

		SessionSettings.bUsesPresence = true;
		SessionSettings.bUseLobbiesIfAvailable = true;

		// 추가 설정
		SessionSettings.bAllowInvites = true;
		SessionSettings.bAllowJoinViaPresence = true;
		SessionSettings.bAllowJoinInProgress = true;

		// 고유 식별자 추가 (자신의 게임만 찾기 위해)
		SessionSettings.Set(FName("GAME_TYPE"), FString("EMBER_GAME"), EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);


		SessionInterface->CreateSession(0, SESSION_NAME, SessionSettings);
	}
}

void UEmberGameInstance::OnCreateSessionComplete(FName SessionName, bool Success)
{
	if (!Success)
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not create session"));
		return;
	}

	if (Menu != nullptr)
	{
		Menu->Teardown();
	}

	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting"));

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/Loby/Maps/LobyMap?listen");
}

void UEmberGameInstance::RefreshServerList()
{
	SessionSearch = MakeShareable(new FOnlineSessionSearch());
	if (SessionSearch.IsValid())
	{
		SessionSearch->bIsLanQuery = false;
		SessionSearch->MaxSearchResults = 100;
		SessionSearch->QuerySettings.Set(SEARCH_PRESENCE,true,EOnlineComparisonOp::Equals);
		UE_LOG(LogTemp, Warning, TEXT("Starting Find Session"));
		SessionInterface->FindSessions(0, SessionSearch.ToSharedRef());
	}
}

void UEmberGameInstance::OnFindSessionsComplete(bool Success)
{
	if (Success && SessionSearch.IsValid() && Menu != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Finished Find Session"));

		TArray<FString> ServerNames;
		for (const FOnlineSessionSearchResult& SearchResult : SessionSearch->SearchResults)
		{
			UE_LOG(LogTemp, Warning, TEXT("Found session names: %s"), *SearchResult.GetSessionIdStr());
			ServerNames.Add(SearchResult.GetSessionIdStr());
		}

		Menu->SetServerList(ServerNames);
	}
}

void UEmberGameInstance::Join(uint32 Index)
{
	UE_LOG(LogTemp, Warning, TEXT("=== Join() called with Index: %d ==="), Index);

	if (!SessionInterface.IsValid()) {
		UE_LOG(LogTemp, Error, TEXT("SessionInterface is NOT valid"));
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("SessionInterface is valid"));

	if (!SessionSearch.IsValid()) {
		UE_LOG(LogTemp, Error, TEXT("SessionSearch is NOT valid"));
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("SessionSearch is valid"));

	if (Index >= (uint32)SessionSearch->SearchResults.Num()) {
		UE_LOG(LogTemp, Error, TEXT("Index %d is out of range. SearchResults count: %d"), Index, SessionSearch->SearchResults.Num());
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("Index is valid. SearchResults count: %d"), SessionSearch->SearchResults.Num());

	const FOnlineSessionSearchResult& SelectedSession = SessionSearch->SearchResults[Index];
	UE_LOG(LogTemp, Warning, TEXT("Selected session ID: %s"), *SelectedSession.GetSessionIdStr());

	if (Menu != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tearing down menu"));
		Menu->Teardown();
	}

	UE_LOG(LogTemp, Warning, TEXT("Calling JoinSession with SESSION_NAME: %s"), *SESSION_NAME.ToString());
	SessionInterface->JoinSession(0, SESSION_NAME, SessionSearch->SearchResults[Index]);
	UE_LOG(LogTemp, Warning, TEXT("JoinSession called successfully"));
}

void UEmberGameInstance::OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
	UE_LOG(LogTemp, Warning, TEXT("=== OnJoinSessionComplete called ==="));
	UE_LOG(LogTemp, Warning, TEXT("SessionName: %s"), *SessionName.ToString());
	UE_LOG(LogTemp, Warning, TEXT("Result: %d"), (int32)Result);

	// 결과 코드별 상세 로그
	switch (Result)
	{
	case EOnJoinSessionCompleteResult::Success:
		UE_LOG(LogTemp, Warning, TEXT("Join Success"));
		break;
	case EOnJoinSessionCompleteResult::SessionIsFull:
		UE_LOG(LogTemp, Error, TEXT("Session is full"));
		return;
	case EOnJoinSessionCompleteResult::SessionDoesNotExist:
		UE_LOG(LogTemp, Error, TEXT("Session does not exist"));
		return;
	case EOnJoinSessionCompleteResult::CouldNotRetrieveAddress:
		UE_LOG(LogTemp, Error, TEXT("Could not retrieve address"));
		return;
	case EOnJoinSessionCompleteResult::AlreadyInSession:
		UE_LOG(LogTemp, Error, TEXT("Already in session"));
		return;
	default:
		UE_LOG(LogTemp, Error, TEXT("Unknown join error: %d"), (int32)Result);
		return;
	}
	if (!SessionInterface.IsValid()) {
		UE_LOG(LogTemp, Error, TEXT("SessionInterface is not valid in OnJoinSessionComplete"));
		return;
	}

	if (Result != EOnJoinSessionCompleteResult::Success) {
		UE_LOG(LogTemp, Error, TEXT("Join session failed with result: %d"), (int32)Result);
		return;
	}

	FString Address;
	if (!SessionInterface->GetResolvedConnectString(SessionName, Address)) {
		UE_LOG(LogTemp, Error, TEXT("Could not get connect string for session: %s"), *SessionName.ToString());
		return;
	}

	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	UE_LOG(LogTemp, Warning, TEXT("Joining %s"), *Address);
	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	UE_LOG(LogTemp, Warning, TEXT("Calling ClientTravel to: %s"), *Address);
	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}

void UEmberGameInstance::LoadMainMenu()
{
	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel("/Game/Loby/Widget/WBP_OnlineMenu", ETravelType::TRAVEL_Absolute);
}