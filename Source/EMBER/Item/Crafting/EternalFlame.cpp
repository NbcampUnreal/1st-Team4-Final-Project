#include "Item/Crafting/EternalFlame.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Interaction/EmberTemperature.h"
#include "Player/EmberPlayerCharacter.h" // 캐스팅에 필요

AEternalFlame::AEternalFlame()
{
	WarmingZone = CreateDefaultSubobject<USphereComponent>(TEXT("WarmingZone"));
	WarmingZone->SetupAttachment(GetRootComponent());
	WarmingZone->SetSphereRadius(800.0f);
	WarmingZone->SetCollisionProfileName(TEXT("Trigger"));
	WarmingZone->SetGenerateOverlapEvents(true);

	FlameEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FlameEffect"));
	FlameEffect->SetupAttachment(GetRootComponent());
}

void AEternalFlame::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		if (WarmingZone)
		{
			WarmingZone->OnComponentBeginOverlap.AddDynamic(this, &AEternalFlame::OnWarmingZoneOverlapBegin);
			WarmingZone->OnComponentEndOverlap.AddDynamic(this, &AEternalFlame::OnWarmingZoneOverlapEnd);
		}
	}
}

void AEternalFlame::OnWarmingZoneOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!HasAuthority() || !OtherActor) return;

	IEmberTemperature* TemperatureHandler = Cast<IEmberTemperature>(OtherActor);
	if (TemperatureHandler)
	{
		TemperatureHandler->Execute_ApplyWarmingEffect(OtherActor);
		UE_LOG(LogTemp, Log, TEXT("EternalFlame: Applied warming effect to %s"), *OtherActor->GetName());
	}
}

void AEternalFlame::OnWarmingZoneOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (!HasAuthority() || !OtherActor) return;
	
	IEmberTemperature* TemperatureHandler = Cast<IEmberTemperature>(OtherActor);
	if (TemperatureHandler)
	{
		TemperatureHandler->Execute_RemoveWarmingEffect(OtherActor);
		UE_LOG(LogTemp, Log, TEXT("EternalFlame: Removed warming effect from %s"), *OtherActor->GetName());
	}
}