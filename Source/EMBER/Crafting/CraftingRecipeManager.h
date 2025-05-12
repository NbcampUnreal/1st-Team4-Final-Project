#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CraftingRecipe.h" 
#include "CraftingRecipeManager.generated.h"

UCLASS(BlueprintType)
class EMBER_API UCraftingRecipeManager : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite, Category = "Crafting")
	TArray<UCraftingRecipe*> Recipes;
    
	UFUNCTION(BlueprintCallable, Category = "Crafting")
	UCraftingRecipe* GetRecipeByName(const FString& RecipeName) const;
};
