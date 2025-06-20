#include "AI/AIWeapon/DragonSpitProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "NiagaraComponent.h"
#include "NiagaraSystem.h"

ADragonSpitProjectile::ADragonSpitProjectile()
{
	PrimaryActorTick.bCanEverTick = false;

	SpitCollision = CreateDefaultSubobject<USphereComponent>(FName("SpitCollision"));
	SpitCollision->InitSphereRadius(15.f);
	SpitCollision->SetCollisionProfileName("Custom");
	SpitCollision->IgnoreActorWhenMoving(this, true);
	SpitCollision->OnComponentHit.AddDynamic(this, &ADragonSpitProjectile::OnHit);
	SetRootComponent(SpitCollision);

	SpitEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("SpitEffect"));
	SpitEffect->SetupAttachment(SpitCollision);
	SpitEffect->SetAutoActivate(false);

	SpitMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("SpitMovement"));
	SpitMovement->InitialSpeed = 1000.f;
	SpitMovement->MaxSpeed = 1000.f;
	SpitMovement->bRotationFollowsVelocity = true;
	SpitMovement->bShouldBounce = false;

	InitialLifeSpan = 3.f;
}

void ADragonSpitProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void ADragonSpitProjectile::SetTargetActor(AActor* Target)
{
	TargetActor = Target;
	
	if (!TargetActor || !SpitMovement) return;
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("TargetActor: %s"), *GetNameSafe(TargetActor)));

	FVector Direction = (TargetActor->GetActorLocation() - GetActorLocation()).GetSafeNormal();
	SpitMovement->Velocity = Direction * SpitMovement->InitialSpeed;

	if (SpitNiagara && SpitEffect)
	{
		SpitEffect->SetAsset(SpitNiagara);
		SpitEffect->Activate();
	}
}

void ADragonSpitProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	Destroy();
}


