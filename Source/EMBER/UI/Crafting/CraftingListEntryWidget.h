#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "UI/Crafting/CraftingRecipeListItemData.h"

#include "CraftingListEntryWidget.generated.h"

class UTextBlock;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCraftingListEntryClicked, UCraftingRecipeListItemData*, ListItemData);

UCLASS()
class EMBER_API UCraftingListEntryWidget : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UCraftingListEntryWidget(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* RecipeNameText;

	UPROPERTY(BlueprintAssignable, Category = "ListEntry")
	FOnCraftingListEntryClicked OnThisEntryClicked;

protected:
	virtual void NativeConstruct() override;
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;

	UFUNCTION(BlueprintCallable)
	void HandleClick();

private:
	UPROPERTY()
	TObjectPtr<UCraftingRecipeListItemData> CurrentListItemData;
};