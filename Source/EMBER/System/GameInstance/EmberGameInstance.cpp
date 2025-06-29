// Fill out your copyright notice in the Description page of Project Settings.

#include "EmberGameInstance.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "OnlineSessionSettings.h"
#include "GameFramework/GameModeBase.h"
#include "Online/OnlineSessionNames.h"
#include "UI/MainWidget/CMainMenuWidget.h"

const static FName SESSION_NAME = TEXT("Game");
const static FName SERVER_NAME_SETTINGS_KEY = TEXT("ServerName");

UEmberGameInstance::UEmberGameInstance(const FObjectInitializer& ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/Loby/Widget/WBP_OnlineMenu"));
	if (!ensure(MenuBPClass.Class != nullptr)) return;

	MenuClass = MenuBPClass.Class;

	ConstructorHelpers::FClassFinder<UUserWidget> InGameMenuBPClass(TEXT("/Game/Loby/Widget/WBP_InGameMenu"));
	if (!ensure(InGameMenuBPClass.Class != nullptr)) return;

	InGameMenuClass = InGameMenuBPClass.Class;
}

void UEmberGameInstance::Init()
{
	IOnlineSubsystem* subsystem = IOnlineSubsystem::Get();
	UE_LOG(LogTemp, Warning, TEXT("Current Subsystem: %s"),
		subsystem ? *subsystem->GetSubsystemName().ToString() : TEXT("NULL"));

	if (subsystem != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found Subsystem %s"), *subsystem->GetSubsystemName().ToString());
		SessionInterface = subsystem->GetSessionInterface();
		if (SessionInterface.IsValid())
		{
			UE_LOG(LogTemp, Warning, TEXT("Found session interface"));

			SessionInterface->OnCreateSessionCompleteDelegates.AddUObject(this, &UEmberGameInstance::OnCreateSessionComplete);
			SessionInterface->OnDestroySessionCompleteDelegates.AddUObject(this, &UEmberGameInstance::OnDestroySessionComplete);
			SessionInterface->OnFindSessionsCompleteDelegates.AddUObject(this, &UEmberGameInstance::OnFindSessionsComplete);
			SessionInterface->OnJoinSessionCompleteDelegates.AddUObject(this, &UEmberGameInstance::OnJoinSessionComplete);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Found no session interface"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Found no subsystem"));
	}

	if (GEngine != nullptr)
	{
		GEngine->OnNetworkFailure().AddUObject(this, &UEmberGameInstance::FOnNetworkFailure);
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

void UEmberGameInstance::Host(FString InServerName)
{
	DesiredServerName = InServerName;
	if (!SessionInterface.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("Session Interface is null"));
		return;
	}

	FNamedOnlineSession* existingSession = SessionInterface->GetNamedSession(SESSION_NAME);
	if (existingSession != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Destroy existing Session"));
		SessionInterface->DestroySession(SESSION_NAME);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Create new Session"));
		CreateSession();
	}
}

void UEmberGameInstance::OnCreateSessionComplete(FName InSessionName, bool bSuccess)
{
	if (!bSuccess)
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not create session"));
		LoadMainMenu();
		return;
	}

	if (SessionInterface.IsValid())
	{
		// Register delegate for StartSessionComplete
		SessionInterface->AddOnStartSessionCompleteDelegate_Handle(
			FOnStartSessionCompleteDelegate::CreateUObject(
				this, &UEmberGameInstance::OnStartSessionComplete
			)
		);

		SessionInterface->StartSession(InSessionName);
	}

	if (Menu != nullptr)
	{
		Menu->Teardown();
	}

	UE_LOG(LogTemp, Warning, TEXT("Session created successfully, waiting for StartSession."));
}

void UEmberGameInstance::OnStartSessionComplete(FName SessionName, bool bWasSuccessful)
{
	if (!bWasSuccessful)
	{
		UE_LOG(LogTemp, Warning, TEXT("StartSession failed"));
		LoadMainMenu();
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("StartSession succeeded. Doing ServerTravel."));

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->GetAuthGameMode()->bUseSeamlessTravel = true;
	World->ServerTravel(TEXT("/Game/Loby/Maps/LobyMap?listen"));
}

void UEmberGameInstance::OnDestroySessionComplete(FName InSessionName, bool bSuccess)
{
	if (!bSuccess)
	{
		UE_LOG(LogTemp, Warning, TEXT("DestroySession failed."));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Session destroyed. Creating new session."));
	CreateSession();
}

void UEmberGameInstance::CreateSession()
{
	if (SessionInterface.IsValid())
	{
		FOnlineSessionSettings sessionSettings;
		if (IOnlineSubsystem::Get()->GetSubsystemName() == TEXT("NULL"))
		{
			sessionSettings.bIsLANMatch = true;
		}
		else
		{
			sessionSettings.bIsLANMatch = false;
		}

		sessionSettings.NumPublicConnections = 5;
		ConectedPlayerCount = sessionSettings.NumPublicConnections;
		sessionSettings.bShouldAdvertise = true;
		sessionSettings.bUsesPresence = true;
		sessionSettings.bAllowJoinInProgress = true;
		sessionSettings.bAllowJoinViaPresence = true;
		sessionSettings.bUseLobbiesIfAvailable = true;

		sessionSettings.Set(SERVER_NAME_SETTINGS_KEY, DesiredServerName, EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);

		SessionInterface->CreateSession(0, SESSION_NAME, sessionSettings);

		UE_LOG(LogTemp, Warning, TEXT("CreateSession called for %s"), *DesiredServerName);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("SessionInterface is null in CreateSession."));
	}
}

void UEmberGameInstance::OnFindSessionsComplete(bool bSuccess)
{
	if (!bSuccess || !SessionSearch.IsValid() || Menu == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("FindSessions failed."));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Finished FindSessions."));

	TArray<FServerData> serverDatas;
	for (const FOnlineSessionSearchResult& searchResult : SessionSearch->SearchResults)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found Session Id: %s"), *searchResult.GetSessionIdStr());
		FServerData serverData;
		serverData.Name = searchResult.GetSessionIdStr();
		serverData.MaxPlayers = searchResult.Session.SessionSettings.NumPublicConnections;
		int32 openConnections = searchResult.Session.NumOpenPublicConnections;
		serverData.CurrentPlayers = serverData.MaxPlayers - openConnections;
		serverData.HostUserName = searchResult.Session.OwningUserName;

		FString serverName;
		if (searchResult.Session.SessionSettings.Get(SERVER_NAME_SETTINGS_KEY, serverName))
		{
			UE_LOG(LogTemp, Warning, TEXT("ServerName found in settings: %s"), *serverName);
			serverData.Name = serverName;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No ServerName found in settings."));
			serverData.Name = TEXT("could not find name");
		}

		serverDatas.Add(serverData);
	}

	Menu->SetServerList(serverDatas);
}

void UEmberGameInstance::Join(uint32 InIndex)
{
	if (!SessionInterface.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("Join: Session Interface invalid."));
		return;
	}
	if (!SessionSearch.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("Join: Session Search invalid."));
		return;
	}

	if (Menu != nullptr)
	{
		Menu->Teardown();
	}

	UE_LOG(LogTemp, Warning, TEXT("Joining session at index %d"), InIndex);
	UE_LOG(LogTemp, Warning, TEXT("Session name to join: %s"), *DesiredServerName);

	SessionInterface->JoinSession(0, SESSION_NAME, SessionSearch->SearchResults[InIndex]);
}

void UEmberGameInstance::OnJoinSessionComplete(FName InSessionName, EOnJoinSessionCompleteResult::Type InResult)
{
	if (!SessionInterface.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("OnJoinSessionComplete: Session Interface invalid."));
		return;
	}

	FString address;
	if (SessionInterface->GetResolvedConnectString(SESSION_NAME, address))
	{
		UE_LOG(LogTemp, Warning, TEXT("Got connect string: %s"), *address);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("JoinSession: Could not get connect string"));
		LoadMainMenu();
		return;
	}

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	UE_LOG(LogTemp, Warning, TEXT("Join session complete. Travelling to %s"), *address);
	GEngine->AddOnScreenDebugMessage(1, 5, FColor::Blue, TEXT("Join session complete"));
	PlayerController->ClientTravel(address, ETravelType::TRAVEL_Absolute);
}

void UEmberGameInstance::StartSession()
{
	if (SessionInterface.IsValid())
	{
		SessionInterface->StartSession(SESSION_NAME);
	}
}

void UEmberGameInstance::LoadMainMenu()
{
	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel(TEXT("/Game/ProMainMenuV3/Levels/LVL_MainMenu_Test"), ETravelType::TRAVEL_Absolute);
}

void UEmberGameInstance::FOnNetworkFailure(UWorld* InWorld, UNetDriver* InNetDriver,
	ENetworkFailure::Type InFailureType, const FString& InErrorString)
{
	UE_LOG(LogTemp, Warning, TEXT("Network Failure: %s"), *InErrorString);
	LoadMainMenu();
}

void UEmberGameInstance::RefreshServerList()
{
	SessionSearch = MakeShareable(new FOnlineSessionSearch());
	if (SessionSearch.IsValid())
	{
		SessionSearch->MaxSearchResults = 100;
		SessionSearch->QuerySettings.Set(SEARCH_PRESENCE, true, EOnlineComparisonOp::Equals);
		UE_LOG(LogTemp, Warning, TEXT("Starting FindSessions."));
		SessionInterface->FindSessions(0, SessionSearch.ToSharedRef());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not start FindSessions."));
	}
}
