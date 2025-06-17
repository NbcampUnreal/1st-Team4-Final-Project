#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DragonSpitProjectile.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UProjectileMovementComponent;

UCLASS()
class EMBER_API ADragonSpitProjectile : public AActor
{
	GENERATED_BODY()
	
public:
	ADragonSpitProjectile();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	USphereComponent* SpitCollision;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* SpitMesh;

	UPROPERTY(VisibleAnywhere)
	UProjectileMovementComponent* SpitMovement;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
};
