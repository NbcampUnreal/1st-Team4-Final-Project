#include "MonsterAIBase.h"

#include "ALootManagerActor.h"
#include "AI/MonsterAIController.h"
#include "GAS/EmberAbilitySystemComponent.h"
#include "AI/AbilitySystem/MonsterGameplayEffectComponent.h"
#include "AI/AbilitySystem/Abilities/MonsterGameplayAbility.h"
#include "AI/Data/MonsterAIData.h"
#include "AI/Data/MonsterAITemplate.h"
#include "AI/Weapon/MonsterAIWeapon.h"
#include "MonsterAIAttributeSet.h"
#include "AI/Components/HealthComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerState.h"
#include "GAS/Attribute/EmberAS_Player.h"
#include "Perception/AISense_Damage.h"

AMonsterAIBase::AMonsterAIBase()
{
	AIControllerClass = AMonsterAIController::StaticClass();

	if (!ASC)
	{
		ASC = CreateDefaultSubobject<UEmberAbilitySystemComponent>(TEXT("MonsterASC"));
		ASC->SetIsReplicated(true);
		ASC->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	}

	AttributeSet = CreateDefaultSubobject<UEmberAS_Player>(TEXT("AttributeSet"));

	UE_LOG(LogTemp, Warning, TEXT("EmberBaseCharacter Constructor - ASC: %s"),
		ASC ? *ASC->GetName() : TEXT("Null"));
	UE_LOG(LogTemp, Warning, TEXT("EmberBaseCharacter Constructor - this: %s"),
		*GetName());
	//HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
}

void AMonsterAIBase::PostInitializeComponents()
{
	UE_LOG(LogTemp, Warning, TEXT("MonsterAIBase PostInitializeComponents START - ASC: %s"),
		ASC ? TEXT("Valid") : TEXT("Null"));
	Super::PostInitializeComponents();
	UE_LOG(LogTemp, Warning, TEXT("MonsterAIBase PostInitializeComponents END - ASC: %s"),
		ASC ? TEXT("Valid") : TEXT("Null"));
}

void AMonsterAIBase::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("MonsterAIBase BeginPlay START - ASC: %s"),
		ASC ? TEXT("Valid") : TEXT("Null"));
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("MonsterAIBase BeginPlay AFTER Super - ASC: %s"),
		ASC ? TEXT("Valid") : TEXT("Null"));
	if (ASC)
	{
		ASC->InitAbilityActorInfo(this, this);
		UE_LOG(LogTemp, Warning, TEXT("ASC Valid"));
	}
	if (HasAuthority())
	{
		InitializeMonsterAI();
	}

	/*if (HealthComponent)
	{
		HealthComponent->OnDeath.BindUObject(this, &ThisClass::OnDeath);
	}*/
}

void AMonsterAIBase::InitializeMonsterAI()
{
	const UMonsterAITemplate& MonsterAITemplate = UMonsterAIData::Get().FindMonsterAITemplateByClass(GetClass());

	/* Create Weapon */
	if (MonsterAITemplate.WeaponClass)
	{
		UWorld* World = GetWorld();
		WeaponActor = World->SpawnActorDeferred<AMonsterAIWeapon>(MonsterAITemplate.WeaponClass, FTransform::Identity, this);
		WeaponActor->SetActorRelativeTransform(MonsterAITemplate.WeaponAttachTransform);
		WeaponActor->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, MonsterAITemplate.WeaponAttachSocket);
		WeaponActor->FinishSpawning(FTransform::Identity, true);
	}

	/* Grant Ability*/
	if (ASC)
	{
		for (const FEmberAbilitySet_GameplayAbility& AbilityToGrant : MonsterAITemplate.GrantedGameplayAbilities)
		{
			if (!IsValid(AbilityToGrant.Ability))
				continue;	
			
			UMonsterGameplayAbility* AbilityCDO = AbilityToGrant.Ability->GetDefaultObject<UMonsterGameplayAbility>();

			FGameplayAbilitySpec AbilitySpec(AbilityCDO, 1);
			AbilitySpec.SourceObject = this;
			AbilitySpec.DynamicAbilityTags.AddTag(AbilityToGrant.GameplayTag);

			ASC->GiveAbility(AbilitySpec);
		}
	}

	if (HealthComponent)
	{
		HealthComponent->OnHealthChanged.AddDynamic(this, &ThisClass::HandleHealthChanged);
	}
}

void AMonsterAIBase::HandleHealthChanged(UHealthComponent* InHealthComponent, float OldValue, float NewValue, AActor* DamageInstigator)
{
	if (DamageInstigator == nullptr)
		return;

	APlayerState* PS = Cast<APlayerState>(DamageInstigator);
	if (PS == nullptr)
		return;

	APawn* InstigatorPawn = PS->GetPawn();
	if (InstigatorPawn == nullptr)
		return;
	
	if (AAIController* AIController = Cast<AAIController>(GetController()))
	{
		const float DamageAmount = OldValue - NewValue;
		
		UAISense_Damage::ReportDamageEvent(
			GetWorld(),
			this,
			InstigatorPawn,
			DamageAmount,
			InstigatorPawn->GetActorLocation(),
			GetActorLocation()
		);
	}
}


void AMonsterAIBase::OnDeath()
{
	if (HasAuthority())
	{
		if (WeaponActor)
		{
			WeaponActor->Destroy();
		}

		///* 몬스터 아이템 드랍 */
		if (ALootManagerActor* LootManager = ALootManagerActor::GetLootManager(this))
		{
			FMonsterDiedMessage Msg;
			Msg.MonsterID = FName("Test");
			Msg.DeathLocation = GetActorLocation();
			
			ILootableInterface::Execute_NotifyMonsterDied(LootManager, Msg);
		
		}
	}
	
	DisableMovementAndCollision();
}

void AMonsterAIBase::DisableMovementAndCollision()
{
	if (AAIController* AIController = Cast<AAIController>(GetController()))
	{
		AIController->UnPossess();
	}

	if (UCapsuleComponent* Capsule = GetCapsuleComponent())
	{
		Capsule->SetCollisionResponseToAllChannels(ECR_Ignore);
		Capsule->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
		Capsule->SetCollisionResponseToChannel(ECC_WorldDynamic,ECR_Block);
	}

	if (USkeletalMeshComponent* SkeletalMesh = GetMesh())
	{
		SkeletalMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
	}

	if (UCharacterMovementComponent* MonsterAIMovement = GetCharacterMovement())
	{
		MonsterAIMovement->Velocity = FVector(0.f, 0.f, MonsterAIMovement->Velocity.Z);
		MonsterAIMovement->UpdateComponentVelocity();
	}
}
