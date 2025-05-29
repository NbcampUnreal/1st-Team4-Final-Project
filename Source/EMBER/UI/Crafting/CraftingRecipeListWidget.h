#pragma once

#include "CoreMinimal.h"
#include "UI/Common/EmberActivatableWidget.h"
#include "Crafting/CraftingRecipeManager.h" 
#include "UI/Crafting/CraftingRecipeListItemData.h" 

#include "CraftingRecipeListWidget.generated.h" 

class UListView;
struct FCraftingRecipeRow; 

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRecipeRowSelectedInListSignature, const FCraftingRecipeRow&, SelectedRecipeRow);

UCLASS()
class EMBER_API UCraftingRecipeListWidget : public UEmberActivatableWidget
{
	GENERATED_BODY()

public:
	UCraftingRecipeListWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintCallable, Category = "Crafting")
	void SetRecipeList(const TArray<FCraftingRecipeRow>& Recipes);
    
	UPROPERTY(BlueprintAssignable, Category = "Crafting")
	FOnRecipeRowSelectedInListSignature OnRecipeSelected;

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UListView* RecipeListView;

	UFUNCTION()
	void HandleRecipeClicked(UObject* ItemObject); 
};