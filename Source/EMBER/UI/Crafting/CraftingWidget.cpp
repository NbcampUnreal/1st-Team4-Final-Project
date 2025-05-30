#include "UI/Crafting/CraftingWidget.h"
#include "UI/Crafting/CraftingRecipeListWidget.h"
#include "UI/Crafting/CraftingIngredientWidget.h"
#include "UI/Crafting/CraftingResultWidget.h"
#include "UI/Crafting/CraftingMainMaterialWidget.h"
#include "UI/Crafting/CraftingOutputBoxWidget.h"
#include "Crafting/CraftingSystem.h"
#include "Crafting/CraftingRecipeManager.h"
#include "Player/EmberPlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Components/WidgetSwitcher.h"
#include "Components/TextBlock.h"
#include "Item/ItemInstance.h"

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
                if (ActiveRecipeList[i].OutputItemTemplateID == FoundRecipeRow->OutputItemTemplateID) 
                {
                    SelectedRecipeIndex = i;
                    break;
                }
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
    UE_LOG(LogTemp, Warning, TEXT("UCraftingWidget::ChangeCategory function needs re-evaluation based on StationType or removed if not used."));
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
    else
    {
       UE_LOG(LogTemp, Warning, TEXT("UCraftingWidget::RefreshAll - RecipeListWidget is NULL."));
    }
    
    AEmberPlayerCharacter* Player = Cast<AEmberPlayerCharacter>(GetOwningPlayerPawn());
    UCraftingSystem* CraftingSystem = Player ? Player->FindComponentByClass<UCraftingSystem>() : nullptr;

    bool bIsQualityRecipe = (SelectedRecipePtr && SelectedRecipePtr->RequiredMainMaterialCount > 0);

    if (SelectedRecipeDisplayWidget)
    {
        if (SelectedRecipePtr)
        {
            SelectedRecipeDisplayWidget->SetTargetRecipe(*SelectedRecipePtr);
            if (Player && CraftingSystem)
            {
                TMap<FGameplayTag, int32> PlayerTotalIngredientsForDisplay = CraftingSystem->AggregateIngredients(Player);
                SelectedRecipeDisplayWidget->SetProvidedIngredients(PlayerTotalIngredientsForDisplay);

                if (bIsQualityRecipe)
                {
                    TMap<EItemRarity, float> RarityChances = CraftingSystem->GetRarityProbabilities(*SelectedRecipePtr, CurrentSelectedMainIngredients);
                    SelectedRecipeDisplayWidget->UpdateRarityChances(RarityChances);
                }
                else 
                {
                    TMap<EItemRarity, float> DefaultChances;
                    DefaultChances.Add(EItemRarity::Common, 1.f); 
                    SelectedRecipeDisplayWidget->UpdateRarityChances(DefaultChances);
                }
            }
            else
            {
                SelectedRecipeDisplayWidget->SetProvidedIngredients(TMap<FGameplayTag, int32>());
                SelectedRecipeDisplayWidget->UpdateRarityChances(TMap<EItemRarity, float>());
            }
            SelectedRecipeDisplayWidget->SetVisibility(ESlateVisibility::Visible);
        }
        else
        {
            FCraftingRecipeRow EmptyRecipeRowForClearing; 
            SelectedRecipeDisplayWidget->SetTargetRecipe(EmptyRecipeRowForClearing);
            SelectedRecipeDisplayWidget->SetProvidedIngredients(TMap<FGameplayTag, int32>());
            SelectedRecipeDisplayWidget->UpdateRarityChances(TMap<EItemRarity, float>());
            SelectedRecipeDisplayWidget->SetVisibility(ESlateVisibility::Collapsed);
        }
    }
     else
    {
       UE_LOG(LogTemp, Warning, TEXT("UCraftingWidget::RefreshAll - SelectedRecipeDisplayWidget is NULL."));
    }

    if (CenterContentSwitcher)
    {
        if (bIsQualityRecipe)
        {
            if (MainMaterialSelectorWidget && CraftingSystem && Player && SelectedRecipePtr)
            {
                TArray<FSelectableMainMaterialInfo> SelectableInfos;
                TMap<FGameplayTag, int32> PlayerAggregatedMainIngredients = CraftingSystem->AggregateIngredients(Player); 
                
                for(const auto& Pair : PlayerAggregatedMainIngredients)
                {
                    if(SelectedRecipePtr->AllowedMainMaterialTags.HasTag(Pair.Key))
                    {
                        FSelectableMainMaterialInfo Info;
                        Info.MaterialTag = Pair.Key;
                        Info.AvailableCountInInventory = Pair.Value;
                        Info.Grade = CraftingSystem->GetMaterialScore(Pair.Key);
                        Info.DisplayName = FText::FromString(Pair.Key.GetTagName().ToString()); 
                        SelectableInfos.Add(Info);
                    }
                }
                MainMaterialSelectorWidget->InitializeSelector(SelectableInfos, SelectedRecipePtr->RequiredMainMaterialCount);
                CenterContentSwitcher->SetActiveWidget(MainMaterialSelectorWidget);
            }
            else if (GeneralRecipeIngredientsWidget) 
            {
                CenterContentSwitcher->SetActiveWidget(GeneralRecipeIngredientsWidget);
                FCraftingRecipeRow EmptyRecipeForIngredientWidget;
                TMap<FGameplayTag, int32> EmptyPlayerIngredients;
                GeneralRecipeIngredientsWidget->UpdateDisplay(EmptyRecipeForIngredientWidget, EmptyPlayerIngredients, 0);
            }
        }
        else 
        {
            if (GeneralRecipeIngredientsWidget && Player && CraftingSystem)
            {
                TMap<FGameplayTag, int32> PlayerAggregatedIngredients = CraftingSystem->AggregateIngredients(Player);
                if (SelectedRecipePtr)
                {
                    GeneralRecipeIngredientsWidget->UpdateDisplay(*SelectedRecipePtr, PlayerAggregatedIngredients, CraftAmount);
                }
                else
                {
                    FCraftingRecipeRow EmptyRecipeRow; 
                    GeneralRecipeIngredientsWidget->UpdateDisplay(EmptyRecipeRow, PlayerAggregatedIngredients, CraftAmount);
                }
                CenterContentSwitcher->SetActiveWidget(GeneralRecipeIngredientsWidget);
            }
            else if (MainMaterialSelectorWidget)
            {
                 CenterContentSwitcher->SetActiveWidget(MainMaterialSelectorWidget);
                 if(MainMaterialSelectorWidget) MainMaterialSelectorWidget->SetVisibility(ESlateVisibility::Collapsed);
            }
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("UCraftingWidget::RefreshAll - CenterContentSwitcher is NULL. Manual visibility control would be needed."));
        if(MainMaterialSelectorWidget) MainMaterialSelectorWidget->SetVisibility(bIsQualityRecipe ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
        if(GeneralRecipeIngredientsWidget) 
        {
            if (SelectedRecipePtr && !bIsQualityRecipe && Player && CraftingSystem)
            {
                TMap<FGameplayTag, int32> PlayerAggregatedIngredients = CraftingSystem->AggregateIngredients(Player);
                GeneralRecipeIngredientsWidget->UpdateDisplay(*SelectedRecipePtr, PlayerAggregatedIngredients, CraftAmount);
                GeneralRecipeIngredientsWidget->SetVisibility(ESlateVisibility::Visible);
            }
            else
            {
                 if(GeneralRecipeIngredientsWidget) 
                 {
                    FCraftingRecipeRow EmptyRecipeRow;
                    TMap<FGameplayTag, int32> EmptyPlayerIngredients;
                    GeneralRecipeIngredientsWidget->UpdateDisplay(EmptyRecipeRow, EmptyPlayerIngredients, 0); 
                    GeneralRecipeIngredientsWidget->SetVisibility(ESlateVisibility::Collapsed);
                 }
            }
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
        UE_LOG(LogTemp, Warning, TEXT("UCraftingWidget::AttemptCraftCurrentRecipe - No valid recipe selected."));
        return;
    }

    const FCraftingRecipeRow& SelectedRecipeRef = ActiveRecipeList[SelectedRecipeIndex];

    AEmberPlayerCharacter* Player = Cast<AEmberPlayerCharacter>(GetOwningPlayerPawn());
    if (!Player) return;

    UCraftingSystem* CraftingSystem = Player->FindComponentByClass<UCraftingSystem>();
    if (!CraftingSystem) return;

    if(CraftingOutputBoxWidget && CraftingOutputBoxWidget->IsFull())
    {
        UE_LOG(LogTemp, Warning, TEXT("UCraftingWidget::AttemptCraftCurrentRecipe - CraftingOutputBox is full!"));
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
            UE_LOG(LogTemp, Warning, TEXT("UCraftingWidget::AttemptCraftCurrentRecipe: Selected main ingredient count (%d) does not match recipe requirement (%d). Cannot craft."), TotalSelectedCount, SelectedRecipeRef.RequiredMainMaterialCount);
            return; 
        }
    }
    
    for (int32 i = 0; i < CraftAmount; ++i)
    {
        if(CraftingOutputBoxWidget && CraftingOutputBoxWidget->IsFull())
        {
            UE_LOG(LogTemp, Warning, TEXT("UCraftingWidget::AttemptCraftCurrentRecipe - OutputBox became full during batch craft. Crafted %d."), i);
            break;
        }

       UItemInstance* CraftedItem = CraftingSystem->StartCrafting(Player, SelectedRecipeRef, MainIngredientsToUse);
       if (CraftedItem)
       {
           if (CraftingOutputBoxWidget)
           {
               if(!CraftingOutputBoxWidget->TryAddItem(CraftedItem))
               {
                   UE_LOG(LogTemp, Error, TEXT("UCraftingWidget::AttemptCraftCurrentRecipe - Failed to add item to CraftingOutputBox."));
               }
           }
           else
           {
                UE_LOG(LogTemp, Error, TEXT("UCraftingWidget::AttemptCraftCurrentRecipe - CraftingOutputBoxWidget is NULL. Item not placed."));
           }
       }
       else
       {
           UE_LOG(LogTemp, Warning, TEXT("UCraftingWidget::AttemptCraftCurrentRecipe - Crafting failed for one item in batch (materials might be insufficient for repeated crafts)."));
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
        if (ActiveRecipeList[i].OutputItemTemplateID == SelectedRecipeRow.OutputItemTemplateID) 
        {
            SelectedRecipeIndex = i;
            bFound = true;
            break;
        }
    }

    if (bFound)
    {
        UE_LOG(LogTemp, Log, TEXT("UCraftingWidget::HandleRecipeSelectedFromList - Recipe '%s' selected at index %d."), *SelectedRecipeRow.RecipeDisplayName.ToString(), SelectedRecipeIndex);
        ClearSelectedMainIngredients();
        RefreshAll();
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("UCraftingWidget::HandleRecipeSelectedFromList - Selected recipe row (Output ID: %d) not found in ActiveRecipeList."), SelectedRecipeRow.OutputItemTemplateID);
    }
}

void UCraftingWidget::HandleMainMaterialSelectionChanged(const FSelectedIngredientsMapWrapper& SelectedIngredientsWrapper)
{
    CurrentSelectedMainIngredients = SelectedIngredientsWrapper.IngredientsMap;
    UE_LOG(LogTemp, Log, TEXT("UCraftingWidget::HandleMainMaterialSelectionChanged - Main ingredients updated. Count: %d"), CurrentSelectedMainIngredients.Num());
    RefreshAll();
}