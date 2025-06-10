#include "UI/Crafting/CraftingWidget.h"
#include "UI/Crafting/CraftingRecipeListWidget.h"
#include "UI/Crafting/CraftingIngredientWidget.h"
#include "UI/Crafting/CraftingResultWidget.h"
#include "UI/Crafting/CraftingMainMaterialWidget.h"
#include "UI/Crafting/CraftingOutputBoxWidget.h"
#include "Crafting/CraftingSystem.h"
#include "Crafting/CraftingRecipeManager.h"
#include "Player/EmberPlayerCharacter.h"
#include "Item/Crafting/CraftingBuilding.h"
#include "Item/ItemInstance.h"
#include "Item/ItemTemplate.h"
#include "UI/Data/EmberItemData.h"
#include "Kismet/GameplayStatics.h"
#include "Components/WidgetSwitcher.h"
#include "Components/PanelWidget.h"
#include "Components/Border.h"

UCraftingWidget::UCraftingWidget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , CurrentStationTypeForUI(EStationType::None)
    , SelectedRecipeIndex(-1)
    , CraftAmount(1)
    , SelectedRecipeName(NAME_None)
{
    CurrentStationActorRef = nullptr;
    RecipeListWidget = nullptr;
    CenterContentSwitcher = nullptr;
    GeneralRecipeIngredientsWidget = nullptr;
    MainMaterialSelectorWidget = nullptr;
    SelectedRecipeDisplayWidget = nullptr;
    CraftingOutputBoxWidget = nullptr;
    PlayerInventoryDisplayWidget = nullptr;
}

void UCraftingWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (MainMaterialSelectorWidget)
    {
        MainMaterialSelectorWidget->OnSelectionChanged.RemoveAll(this);
        MainMaterialSelectorWidget->OnSelectionChanged.AddDynamic(this, &UCraftingWidget::HandleMainMaterialSelectionChanged);
    }

    if (RecipeListWidget)
    {
        RecipeListWidget->OnRecipeListItemSelected.RemoveAll(this);
        RecipeListWidget->OnRecipeListItemSelected.AddDynamic(this, &UCraftingWidget::HandleRecipeSelectedFromList);
    }
}

void UCraftingWidget::NativeDestruct()
{
    Super::NativeDestruct();
}

FReply UCraftingWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
    const FKey Key = InKeyEvent.GetKey();
    if (Key == EKeys::W)        { UpdateSelectedRecipe(-1); return FReply::Handled(); }
    else if (Key == EKeys::S)   { UpdateSelectedRecipe(1);  return FReply::Handled(); }
    else if (Key == EKeys::E)   { AttemptCraftCurrentRecipe(); return FReply::Handled(); }
    else if (Key == EKeys::A)   { AdjustCraftAmount(-1); return FReply::Handled(); }
    else if (Key == EKeys::D)   { AdjustCraftAmount(1);  return FReply::Handled(); }

    return Super::NativeOnKeyDown(InGeometry, InKeyEvent);
}

void UCraftingWidget::InitializeForStation(ACraftingBuilding* InStationActor, FName OptionalInitialRecipeRowName)
{
    CurrentStationActorRef = InStationActor;
    
    if (AEmberPlayerCharacter* Player = Cast<AEmberPlayerCharacter>(GetOwningPlayerPawn()))
    {
        if(UCraftingSystem* CraftingSystem = Player->FindComponentByClass<UCraftingSystem>())
        {
            CurrentStationTypeForUI = InStationActor ? InStationActor->StationType : EStationType::None;
            CraftingSystem->CurrentStationForSystem = CurrentStationTypeForUI;
        }
    }

    SelectedRecipeIndex = -1;
    SelectedRecipeName = NAME_None;
    PopulateActiveRecipeList();

    if (!OptionalInitialRecipeRowName.IsNone())
    {
        for (int32 i = 0; i < ActiveRecipeList.Num(); ++i)
        {
            if (ActiveRecipeList[i].RecipeRowName == OptionalInitialRecipeRowName)
            {
                SelectedRecipeIndex = i;
                SelectedRecipeName = OptionalInitialRecipeRowName;
                break;
            }
        }
    }

    if (ActiveRecipeList.Num() > 0 && SelectedRecipeIndex == -1)
    {
        SelectedRecipeIndex = 0;
        SelectedRecipeName = ActiveRecipeList[0].RecipeRowName;
    }

    ClearSelectedMainIngredients();
    RefreshAll();
}

void UCraftingWidget::PopulateActiveRecipeList()
{
    ActiveRecipeList.Empty();

    AEmberPlayerCharacter* Player = Cast<AEmberPlayerCharacter>(GetOwningPlayerPawn());
    if (!Player) return;
    UCraftingSystem* Sys = Player->FindComponentByClass<UCraftingSystem>();
    if (!Sys || !Sys->RecipeManager || !Sys->RecipeManager->RecipeDataTable) return;
    
    UDataTable* DT = Sys->RecipeManager->RecipeDataTable;
    for (const FName& RowName : DT->GetRowNames())
    {
        if (FCraftingRecipeRow* RowPtr = DT->FindRow<FCraftingRecipeRow>(RowName, TEXT("CraftingWidget")))
        {
            bool bMatch = (RowPtr->CraftingStation == CurrentStationTypeForUI) || (RowPtr->bCraftableByCharacter && CurrentStationTypeForUI == EStationType::None);
            if (bMatch)
            {
                ActiveRecipeList.Add(FNamedCraftingRecipe{ RowName, *RowPtr });
            }
        }
    }
}

void UCraftingWidget::ClearSelectedMainIngredients()
{
    CurrentSelectedMainIngredients.Empty();
    if (MainMaterialSelectorWidget)
    {
        MainMaterialSelectorWidget->ClearStagedMaterials();
    }
}

void UCraftingWidget::UpdateSelectedRecipe(int32 Direction)
{
    if (ActiveRecipeList.Num() == 0)
    {
        SelectedRecipeIndex = -1;
        SelectedRecipeName = NAME_None;
    }
    else
    {
        SelectedRecipeIndex = (SelectedRecipeIndex + Direction + ActiveRecipeList.Num()) % ActiveRecipeList.Num();
        SelectedRecipeName = ActiveRecipeList.IsValidIndex(SelectedRecipeIndex) ? ActiveRecipeList[SelectedRecipeIndex].RecipeRowName : NAME_None;
    }
    ClearSelectedMainIngredients();
    RefreshAll();
}

void UCraftingWidget::AdjustCraftAmount(int32 Delta)
{
    CraftAmount = FMath::Clamp(CraftAmount + Delta, 1, 99);
    RefreshAll();
}

void UCraftingWidget::RefreshAll()
{
    const FCraftingRecipeRow* SelectedRecipeDataPtr = nullptr;
    if (ActiveRecipeList.IsValidIndex(SelectedRecipeIndex))
    {
        SelectedRecipeDataPtr = &ActiveRecipeList[SelectedRecipeIndex].RecipeData;
    }

    if (RecipeListWidget)
    {
        RecipeListWidget->SetRecipeList(ActiveRecipeList);
        RecipeListWidget->SetStationTitle(CurrentStationTypeForUI);
    }

    TMap<FGameplayTag,int32> PlayerIngredients;
    AEmberPlayerCharacter* Player = Cast<AEmberPlayerCharacter>(GetOwningPlayerPawn());
    UCraftingSystem* CraftingSystem = Player ? Player->FindComponentByClass<UCraftingSystem>() : nullptr;
    if (Player && CraftingSystem)
    {
        PlayerIngredients = CraftingSystem->AggregateIngredients(Player);
    }

    if (SelectedRecipeDisplayWidget)
    {
        if (SelectedRecipeDataPtr)
        {
            SelectedRecipeDisplayWidget->SetRecipeDetails(*SelectedRecipeDataPtr, PlayerIngredients, CraftAmount);

            if (SelectedRecipeDataPtr->RequiredMainMaterialCount > 0)
            {
                if(CraftingSystem)
                {
                    auto Chances = CraftingSystem->GetRarityProbabilities(*SelectedRecipeDataPtr, CurrentSelectedMainIngredients);
                    SelectedRecipeDisplayWidget->UpdateRarityDisplay(*SelectedRecipeDataPtr, Chances);
                }
            }
            else
            {
                SelectedRecipeDisplayWidget->UpdateRarityDisplay(*SelectedRecipeDataPtr, {});
            }
        }
        else
        {
            SelectedRecipeDisplayWidget->ClearDetails();
        }
    }

    bool bIsQualityRecipe = (SelectedRecipeDataPtr && SelectedRecipeDataPtr->RequiredMainMaterialCount > 0);
    if (CenterContentSwitcher)
    {
        if (bIsQualityRecipe)
        {
            if (MainMaterialSelectorWidget) CenterContentSwitcher->SetActiveWidget(MainMaterialSelectorWidget);
        }
        else
        {
            if (GeneralRecipeIngredientsWidget) CenterContentSwitcher->SetActiveWidget(GeneralRecipeIngredientsWidget);
        }
    }
    if (MainMaterialSelectorWidget) MainMaterialSelectorWidget->SetVisibility(bIsQualityRecipe ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
    if (GeneralRecipeIngredientsWidget) GeneralRecipeIngredientsWidget->SetVisibility(!bIsQualityRecipe ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);

    if (CraftingOutputBoxWidget)
    {
        CraftingOutputBoxWidget->SetVisibility(ESlateVisibility::Visible);
    }
    
    if (PlayerInventoryDisplayWidget)
    {
        PlayerInventoryDisplayWidget->SetVisibility(ESlateVisibility::Visible);
    }
}

void UCraftingWidget::AttemptCraftCurrentRecipe()
{
    if (!ActiveRecipeList.IsValidIndex(SelectedRecipeIndex)) return;
    
    AEmberPlayerCharacter* Player = Cast<AEmberPlayerCharacter>(GetOwningPlayerPawn());
    UCraftingSystem* Sys = Player ? Player->FindComponentByClass<UCraftingSystem>() : nullptr;
    if (!Sys || !Player) return;

    const FNamedCraftingRecipe& NamedRecipe = ActiveRecipeList[SelectedRecipeIndex];
    TMap<FGameplayTag,int32> MainToUse;
    if (NamedRecipe.RecipeData.RequiredMainMaterialCount > 0)
    {
        MainToUse = CurrentSelectedMainIngredients;
    }
    
    for (int32 i = 0; i < CraftAmount; ++i)
    {
        FCraftingResult CraftResult = Sys->Client_PreCraftCheck(Player, NamedRecipe.RecipeData, MainToUse);
        if (CraftResult.bWasSuccessful)
        {
            if (CraftingOutputBoxWidget)
            {
                if (!CraftingOutputBoxWidget->TryAddItem(CraftResult.ItemTemplateClass, CraftResult.Rarity, 1))
                {
                    break;
                }
            }
            if(CurrentStationActorRef)
            {
                 Sys->RequestServerCraft(Player, CurrentStationActorRef, NamedRecipe.RecipeRowName, MainToUse);
            }
            else 
            {
                 UE_LOG(LogTemp, Warning, TEXT("UCraftingWidget::AttemptCraftCurrentRecipe - No station actor. Bare-hands craft server request needs to be implemented."));
            }
        }
        else
        {
            break;
        }
    }

    ClearSelectedMainIngredients();
    RefreshAll();
}

void UCraftingWidget::HandleRecipeSelectedFromList(UCraftingRecipeListItemData* SelectedItemData)
{
    if (!SelectedItemData) return;

    for (int32 i = 0; i < ActiveRecipeList.Num(); ++i)
    {
        if (ActiveRecipeList[i].RecipeRowName == SelectedItemData->RecipeRowName)
        {
            SelectedRecipeIndex = i;
            SelectedRecipeName = SelectedItemData->RecipeRowName;
            ClearSelectedMainIngredients();
            RefreshAll();
            return;
        }
    }
}

void UCraftingWidget::HandleMainMaterialSelectionChanged(const FSelectedIngredientsMapWrapper& Wrapper)
{
    CurrentSelectedMainIngredients = Wrapper.IngredientsMap;
    RefreshAll();
}