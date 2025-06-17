#include "Item/Crafting/CraftingBuilding.h"
#include "Item/Managers/InventoryManagerComponent.h"
#include "Player/EmberPlayerCharacter.h"
#include "Crafting/CraftingSystem.h"
#include "Item/ItemInstance.h"
#include "Item/ItemTemplate.h" 
#include "Net/UnrealNetwork.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "UI/Crafting/CraftingWidget.h"      
#include "Kismet/GameplayStatics.h"   
#include "GameFramework/PlayerController.h"
#include "Engine/DataTable.h"
#include "Crafting/CraftingRecipeManager.h"
#include "UI/Data/EmberItemData.h"


ACraftingBuilding::ACraftingBuilding()
{
    PrimaryActorTick.bCanEverTick = false;
    bReplicates = true;
    SetReplicateMovement(true);

    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    RootComponent = MeshComponent;

    InteractionRange = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionRange"));
    InteractionRange->SetupAttachment(RootComponent);
    InteractionRange->SetSphereRadius(200.0f); 
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
}

void ACraftingBuilding::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(ACraftingBuilding, OutputInventoryComponent); 
}

void ACraftingBuilding::OnInteractionRangeOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    AEmberPlayerCharacter* PlayerCharacter = Cast<AEmberPlayerCharacter>(OtherActor);
    if (PlayerCharacter && PlayerCharacter->IsLocallyControlled())
    {
        APlayerController* PC = Cast<APlayerController>(PlayerCharacter->GetController());
        if (PC && CraftingWidgetClass && !ActiveCraftingUI)
        {
            ActiveCraftingUI = CreateWidget<UCraftingWidget>(PC, CraftingWidgetClass);
            if (ActiveCraftingUI)
            {
                ActiveCraftingUI->InitializeForStation(this, NAME_None); 
                ActiveCraftingUI->AddToViewport();
                
                FInputModeGameAndUI InputModeData;
                InputModeData.SetWidgetToFocus(ActiveCraftingUI->TakeWidget());
                InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
                PC->SetInputMode(InputModeData);
                PC->SetShowMouseCursor(true);
            }
        }
    }
}

void ACraftingBuilding::OnInteractionRangeOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    AEmberPlayerCharacter* PlayerCharacter = Cast<AEmberPlayerCharacter>(OtherActor);
    if (PlayerCharacter && PlayerCharacter->IsLocallyControlled()) 
    {
        if (ActiveCraftingUI)
        {
            ActiveCraftingUI->RemoveFromParent();
            ActiveCraftingUI = nullptr;

            APlayerController* PC = Cast<APlayerController>(PlayerCharacter->GetController());
            if (PC)
            {
                PC->SetInputMode(FInputModeGameOnly());
                PC->SetShowMouseCursor(false);
            }
        }
    }
}

void ACraftingBuilding::Server_ExecuteCrafting_Implementation(FName RecipeRowName, const TArray<FGameplayTag>& SelectedMainIngredientTags, const TArray<int32>& SelectedMainIngredientQuantities, AEmberPlayerCharacter* RequestingPlayer)
{
    if (!HasAuthority() || !RequestingPlayer) return;

    UCraftingSystem* CraftingSystem = RequestingPlayer->FindComponentByClass<UCraftingSystem>();
    if (!CraftingSystem || !CraftingSystem->RecipeManager || !CraftingSystem->RecipeManager->RecipeDataTable) return;

    const FCraftingRecipeRow* RecipeDataPtr = CraftingSystem->RecipeManager->RecipeDataTable->FindRow<FCraftingRecipeRow>(RecipeRowName, TEXT("Server_ExecuteCrafting"));
    if (!RecipeDataPtr) return;

    const FCraftingRecipeRow& RecipeData = *RecipeDataPtr;
    TMap<FGameplayTag, int32> SelectedMainIngredientsMap;
    for (int32 i = 0; i < SelectedMainIngredientTags.Num(); ++i)
    {
        if (SelectedMainIngredientQuantities.IsValidIndex(i))
        {
            SelectedMainIngredientsMap.Add(SelectedMainIngredientTags[i], SelectedMainIngredientQuantities[i]);
        }
    }

    if (CraftingSystem->CanCraftRecipeAtStation(RecipeData, this->GetStationTag()) && CraftingSystem->HasRequiredMaterials(RequestingPlayer, RecipeData, SelectedMainIngredientsMap))
    {
        CraftingSystem->ConsumeMaterials_Server(RequestingPlayer, RecipeData, SelectedMainIngredientsMap);
        
        EItemRarity FinalRarity = CraftingSystem->EvaluateItemRarity(RecipeData, SelectedMainIngredientsMap);
        TSubclassOf<UItemTemplate> ResultItemTemplateClass = RecipeData.ItemTemplateClass;

        if (ResultItemTemplateClass)
        {
            UInventoryManagerComponent* PlayerInventory = RequestingPlayer->FindComponentByClass<UInventoryManagerComponent>();
            if (PlayerInventory)
            {
                const int32 AddedAmount = PlayerInventory->TryAddItemByRarity(ResultItemTemplateClass, FinalRarity, 1);
                if (AddedAmount > 0)
                {
                    UE_LOG(LogTemp, Log, TEXT("[SERVER] Crafting Success! Added %s to player inventory."), *ResultItemTemplateClass->GetName());
                }
                else
                {
                    UE_LOG(LogTemp, Warning, TEXT("[SERVER] Crafting Failed! Player inventory might be full."));
                }
            }
        }
    }
    else
    {
         UE_LOG(LogTemp, Warning, TEXT("[SERVER] ACraftingBuilding: Final server-side check failed for recipe %s."), *RecipeRowName.ToString());
    }
}