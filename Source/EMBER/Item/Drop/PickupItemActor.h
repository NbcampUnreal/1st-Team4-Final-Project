#pragma once

#include "CoreMinimal.h"
#include "Interaction/Actors/Pickup/EmberPickupableItemBase.h"
#include "Interaction/EmberInteractable.h"
#include "GameFlag.h"
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
class EMBER_API APickupItemActor : public AEmberPickupableItemBase, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	APickupItemActor();

	void InitializeLootPouch(const TArray<FLootResultData>& InLootData);

	virtual FEmberInteractionInfo GetPreInteractionInfo(const FEmberInteractionQuery& InteractionQuery) const override;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UFUNCTION(BlueprintCallable, Category = "PickupItem")
	void OnItemAcquired(AActor* InteractingActor);

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USphereComponent> InteractionSphere;

	UPROPERTY(EditDefaultsOnly, Category = "PickupItem|UI")
	TSubclassOf<UUserWidget> InteractionPromptWidgetClass;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, ReplicatedUsing = OnRep_LootContents, Category = "Loot Pouch")
	TArray<FLootResultData> LootContents;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UEmberAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(EditDefaultsOnly, Category = "PickupItem|Gameplay")
	TSubclassOf<UGameplayEffect> ItemAcquisitionEffect;
	
	UPROPERTY(EditDefaultsOnly, Category = "PickupItem|Gameplay")
    TSubclassOf<UEmberGameplayAbility_Interact_Object> InteractAbilityClass;

	UFUNCTION()
	void OnRep_LootContents();

	UFUNCTION()
	void ApplyItemAcquisitionEffect(AActor* TargetActor);

private:
	UFUNCTION()
	void OnInteractionSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnInteractionSphereOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY()
	TObjectPtr<UUserWidget> InteractionPromptWidget;

	UPROPERTY()
	FGameplayAbilitySpecHandle InteractAbilityHandle;
};