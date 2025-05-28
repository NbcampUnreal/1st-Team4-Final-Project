#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Crafting/CraftingRecipeManager.h"
#include "CraftingBuilding.generated.h"

class UCraftingWidget; 

UCLASS(Abstract)
class EMBER_API ACraftingBuilding : public AActor
{
    GENERATED_BODY()

public:
    ACraftingBuilding();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    class UStaticMeshComponent* BuildingMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    class UBoxComponent* InteractionBox;

    UPROPERTY()
    AActor* OverlappingPlayer;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
    TSubclassOf<class UUserWidget> InteractionWidgetClass;

    UPROPERTY()
    UUserWidget* InteractionWidget;
    
    UPROPERTY(EditDefaultsOnly, Category = "UI")
    TSubclassOf<UCraftingWidget> MainCraftingWidgetClass; 

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EStationType StationType = EStationType::None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UCraftingRecipeData* SelectedRecipe;

public:
    UFUNCTION()
    virtual void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    virtual void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

    UFUNCTION(BlueprintCallable, Category = "Interaction")
    virtual void HandleInput();

    UFUNCTION(BlueprintCallable, Category = "Interaction")
    virtual void OnInteract(AActor* Interactor);

    UFUNCTION(BlueprintCallable, Category = "Interaction")
    virtual void ShowInteractPrompt();

    UFUNCTION(BlueprintCallable, Category = "Interaction")
    virtual void HideInteractPrompt();
};