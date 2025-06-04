#include "AI/Boss/Griffon.h"

#include "C_StateComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AI/AnimInstance/BaseAIAnimInstance.h"
#include "AnimInstance/Griffon_AnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "kismet/GameplayStatics.h"

AGriffon::AGriffon()
{
	MaxHP = 20.0f;
	AttackPower = 10.0f;
	WalkSpeed = 250.f;
	RunSpeed = 750.f;
	FlySpeed = 1200.0f;
	PrimaryActorTick.bCanEverTick = true;
}

void AGriffon::BeginPlay()
{
	ABaseAI::BeginPlay();
}

void AGriffon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetActorLocation().Z > 700.0f)
	{
		GetCharacterMovement()->Velocity.Z = 0.0f;
	}

	if (GetCharacterMovement()->IsMovingOnGround())
	{
		GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	}
}

void AGriffon::Attack()
{
	//AActor* TargetActor = Cast<AActor>(BlackboardComp->GetValueAsObject(("TargetActor")));
	AActor* TargetActor = Cast<AActor>(Behavior.Get()->GetTarget());
	if(TargetActor == nullptr)
	{
		UE_LOG(LogTemp, Error, L"Target is Null");
		return;
	}
	UBaseAIAnimInstance* AnimInstance = Cast<UBaseAIAnimInstance>(GetMesh()->GetAnimInstance());

	UGameplayStatics::ApplyDamage(TargetActor, AttackPower, GetController(), this, nullptr);
	GetController()->StopMovement();

	AIState->SetActionMode();
	// AnimalState = EAnimalState::Attack;
	// AnimInstance->AnimalState = EAnimalState::Attack;
	// AnimInstance->PlayStateMontage();
}

//void AGriffon::OnTargetPerceptionUpdated(AActor* UpdatedActor, FAIStimulus Stimulus)
//{
//	Super::OnTargetPerceptionUpdated(UpdatedActor, Stimulus);
//	
//	// SetBlackboardVector("OriginLocation", GetActorLocation());
//}

void AGriffon::SetCombatState()
{
	SetRunSpeed();
}
