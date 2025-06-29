// Fill out your copyright notice in the Description page of Project Settings.


#include "EmberGameInstance.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "OnlineSessionSettings.h"
#include "GameFramework/GameModeBase.h"
#include "Online/OnlineSessionNames.h"
#include "UI/MainWidget/CMainMenuWidget.h"

//const static FName SESSION_NAME = L"Game";
const static FName SERVER_NAME_SETTINGS_KEY = L"ServerName";

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
		if (SessionInterface.IsValid() == true)
		{
			UE_LOG(LogTemp, Warning, TEXT("Found session interface"));

			SessionInterface->OnCreateSessionCompleteDelegates.AddUObject(this, &UEmberGameInstance::OnCreateSessionComplete);
			SessionInterface->OnDestroySessionCompleteDelegates.AddUObject(this, &UEmberGameInstance::OnDestroySessionComplete);
			SessionInterface->OnFindSessionsCompleteDelegates.AddUObject(this, &UEmberGameInstance::OnFindSessionsComplete);
			SessionInterface->OnJoinSessionCompleteDelegates.AddUObject(this, &UEmberGameInstance::OnJoinSessionComplete);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Found not session interface"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Found not subsystem"));
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
	CurrentSessionName = *InServerName;
	if (SessionInterface.IsValid() == false)
	{
		UE_LOG(LogTemp, Warning, L"Session Interface is null");
		return;
	}
	FNamedOnlineSession* existingSession = SessionInterface->GetNamedSession(CurrentSessionName);
	if (existingSession != nullptr)
	{
		UE_LOG(LogTemp, Warning, L"Destroy Session");
		SessionInterface->DestroySession(CurrentSessionName);
	}
	else
	{
		UE_LOG(LogTemp, Warning, L"Create Session");
		CreateSession();
	}
}

void UEmberGameInstance::OnCreateSessionComplete(FName InSessionName, bool bSucess)
{
	if (bSucess == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not create session"));
		LoadMainMenu();
		return;
	}
	if (Menu != nullptr)
	{
		Menu->Teardown();
	}
	GetWorld()->GetAuthGameMode()->bUseSeamlessTravel = true;
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting"));

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/Loby/Maps/LobyMap?listen");
}

void UEmberGameInstance::OnDestroySessionComplete(FName InSessionName, bool bSucess)
{
	if (bSucess == false)
	{
		return;
	}
	CreateSession();
}

void UEmberGameInstance::CreateSession()
{
	if (SessionInterface.IsValid()) {
		FOnlineSessionSettings sessionSettings;
		if (IOnlineSubsystem::Get()->GetSubsystemName() == "NULL")
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
		sessionSettings.bUseLobbiesIfAvailable = true; // 이 값이 반드시 같아야 함

		sessionSettings.Set(SERVER_NAME_SETTINGS_KEY, CurrentSessionName.ToString(), EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);

		SessionInterface->CreateSession(0, CurrentSessionName, sessionSettings);
		UE_LOG(LogTemp, Warning, TEXT("Create Session, Session %s"), *CurrentSessionName.ToString());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Create Session, Session Interface is null"));
		return;
	}
	//SessionInterface->UpdateSession(IOnlineSubsystem::Get()->GetSubsystemName(), *SessionInterface.Get()->GetSessionSettings(IOnlineSubsystem::Get()->GetSubsystemName()));
}

void UEmberGameInstance::OnFindSessionsComplete(bool bSucess)
{
	if (bSucess == false || SessionSearch.IsValid() == false || Menu == nullptr)
	{
		UE_LOG(LogTemp, Warning, L"False Find Session");
		return;
	}
	UE_LOG(LogTemp, Warning, L"Finished Find Session");

	TArray<FServerData> serverDatas;
	for (const FOnlineSessionSearchResult& searchResult : SessionSearch->SearchResults)
	{
		UE_LOG(LogTemp, Warning, L"Found Session Name: %s", *searchResult.GetSessionIdStr());
		FServerData serverData;
		serverData.Name = searchResult.GetSessionIdStr();
		serverData.MaxPlayers = searchResult.Session.SessionSettings.NumPublicConnections;
		int32 a = searchResult.Session.NumOpenPublicConnections;
		serverData.CurrentPlayers = serverData.MaxPlayers - a;
		serverData.HostUserName = searchResult.Session.OwningUserName;
		FString serverName;
		if (searchResult.Session.SessionSettings.Get(SERVER_NAME_SETTINGS_KEY, serverName))
		{
			UE_LOG(LogTemp, Warning, L"Data found in settings : %s", *serverName);
			serverData.Name = serverName;
		}
		else
		{
			UE_LOG(LogTemp, Warning, L"Didn't get expected data");
			serverData.Name = "could not find name";
		}

		serverDatas.Add(serverData);
	}

	Menu->SetServerList(serverDatas);
}

void UEmberGameInstance::OnJoinSessionComplete(FName InSessionName, EOnJoinSessionCompleteResult::Type InResult)
{
	if (SessionInterface.IsValid() == false)
	{
		UE_LOG(LogTemp, Warning, L"OnJoinSessionComplete, Session Interface is not Valid");
		return;
	}

	FString address{};
	if (SessionInterface->GetResolvedConnectString(InSessionName, address) == false)
	{
		UE_LOG(LogTemp, Warning, L"JoinSession, Could not get connect string");
		return;
	}

	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, FString::Printf(TEXT("Joining %s"), *address));

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	UE_LOG(LogTemp, Warning, L"Join session complete");
	GEngine->AddOnScreenDebugMessage(1, 5, FColor::Blue, TEXT("Join session complete"));
	PlayerController->ClientTravel(address, ETravelType::TRAVEL_Absolute);
	SessionInterface->UpdateSession(IOnlineSubsystem::Get()->GetSubsystemName(), *SessionInterface.Get()->GetSessionSettings(IOnlineSubsystem::Get()->GetSubsystemName()));
}

void UEmberGameInstance::StartSession()
{
	if (SessionInterface.IsValid() == false)
		return;

	SessionInterface->StartSession(CurrentSessionName);
}

void UEmberGameInstance::FOnNetworkFailure(UWorld* InWorld, UNetDriver* InNetDriver,
	ENetworkFailure::Type InFaulureType, const FString& InErrorString)
{
	LoadMainMenu();
}

void UEmberGameInstance::Join(uint32 InIndex)
{
	if (SessionInterface.IsValid() == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Join, Session Interface is not Vaild"));
		return;
	}
	if (SessionSearch.IsValid() == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Session Search is not Vaild"));
		return;
	}

	if (Menu != nullptr)
	{
		Menu->Teardown();
	}

	UE_LOG(LogTemp, Warning, TEXT("Joining session at index %d"), InIndex);
	UE_LOG(LogTemp, Warning, TEXT("Session name to join: %s"), *CurrentSessionName.ToString());


	SessionInterface->JoinSession(0, CurrentSessionName, SessionSearch->SearchResults[InIndex]);
}

void UEmberGameInstance::LoadMainMenu()
{
	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel("/Game/ProMainMenuV3/Levels/LVL_MainMenu_Test", ETravelType::TRAVEL_Absolute);
}

void UEmberGameInstance::RefreshServerList()
{
	SessionSearch = MakeShareable(new FOnlineSessionSearch());
	if (SessionSearch.IsValid() == true)
	{
		//SessionSearch->bIsLanQuery = true;
		SessionSearch->MaxSearchResults = 100;
		SessionSearch->QuerySettings.Set(SEARCH_PRESENCE, true, EOnlineComparisonOp::Equals);
		UE_LOG(LogTemp, Warning, L"Starting Find Session");
		SessionInterface->FindSessions(0, SessionSearch.ToSharedRef());
	}
	else
	{
		UE_LOG(LogTemp, Warning, L"Not Starting Find Session");
	}
}


