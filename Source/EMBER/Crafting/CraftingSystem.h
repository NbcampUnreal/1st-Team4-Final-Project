#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CraftingRecipeManager.h"
#include "Player/EmberPlayerCharacter.h"
#include "../GameInfo/GameFlag.h"
#include "CraftingSystem.generated.h"

UENUM(BlueprintType)
enum class EStationType : uint8
{
    CraftingTable UMETA(DisplayName = "Crafting Table"),
    Furnace       UMETA(DisplayName = "Furnace"),
    CookingPot    UMETA(DisplayName = "Cooking Pot"),
    WeaponTable   UMETA(DisplayName = "Weapon Crafting Table"),
    ClothingTable UMETA(DisplayName = "Clothing Crafting Table")
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class EMBER_API UCraftingSystem : public UActorComponent
{
    GENERATED_BODY()
public:
    UCraftingSystem();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
    UCraftingRecipeManager* RecipeManager;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
    UAnimMontage* ProcessingAnimation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
    EStationType CurrentStation;

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    void StartCrafting(AEmberPlayerCharacter* Player, const FString& ItemName);

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    TMap<FString, int32> AggregateIngredients(AEmberPlayerCharacter* Player);

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    EItemRarity CalculateCraftingOutcome(const class UCraftingRecipe* Recipe, const TMap<FString, int32>& ChosenMaterials, bool bIsWeapon);
protected:
    virtual void BeginPlay() override;
    void AddItemToInventory(AEmberPlayerCharacter* Player, const FString& ItemName);
private:
    bool CanCraftInCurrentStation(const UCraftingRecipe* Recipe) const;
    TMap<FString, int32> SearchNearChestsIngredients(AEmberPlayerCharacter* Player);
};
