#include "UI/Crafting/CraftingWidget.h"
#include "UI/Crafting/CraftingRecipeListWidget.h"
#include "UI/Crafting/CraftingIngredientWidget.h"
#include "UI/Crafting/CraftingResultWidget.h"
#include "UI/Crafting/CraftingMainMaterialWidget.h"
#include "Crafting/CraftingSystem.h"
#include "Crafting/CraftingRecipeManager.h"
#include "Player/EmberPlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Components/WidgetSwitcher.h"

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

    UE_LOG(LogTemp, Log, TEXT("UCraftingWidget::InitializeForStation - StationType: %s, OptionalInitialRecipeRowName: %s"), 
        *UEnum::GetValueAsString(InStationType), *OptionalInitialRecipeRowName.ToString());

    PopulateActiveRecipeList();

    if (!OptionalInitialRecipeRowName.IsNone() && ActiveRecipeList.Num() > 0)
    {
        AEmberPlayerCharacter* Player = Cast<AEmberPlayerCharacter>(GetOwningPlayerPawn());
        UCraftingSystem* CraftingSystem = Player ? Player->FindComponentByClass<UCraftingSystem>() : nullptr;
        if (CraftingSystem && CraftingSystem->RecipeManager && CraftingSystem->RecipeManager->RecipeDataTable)
        {
            const FCraftingRecipeRow* FoundRecipeRow = CraftingSystem->RecipeManager->RecipeDataTable->FindRow<FCraftingRecipeRow>(OptionalInitialRecipeRowName, TEXT("InitializeForStation"));
            if (FoundRecipeRow)
            {
                for (int32 i = 0; i < ActiveRecipeList.Num(); ++i)
                {
                    if (ActiveRecipeList[i].OutputItemTemplateID == FoundRecipeRow->OutputItemTemplateID) // 더 정확한 비교를 위해 RowName 직접 비교 등 고려
                    {
                        SelectedRecipeIndex = i;
                        break;
                    }
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
    UE_LOG(LogTemp, Log, TEXT("UCraftingWidget::InitializeForStation - Finished. Active Recipes: %d, Selected Index: %d"), ActiveRecipeList.Num(), SelectedRecipeIndex);
}

void UCraftingWidget::PopulateActiveRecipeList()
{
    ActiveRecipeList.Empty();

    AEmberPlayerCharacter* Player = Cast<AEmberPlayerCharacter>(GetOwningPlayerPawn());
    if (!Player) 
    {
        UE_LOG(LogTemp, Warning, TEXT("UCraftingWidget::PopulateActiveRecipeList - Player is NULL."));
        return;
    }
    UCraftingSystem* CraftingSystem = Player->FindComponentByClass<UCraftingSystem>();
    if (!CraftingSystem || !CraftingSystem->RecipeManager || !CraftingSystem->RecipeManager->RecipeDataTable)
    {
        UE_LOG(LogTemp, Warning, TEXT("UCraftingWidget::PopulateActiveRecipeList - CraftingSystem, RecipeManager, or RecipeDataTable is NULL."));
        return;
    }

    UE_LOG(LogTemp, Log, TEXT("UCraftingWidget::PopulateActiveRecipeList - Populating for StationType: %s"), *UEnum::GetValueAsString(CurrentStationTypeForUI));
    
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
    UE_LOG(LogTemp, Log, TEXT("UCraftingWidget::PopulateActiveRecipeList - Found %d recipes."), ActiveRecipeList.Num());
}

void UCraftingWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (ResultWidget)
    {
       ResultWidget->OnCraftActionRequested.AddDynamic(this, &UCraftingWidget::OnCraftButtonPressed);
    }

    if (MainMaterialSelectorWidget) 
    {
        MainMaterialSelectorWidget->OnSelectionChanged.AddDynamic(this, &UCraftingWidget::HandleMainMaterialSelectionChanged);
    }

    if (RecipeListWidget)
    {
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
       ChangeCategory(); 
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
    UE_LOG(LogTemp, Warning, TEXT("UCraftingWidget::ChangeCategory function needs re-evaluation based on StationType or removed."));
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
       RecipeListWidget->SetRecipeList(ActiveRecipeList);
    }
    else
    {
       UE_LOG(LogTemp, Warning, TEXT("UCraftingWidget::RefreshAll - RecipeListWidget is NULL."));
    }
    
    AEmberPlayerCharacter* Player = Cast<AEmberPlayerCharacter>(GetOwningPlayerPawn());
    UCraftingSystem* CraftingSystem = Player ? Player->FindComponentByClass<UCraftingSystem>() : nullptr;

    bool bIsQualityRecipe = (SelectedRecipePtr && SelectedRecipePtr->RequiredMainMaterialCount > 0);

    if (CenterPaneSwitcher)
    {
        if (bIsQualityRecipe)
        {
            if (MainMaterialSelectorWidget && CraftingSystem && Player && SelectedRecipePtr)
            {
                TArray<FSelectableMainMaterialInfo> SelectableInfos;
                TMap<FGameplayTag, int32> PlayerAggregatedIngredients = CraftingSystem->AggregateIngredients(Player); 
                
                for(const auto& Pair : PlayerAggregatedIngredients)
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
                CenterPaneSwitcher->SetActiveWidget(MainMaterialSelectorWidget);
            }
             else if (IngredientWidget)
            {
                CenterPaneSwitcher->SetActiveWidget(IngredientWidget);
                IngredientWidget->SetIngredientData(TMap<FGameplayTag, int32>());
            }
        }
        else 
        {
            if (IngredientWidget)
            {
                 if (SelectedRecipePtr)
                {
                    IngredientWidget->SetIngredientData(SelectedRecipePtr->Ingredients);
                }
                else
                {
                    IngredientWidget->SetIngredientData(TMap<FGameplayTag, int32>());
                }
                CenterPaneSwitcher->SetActiveWidget(IngredientWidget);
            }
             else if (MainMaterialSelectorWidget)
            {
                CenterPaneSwitcher->SetActiveWidget(MainMaterialSelectorWidget); 
                MainMaterialSelectorWidget->SetVisibility(ESlateVisibility::Collapsed);
            }
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("UCraftingWidget::RefreshAll - CenterPaneSwitcher is NULL."));
    }


    if (ResultWidget)
    {
        if (SelectedRecipePtr)
        {
            ResultWidget->SetTargetRecipe(*SelectedRecipePtr);
            if (Player && CraftingSystem)
            {
                TMap<FGameplayTag, int32> PlayerTotalIngredients = CraftingSystem->AggregateIngredients(Player);
                ResultWidget->SetProvidedIngredients(PlayerTotalIngredients);
            }
            else
            {
                ResultWidget->SetProvidedIngredients(TMap<FGameplayTag, int32>());
            }

            if (CraftingSystem)
            {
                if (bIsQualityRecipe)
                {
                    TMap<EItemRarity, float> RarityChances = CraftingSystem->GetRarityProbabilities(*SelectedRecipePtr, CurrentSelectedMainIngredients);
                    ResultWidget->UpdateRarityChances(RarityChances);
                }
                else 
                {
                    TMap<EItemRarity, float> DefaultChances;
                    DefaultChances.Add(EItemRarity::Common, 1.f); 
                    ResultWidget->UpdateRarityChances(DefaultChances);
                }
            }
            else
            {
                 ResultWidget->UpdateRarityChances(TMap<EItemRarity, float>());
            }
            ResultWidget->SetVisibility(ESlateVisibility::Visible);
        }
        else
        {
            FCraftingRecipeRow EmptyRecipeRowForClearing; // 빈 구조체 전달용
            ResultWidget->SetTargetRecipe(EmptyRecipeRowForClearing); // nullptr 대신 빈 구조체 참조 전달
            ResultWidget->SetProvidedIngredients(TMap<FGameplayTag, int32>());
            ResultWidget->UpdateRarityChances(TMap<EItemRarity, float>());
            ResultWidget->SetVisibility(ESlateVisibility::Collapsed);
        }
    }
     else
    {
       UE_LOG(LogTemp, Warning, TEXT("UCraftingWidget::RefreshAll - ResultWidget is NULL."));
    }
}

void UCraftingWidget::OnCraftButtonPressed()
{
    if (!ActiveRecipeList.IsValidIndex(SelectedRecipeIndex)) return;

    const FCraftingRecipeRow& SelectedRecipeRef = ActiveRecipeList[SelectedRecipeIndex];

    AEmberPlayerCharacter* Player = Cast<AEmberPlayerCharacter>(GetOwningPlayerPawn());
    if (!Player) return;

    UCraftingSystem* CraftingSystem = Player->FindComponentByClass<UCraftingSystem>();
    if (!CraftingSystem) return;

    TMap<FGameplayTag, int32> MainIngredientsToUse;
    bool bUsesQualitySystem = (SelectedRecipeRef.RequiredMainMaterialCount > 0);

    if (bUsesQualitySystem)
    {
        MainIngredientsToUse = CurrentSelectedMainIngredients;
        int32 TotalSelectedCount = 0;
        for (const auto& Elem : MainIngredientsToUse) { TotalSelectedCount += Elem.Value; }

        if (TotalSelectedCount != SelectedRecipeRef.RequiredMainMaterialCount)
        {
            UE_LOG(LogTemp, Warning, TEXT("UCraftingWidget::OnCraftButtonPressed: Selected main ingredient count (%d) does not match recipe requirement (%d). Cannot craft."), TotalSelectedCount, SelectedRecipeRef.RequiredMainMaterialCount);
            return; 
        }
    }

    for (int32 i = 0; i < CraftAmount; ++i)
    {
       CraftingSystem->StartCrafting(Player, SelectedRecipeRef, MainIngredientsToUse);
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
        ClearSelectedMainIngredients();
        RefreshAll();
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("UCraftingWidget::HandleRecipeSelectedFromList - Selected recipe row not found in ActiveRecipeList. This might happen if ActiveRecipeList is populated with pointers from DataTable and compared with a copy from delegate. Comparing by a unique ID like RowName or OutputItemTemplateID is generally safer."));
    }
}

void UCraftingWidget::HandleMainMaterialSelectionChanged(const FSelectedIngredientsMapWrapper& SelectedIngredientsWrapper)
{
    CurrentSelectedMainIngredients = SelectedIngredientsWrapper.IngredientsMap;
    RefreshAll();
}