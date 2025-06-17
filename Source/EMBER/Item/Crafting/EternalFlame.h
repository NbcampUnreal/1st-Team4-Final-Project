#pragma once

#include "CoreMinimal.h"
#include "Item/Crafting/CraftingBuilding.h"
#include "EternalFlame.generated.h"

class UParticleSystemComponent;
class USphereComponent;

UCLASS()
class EMBER_API AEternalFlame : public ACraftingBuilding
{
	GENERATED_BODY()

public:
	AEternalFlame();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USphereComponent> WarmingZone;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UParticleSystemComponent> FlameEffect;

private:
	UFUNCTION()
	void OnWarmingZoneOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnWarmingZoneOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};