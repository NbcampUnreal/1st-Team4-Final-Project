#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Crafting/CraftingRecipeManager.h"
#include "CraftingBuilding.generated.h"

class UCraftingWidget;
struct FCraftingRecipeRow;
class UCraftingRecipeManager;
class AEmberPlayerCharacter;
class UStaticMeshComponent;
class UBoxComponent;
class UUserWidget;

UCLASS(Abstract)
class EMBER_API ACraftingBuilding : public AActor
{
    GENERATED_BODY()

public:
    ACraftingBuilding();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    TObjectPtr<UStaticMeshComponent> BuildingMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    TObjectPtr<UBoxComponent> InteractionBox;

    UPROPERTY()
    TObjectPtr<AEmberPlayerCharacter> OverlappingPlayerCharacter;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
    TSubclassOf<UUserWidget> InteractionPromptWidgetClass;

    UPROPERTY()
    TObjectPtr<UUserWidget> InteractionPromptWidgetInstance;
    
    UPROPERTY(EditDefaultsOnly, Category = "UI")
    TSubclassOf<UCraftingWidget> MainCraftingUIClass; 

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Crafting")
    EStationType StationType = EStationType::None;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Crafting", meta = (GetOptions = "EditorOnly_GetRecipeRowNames"))
    FName SelectedRecipeRowName;
    
    const FCraftingRecipeRow* CachedSelectedRecipeData;

    UFUNCTION()
    TArray<FName> EditorOnly_GetRecipeRowNames() const;


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

private:
    UCraftingRecipeManager* GetRecipeManagerFromPlayer(AEmberPlayerCharacter* Player) const;
};