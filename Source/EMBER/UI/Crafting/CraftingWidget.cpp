#include "CraftingWidget.h"
#include "CraftingRecipeListWidget.h"
#include "CraftingIngredientWidget.h"
#include "CraftingResultWidget.h"
#include "Crafting/CraftingSystem.h"
#include "Crafting/CraftingRecipeManager.h"
#include "Player/EmberPlayerCharacter.h"

UCraftingWidget::UCraftingWidget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

void UCraftingWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (ResultWidget)
    {
       ResultWidget->OnCraftActionRequested.AddDynamic(this, &UCraftingWidget::OnCraftButtonPressed);
    }
    ClearSelectedMainIngredients();
    RefreshAll();
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
}

void UCraftingWidget::UpdateSelectedRecipe(int32 Direction)
{
    TArray<UCraftingRecipeData*>& Recipes = bIsWeaponCategory ? WeaponRecipes : ClothingRecipes;

    if (Recipes.Num() == 0) 
    {
        SelectedRecipeIndex = 0; 
        ClearSelectedMainIngredients();
        RefreshAll(); 
        return;
    }

    SelectedRecipeIndex = (SelectedRecipeIndex + Direction + Recipes.Num()) % Recipes.Num();
    ClearSelectedMainIngredients();
    RefreshAll();
}

void UCraftingWidget::ChangeCategory()
{
    bIsWeaponCategory = !bIsWeaponCategory;
    SelectedRecipeIndex = 0;
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
    const TArray<UCraftingRecipeData*>& Recipes = bIsWeaponCategory ? WeaponRecipes : ClothingRecipes;
    
    UCraftingRecipeData* SelectedRecipe = nullptr;
    if (Recipes.IsValidIndex(SelectedRecipeIndex))
    {
        SelectedRecipe = Recipes[SelectedRecipeIndex];
    }

    if (RecipeListWidget)
    {
       RecipeListWidget->SetRecipeList(Recipes);
    }

    if (IngredientWidget) 
    {
        if (SelectedRecipe)
        {
            TMap<FString, int32> DisplayIngredients; 
            for(const auto& IngredientPair : SelectedRecipe->Ingredients)
            {
                DisplayIngredients.Add(IngredientPair.Key.ToString(), IngredientPair.Value);
            }
            if (SelectedRecipe->RequiredMainMaterialCount > 0)
            {
                FString MainMatReqStr = FString::Printf(TEXT("주재료 (%d개 필요)"), SelectedRecipe->RequiredMainMaterialCount);
                // TODO: AllowedMainMaterialTags를 기반으로 어떤 종류의 주재료인지 표시하는 로직 추가 가능
                DisplayIngredients.Add(MainMatReqStr, SelectedRecipe->RequiredMainMaterialCount);
            }
            IngredientWidget->SetIngredientData(DisplayIngredients);
        }
        else
        {
            IngredientWidget->SetIngredientData(TMap<FString, int32>()); 
        }
    }

    if (ResultWidget)
    {
        AEmberPlayerCharacter* Player = Cast<AEmberPlayerCharacter>(GetOwningPlayerPawn());
        UCraftingSystem* CraftingSystem = Player ? Player->FindComponentByClass<UCraftingSystem>() : nullptr;

        if (SelectedRecipe)
        {
            ResultWidget->SetTargetRecipe(SelectedRecipe);
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
                bool bUsesQualitySystem = (SelectedRecipe->RequiredMainMaterialCount > 0);
                if (bUsesQualitySystem)
                {
                    TMap<EItemRarity, float> RarityChances = CraftingSystem->GetRarityProbabilities(SelectedRecipe, CurrentSelectedMainIngredients);
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
        }
        else
        {
            ResultWidget->SetTargetRecipe(nullptr);
            ResultWidget->SetProvidedIngredients(TMap<FGameplayTag, int32>());
            ResultWidget->UpdateRarityChances(TMap<EItemRarity, float>());
        }
    }
}

void UCraftingWidget::OnCraftButtonPressed()
{
    const TArray<UCraftingRecipeData*>& Recipes = bIsWeaponCategory ? WeaponRecipes : ClothingRecipes;
    if (!Recipes.IsValidIndex(SelectedRecipeIndex)) return;

    UCraftingRecipeData* SelectedRecipe = Recipes[SelectedRecipeIndex];
    if (!SelectedRecipe) return;

    AEmberPlayerCharacter* Player = Cast<AEmberPlayerCharacter>(GetOwningPlayerPawn());
    if (!Player) return;

    UCraftingSystem* CraftingSystem = Player->FindComponentByClass<UCraftingSystem>();
    if (!CraftingSystem) return;

    TMap<FGameplayTag, int32> MainIngredientsToUse;
    bool bUsesQualitySystem = (SelectedRecipe->RequiredMainMaterialCount > 0);

    if (bUsesQualitySystem)
    {
        MainIngredientsToUse = CurrentSelectedMainIngredients;

        int32 TotalSelectedCount = 0;
        for (const auto& Elem : MainIngredientsToUse)
        {
            TotalSelectedCount += Elem.Value;
        }

        if (TotalSelectedCount != SelectedRecipe->RequiredMainMaterialCount)
        {
            UE_LOG(LogTemp, Warning, TEXT("UCraftingWidget::OnCraftButtonPressed: Selected main ingredient count (%d) does not match recipe requirement (%d). Cannot craft."), TotalSelectedCount, SelectedRecipe->RequiredMainMaterialCount);
            return; 
        }
    }

    for (int32 i = 0; i < CraftAmount; ++i)
    {
       CraftingSystem->StartCrafting(Player, SelectedRecipe, MainIngredientsToUse);
    }
    
    ClearSelectedMainIngredients(); 
    RefreshAll(); 
}