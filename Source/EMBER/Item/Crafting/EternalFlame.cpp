#include "Item/Crafting/EternalFlame.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffect.h"

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
	if (!HasAuthority() || !WarmingGameplayEffect || !OtherActor) return;

	IAbilitySystemInterface* AbilitySystemInterface = Cast<IAbilitySystemInterface>(OtherActor);
	if (!AbilitySystemInterface) return;

	UAbilitySystemComponent* AbilitySystemComponent = AbilitySystemInterface->GetAbilitySystemComponent();
	if (!AbilitySystemComponent) return;

	if (WarmedActorsMap.Contains(OtherActor)) return;

	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);

	FActiveGameplayEffectHandle NewEffectHandle = AbilitySystemComponent->ApplyGameplayEffectToSelf(WarmingGameplayEffect->GetDefaultObject<UGameplayEffect>(), 1.0f, EffectContext);

	if (NewEffectHandle.IsValid())
	{
		WarmedActorsMap.Add(OtherActor, NewEffectHandle);
		UE_LOG(LogTemp, Log, TEXT("EternalFlame: Applied warming effect to %s"), *OtherActor->GetName());
	}
}

void AEternalFlame::OnWarmingZoneOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (!HasAuthority() || !OtherActor) return;

	FActiveGameplayEffectHandle* FoundHandle = WarmedActorsMap.Find(OtherActor);
	if (!FoundHandle || !FoundHandle->IsValid()) return;

	IAbilitySystemInterface* AbilitySystemInterface = Cast<IAbilitySystemInterface>(OtherActor);
	if (!AbilitySystemInterface) return;

	UAbilitySystemComponent* AbilitySystemComponent = AbilitySystemInterface->GetAbilitySystemComponent();
	if (!AbilitySystemComponent) return;

	AbilitySystemComponent->RemoveActiveGameplayEffect(*FoundHandle);
	WarmedActorsMap.Remove(OtherActor);
	UE_LOG(LogTemp, Log, TEXT("EternalFlame: Removed warming effect from %s"), *OtherActor->GetName());
}