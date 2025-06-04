#pragma once

#include "CoreMinimal.h"
#include "UI/Common/EmberActivatableWidget.h"
#include "Crafting/CraftingRecipeManager.h" 
#include "UI/Crafting/CraftingRecipeListItemData.h"
#include "CraftingRecipeListWidget.generated.h"

class UListView;
class UScrollBox;
class UTextBlock;
class UCraftingListEntryWidget; 
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

	UFUNCTION(BlueprintCallable, Category = "Crafting")
	void SetStationTitle(EStationType InStationType);
    
	UPROPERTY(BlueprintAssignable, Category = "Crafting")
	FOnRecipeRowSelectedInListSignature OnRecipeSelected;

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, Category = "RecipeList", meta = (BindWidgetOptional))
	TObjectPtr<UTextBlock> StationNameText_InList; 

	UPROPERTY(BlueprintReadOnly, Category = "RecipeList", meta = (BindWidget))
	TObjectPtr<UListView> RecipeListView;

	UPROPERTY(BlueprintReadOnly, Category = "RecipeList", meta = (BindWidgetOptional))
	TObjectPtr<UScrollBox> RecipeListScrollBox;

	UFUNCTION()
	void HandleRecipeClicked(UObject* ItemObject);
};