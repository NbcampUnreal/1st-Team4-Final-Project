#include "CraftingSystem.h"
#include "Engine/Engine.h"
#include "CraftingRecipe.h"
#include "Player/EmberPlayerCharacter.h" 

UCraftingSystem::UCraftingSystem()
{
    Recipes = TArray<UCraftingRecipe*>();
    ProcessingAnimation = nullptr; 
}

void UCraftingSystem::BeginPlay()
{
    Super::BeginPlay();
}

void UCraftingSystem::StartCrafting(AEmberPlayerCharacter* Player, const FString& ItemName)
{
    UCraftingRecipe* SelectedRecipe = GetRecipeByName(ItemName);
    if (!SelectedRecipe)
    {
        UE_LOG(LogTemp, Warning, TEXT("레시피 '%s'를 찾지 못했습니다."), *ItemName);
        return;
    }

    TMap<FString, int32> AvailableIngredients = AggregateIngredients(Player);

    if (ProcessingAnimation)
    {
    }

    AddItemToInventory(Player, ItemName);
    UE_LOG(LogTemp, Log, TEXT("'%s' 제작 완료!"), *ItemName);
}

TMap<FString, int32> UCraftingSystem::AggregateIngredients(AEmberPlayerCharacter* Player)
{
    TMap<FString, int32> IngredientsFromInventory;
    TMap<FString, int32> IngredientsFromChests = SearchNearChestsIngredients(Player);

    for (auto& Pair : IngredientsFromChests)
    {
        int32* ExistingQuantity = IngredientsFromInventory.Find(Pair.Key);
        if (ExistingQuantity)
        {
            *ExistingQuantity += Pair.Value;
        }
        else
        {
            IngredientsFromInventory.Add(Pair.Key, Pair.Value);
        }
    }
    return IngredientsFromInventory;
}

void UCraftingSystem::AddItemToInventory(AEmberPlayerCharacter* Player, const FString& ItemName)
{
}

TMap<FString, int32> UCraftingSystem::SearchNearChestsIngredients(AEmberPlayerCharacter* Player)
{
    TMap<FString, int32> ChestIngredients;
    return ChestIngredients;
}

UCraftingRecipe* UCraftingSystem::GetRecipeByName(const FString& RecipeName) const
{
    for (UCraftingRecipe* Recipe : Recipes)
    {
        if (Recipe && Recipe->ItemName.Equals(RecipeName))
        {
            return Recipe;
        }
    }
    return nullptr;
}
