#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "UI/Crafting/CraftingRecipeListItemData.h"

#include "CraftingListEntryWidget.generated.h"

class UTextBlock;
class UBorder;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCraftingListEntryClicked, UCraftingRecipeListItemData*, ListItemData);

UCLASS()
class EMBER_API UCraftingListEntryWidget : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UCraftingListEntryWidget(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UTextBlock> RecipeNameText;
    
	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	TObjectPtr<UBorder> SelectionHighlightBorder;

	UPROPERTY(BlueprintAssignable, Category = "ListEntry")
	FOnCraftingListEntryClicked OnThisEntryClicked;

protected:
	virtual void NativeConstruct() override;
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
    
	UFUNCTION(BlueprintImplementableEvent, Category = "ListEntry", meta = (DisplayName = "OnRecipeStatusUpdated_BP"))
	void K2_OnRecipeStatusUpdated(bool bIsCraftable);

	UFUNCTION(BlueprintCallable)
	void HandleClick();

	UPROPERTY(BlueprintReadOnly, Category="ListEntry")
	TObjectPtr<UCraftingRecipeListItemData> CurrentListItemData;
};