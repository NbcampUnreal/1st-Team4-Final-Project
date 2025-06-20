#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Crafting/CraftingRecipeManager.h"
#include "GameFlag.h"
#include "GameplayTagContainer.h"
#include "CraftingBuilding.generated.h"

class UInventoryManagerComponent;
class UStaticMeshComponent;
class USphereComponent;
class UCraftingWidget;
class AEmberPlayerCharacter;
class UAnimMontage;

UCLASS()
class EMBER_API ACraftingBuilding : public AActor
{
    GENERATED_BODY()
    
public:    
    ACraftingBuilding();

protected:
    virtual void BeginPlay() override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    TObjectPtr<UStaticMeshComponent> MeshComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    TObjectPtr<USphereComponent> InteractionRange;

    UPROPERTY(EditDefaultsOnly, Category = "Crafting UI")
    TSubclassOf<UCraftingWidget> CraftingWidgetClass;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Crafting")
    TObjectPtr<UAnimMontage> CraftingAnimation;
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Crafting")
    FGameplayTag StationTag;

public:    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
    EStationType StationType;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Crafting|Output", Replicated)
    TObjectPtr<UInventoryManagerComponent> OutputInventoryComponent;

    UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Crafting")
    void Server_ExecuteCrafting(FName RecipeRowName, const TArray<FGameplayTag>& SelectedMainIngredientTags, const TArray<int32>& SelectedMainIngredientQuantities, AEmberPlayerCharacter* RequestingPlayer);

    UFUNCTION(BlueprintPure, Category = "Crafting")
    UAnimMontage* GetCraftingAnimation() const { return CraftingAnimation; }
    
    UFUNCTION(BlueprintPure, Category = "Crafting")
    FGameplayTag GetStationTag() const { return StationTag; }

private:
    UFUNCTION()
    void OnInteractionRangeOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void OnInteractionRangeOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

    UPROPERTY()
    TObjectPtr<UCraftingWidget> ActiveCraftingUI;
};