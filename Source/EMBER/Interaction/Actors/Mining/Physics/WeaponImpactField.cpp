// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponImpactField.h"

#include "Components/SphereComponent.h"
#include "Field/FieldSystemComponent.h"
#include "Field/FieldSystemObjects.h"

AWeaponImpactField::AWeaponImpactField(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;
	
	// SphereCollision
	{
		ForceMagnitude = 2500.f;
		SphereRadius = 25.f;
		SphereScaleMultiplier = 2.3f;
		
		MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMeshComponent"));
		MeshComponent->SetupAttachment(GetRootComponent());

		SphereCollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollisionComponent"));
		SphereCollisionComponent->SetSphereRadius(SphereRadius * SphereScaleMultiplier, true);
		// SphereCollisionComponent->SetHiddenInGame(false);
		MeshComponent->SetupAttachment(GetRootComponent());
	}

	// RadialFalloff
	{
		StrainMagnitude = 50000.f;
		
		RadialFalloffStrain = CreateDefaultSubobject<URadialFalloff>(TEXT("RadialFalloffStrain"));
		RadialFalloffStrain->SetRadialFalloff(StrainMagnitude, 0.f, 1.f, 0.f, SphereRadius * SphereScaleMultiplier, SphereCollisionComponent->GetComponentLocation(), EFieldFalloffType::Field_FallOff_None);

		FieldSystemComponent->AddFieldCommand(true, EFieldPhysicsType::Field_ExternalClusterStrain, nullptr, RadialFalloffStrain);
	}

	// RadialVector
	{
		RadialVectorForce = CreateDefaultSubobject<URadialVector>(TEXT("RadialVectorForce"));
		RadialVectorForce->SetRadialVector(ForceMagnitude, FieldSystemComponent->GetComponentLocation());
	}
}

void AWeaponImpactField::Init(float InForceMagnitude, float InSphereScaleMultiplier)
{
	ForceMagnitude = InForceMagnitude;
	SphereScaleMultiplier = InSphereScaleMultiplier;
}

void AWeaponImpactField::BeginPlay()
{
	Super::BeginPlay();
}
