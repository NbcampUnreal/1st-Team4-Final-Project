#pragma once

#include "CoreMinimal.h"
#include "Interaction/Actors/Pickup/EmberPickupableItemBase.h"
#include "Interaction/EmberInteractable.h"
#include "Item/Drop/LootTable.h"
#include "Components/SphereComponent.h"
#include "AbilitySystemInterface.h"
#include "GameplayAbilitySpec.h"
#include "PickupItemActor.generated.h"

class UItemTemplate;
class UItemInstance;
class UUserWidget;
class UAbilitySystemComponent;
class UGameplayEffect;
class UEmberAbilitySystemComponent;
class UEmberGameplayAbility_Interact_Object;

UCLASS()
class EMBER_API APickupItemActor : public AEmberPickupableItemBase
{
	GENERATED_BODY()

public:
	APickupItemActor();

	void InitializeLootPouch(const FLootResultData& InLootData);

protected:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, ReplicatedUsing = OnRep_LootContents, Category = "Loot Pouch")
	FLootResultData LootContent;

	UFUNCTION()
	void OnRep_LootContents();
};