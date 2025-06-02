#include "UI/Crafting/CraftingListEntryWidget.h"

#include "ItemTemplate.h"
#include "Components/TextBlock.h"
#include "Components/Border.h"
#include "Components/Image.h"
#include "UI/Crafting/CraftingRecipeListItemData.h" 
#include "Crafting/CraftingRecipeManager.h" 
#include "Crafting/CraftingSystem.h" 
#include "Player/EmberPlayerCharacter.h" 
#include "UI/Data/EmberItemData.h"

UCraftingListEntryWidget::UCraftingListEntryWidget(const FObjectInitializer& ObjectInitializer) 
	: Super(ObjectInitializer)
{
	CurrentListItemData = nullptr;
	SelectionHighlightBorder = nullptr; 
}

PRAGMA_DISABLE_OPTIMIZATION
void UCraftingListEntryWidget::InitializeUI(TSubclassOf<UItemTemplate> ItemTemplateClass)
{
	int32 ItemTemplateID = UEmberItemData::Get().FindItemTemplateIDByClass(ItemTemplateClass);
	const UItemTemplate& ItemTemplate = UEmberItemData::Get().FindItemTemplateByID(ItemTemplateID);
	
	RecipeNameText->SetText(ItemTemplate.DisplayName);
	// TODO : 아이콘 이미지 수정 
	RecipeIcon->SetBrushFromTexture(ItemTemplate.IconTexture);
}
PRAGMA_ENABLE_OPTIMIZATION

void UCraftingListEntryWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UCraftingListEntryWidget::NativeOnListItemObjectSet(UObject* ListItemObject)
{
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