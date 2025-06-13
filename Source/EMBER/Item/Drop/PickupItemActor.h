#pragma once

#include "CoreMinimal.h"
#include "Interaction/Actors/Pickup/EmberPickupableItemBase.h"
#include "GameFlag.h"
#include "PickupItemActor.generated.h"

class UItemTemplate;
class UItemInstance;

UCLASS()
class EMBER_API APickupItemActor : public AEmberPickupableItemBase
{
    GENERATED_BODY()

public:
    APickupItemActor();

    void InitializeForLootDrop(TSubclassOf<UItemTemplate> InItemTemplateClass, int32 InQuantity, EItemRarity InRarity);

protected:
    virtual void BeginPlay() override;
};