#include "AI/Boss/Dragon.h"
#include "CAIController.h"
#include "AIWeapon/DragonSpitProjectile.h"
#include "AIWeapon/DragonBreathActor.h"
#include "AIWeapon/DragonMeteorSpawner.h"
#include "AnimInstance/DragonAnimInstance.h"
#include "BehaviorTree/CBehaviorTreeComponent.h"
#include "Task/BTT_DragonMeteor.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"

ADragon::ADragon()
{
}

void ADragon::BeginPlay()
{
	Super::BeginPlay();

	AIController = Cast<ACAIController>(GetController());
	BTComp = FindComponentByClass<UCBehaviorTreeComponent>();
}

void ADragon::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (bOrbiting)
	{
		UpdateOrbit(DeltaSeconds);
	}
}

void ADragon::SpawnSpit()
{
	if (!SpitClass || !BTComp)
	{
		UE_LOG(LogTemp, Error, TEXT("SpawnSpit() aborted: SpitClass or BTComp is null"));
		return;
	}

	TargetActor = BTComp->GetTarget();

	if (!TargetActor)
	{
		UE_LOG(LogTemp, Error, TEXT("SpawnSpit() aborted: TargetActor is null"));
		return;
	}
	
	FVector SpawnLocation = GetMesh()->GetSocketLocation(TEXT("MouthSocket"));
	FVector Direction = (TargetActor->GetActorLocation() - SpawnLocation).GetSafeNormal();
	FRotator SpawnRotation = Direction.Rotation();

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.Instigator = GetInstigator();
	
	ADragonSpitProjectile* SpitProjectile = GetWorld()->SpawnActor<ADragonSpitProjectile>(SpitClass, SpawnLocation, SpawnRotation, SpawnParams);
	if (SpitProjectile)
	{
		SpitProjectile->SetTargetActor(TargetActor);
	}
}

void ADragon::SpawnBreath()
{
	if (!BreathClass || !BTComp)
	{
		UE_LOG(LogTemp, Error, TEXT("SpawnBreath() aborted: BreathClass or BTComp is null"));
		return;
	}

	if (CurrentBreath) return;

	TargetActor = BTComp->GetTarget();

	if (!TargetActor)
	{
		UE_LOG(LogTemp, Error, TEXT("SpawnBreath() aborted: TargetActor is null"));
		return;
	}
	
	FVector SpawnLocation = GetMesh()->GetSocketLocation(TEXT("MouthSocket"));
	FVector Direction = (TargetActor->GetActorLocation() - SpawnLocation).GetSafeNormal();
	FRotator SpawnRotation = Direction.Rotation();

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.Instigator = GetInstigator();

	CurrentBreath = GetWorld()->SpawnActor<ADragonBreathActor>(
		BreathClass,
		SpawnLocation,
		SpawnRotation,
		SpawnParams
		);

	if (CurrentBreath)
	{
		CurrentBreath->AttachToComponent(
			GetMesh(),
			FAttachmentTransformRules::SnapToTargetNotIncludingScale,
			TEXT("MouthSocket")
			);
	}
}

void ADragon::StopBreath()
{
	if (CurrentBreath)
	{
		CurrentBreath->Destroy();
		CurrentBreath = nullptr;
	}
}

void ADragon::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);

	GetCharacterMovement()->SetMovementMode(MOVE_Walking);

	if (LandingEffect)
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(
			GetWorld(),
			LandingEffect,
			Hit.ImpactPoint,
			FRotator::ZeroRotator,
			FVector(3.f),
			true,
			true,
			ENCPoolMethod::None,
			true);
	}
	if (CurrentMeteorTask)
	{
		if (UDragonAnimInstance* DragonAnim = Cast<UDragonAnimInstance>(GetMesh()->GetAnimInstance()))
		{
			DragonAnim->Montage_Stop(0.2f);
		}
		
		CurrentMeteorTask->FinishFromLanded();
		CurrentMeteorTask = nullptr;
	}
}

void ADragon::OnDeath()
{
	Super::OnDeath();

	if (CurrentMeteorSpawner)
	{
		CurrentMeteorSpawner->Destroy();
		CurrentMeteorSpawner = nullptr;
	}
}

void ADragon::StartMeteorPhase()
{
	if (bMeteorStarted) return;
	bMeteorStarted = true;

	if (MeteorSpawnerClass && !CurrentMeteorSpawner)
	{
		FVector SpawnLocation = GetActorLocation() + FVector(0, 0, 2000.f);
		CurrentMeteorSpawner = GetWorld()->SpawnActor<ADragonMeteorSpawner>(
			MeteorSpawnerClass,
			SpawnLocation,
			FRotator::ZeroRotator);

		if (CurrentMeteorSpawner)
		{
			CurrentMeteorSpawner->Initialize(this);
		}
	}

	bOrbiting = true;
	OrbitAngle = 0.f;
	OrbitCenter = GetActorLocation();
}

void ADragon::UpdateOrbit(float DeltaTime)
{
	const float OrbitSpeed = 90.f;
	const float OrbitRadius = 800.f;

	OrbitAngle += OrbitSpeed * DeltaTime;
	const float Radians = FMath::DegreesToRadians(OrbitAngle);
	const FVector Offset = FVector(FMath::Cos(Radians), FMath::Sin(Radians), 0.f) * OrbitRadius;

	FVector NewLocation = OrbitCenter + Offset;
	NewLocation.Z = GetActorLocation().Z;

	SetActorLocation(NewLocation);
	SetActorRotation((OrbitCenter - NewLocation).Rotation());

	if (OrbitAngle >= 360.f)
	{
		bOrbiting = false;
	}
}
