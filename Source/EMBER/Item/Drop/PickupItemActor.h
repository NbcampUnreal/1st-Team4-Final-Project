#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFlag.h"
#include "PickupItemActor.generated.h"

class UStaticMeshComponent;
class USphereComponent;
class UItemTemplate;
class AEmberPlayerCharacter;
class UUserWidget;

UCLASS()
class EMBER_API APickupItemActor : public AActor
{
    GENERATED_BODY()
    
public:    
    APickupItemActor();

protected:
    virtual void BeginPlay() override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
    UFUNCTION(BlueprintCallable, Category = "PickupItem")
    void InitializePickup(TSubclassOf<UItemTemplate> InItemTemplateClass, int32 InQuantity, EItemRarity InRarity);

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    TObjectPtr<USceneComponent> DefaultSceneRoot;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    TObjectPtr<UStaticMeshComponent> ItemMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    TObjectPtr<USphereComponent> InteractionSphere;

    UPROPERTY(EditDefaultsOnly, Category = "PickupItem|UI")
    TSubclassOf<UUserWidget> InteractionPromptWidgetClass;

private:
    UFUNCTION()
    void OnRep_ItemDataUpdated();

    UFUNCTION()
    void OnInteractionSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void OnInteractionRangeOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

    void UpdateItemVisuals();

    UFUNCTION(Server, Reliable)
    void Server_RequestPickup(AEmberPlayerCharacter* RequestingPlayer);

    UPROPERTY(ReplicatedUsing = OnRep_ItemDataUpdated)
    TSubclassOf<UItemTemplate> ItemTemplateClass;

    UPROPERTY(Replicated)
    int32 Quantity;

    UPROPERTY(Replicated)
    EItemRarity Rarity;

    UPROPERTY()
    TObjectPtr<UUserWidget> InteractionPromptWidget;
};