#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "CraftingWidget.h"
#include "GameFlag.h"
#include "../Common/EmberActivatableWidget.h"
#include "CraftingResultWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnResultCraftActionRequestedSignature);

UCLASS()
class EMBER_API UCraftingResultWidget : public UEmberActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Crafting")
	void UpdateRarityChances(const TMap<EItemRarity, float>& RarityChances);

	UFUNCTION(BlueprintCallable, Category = "Crafting")
	void RefreshRarityPreview();

	UFUNCTION(BlueprintCallable, Category = "Crafting")
	void SetTargetRecipe(class UCraftingRecipeData* InRecipe);

	UFUNCTION(BlueprintCallable, Category = "Crafting")
	void SetProvidedIngredients(const TMap<FGameplayTag, int32>& InIngredients);

	UPROPERTY(BlueprintAssignable, Category = "Crafting")
	FOnResultCraftActionRequestedSignature OnCraftActionRequested;

protected:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnCraftButtonClicked();

protected:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ResultText;

	UPROPERTY(meta = (BindWidget))
	class UButton* CraftButton;

private:
	UCraftingRecipeData* TargetRecipe;
	TMap<FGameplayTag, int32> ProvidedIngredients;
};