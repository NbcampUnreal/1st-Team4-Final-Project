#include "Item/Crafting/CraftingBuilding.h"
#include "Item/Managers/InventoryManagerComponent.h"
#include "Player/EmberPlayerCharacter.h"
#include "Crafting/CraftingSystem.h"
#include "Item/ItemTemplate.h" 
#include "Net/UnrealNetwork.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/PlayerController.h"
#include "Engine/DataTable.h"
#include "Crafting/CraftingRecipeManager.h"


ACraftingBuilding::ACraftingBuilding()
{
    PrimaryActorTick.bCanEverTick = false;
    bReplicates = true;

    OutputInventoryComponent = CreateDefaultSubobject<UInventoryManagerComponent>(TEXT("OutputInventory"));
    if (OutputInventoryComponent)
    {
        OutputInventoryComponent->SetIsReplicated(true);
    }

    StationType = EStationType::CraftingTable;
}

void ACraftingBuilding::BeginPlay()
{
    Super::BeginPlay();
}

void ACraftingBuilding::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(ACraftingBuilding, OutputInventoryComponent); 
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