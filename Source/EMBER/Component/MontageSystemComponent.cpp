#include "MontageSystemComponent.h"
#include "GameFramework/Pawn.h"
#include "Components/SkeletalMeshComponent.h"

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
		if (APawn* Pawn = Cast<APawn>(Owner))
		{
			if (USkeletalMeshComponent* MeshComp = Owner->FindComponentByClass<USkeletalMeshComponent>())
			{
				AnimInstance = MeshComp->GetAnimInstance();
				if (AnimInstance)
				{
					FOnMontageEnded EndDelegate;
					EndDelegate.BindUObject(this, &UMontageSystemComponent::OnMontageEnded);
					AnimInstance->OnMontageEnded.AddDynamic(this, &UMontageSystemComponent::OnMontageEnded);
				}
			}
		}
	}
}
void UMontageSystemComponent::RequestPlayMontage(UAnimMontage* Montage, float PlayRate, FName SectionName)
{
	if (ValidateRequestPlayMontage(Montage, PlayRate, SectionName))
	{
		ServerPlayMontage(Montage, PlayRate, SectionName);
	}
}

void UMontageSystemComponent::ServerPlayMontage_Implementation(UAnimMontage* Montage, float PlayRate, FName SectionName)
{
	if (!Montage) return;

	// 서버에서 재생 승인 후
	MulticastPlayMontage(Montage, PlayRate, SectionName);
}
bool UMontageSystemComponent::ServerPlayMontage_Validate(UAnimMontage* Montage, float PlayRate, FName SectionName)
{
	return true;
}

void UMontageSystemComponent::OnMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	if (Montage && Montage == CurrentMontage)
	{
		// 재생 종료 처리
		CurrentMontage = nullptr;
	}
}

bool UMontageSystemComponent::ValidateRequestPlayMontage(UAnimMontage* Montage, float PlayRate, FName SectionName)
{
	return Montage != nullptr && GetOwner()->HasAuthority() == false; // 클라이언트에서만 호출
}
void UMontageSystemComponent::MulticastPlayMontage_Implementation(UAnimMontage* Montage, float PlayRate, FName SectionName)
{
	if (AnimInstance && Montage)
	{
		CurrentMontage = Montage;
		AnimInstance->Montage_Play(Montage, PlayRate);
		if (SectionName != NAME_None)
		{
			AnimInstance->Montage_JumpToSection(SectionName, Montage);
		}
	}
}
void UMontageSystemComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UMontageSystemComponent, CurrentMontage);
	// 필요시 다른 변수들도 등록
}