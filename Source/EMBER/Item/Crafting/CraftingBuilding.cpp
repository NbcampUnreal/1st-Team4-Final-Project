#include "Item/Crafting/CraftingBuilding.h"
#include "Item/Managers/InventoryManagerComponent.h"
#include "Player/EmberPlayerCharacter.h"
#include "Crafting/CraftingSystem.h"
#include "Item/ItemTemplate.h" 
#include "Net/UnrealNetwork.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "UI/Crafting/CraftingWidget.h"      
#include "Kismet/GameplayStatics.h"   
#include "GameFramework/PlayerController.h"
#include "Engine/DataTable.h"
#include "Crafting/CraftingRecipeManager.h"


ACraftingBuilding::ACraftingBuilding()
{
    PrimaryActorTick.bCanEverTick = false;
    bReplicates = true;
    SetReplicateMovement(true);

    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    RootComponent = MeshComponent;

    InteractionRange = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionRange"));
    InteractionRange->SetupAttachment(RootComponent);
    InteractionRange->SetSphereRadius(500.0f); 
    InteractionRange->SetCollisionProfileName(TEXT("Trigger")); 
    InteractionRange->SetGenerateOverlapEvents(true);

    OutputInventoryComponent = CreateDefaultSubobject<UInventoryManagerComponent>(TEXT("OutputInventory"));
    if (OutputInventoryComponent)
    {
        OutputInventoryComponent->SetIsReplicated(true);
    }

    StationType = EStationType::CraftingTable;
    ActiveCraftingUI = nullptr;
    CraftingWidgetClass = nullptr;
}

void ACraftingBuilding::BeginPlay()
{
    Super::BeginPlay();
    
    if (InteractionRange)
    {
        InteractionRange->OnComponentBeginOverlap.AddDynamic(this, &ACraftingBuilding::OnInteractionRangeOverlapBegin);
        InteractionRange->OnComponentEndOverlap.AddDynamic(this, &ACraftingBuilding::OnInteractionRangeOverlapEnd);
    }
    
    if (OutputInventoryComponent && HasAuthority())
    {
        UE_LOG(LogTemp, Log, TEXT("ACraftingBuilding '%s': OutputInventoryComponent initialized on Server with %d x %d slots."), 
            *GetName(), 
            OutputInventoryComponent->GetInventorySlotCount().X, 
            OutputInventoryComponent->GetInventorySlotCount().Y
            );
    }
}

void ACraftingBuilding::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(ACraftingBuilding, OutputInventoryComponent); 
}

void ACraftingBuilding::OnInteractionRangeOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    UE_LOG(LogTemp, Log, TEXT("ACraftingBuilding::OnInteractionRangeOverlapBegin - Overlapped Actor: %s, THIS station: %s"), 
        OtherActor ? *OtherActor->GetName() : TEXT("NULL"), 
        this ? *this->GetName() : TEXT("NULL_THIS_STATION"));

    AEmberPlayerCharacter* PlayerCharacter = Cast<AEmberPlayerCharacter>(OtherActor);
    if (PlayerCharacter && PlayerCharacter->IsLocallyControlled())
    {
        UE_LOG(LogTemp, Log, TEXT("ACraftingBuilding: Overlapped with a locally controlled AEmberPlayerCharacter."));
        
        APlayerController* PC = Cast<APlayerController>(PlayerCharacter->GetController());
        if (PC)
        {
            UE_LOG(LogTemp, Log, TEXT("ACraftingBuilding: PlayerController is valid."));
            if (CraftingWidgetClass)
            {
                UE_LOG(LogTemp, Log, TEXT("ACraftingBuilding: CraftingWidgetClass is set."));
                if (!ActiveCraftingUI) 
                {
                    UE_LOG(LogTemp, Log, TEXT("ACraftingBuilding: ActiveCraftingUI is NULL. Creating Crafting UI..."));
                    ActiveCraftingUI = CreateWidget<UCraftingWidget>(PC, CraftingWidgetClass);
                    if (ActiveCraftingUI)
                    {
                        UE_LOG(LogTemp, Log, TEXT("ACraftingBuilding: Calling InitializeForStation with station: %s"), this ? *this->GetName() : TEXT("NULL_THIS_STATION_BEFORE_CALL"));
                        ActiveCraftingUI->InitializeForStation(this, NAME_None); 
                        ActiveCraftingUI->AddToViewport();
                        
                        FInputModeGameAndUI InputModeData;
                        InputModeData.SetWidgetToFocus(ActiveCraftingUI->TakeWidget());
                        InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
                        PC->SetInputMode(InputModeData);
                        PC->SetShowMouseCursor(true);
                        
                        UE_LOG(LogTemp, Log, TEXT("ACraftingBuilding: Crafting UI Created, Initialized, Added to Viewport, and Input Mode Set."));
                    }
                    else
                    {
                        UE_LOG(LogTemp, Error, TEXT("ACraftingBuilding: Failed to create Crafting UI widget from CraftingWidgetClass!"));
                    }
                }
                else
                {
                    UE_LOG(LogTemp, Warning, TEXT("ACraftingBuilding: Crafting UI (ActiveCraftingUI) already exists for this station."));
                }
            }
            else
            {
                UE_LOG(LogTemp, Error, TEXT("ACraftingBuilding: CraftingWidgetClass is NOT set in the Blueprint defaults of %s!"), *this->GetName());
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("ACraftingBuilding: Could not get PlayerController from PlayerCharacter."));
        }
    }
    else if (PlayerCharacter)
    {
        UE_LOG(LogTemp, Log, TEXT("ACraftingBuilding: Overlapped with an AEmberPlayerCharacter, but it's not locally controlled."));
    }
}

void ACraftingBuilding::OnInteractionRangeOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    UE_LOG(LogTemp, Log, TEXT("ACraftingBuilding::OnInteractionRangeOverlapEnd - OtherActor: %s, THIS station: %s"), 
        OtherActor ? *OtherActor->GetName() : TEXT("NULL"),
        this ? *this->GetName() : TEXT("NULL_THIS_STATION"));

    AEmberPlayerCharacter* PlayerCharacter = Cast<AEmberPlayerCharacter>(OtherActor);
    if (PlayerCharacter && PlayerCharacter->IsLocallyControlled()) 
    {
        UE_LOG(LogTemp, Log, TEXT("ACraftingBuilding: Locally controlled PlayerCharacter left interaction range."));
        if (ActiveCraftingUI)
        {
            UE_LOG(LogTemp, Log, TEXT("ACraftingBuilding: Removing ActiveCraftingUI."));
            ActiveCraftingUI->RemoveFromParent();
            ActiveCraftingUI = nullptr;

            APlayerController* PC = Cast<APlayerController>(PlayerCharacter->GetController());
            if (PC)
            {
                PC->SetInputMode(FInputModeGameOnly());
                PC->SetShowMouseCursor(false);
                UE_LOG(LogTemp, Log, TEXT("ACraftingBuilding: Input Mode set back to GameOnly."));
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("ACraftingBuilding: Player left range, but ActiveCraftingUI was already NULL or not set."));
        }
    }
}

void ACraftingBuilding::Server_ExecuteCrafting_Implementation(FName RecipeRowName, const TArray<FGameplayTag>& SelectedMainIngredientTags, const TArray<int32>& SelectedMainIngredientQuantities, AEmberPlayerCharacter* RequestingPlayer)
{
    if (!HasAuthority()) return;
    if (!RequestingPlayer) 
    {
        UE_LOG(LogTemp, Error, TEXT("ACraftingBuilding::Server_ExecuteCrafting - RequestingPlayer is NULL."));
        return;
    }

    UCraftingSystem* CraftingSystem = RequestingPlayer->FindComponentByClass<UCraftingSystem>();
    if (!CraftingSystem || !CraftingSystem->RecipeManager || !CraftingSystem->RecipeManager->RecipeDataTable)
    {
        UE_LOG(LogTemp, Error, TEXT("ACraftingBuilding::Server_ExecuteCrafting - CraftingSystem, RecipeManager, or RecipeDataTable is NULL."));
        return;
    }

    const FCraftingRecipeRow* RecipeDataPtr = CraftingSystem->RecipeManager->RecipeDataTable->FindRow<FCraftingRecipeRow>(RecipeRowName, TEXT("Server_ExecuteCrafting"));
    if (!RecipeDataPtr)
    {
        UE_LOG(LogTemp, Error, TEXT("ACraftingBuilding::Server_ExecuteCrafting - RecipeRowName '%s' not found in DataTable on Server."), *RecipeRowName.ToString());
        return;
    }
    const FCraftingRecipeRow& RecipeData = *RecipeDataPtr;

    TMap<FGameplayTag, int32> SelectedMainIngredientsMap;
    for (int32 i = 0; i < SelectedMainIngredientTags.Num(); ++i)
    {
        if (SelectedMainIngredientQuantities.IsValidIndex(i))
        {
            SelectedMainIngredientsMap.Add(SelectedMainIngredientTags[i], SelectedMainIngredientQuantities[i]);
        }
    }

    UE_LOG(LogTemp, Log, TEXT("ACraftingBuilding::Server_ExecuteCrafting - Server received craft request for: %s by Player: %s"), *RecipeData.RecipeDisplayName.ToString(), *RequestingPlayer->GetName());

    if (!CraftingSystem->CanCraftRecipeAtStation(RecipeData, StationType))
    {
        UE_LOG(LogTemp, Warning, TEXT("ACraftingBuilding::Server_ExecuteCrafting - Server: Cannot craft recipe '%s' at this station type '%s'. Recipe requires '%s'."), 
            *RecipeRowName.ToString(), *UEnum::GetValueAsString(StationType), *UEnum::GetValueAsString(RecipeData.CraftingStation));
        return;
    }

    if (!CraftingSystem->HasRequiredMaterials(RequestingPlayer, RecipeData, SelectedMainIngredientsMap))
    {
        UE_LOG(LogTemp, Warning, TEXT("ACraftingBuilding::Server_ExecuteCrafting - Server: Missing required materials for recipe %s."), *RecipeRowName.ToString());
        return;
    }

    EItemRarity FinalRarity = EItemRarity::Common;
    if (RecipeData.RequiredMainMaterialCount > 0)
    {
        FinalRarity = CraftingSystem->EvaluateItemRarity(RecipeData, SelectedMainIngredientsMap);
    }

    if (!CraftingSystem->ConsumeMaterials(RequestingPlayer, RecipeData, SelectedMainIngredientsMap))
    {
        UE_LOG(LogTemp, Warning, TEXT("ACraftingBuilding::Server_ExecuteCrafting - Server: ConsumeMaterials FAILED for recipe %s (Note: ConsumeMaterials is a stub)."), *RecipeRowName.ToString());
        return;
    }
    UE_LOG(LogTemp, Log, TEXT("ACraftingBuilding::Server_ExecuteCrafting - Server: Materials consumed (stub) for recipe %s."), *RecipeRowName.ToString());
    
    if (!RecipeData.ItemTemplateClass)
    {
        UE_LOG(LogTemp, Error, TEXT("ACraftingBuilding::Server_ExecuteCrafting - Server: RecipeData.ItemTemplateClass is NULL for recipe %s."), *RecipeRowName.ToString());
        return;
    }
    
    if (OutputInventoryComponent)
    {
        UE_LOG(LogTemp, Log, TEXT("ACraftingBuilding::Server_ExecuteCrafting - Server: Attempting to add item to OutputInventory. Class: %s, Rarity: %s, Count: 1"), 
            *RecipeData.ItemTemplateClass->GetName(), 
            *UEnum::GetValueAsString(FinalRarity)
            );
        
        int32 AddedAmount = OutputInventoryComponent->TryAddItemByRarity(RecipeData.ItemTemplateClass, FinalRarity, 1); 
        
        if (AddedAmount > 0)
        {
            UE_LOG(LogTemp, Log, TEXT("ACraftingBuilding::Server_ExecuteCrafting - Server: Item successfully ADDED (%d) to OutputInventoryComponent. Current items: %d."), AddedAmount, OutputInventoryComponent->GetAllEntries().Num());
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("ACraftingBuilding::Server_ExecuteCrafting - Server: FAILED to add item to OutputInventoryComponent. AddedAmount: %d. Current items: %d"), AddedAmount, OutputInventoryComponent->GetAllEntries().Num());
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("ACraftingBuilding::Server_ExecuteCrafting - Server: OutputInventoryComponent is NULL on this CraftingBuilding: %s."), *GetName());
    }
}