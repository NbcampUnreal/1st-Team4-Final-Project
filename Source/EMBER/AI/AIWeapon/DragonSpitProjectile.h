#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DragonSpitProjectile.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UProjectileMovementComponent;
class UNiagaraComponent;
class UNiagaraSystem;

UCLASS()
class EMBER_API ADragonSpitProjectile : public AActor
{
	GENERATED_BODY()
	
public:
	ADragonSpitProjectile();
	void SetTargetActor(AActor* Target);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	USphereComponent* SpitCollision;

	UPROPERTY(VisibleAnywhere)
	UNiagaraComponent* SpitEffect;
	
	UPROPERTY(EditDefaultsOnly)
	UNiagaraSystem* SpitNiagara;

	UPROPERTY(VisibleAnywhere)
	UProjectileMovementComponent* SpitMovement;

	AActor* TargetActor = nullptr;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
};
