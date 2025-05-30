#include "UI/Crafting/CraftingListEntryWidget.h"
#include "Components/TextBlock.h"
#include "Components/Border.h"
#include "UI/Crafting/CraftingRecipeListItemData.h" 
#include "Crafting/CraftingRecipeManager.h" 
#include "Crafting/CraftingSystem.h" 
#include "Player/EmberPlayerCharacter.h" 

UCraftingListEntryWidget::UCraftingListEntryWidget(const FObjectInitializer& ObjectInitializer) 
	: Super(ObjectInitializer)
{
	CurrentListItemData = nullptr;
	SelectionHighlightBorder = nullptr; 
}

void UCraftingListEntryWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UCraftingListEntryWidget::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	CurrentListItemData = Cast<UCraftingRecipeListItemData>(ListItemObject);

	if (RecipeNameText && CurrentListItemData)
	{
		RecipeNameText->SetText(CurrentListItemData->RecipeData.RecipeDisplayName);
	}
	else if (RecipeNameText)
	{
		RecipeNameText->SetText(FText::FromString(TEXT("...")));
	}

	AEmberPlayerCharacter* Player = Cast<AEmberPlayerCharacter>(GetOwningPlayerPawn());
	UCraftingSystem* CraftingSystem = Player ? Player->FindComponentByClass<UCraftingSystem>() : nullptr;
	bool bCanCraft = false;
	if (CraftingSystem && CurrentListItemData && Player)
	{
		TMap<FGameplayTag, int32> EmptySelectedMainIngredients;
		bCanCraft = CraftingSystem->HasRequiredMaterials(Player, CurrentListItemData->RecipeData, EmptySelectedMainIngredients);
	}
	K2_OnRecipeStatusUpdated(bCanCraft);
}

void UCraftingListEntryWidget::HandleClick()
{
	if (CurrentListItemData)
	{
		OnThisEntryClicked.Broadcast(CurrentListItemData);
	}
}