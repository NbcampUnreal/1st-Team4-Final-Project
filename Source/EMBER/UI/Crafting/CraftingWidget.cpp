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
#include "Kismet/GameplayStatics.h"
#include "Components/WidgetSwitcher.h"
#include "Components/TextBlock.h"
#include "Item/Crafting/CraftingBuilding.h"
#include "Item/Managers/InventoryManagerComponent.h" 
#include "Components/PanelWidget.h"
#include "Components/Border.h"


UCraftingWidget::UCraftingWidget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , CurrentStationTypeForUI(EStationType::None)
    , SelectedRecipeIndex(-1)
    , CraftAmount(1)
{
    CurrentStationActorRef = nullptr;
    ActiveOutputInventoryUI = nullptr;
    StationOutputInventoryWidgetClass = nullptr;
    RecipeListWidget = nullptr;
    CenterContentSwitcher = nullptr;
    GeneralRecipeIngredientsWidget = nullptr;
    MainMaterialSelectorWidget = nullptr;
    SelectedRecipeDisplayWidget = nullptr;
    OutputInventoryDisplayContainer = nullptr;
    PlayerInventoryDisplayWidget = nullptr;
}

void UCraftingWidget::InitializeForStation(ACraftingBuilding* InStationActor, FName OptionalInitialRecipeRowName)
{
    UE_LOG(LogTemp, Warning, TEXT("UCraftingWidget::InitializeForStation - Entry - InStationActor: %s"), InStationActor ? *InStationActor->GetName() : TEXT("NULL at Entry"));

    CurrentStationActorRef = InStationActor;
    UE_LOG(LogTemp, Warning, TEXT("UCraftingWidget::InitializeForStation - After Assignment - CurrentStationActorRef: %s"), CurrentStationActorRef ? *CurrentStationActorRef->GetName() : TEXT("NULL after assignment"));

    CurrentStationActorRef = InStationActor;
    if (CurrentStationActorRef)
    {
        CurrentStationTypeForUI = CurrentStationActorRef->StationType;
    }
    else
    {
        CurrentStationTypeForUI = EStationType::None; 
        UE_LOG(LogTemp, Warning, TEXT("UCraftingWidget::InitializeForStation - InStationActor is NULL."));
    }
    
    SelectedRecipeIndex = -1; 
    SelectedRecipeName = NAME_None;

    PopulateActiveRecipeList();
    
    if (!OptionalInitialRecipeRowName.IsNone() && ActiveRecipeList.Num() > 0)
    {
        for (int32 i = 0; i < ActiveRecipeList.Num(); ++i)
        {
            if (ActiveRecipeList[i].RecipeRowName == OptionalInitialRecipeRowName) 
            {
                SelectedRecipeIndex = i;
                SelectedRecipeName = ActiveRecipeList[i].RecipeRowName;
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

    if (OutputInventoryDisplayContainer)
    {
        OutputInventoryDisplayContainer->ClearChildren();
        if (ActiveOutputInventoryUI)
        {
            ActiveOutputInventoryUI->RemoveFromParent();
            ActiveOutputInventoryUI = nullptr;
        }

        if (StationOutputInventoryWidgetClass && CurrentStationActorRef && CurrentStationActorRef->OutputInventoryComponent)
        {
            ActiveOutputInventoryUI = CreateWidget<UCraftingOutputBoxWidget>(this, StationOutputInventoryWidgetClass);
            if (ActiveOutputInventoryUI)
            {                
                ActiveOutputInventoryUI->InitializeDataSource(CurrentStationActorRef->OutputInventoryComponent);
                
                if (UBorder* BorderContainer = Cast<UBorder>(OutputInventoryDisplayContainer))
                {
                    BorderContainer->SetContent(ActiveOutputInventoryUI);
                }
                else
                {
                    OutputInventoryDisplayContainer->AddChild(ActiveOutputInventoryUI); 
                }
                UE_LOG(LogTemp, Log, TEXT("UCraftingWidget::InitializeForStation - Station Output Inventory UI (UCraftingOutputBoxWidget) created and initialized."));
            }
            else
            {
                 UE_LOG(LogTemp, Warning, TEXT("UCraftingWidget::InitializeForStation - Failed to create StationOutputInventoryWidgetClass instance (expected UCraftingOutputBoxWidget)."));
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("UCraftingWidget::InitializeForStation - StationOutputInventoryWidgetClass, CurrentStationActorRef, or its OutputInventoryComponent is NULL. Cannot create output UI."));
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("UCraftingWidget::InitializeForStation - OutputInventoryDisplayContainer is NULL. Check UMG Binding in WBP_CraftingMain."));
    }

    RefreshAll();
}

void UCraftingWidget::PopulateActiveRecipeList()
{
    ActiveRecipeList.Empty();

    AEmberPlayerCharacter* Player = Cast<AEmberPlayerCharacter>(GetOwningPlayerPawn());
    if (!Player) return;
    UCraftingSystem* CraftingSystem = Player->FindComponentByClass<UCraftingSystem>();
    if (!CraftingSystem || !CraftingSystem->RecipeManager || !CraftingSystem->RecipeManager->RecipeDataTable) return;
    
    TArray<FName> RowNames = CraftingSystem->RecipeManager->RecipeDataTable->GetRowNames();
    for (const FName& RowName : RowNames)
    {
        FCraftingRecipeRow* RecipeRowPtr = CraftingSystem->RecipeManager->RecipeDataTable->FindRow<FCraftingRecipeRow>(RowName, TEXT("PopulateActiveRecipeList"));
        if (RecipeRowPtr)
        {
            bool bStationMatch = (RecipeRowPtr->CraftingStation == CurrentStationTypeForUI);
            if (RecipeRowPtr->bCraftableByCharacter && CurrentStationTypeForUI == EStationType::None)
            {
                bStationMatch = true; 
            }

            if (bStationMatch)
            {
                FNamedCraftingRecipe NamedRecipe;
                NamedRecipe.RecipeRowName = RowName;
                NamedRecipe.RecipeData = *RecipeRowPtr;
                ActiveRecipeList.Add(NamedRecipe);
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
        RecipeListWidget->OnRecipeListItemSelected.RemoveAll(this);
        RecipeListWidget->OnRecipeListItemSelected.AddDynamic(this, &UCraftingWidget::HandleRecipeSelectedFromList);
    }
}

FReply UCraftingWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
    const FKey Key = InKeyEvent.GetKey();
    if (Key == EKeys::W) { UpdateSelectedRecipe(-1); return FReply::Handled(); }
    else if (Key == EKeys::S) { UpdateSelectedRecipe(1); return FReply::Handled(); }
    else if (Key == EKeys::E) { AttemptCraftCurrentRecipe(); return FReply::Handled(); }
    else if (Key == EKeys::A) { AdjustCraftAmount(-1); return FReply::Handled(); }
    else if (Key == EKeys::D) { AdjustCraftAmount(1); return FReply::Handled(); }
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
        SelectedRecipeName = NAME_None;
        ClearSelectedMainIngredients();
        RefreshAll(); 
        return;
    }

    SelectedRecipeIndex = (SelectedRecipeIndex + Direction + ActiveRecipeList.Num()) % ActiveRecipeList.Num();
    if(ActiveRecipeList.IsValidIndex(SelectedRecipeIndex))
    {
        SelectedRecipeName = ActiveRecipeList[SelectedRecipeIndex].RecipeRowName;
    }
    else
    {
        SelectedRecipeName = NAME_None;
    }
    ClearSelectedMainIngredients();
    RefreshAll();
}

void UCraftingWidget::ChangeCategory()
{
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
    
    AEmberPlayerCharacter* Player = Cast<AEmberPlayerCharacter>(GetOwningPlayerPawn());
    UCraftingSystem* CraftingSystem = Player ? Player->FindComponentByClass<UCraftingSystem>() : nullptr;
    
    TMap<FGameplayTag, int32> PlayerAggregatedIngredients;
    if(Player && CraftingSystem)
    {
        PlayerAggregatedIngredients = CraftingSystem->AggregateIngredients(Player);
    }

    if (SelectedRecipeDisplayWidget)
    {
        if (SelectedRecipeDataPtr)
        {
            SelectedRecipeDisplayWidget->SetRecipeDetails(*SelectedRecipeDataPtr, PlayerAggregatedIngredients, CraftAmount);
            
            bool bIsQualityRecipeForDisplay = (SelectedRecipeDataPtr->RequiredMainMaterialCount > 0);
            if (bIsQualityRecipeForDisplay && CraftingSystem)
            {
                TMap<EItemRarity, float> RarityChances = CraftingSystem->GetRarityProbabilities(*SelectedRecipeDataPtr, CurrentSelectedMainIngredients);
                SelectedRecipeDisplayWidget->UpdateRarityDisplay(*SelectedRecipeDataPtr, RarityChances);
            }
            else if (!bIsQualityRecipeForDisplay && CraftingSystem) 
            {
                 SelectedRecipeDisplayWidget->UpdateRarityDisplay(*SelectedRecipeDataPtr, TMap<EItemRarity, float>());
            }
        }
        else
        {
            SelectedRecipeDisplayWidget->ClearDetails();
        }
    }

    bool bIsQualityRecipeOverall = (SelectedRecipeDataPtr && SelectedRecipeDataPtr->RequiredMainMaterialCount > 0);
    if (CenterContentSwitcher)
    {
        if (bIsQualityRecipeOverall)
        {
            if (MainMaterialSelectorWidget && CraftingSystem && Player && SelectedRecipeDataPtr)
            {
                TArray<FSelectableMainMaterialInfo> SelectableInfos;
                for(const auto& Pair : PlayerAggregatedIngredients)
                {
                    if(SelectedRecipeDataPtr->AllowedMainMaterialTags.HasTag(Pair.Key))
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
                MainMaterialSelectorWidget->InitializeSelector(SelectableInfos, SelectedRecipeDataPtr->RequiredMainMaterialCount);
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
            if (MainMaterialSelectorWidget) MainMaterialSelectorWidget->SetVisibility(ESlateVisibility::Collapsed);
            if (GeneralRecipeIngredientsWidget) GeneralRecipeIngredientsWidget->SetVisibility(ESlateVisibility::Collapsed); 
            
            if (MainMaterialSelectorWidget) CenterContentSwitcher->SetActiveWidget(MainMaterialSelectorWidget); 
            else if (GeneralRecipeIngredientsWidget) CenterContentSwitcher->SetActiveWidget(GeneralRecipeIngredientsWidget);
            else if (CenterContentSwitcher->GetChildrenCount() > 0) CenterContentSwitcher->SetActiveWidgetIndex(0);
        }
    }
    
    if (PlayerInventoryDisplayWidget) PlayerInventoryDisplayWidget->SetVisibility(ESlateVisibility::Visible);
}

void UCraftingWidget::AttemptCraftCurrentRecipe()
{
    if (!ActiveRecipeList.IsValidIndex(SelectedRecipeIndex)) return;

    const FNamedCraftingRecipe& SelectedNamedRecipe = ActiveRecipeList[SelectedRecipeIndex];
    const FCraftingRecipeRow& SelectedRecipeRef = SelectedNamedRecipe.RecipeData;
    FName RecipeNameToCraft = SelectedNamedRecipe.RecipeRowName;

    AEmberPlayerCharacter* Player = Cast<AEmberPlayerCharacter>(GetOwningPlayerPawn());
    if (!Player) return;

    UCraftingSystem* CraftingSystem = Player->FindComponentByClass<UCraftingSystem>();
    if (!CraftingSystem) return;
    
    if (!CurrentStationActorRef)
    {
        UE_LOG(LogTemp, Error, TEXT("UCraftingWidget::AttemptCraftCurrentRecipe - CurrentStationActorRef is NULL. Cannot determine target station."));
        return;
    }
    
    TMap<FGameplayTag, int32> MainIngredientsToUse;
    bool bUsesQualitySystem = (SelectedRecipeRef.RequiredMainMaterialCount > 0);

    if (bUsesQualitySystem)
    {
        MainIngredientsToUse = CurrentSelectedMainIngredients;
        int32 TotalSelectedCount = 0;
        for (const auto& Elem : MainIngredientsToUse) { TotalSelectedCount += Elem.Value; }
        if (TotalSelectedCount != SelectedRecipeRef.RequiredMainMaterialCount) return; 
    }
    
    for (int32 i = 0; i < CraftAmount; ++i)
    {
        if (CraftingSystem)
        {
            CraftingSystem->RequestServerCraft(Player, CurrentStationActorRef, RecipeNameToCraft, MainIngredientsToUse);
        }
    }
    
    ClearSelectedMainIngredients(); 
    RefreshAll(); 
}

void UCraftingWidget::HandleRecipeSelectedFromList(UCraftingRecipeListItemData* SelectedItemData)
{
    if(!SelectedItemData) return;

    bool bFound = false;
    for (int32 i = 0; i < ActiveRecipeList.Num(); ++i)
    {
        if (ActiveRecipeList[i].RecipeRowName == SelectedItemData->RecipeRowName) 
        {
            SelectedRecipeIndex = i;
            SelectedRecipeName = ActiveRecipeList[i].RecipeRowName;
            bFound = true;
            break;
        }
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