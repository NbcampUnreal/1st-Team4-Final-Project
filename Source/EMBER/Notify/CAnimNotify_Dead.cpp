// Fill out your copyright notice in the Description page of Project Settings.


#include "Notify/CAnimNotify_Dead.h"

#include "AIComponent/CAIWeaponComponent.h"
#include "GameFramework/Character.h"

void UCAnimNotify_Dead::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                               const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
	if (MeshComp == nullptr)
	{
		UE_LOG(LogTemp, Error, L"Mesh Component is null");
		return;
	}
	if (MeshComp->GetOwner() == nullptr)
	{
		UE_LOG(LogTemp, Error, L"Owner Actor is null");
		return;
	}

	ACharacter* Character = Cast<ACharacter>(MeshComp->GetOwner());
	if (Character == nullptr)
	{
		UE_LOG(LogTemp, Error, L"Character is null");
		return;
	}
	UCAIWeaponComponent* weapon = Cast<UCAIWeaponComponent>(Character->GetComponentByClass(UCAIWeaponComponent::StaticClass()));
	if (weapon != nullptr)
	{
		weapon->DestroyWeapon();
	}
	Character->Destroy();
}

FString UCAnimNotify_Dead::GetNotifyName_Implementation() const
{
	return "Dead";
}
