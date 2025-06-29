#include "CMainMenuWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"
#include "Components/TextBlock.h"

#include "CServerRow.h"
#include "MenuInterface.h"
#include "GameFramework/GameModeBase.h"
#include "kismet/GameplayStatics.h"


UCMainMenuWidget::UCMainMenuWidget(const FObjectInitializer& ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UUserWidget> serverRow(TEXT("/Game/Loby/Widget/WBP_ServerRow"));
	if (!ensure(serverRow.Class != nullptr)) return;

	ServerRowClass = serverRow.Class;
}

bool UCMainMenuWidget::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	//Main Menu
	if (!ensure(HostButton != nullptr)) return false;
	HostButton->OnClicked.AddDynamic(this, &UCMainMenuWidget::OpenHostMenu);
	if (!ensure(JoinButton != nullptr)) return false;
	JoinButton->OnClicked.AddDynamic(this, &UCMainMenuWidget::OpenJoinMenu);

	//Host Menu
	if (!ensure(ConfirmHostMenuButton != nullptr)) return false;
	ConfirmHostMenuButton->OnClicked.AddDynamic(this, &UCMainMenuWidget::HostServer);
	if (!ensure(CancelHostMenuButton != nullptr)) return false;
	CancelHostMenuButton->OnClicked.AddDynamic(this, &UCMainMenuWidget::OpenMainMenu);

	//Join Menu
	if (!ensure(CancelJoinMenuButton != nullptr)) return false;
	CancelJoinMenuButton->OnClicked.AddDynamic(this, &UCMainMenuWidget::OpenMainMenu);
	if (!ensure(ConfirmJoinMenuButton != nullptr)) return false;
	ConfirmJoinMenuButton->OnClicked.AddDynamic(this, &UCMainMenuWidget::JoinServer);

	if (!ensure(QuitButton != nullptr)) return false;
	QuitButton->OnClicked.AddDynamic(this, &UCMainMenuWidget::QuitPressed);

	return true;
}

void UCMainMenuWidget::HostServer()
{
	if (MenuInterface != nullptr)
	{
		FString serverName = ServerHostName->Text.ToString();
		MenuInterface->Host(serverName);
	}
}

void UCMainMenuWidget::JoinServer()
{
	if (SelectedIndex.IsSet() == true && MenuInterface != nullptr)
	{
		UE_LOG(LogTemp, Warning, L"Selected index %d", SelectedIndex.GetValue());
		MenuInterface->Join(SelectedIndex.GetValue());
	}
	else
	{
		UE_LOG(LogTemp, Warning, L"Selected index not set");
	}
}

void UCMainMenuWidget::OpenHostMenu()
{
	MenuSwitcher->SetActiveWidget(HostMenu);
}

void UCMainMenuWidget::OpenJoinMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(JoinMenu != nullptr)) return;
	MenuSwitcher->SetActiveWidget(JoinMenu);
	if (MenuInterface != nullptr)
		MenuInterface->RefreshServerList();
}

void UCMainMenuWidget::OpenMainMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(JoinMenu != nullptr)) return;
	MenuSwitcher->SetActiveWidget(MainMenu);
}

void UCMainMenuWidget::QuitPressed()
{
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ConsoleCommand("quit");
}

void UCMainMenuWidget::SetServerList(TArray<FServerData> InServerName)
{
	UWorld* world = GetWorld();
	if (ensure(world != nullptr) == false)
		return;

	ServerList->ClearChildren();
	uint32 i{};

	for (const FServerData& serverData : InServerName)
	{
		UCServerRow* row = CreateWidget<UCServerRow>(world, ServerRowClass);
		if (ensure(row != nullptr) == false)
			return;

		row->ServerName->SetText(FText::FromString(serverData.Name));
		row->HostUser->SetText(FText::FromString(serverData.HostUserName));
		FString fractionText = FString::Printf(L"%d/%d", serverData.CurrentPlayers, serverData.MaxPlayers);
		row->ConnectionFraction->SetText(FText::FromString(fractionText));

		row->Setup(this, i++);
		ServerList->AddChild(row);
	}
}

void UCMainMenuWidget::SelectIndex(uint32 InIndex)
{
	SelectedIndex = InIndex;
	UpdateChildren();
}

void UCMainMenuWidget::UpdateChildren()
{
	for (int32 i = 0; i < ServerList->GetChildrenCount(); i++)
	{
		UCServerRow* row = Cast<UCServerRow>(ServerList->GetChildAt(i));
		if (row != nullptr)
		{
			row->bSelected = (SelectedIndex.IsSet() && SelectedIndex.GetValue() == i);
		}
	}
}
