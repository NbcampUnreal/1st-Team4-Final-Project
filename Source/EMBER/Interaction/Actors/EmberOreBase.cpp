// Fill out your copyright notice in the Description page of Project Settings.


#include "EmberOreBase.h"

#include "Field/FieldSystemActor.h"
#include "GameInfo/GameplayTags.h"
#include "GeometryCollection/GeometryCollectionComponent.h"
#include "kismet/GameplayStatics.h"
#include "Mining/Physics/ChaosAnchorField.h"
#include "Mining/Physics/WeaponImpactField.h"

AEmberOreBase::AEmberOreBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	RequiredTags.AddTag(EmberGameplayTags::Ability_Mining);

	AnchorField = CreateDefaultSubobject<UChildActorComponent>("AnchorField");
	AnchorField->SetChildActorClass(AChaosAnchorField::StaticClass());
	
	GeometryCollection = CreateDefaultSubobject<UGeometryCollectionComponent>("GeometryCollection");
	GeometryCollection->SetGenerateOverlapEvents(true);
	GeometryCollection->SetCollisionProfileName(TEXT("Mineable"));
}

void AEmberOreBase::BeginPlay()
{
	Super::BeginPlay();

	OnTakePointDamage.AddDynamic(this, &ThisClass::HandlePointDamage);
	GeometryCollection->OnChaosBreakEvent.AddDynamic(this, &ThisClass::HandleBreakEvent);
}

void AEmberOreBase::HandlePointDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy,
	FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector ShotFromDirection,
	const UDamageType* DamageType, AActor* DamageCauser)
{
	if (HasAuthority() == false)
		return;

	if (ChaosImpactClass == nullptr)
		return;

	FTransform SpawnTransform = FTransform::Identity;
	SpawnTransform.SetLocation(HitLocation);
	
	AWeaponImpactField* WeaponImpact = GetWorld()->SpawnActorDeferred<AWeaponImpactField>(
		ChaosImpactClass,
		SpawnTransform,
		nullptr,
		nullptr,
		ESpawnActorCollisionHandlingMethod::AlwaysSpawn,
		ESpawnActorScaleMethod::MultiplyWithRoot
	);
	
	if (WeaponImpact)
	{
		// TODO : 무기에 따른 충돌 물리 계산 필요
		float ForceMagnitude = 37000.f;
		float SphereScaleMultiplier = 2.f;
		
		WeaponImpact->Init(ForceMagnitude, SphereScaleMultiplier);
		UGameplayStatics::FinishSpawningActor(WeaponImpact, SpawnTransform);
	}
}

void AEmberOreBase::HandleBreakEvent(const FChaosBreakEvent& BreakEvent)
{
	if (HasAuthority() == false)
		return;

	// 특정 임계치를 넘어가면 돌을 제거한다.

	UE_LOG(LogTemp, Warning, TEXT("Break Event"));
}
