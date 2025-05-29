#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Engine/DataTable.h"
#include "CraftingRecipeManager.generated.h"

UENUM(BlueprintType)
enum class EStationType : uint8
{
    None,
    CraftingTable,
    Furnace,
    CookingPot,
    WeaponTable,
    ClothingTable,
    Campfire
};

USTRUCT(BlueprintType)
struct FCraftingRecipeRow : public FTableRowBase
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText RecipeDisplayName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 OutputItemTemplateID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FGameplayTag, int32> Ingredients;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTagContainer AllowedMainMaterialTags;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 RequiredMainMaterialCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CraftingTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bCraftableByCharacter;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EStationType CraftingStation;

    FCraftingRecipeRow()
        : OutputItemTemplateID(0)
        , RequiredMainMaterialCount(0)
        , CraftingTime(0.f)
        , bCraftableByCharacter(false)
        , CraftingStation(EStationType::None)
    {}
};

UCLASS(BlueprintType)
class EMBER_API UCraftingRecipeManager : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Crafting")
    UDataTable* RecipeDataTable;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Data")
    TMap<int32, FGameplayTag> ItemIDToMaterialTagMap;

    const FCraftingRecipeRow* GetRecipeRowByOutputItemID(int32 TemplateID) const;
    
    void GetAllRecipeRows(TArray<FCraftingRecipeRow*>& OutRows) const;

    UFUNCTION(BlueprintCallable, Category = "Item Data")
    FGameplayTag GetMaterialTagForItem(int32 ItemTemplateID) const;
};