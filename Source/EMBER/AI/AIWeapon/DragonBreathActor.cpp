#include "AI/AIWeapon/DragonBreathActor.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADragonBreathActor::ADragonBreathActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ADragonBreathActor::BeginPlay()
{
	Super::BeginPlay();

	if (BreathEffect)
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(
			GetWorld(),
			BreathEffect,
			GetActorLocation(),
			GetActorRotation()
			);
	}
}

void ADragonBreathActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SprayDamage();
}

void ADragonBreathActor::SprayDamage()
{
	const FVector Origin = GetActorLocation();
	const FRotator ForwardRot = GetActorRotation();

	const int32 NumTraces = FMath::Max(TraceCount, 1);
	const float AngleStep = (NumTraces > 1) ? TotalSpreadAngle / (NumTraces - 1) : 0.f;

	for (int32 i = 0; i < NumTraces; ++i)
	{
		const float AngleOffset = -TotalSpreadAngle / 2.f + i * AngleStep;
		const FRotator SpreadRot = ForwardRot + FRotator(0.f, AngleOffset, 0.f);
		const FVector End = Origin + SpreadRot.Vector() * TraceLength;

#if !(UE_BUILD_SHIPPING)
		DrawDebugSphere(
			GetWorld(),
			End,
			TraceRadius,
			12,
			FColor::Red,
			false,
			0.f,
			0,
			1.f);
#endif

		FHitResult Hit;
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(this);

		bool bHit = GetWorld()->SweepSingleByChannel(
			Hit,
			Origin,
			End,
			FQuat::Identity,
			ECC_Pawn,
			FCollisionShape::MakeSphere(TraceRadius),
			Params);

		if (bHit && Hit.GetActor() && !DamagedActors.Contains(Hit.GetActor()))
		{
			UGameplayStatics::ApplyDamage(
				Hit.GetActor(),
				Damage,
				GetInstigatorController(),
				this,
				UDamageType::StaticClass());

			DamagedActors.Add(Hit.GetActor());
		}
	}
}



