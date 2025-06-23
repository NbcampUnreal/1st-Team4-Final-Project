#include "AI/Boss/Dragon.h"
#include "CAIController.h"
#include "AIWeapon/DragonSpitProjectile.h"
#include "AIWeapon/DragonBreathActor.h"
#include "BehaviorTree/CBehaviorTreeComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ADragon::ADragon()
{
}

void ADragon::BeginPlay()
{
	Super::BeginPlay();

	AIController = Cast<ACAIController>(GetController());
	BTComp = FindComponentByClass<UCBehaviorTreeComponent>();
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
}
