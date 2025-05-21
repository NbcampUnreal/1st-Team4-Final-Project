#pragma once

#include "CoreMinimal.h"
#include "../GameInfo/GameFlag.h" 
#include "Components/ActorComponent.h"
#include "CraftingSystem.generated.h"

UENUM(BlueprintType)
enum class EStationType : uint8
{
    CraftingTable,
    Furnace,
    CookingPot,
    WeaponTable,
    ClothingTable
};

class AEmberPlayerCharacter;
class UCraftingRecipe; 
class UCraftingRecipeManager;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class EMBER_API UCraftingSystem : public UActorComponent
{
    GENERATED_BODY()

public:
    UCraftingSystem();

protected:
    virtual void BeginPlay() override;

public:
    UFUNCTION(BlueprintCallable, Category = "Crafting")
    void StartCrafting(AEmberPlayerCharacter* Player, const FString& ItemName);

    TMap<FString, int32> AggregateIngredients(AEmberPlayerCharacter* Player);

    void AddItemToInventory(AEmberPlayerCharacter* Player, const FString& ItemName);

    bool CanCraftInCurrentStation(const UCraftingRecipe* Recipe) const;

    TMap<FString, int32> SearchNearChestsIngredients(AEmberPlayerCharacter* Player);

    EItemRarity CalculateCraftingOutcome(const UCraftingRecipe* Recipe, const TMap<FString, int32>& ChosenMaterials, bool bIsWeapon);

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    bool CanActivateCraftingButton(const UCraftingRecipe* Recipe, const TMap<FString, int32>& AggregatedIngredients);

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
    UCraftingRecipeManager* RecipeManager;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
    UAnimMontage* ProcessingAnimation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
    EStationType CurrentStation;
};
