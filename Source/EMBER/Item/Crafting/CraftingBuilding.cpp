#include "CraftingBuilding.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Blueprint/UserWidget.h"
#include "Player/EmberPlayerCharacter.h"
#include "../Crafting/CraftingSystem.h"
#include "GameFramework/PlayerController.h"

ACraftingBuilding::ACraftingBuilding()
{
    PrimaryActorTick.bCanEverTick = true;

    BuildingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BuildingMesh"));
    RootComponent = BuildingMesh;

    InteractionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("InteractionBox"));
    InteractionBox->SetupAttachment(BuildingMesh);
    InteractionBox->SetBoxExtent(FVector(100.f, 100.f, 50.f));
    InteractionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    InteractionBox->SetCollisionResponseToAllChannels(ECR_Ignore);
    InteractionBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

    SelectedItem = TEXT("DefaultItem");

    OverlappingPlayer = nullptr;
    InteractionWidget = nullptr;
}

void ACraftingBuilding::BeginPlay()
{
    Super::BeginPlay();

    InteractionBox->OnComponentBeginOverlap.AddDynamic(this, &ACraftingBuilding::OnOverlapBegin);
    InteractionBox->OnComponentEndOverlap.AddDynamic(this, &ACraftingBuilding::OnOverlapEnd);
}

void ACraftingBuilding::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ACraftingBuilding::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    AEmberPlayerCharacter* Player = Cast<AEmberPlayerCharacter>(OtherActor);
    if (Player)
    {
        OverlappingPlayer = Player;

        APlayerController* PC = Cast<APlayerController>(Player->GetController());
        if (PC)
        {
            EnableInput(PC);
            if (InputComponent)
            {
                InputComponent->BindAction("Interact", IE_Pressed, this, &ACraftingBuilding::HandleInput);
            }
        }

        ShowInteractPrompt();
    }
}

void ACraftingBuilding::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    AEmberPlayerCharacter* Player = Cast<AEmberPlayerCharacter>(OtherActor);
    if (Player && Player == OverlappingPlayer)
    {
        OverlappingPlayer = nullptr;

        APlayerController* PC = Cast<APlayerController>(Player->GetController());
        if (PC)
        {
            DisableInput(PC);
        }
        HideInteractPrompt();
    }
}

void ACraftingBuilding::HandleInput()
{
    HideInteractPrompt();

    if (OverlappingPlayer)
    {
        OnInteract(OverlappingPlayer);
    }
}

void ACraftingBuilding::OnInteract(AActor* Interactor)
{
    AEmberPlayerCharacter* Player = Cast<AEmberPlayerCharacter>(Interactor);
    if (Player)
    {
        UCraftingSystem* CraftingSystem = Player->FindComponentByClass<UCraftingSystem>();
        if (CraftingSystem)
        {
            CraftingSystem->StartCrafting(Player, SelectedItem);
        }
    }
}

void ACraftingBuilding::ShowInteractPrompt()
{
    if (!InteractionWidget && InteractionWidgetClass)
    {
        APlayerController* PC = GetWorld()->GetFirstPlayerController();
        if (PC)
        {
            InteractionWidget = CreateWidget<UUserWidget>(PC, InteractionWidgetClass);
            if (InteractionWidget)
            {
                InteractionWidget->AddToViewport();
            }
        }
    }
    else
    {
    }
}

void ACraftingBuilding::HideInteractPrompt()
{
    if (InteractionWidget)
    {
        InteractionWidget->RemoveFromViewport();
        InteractionWidget = nullptr;
    }
    else
    {
    }
}
