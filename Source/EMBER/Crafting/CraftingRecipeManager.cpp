#include "CraftingRecipeManager.h"
#include "CraftingRecipe.h"
#include "GameplayTagContainer.h"

UCraftingRecipe* UCraftingRecipeManager::GetRecipeByName(const FString& Name)
{
	UCraftingRecipe* Recipe = NewObject<UCraftingRecipe>(this);

	Recipe->RecipeTag = FGameplayTag::RequestGameplayTag(FName(*Name));
    
	Recipe->CraftingTime = 5.0f;
	Recipe->EffectTag = FGameplayTag::RequestGameplayTag(FName("Effect.Default"));
    
	Recipe->MainMaterialType = FGameplayTag::RequestGameplayTag(FName("Material.Iron"));
	Recipe->MainMaterialRequired = 3;
    
	Recipe->Ingredients.Add("Material.Iron", 3);
    
	return Recipe;
}
