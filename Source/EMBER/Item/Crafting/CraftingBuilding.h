#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CraftingBuilding.generated.h"

UCLASS(Abstract)
class EMBER_API ACraftingBuilding : public AActor
{
    GENERATED_BODY()

public:
    ACraftingBuilding();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

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

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
    FString SelectedItem;

public:
    UFUNCTION()
    virtual void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, 
                                AActor* OtherActor, class UPrimitiveComponent* OtherComp, 
                                int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    virtual void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, 
                              AActor* OtherActor, class UPrimitiveComponent* OtherComp, 
                              int32 OtherBodyIndex);

    UFUNCTION(BlueprintCallable, Category = "Interaction")
    virtual void HandleInput();

    UFUNCTION(BlueprintCallable, Category = "Interaction")
    virtual void OnInteract(AActor* Interactor);

    UFUNCTION(BlueprintCallable, Category = "Interaction")
    virtual void ShowInteractPrompt();

    UFUNCTION(BlueprintCallable, Category = "Interaction")
    virtual void HideInteractPrompt();
};
