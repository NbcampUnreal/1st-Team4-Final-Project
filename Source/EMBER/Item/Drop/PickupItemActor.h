#pragma once

#include "CoreMinimal.h"
#include "Interaction/Actors/Pickup/EmberPickupableItemBase.h"
#include "GameFlag.h"
#include "Item/Drop/LootTable.h"
#include "PickupItemActor.generated.h"

class UItemTemplate;
class UItemInstance;
class AEmberPlayerCharacter;
class USphereComponent;
class UInteractionPromptWidget;

UCLASS()
class EMBER_API APickupItemActor : public AEmberPickupableItemBase
{
    GENERATED_BODY()

public:
    APickupItemActor();

    void InitializeLootPouch(const TArray<FLootResultData>& InLootData);

protected:
    virtual void BeginPlay() override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    TObjectPtr<USphereComponent> InteractionSphere;

    UPROPERTY(EditDefaultsOnly, Category = "PickupItem|UI")
    TSubclassOf<UInteractionPromptWidget> InteractionPromptWidgetClass;

    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, ReplicatedUsing = OnRep_LootContents, Category = "Loot Pouch")
    TArray<FLootResultData> LootContents;
    
    UFUNCTION()
    void OnRep_LootContents();

private:
    UFUNCTION()
    void OnInteractionSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void OnInteractionSphereOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

    UFUNCTION(Server, Reliable)
    void Server_RequestLootAll(AEmberPlayerCharacter* RequestingPlayer);

    UPROPERTY()
    TObjectPtr<UInteractionPromptWidget> InteractionPromptWidget;
};