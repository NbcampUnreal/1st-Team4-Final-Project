// Fill out your copyright notice in the Description page of Project Settings.


#include "ChaosAnchorField.h"

#include "Field/FieldSystemComponent.h"
#include "Field/FieldSystemObjects.h"

AChaosAnchorField::AChaosAnchorField(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Cube");
	StaticMeshComponent->SetupAttachment(RootComponent);

	BoxFalloff = CreateDefaultSubobject<UBoxFalloff>(TEXT("BoxFalloff"));
	BoxFalloff->SetBoxFalloff(FieldMagnitude, MinRange, MaxRange, 0.f, StaticMeshComponent->GetComponentTransform(), EFieldFalloffType::Field_FallOff_None);
	
	UniformInteger = CreateDefaultSubobject<UUniformInteger>(TEXT("UniformInteger"));
	UniformInteger->SetUniformInteger(static_cast<int32>(Chaos::EObjectStateType::Static));
	
	CullingField = CreateDefaultSubobject<UCullingField>(TEXT("CullingField"));
	CullingField->SetCullingField(BoxFalloff, UniformInteger, EFieldCullingOperationType::Field_Culling_Outside);

	FieldSystemComponent->AddFieldCommand(true, EFieldPhysicsType::Field_DynamicState, nullptr, CullingField);
}
