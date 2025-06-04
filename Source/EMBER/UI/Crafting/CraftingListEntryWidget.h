#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "UI/Crafting/CraftingRecipeListItemData.h"

#include "CraftingListEntryWidget.generated.h"

class UTextBlock;
class UBorder;
class UImage;
class UItemTemplate;
class UTexture2D;
struct FCraftingRecipeRow;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCraftingListEntryClicked, UCraftingRecipeListItemData*, ListItemData);

UCLASS()
class EMBER_API UCraftingListEntryWidget : public UUserWidget, public IUserObjectListEntry
{
    GENERATED_BODY()

public:
    UCraftingListEntryWidget(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(BlueprintReadOnly, Category="CraftingListEntry", meta = (BindWidget))
    TObjectPtr<UTextBlock> RecipeNameText;

    UPROPERTY(BlueprintReadOnly, Category="CraftingListEntry", meta = (BindWidget))
    TObjectPtr<UImage> RecipeIcon;
    
    UPROPERTY(BlueprintReadOnly, Category="CraftingListEntry", meta = (BindWidgetOptional))
    TObjectPtr<UBorder> SelectionHighlightBorder;

    UPROPERTY(BlueprintAssignable, Category = "CraftingListEntry")
    FOnCraftingListEntryClicked OnThisEntryClicked;

    UFUNCTION(BlueprintImplementableEvent, Category = "ListEntry", meta = (DisplayName = "OnUpdateDisplay_BP"))
    void K2_OnUpdateDisplay(const FText& InRecipeName, UTexture2D* InIconTexture, bool bIsCraftable, bool bIsSelected);
    
    UFUNCTION(BlueprintCallable, Category = "CraftingListEntry")
    void HandleClick();

    UFUNCTION(BlueprintPure, Category = "CraftingListEntry")
    bool CalculateCraftableStatusInternal(UCraftingRecipeListItemData* InListItemData) const;

    UFUNCTION(BlueprintPure, Category = "CraftingListEntry")
    UTexture2D* GetIconTextureFromRecipeDataInternal(UCraftingRecipeListItemData* InListItemData) const;
    
    UFUNCTION(BlueprintCallable, Category = "CraftingListEntry")
    void SetCurrentListItemData(UCraftingRecipeListItemData* InData);


protected:
    virtual void NativeConstruct() override;

    UPROPERTY(BlueprintReadOnly, Category="CraftingListEntry")
    TObjectPtr<UCraftingRecipeListItemData> CurrentListItemDataInternal;
};