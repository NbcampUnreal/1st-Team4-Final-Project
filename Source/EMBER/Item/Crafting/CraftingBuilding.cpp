#include "Item/Crafting/CraftingBuilding.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Blueprint/UserWidget.h"
#include "Player/EmberPlayerCharacter.h"
#include "Crafting/CraftingSystem.h"
#include "UI/Crafting/CraftingWidget.h" 
#include "Crafting/CraftingRecipeManager.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"


ACraftingBuilding::ACraftingBuilding()
{
    PrimaryActorTick.bCanEverTick = false;

    BuildingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BuildingMesh"));
    RootComponent = BuildingMesh;

    InteractionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("InteractionBox"));
    InteractionBox->SetupAttachment(BuildingMesh);
    InteractionBox->SetBoxExtent(FVector(100.f, 100.f, 50.f));
    InteractionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    InteractionBox->SetCollisionResponseToAllChannels(ECR_Ignore);
    InteractionBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

    OverlappingPlayerCharacter = nullptr;
    InteractionPromptWidgetInstance = nullptr;
    CachedSelectedRecipeData = nullptr;
}

UCraftingRecipeManager* ACraftingBuilding::GetRecipeManagerFromPlayer(AEmberPlayerCharacter* Player) const
{
    if (Player)
    {
        UCraftingSystem* CraftingSystem = Player->FindComponentByClass<UCraftingSystem>();
        if (CraftingSystem)
        {
            return CraftingSystem->RecipeManager;
        }
    }
    return nullptr;
}

TArray<FName> ACraftingBuilding::EditorOnly_GetRecipeRowNames() const
{
    TArray<FName> RowNames;
    // For editor functionality, we might need a way to access a default RecipeManager or have one set.
    // This example might not work perfectly in all editor contexts without further setup.
    // A common way is to have a TSoftObjectPtr to the RecipeManager DA in project settings or a game singleton.
    // For simplicity, this example tries to get it via a hypothetical first player if in PIE, or might need a direct asset reference for editor.
    // This part is tricky for direct editor dropdowns without more editor-specific code or a direct UPROPERTY for the RecipeManager DataAsset on ACraftingBuilding.
    // For now, leaving it to fetch via player if possible, otherwise, it won't populate dropdown in standalone editor view of this actor.
    AEmberPlayerCharacter* PlayerForContext = nullptr;
    if (GetWorld() && GetWorld()->IsPlayInEditor())
    {
        PlayerForContext = Cast<AEmberPlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
    }
    
    UCraftingRecipeManager* Manager = GetRecipeManagerFromPlayer(PlayerForContext);
    if (Manager && Manager->RecipeDataTable)
    {
        RowNames = Manager->RecipeDataTable->GetRowNames();
    }
    return RowNames;
}


void ACraftingBuilding::BeginPlay()
{
    Super::BeginPlay();

    InteractionBox->OnComponentBeginOverlap.AddDynamic(this, &ACraftingBuilding::OnOverlapBegin);
    InteractionBox->OnComponentEndOverlap.AddDynamic(this, &ACraftingBuilding::OnOverlapEnd);

    // Cache recipe data if a name is selected and player is already overlapping (e.g. placed on player start)
    // Or, more robustly, fetch it within OnInteract when the player is confirmed.
}

void ACraftingBuilding::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    AEmberPlayerCharacter* Player = Cast<AEmberPlayerCharacter>(OtherActor);
    if (Player)
    {
        OverlappingPlayerCharacter = Player;
        APlayerController* PC = Cast<APlayerController>(Player->GetController());
        if (PC)
        {
            EnableInput(PC);
            if (!InputComponent) // Ensure InputComponent is created if not already
            {
                InputComponent = NewObject<UInputComponent>(this);
                InputComponent->RegisterComponent();
            }
            if (InputComponent) // Check again after potential creation
            {
                InputComponent->BindAction("Interact", IE_Pressed, this, &ACraftingBuilding::HandleInput);
            }
        }
        ShowInteractPrompt();
    }
}

void ACraftingBuilding::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    AEmberPlayerCharacter* Player = Cast<AEmberPlayerCharacter>(OtherActor);
    if (Player && Player == OverlappingPlayerCharacter)
    {
        APlayerController* PC = Cast<APlayerController>(Player->GetController());
        if (PC)
        {
            DisableInput(PC);
        }
        OverlappingPlayerCharacter = nullptr;
        HideInteractPrompt();
    }
}

void ACraftingBuilding::HandleInput()
{
    if (OverlappingPlayerCharacter)
    {
        HideInteractPrompt(); // Hide prompt once interaction starts
        OnInteract(OverlappingPlayerCharacter);
    }
}

void ACraftingBuilding::OnInteract(AActor* Interactor)
{
    AEmberPlayerCharacter* Player = Cast<AEmberPlayerCharacter>(Interactor);
    if (!Player) return;

    APlayerController* PC = Cast<APlayerController>(Player->GetController());
    if (!PC) return;

    UCraftingSystem* CraftingSystem = Player->FindComponentByClass<UCraftingSystem>();
    if (CraftingSystem)
    {
        CraftingSystem->CurrentStation = StationType;
    }

    bool bShouldOpenMainCraftingUI = true;
    const FCraftingRecipeRow* RecipeDataToUse = CachedSelectedRecipeData;

    if (!RecipeDataToUse && !SelectedRecipeRowName.IsNone())
    {
        UCraftingRecipeManager* Manager = GetRecipeManagerFromPlayer(Player);
        if(Manager && Manager->RecipeDataTable)
        {
             RecipeDataToUse = Manager->RecipeDataTable->FindRow<FCraftingRecipeRow>(SelectedRecipeRowName, TEXT("ACraftingBuilding OnInteract"));
             CachedSelectedRecipeData = RecipeDataToUse;
        }
    }

    if (RecipeDataToUse)
    {
        bool bRecipeUsesQualitySystem = (RecipeDataToUse->RequiredMainMaterialCount > 0);
        if (!bRecipeUsesQualitySystem)
        {
            if (CraftingSystem)
            {
                TMap<FGameplayTag, int32> EmptySelectedMainIngredients;
                CraftingSystem->StartCrafting(Player, *RecipeDataToUse, EmptySelectedMainIngredients);
                bShouldOpenMainCraftingUI = false; 
            }
        }
    }

    if (bShouldOpenMainCraftingUI)
    {
        if (MainCraftingUIClass)
        {
            UCraftingWidget* CraftingWidgetInstance = Cast<UCraftingWidget>(CreateWidget(PC, MainCraftingUIClass));
            if (CraftingWidgetInstance)
            {
                UE_LOG(LogTemp, Log, TEXT("ACraftingBuilding: Opening Main Crafting UI for station type: %s"), *UEnum::GetValueAsString(StationType));
                CraftingWidgetInstance->InitializeForStation(StationType, SelectedRecipeRowName);
                CraftingWidgetInstance->AddToViewport();
                
                FInputModeGameAndUI InputModeData;
                InputModeData.SetWidgetToFocus(CraftingWidgetInstance->TakeWidget()); // Set focus to the UI
                InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
                PC->SetInputMode(InputModeData);
                PC->SetShowMouseCursor(true);
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("ACraftingBuilding: MainCraftingUIClass is not set for station type: %s"), *UEnum::GetValueAsString(StationType));
        }
    }
}

void ACraftingBuilding::ShowInteractPrompt()
{
    if (!InteractionPromptWidgetInstance && InteractionPromptWidgetClass)
    {
        APlayerController* PC = OverlappingPlayerCharacter ? Cast<APlayerController>(OverlappingPlayerCharacter->GetController()) : GetWorld()->GetFirstPlayerController();
        if (PC)
        {
            InteractionPromptWidgetInstance = CreateWidget<UUserWidget>(PC, InteractionPromptWidgetClass);
            if (InteractionPromptWidgetInstance)
            {
                InteractionPromptWidgetInstance->AddToViewport();
            }
        }
    }
}

void ACraftingBuilding::HideInteractPrompt()
{
    if (InteractionPromptWidgetInstance)
    {
        InteractionPromptWidgetInstance->RemoveFromViewport();
        InteractionPromptWidgetInstance = nullptr;
    }
}