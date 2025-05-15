#include "MontageSystemComponent.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"
#include "Net/UnrealNetwork.h"

UMontageSystemComponent::UMontageSystemComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	SetIsReplicatedByDefault(true);
}

void UMontageSystemComponent::BeginPlay()
{
    Super::BeginPlay();

    if (AActor* Owner = GetOwner())
    {
        MeshComp = Owner->FindComponentByClass<USkeletalMeshComponent>();
        if (MeshComp)
        {
            AnimInstance = MeshComp->GetAnimInstance();
        }
    }
}

void UMontageSystemComponent::MulticastPlayMontage_Implementation(UAnimMontage* Montage, float PlayRate, FName SectionName)
{
    if (AnimInstance)
    {
        float Duration = AnimInstance->Montage_Play(Montage,PlayRate);

        if (Duration > 0.f)
        {
            // Start at a given Section.
            if (SectionName != NAME_None)
            {
                AnimInstance->Montage_JumpToSection(SectionName, Montage);
            }
        }
    }
}

void UMontageSystemComponent::ServerPlayMontage_Implementation(UAnimMontage* Montage, float PlayRate, FName SectionName)
{
    if (AnimInstance)
    {
        MulticastPlayMontage(Montage, PlayRate);
    }
}

bool UMontageSystemComponent::ServerPlayMontage_Validate(UAnimMontage* Montage, float PlayRate, FName SectionName)
{
    return true;  // 여기에 검증 로직 추가 가능
}

void UMontageSystemComponent::PlayMontage(UAnimMontage* Montage, float PlayRate, FName SectionName)
{
    if (!Montage)
    {
        UE_LOG(LogTemp, Warning, TEXT("Montage is null!"));
        return;
    }

    if (AActor* Owner = GetOwner())
    {
        if (Owner->HasAuthority())
        {
            // 서버인 경우 바로 호출
            MulticastPlayMontage(Montage, PlayRate, SectionName);
        }
        else
        {
            // 클라이언트인 경우 서버에 요청
            ServerPlayMontage(Montage, PlayRate, SectionName);
        }
    }
}