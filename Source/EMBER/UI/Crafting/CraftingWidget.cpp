#include "UI/Crafting/CraftingWidget.h"
#include "UI/Crafting/CraftingRecipeListWidget.h"
#include "UI/Crafting/CraftingIngredientWidget.h"
#include "UI/Crafting/CraftingResultWidget.h"
#include "UI/Crafting/CraftingMainMaterialWidget.h"
#include "UI/Crafting/CraftingOutputBoxWidget.h"
#include "Crafting/CraftingSystem.h"
#include "Crafting/CraftingRecipeManager.h"
#include "Player/EmberPlayerCharacter.h"
#include "Item/ItemInstance.h"
#include "Item/ItemTemplate.h"
#include "UI/Data/EmberItemData.h"
#include "Components/WidgetSwitcher.h"
#include "Components/TextBlock.h"


UCraftingWidget::UCraftingWidget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , CurrentStationTypeForUI(EStationType::None)
    , SelectedRecipeIndex(-1)
    , CraftAmount(1)
{
}

void UCraftingWidget::InitializeForStation(EStationType InStationType, FName OptionalInitialRecipeRowName)
{
    CurrentStationTypeForUI = InStationType;
    SelectedRecipeIndex = -1; 

    PopulateActiveRecipeList();
    
    AEmberPlayerCharacter* Player = Cast<AEmberPlayerCharacter>(GetOwningPlayerPawn());
    UCraftingSystem* CraftingSystem = Player ? Player->FindComponentByClass<UCraftingSystem>() : nullptr;

    if (!OptionalInitialRecipeRowName.IsNone() && ActiveRecipeList.Num() > 0 && CraftingSystem && CraftingSystem->RecipeManager && CraftingSystem->RecipeManager->RecipeDataTable)
    {
        const FCraftingRecipeRow* FoundRecipeRow = CraftingSystem->RecipeManager->RecipeDataTable->FindRow<FCraftingRecipeRow>(OptionalInitialRecipeRowName, TEXT("InitializeForStation"));
        if (FoundRecipeRow)
        {
            for (int32 i = 0; i < ActiveRecipeList.Num(); ++i)
            {
                // Todo: 나중에 수정할 것
                /* if (ActiveRecipeList[i].OutputItemTemplateID == FoundRecipeRow->OutputItemTemplateID) 
                {
                    SelectedRecipeIndex = i;
                    break;
                } */
            }
        }
    }
    
    if (ActiveRecipeList.Num() > 0 && SelectedRecipeIndex == -1)
    {
        SelectedRecipeIndex = 0;
    }

    ClearSelectedMainIngredients();
    RefreshAll();
}

void UCraftingWidget::PopulateActiveRecipeList()
{
    ActiveRecipeList.Empty();

    AEmberPlayerCharacter* Player = Cast<AEmberPlayerCharacter>(GetOwningPlayerPawn());
    if (!Player) 
    {
        return;
    }
    UCraftingSystem* CraftingSystem = Player->FindComponentByClass<UCraftingSystem>();
    if (!CraftingSystem || !CraftingSystem->RecipeManager || !CraftingSystem->RecipeManager->RecipeDataTable)
    {
        return;
    }
    
    FString ContextString;
    TArray<FCraftingRecipeRow*> AllRecipeRowPtrs;
    CraftingSystem->RecipeManager->RecipeDataTable->GetAllRows(ContextString, AllRecipeRowPtrs);

    for (const FCraftingRecipeRow* RecipeRowPtr : AllRecipeRowPtrs)
    {
        if (RecipeRowPtr)
        {
            bool bStationMatch = (RecipeRowPtr->CraftingStation == CurrentStationTypeForUI);
            if (RecipeRowPtr->bCraftableByCharacter && CurrentStationTypeForUI == EStationType::None)
            {
                bStationMatch = true; 
            }

            if (bStationMatch)
            {
                ActiveRecipeList.Add(*RecipeRowPtr);
            }
        }
    }
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
        RecipeListWidget->OnRecipeSelected.RemoveAll(this);
        RecipeListWidget->OnRecipeSelected.AddDynamic(this, &UCraftingWidget::HandleRecipeSelectedFromList);
    }
}

FReply UCraftingWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
    const FKey Key = InKeyEvent.GetKey();

    if (Key == EKeys::W)
    {
       UpdateSelectedRecipe(-1);
       return FReply::Handled();
    }
    else if (Key == EKeys::S)
    {
       UpdateSelectedRecipe(1);
       return FReply::Handled();
    }
    else if (Key == EKeys::E)
    {
       AttemptCraftCurrentRecipe();
       return FReply::Handled();
    }
    else if (Key == EKeys::A)
    {
       AdjustCraftAmount(-1);
       return FReply::Handled();
    }
    else if (Key == EKeys::D)
    {
       AdjustCraftAmount(1);
       return FReply::Handled();
    }

    return Super::NativeOnKeyDown(InGeometry, InKeyEvent);
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
        ClearSelectedMainIngredients();
        RefreshAll(); 
        return;
    }

    SelectedRecipeIndex = (SelectedRecipeIndex + Direction + ActiveRecipeList.Num()) % ActiveRecipeList.Num();
    ClearSelectedMainIngredients();
    RefreshAll();
}

void UCraftingWidget::ChangeCategory()
{
    UE_LOG(LogTemp, Warning, TEXT("UCraftingWidget::ChangeCategory function needs re-evaluation or removal if not used."));
}

void UCraftingWidget::AdjustCraftAmount(int32 Delta)
{
    CraftAmount = FMath::Clamp(CraftAmount + Delta, 1, 99);
    RefreshAll(); 
}

void UCraftingWidget::RefreshAll()
{
    const FCraftingRecipeRow* SelectedRecipePtr = nullptr;
    if (ActiveRecipeList.IsValidIndex(SelectedRecipeIndex))
    {
        SelectedRecipePtr = &ActiveRecipeList[SelectedRecipeIndex];
    }

    if (RecipeListWidget)
    {
       RecipeListWidget->SetStationTitle(CurrentStationTypeForUI);
       RecipeListWidget->SetRecipeList(ActiveRecipeList);
    }
    
    AEmberPlayerCharacter* Player = Cast<AEmberPlayerCharacter>(GetOwningPlayerPawn());
    UCraftingSystem* CraftingSystem = Player ? Player->FindComponentByClass<UCraftingSystem>() : nullptr;
    
    TMap<FGameplayTag, int32> PlayerAggregatedIngredients;
    if(Player && CraftingSystem)
    {
        PlayerAggregatedIngredients = CraftingSystem->AggregateIngredients(Player);
    }

    if (SelectedRecipeDisplayWidget)
    {
        if (SelectedRecipePtr)
        {
            SelectedRecipeDisplayWidget->SetRecipeDetails(*SelectedRecipePtr, PlayerAggregatedIngredients, CraftAmount);
            
            bool bIsQualityRecipeForDisplay = (SelectedRecipePtr->RequiredMainMaterialCount > 0);
            if (bIsQualityRecipeForDisplay && CraftingSystem)
            {
                TMap<EItemRarity, float> RarityChances = CraftingSystem->GetRarityProbabilities(*SelectedRecipePtr, CurrentSelectedMainIngredients);
                SelectedRecipeDisplayWidget->UpdateRarityDisplay(*SelectedRecipePtr, RarityChances);
            }
            else if (!bIsQualityRecipeForDisplay && CraftingSystem) 
            {
                 SelectedRecipeDisplayWidget->UpdateRarityDisplay(*SelectedRecipePtr, TMap<EItemRarity, float>());
            }
        }
        else
        {
            SelectedRecipeDisplayWidget->ClearDetails();
        }
    }

    bool bIsQualityRecipeOverall = (SelectedRecipePtr && SelectedRecipePtr->RequiredMainMaterialCount > 0);
    if (CenterContentSwitcher)
    {
        if (bIsQualityRecipeOverall)
        {
            if (MainMaterialSelectorWidget && CraftingSystem && Player && SelectedRecipePtr)
            {
                TArray<FSelectableMainMaterialInfo> SelectableInfos;
                for(const auto& Pair : PlayerAggregatedIngredients)
                {
                    if(SelectedRecipePtr->AllowedMainMaterialTags.HasTag(Pair.Key))
                    {
                        FSelectableMainMaterialInfo Info;
                        Info.MaterialTag = Pair.Key;
                        Info.AvailableCountInInventory = Pair.Value;
                        Info.Grade = CraftingSystem->GetMaterialScore(Pair.Key);
                        
                        FString DisplayNameStr = Pair.Key.GetTagName().ToString();
                        Info.DisplayName = FText::FromString(DisplayNameStr); 
                        SelectableInfos.Add(Info);
                    }
                }
                MainMaterialSelectorWidget->InitializeSelector(SelectableInfos, SelectedRecipePtr->RequiredMainMaterialCount);
                MainMaterialSelectorWidget->SetVisibility(ESlateVisibility::Visible);
                CenterContentSwitcher->SetActiveWidget(MainMaterialSelectorWidget);
                if (GeneralRecipeIngredientsWidget)
                {
                     GeneralRecipeIngredientsWidget->SetVisibility(ESlateVisibility::Collapsed);
                }
            }
            else 
            {
                if(MainMaterialSelectorWidget) MainMaterialSelectorWidget->SetVisibility(ESlateVisibility::Collapsed);
                if (GeneralRecipeIngredientsWidget) GeneralRecipeIngredientsWidget->SetVisibility(ESlateVisibility::Collapsed);
                
                if (MainMaterialSelectorWidget) CenterContentSwitcher->SetActiveWidget(MainMaterialSelectorWidget);
                else if (GeneralRecipeIngredientsWidget) CenterContentSwitcher->SetActiveWidget(GeneralRecipeIngredientsWidget);
            }
        }
        else 
        {
            if (MainMaterialSelectorWidget)
            {
                MainMaterialSelectorWidget->SetVisibility(ESlateVisibility::Collapsed);
            }
            if (GeneralRecipeIngredientsWidget)
            {
                 GeneralRecipeIngredientsWidget->SetVisibility(ESlateVisibility::Collapsed); 
            }
            
            if (MainMaterialSelectorWidget) CenterContentSwitcher->SetActiveWidget(MainMaterialSelectorWidget); 
            else if (GeneralRecipeIngredientsWidget) CenterContentSwitcher->SetActiveWidget(GeneralRecipeIngredientsWidget);
            else if (CenterContentSwitcher->GetChildrenCount() > 0) CenterContentSwitcher->SetActiveWidgetIndex(0);
        }
    }
    
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
    if (!ActiveRecipeList.IsValidIndex(SelectedRecipeIndex)) 
    {
        return;
    }

    const FCraftingRecipeRow& SelectedRecipeRef = ActiveRecipeList[SelectedRecipeIndex];

    AEmberPlayerCharacter* Player = Cast<AEmberPlayerCharacter>(GetOwningPlayerPawn());
    if (!Player) return;

    UCraftingSystem* CraftingSystem = Player->FindComponentByClass<UCraftingSystem>();
    if (!CraftingSystem) return;

    if(CraftingOutputBoxWidget && CraftingOutputBoxWidget->IsFull())
    {
        return;
    }

    TMap<FGameplayTag, int32> MainIngredientsToUse;
    bool bUsesQualitySystem = (SelectedRecipeRef.RequiredMainMaterialCount > 0);

    if (bUsesQualitySystem)
    {
        MainIngredientsToUse = CurrentSelectedMainIngredients;
        int32 TotalSelectedCount = 0;
        for (const auto& Elem : MainIngredientsToUse) { TotalSelectedCount += Elem.Value; }

        if (TotalSelectedCount != SelectedRecipeRef.RequiredMainMaterialCount)
        {
            return; 
        }
    }
    
    for (int32 i = 0; i < CraftAmount; ++i)
    {
        if(CraftingOutputBoxWidget && CraftingOutputBoxWidget->IsFull())
        {
            break;
        }

       UItemInstance* CraftedItem = CraftingSystem->StartCrafting(Player, SelectedRecipeRef, MainIngredientsToUse);
       if (CraftedItem)
       {
           if (CraftingOutputBoxWidget)
           {
               if(!CraftingOutputBoxWidget->TryAddItem(CraftedItem))
               {
               }
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

void UCraftingWidget::HandleRecipeSelectedFromList(const FCraftingRecipeRow& SelectedRecipeRow)
{
    bool bFound = false;
    for (int32 i = 0; i < ActiveRecipeList.Num(); ++i)
    {
        //Todo : 수정 필요
        /* if (ActiveRecipeList[i].OutputItemTemplateID == SelectedRecipeRow.OutputItemTemplateID) 
        {
            SelectedRecipeIndex = i;
            bFound = true;
            break;
        } */
    }

    if (bFound)
    {
        ClearSelectedMainIngredients();
        RefreshAll();
    }
}

void UCraftingWidget::HandleMainMaterialSelectionChanged(const FSelectedIngredientsMapWrapper& SelectedIngredientsWrapper)
{
    CurrentSelectedMainIngredients = SelectedIngredientsWrapper.IngredientsMap;
    RefreshAll();
}