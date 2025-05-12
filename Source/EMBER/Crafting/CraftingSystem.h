#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CraftingRecipe.h" 
#include "Player/EmberPlayerCharacter.h"  
#include "CraftingSystem.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class EMBER_API UCraftingSystem : public UActorComponent
{
	GENERATED_BODY()

public:
	UCraftingSystem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
	TArray<UCraftingRecipe*> Recipes;

	UFUNCTION(BlueprintCallable, Category = "Crafting")
	void StartCrafting(AEmberPlayerCharacter* Player, const FString& ItemName);

	UFUNCTION(BlueprintCallable, Category = "Crafting")
	TMap<FString, int32> AggregateIngredients(AEmberPlayerCharacter* Player);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
	UAnimMontage* ProcessingAnimation;

	void AddItemToInventory(AEmberPlayerCharacter* Player, const FString& ItemName);

	virtual void BeginPlay() override;

private:
	UCraftingRecipe* GetRecipeByName(const FString& RecipeName) const;

	TMap<FString, int32> SearchNearChestsIngredients(AEmberPlayerCharacter* Player);
};
