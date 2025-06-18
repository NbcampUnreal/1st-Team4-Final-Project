#include "AI/AIWeapon/DragonSpitProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"

ADragonSpitProjectile::ADragonSpitProjectile()
{
	PrimaryActorTick.bCanEverTick = false;

	SpitCollision = CreateDefaultSubobject<USphereComponent>(FName("SpitCollision"));
	SpitCollision->InitSphereRadius(15.f);
	SpitCollision->SetCollisionProfileName("Projectile");
	SpitCollision->IgnoreActorWhenMoving(this, true);
	SpitCollision->OnComponentHit.AddDynamic(this, &ADragonSpitProjectile::OnHit);
	SetRootComponent(SpitCollision);

	// SpitMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpitMesh"));
	// SpitMesh->SetupAttachment(SpitCollision);
	// SpitMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

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

	if (SpitNiagara)
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


