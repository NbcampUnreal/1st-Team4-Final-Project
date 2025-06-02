#include "AI/HumanAIBase.h"

#include "C_CharacterMovementComponent.h"
#include "C_StateComponent.h"
#include "MontageSystemComponent.h"
#include "StatusComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/CBehaviorTreeComponent.h"

AHumanAIBase::AHumanAIBase()
{
	StateComponent = CreateDefaultSubobject<UC_StateComponent>(TEXT("State Component"));
	MoveComponent = CreateDefaultSubobject<UC_CharacterMovementComponent>(TEXT("Move Component"));
	Behavior = CreateDefaultSubobject<UCBehaviorTreeComponent>(TEXT("BehaviorTree"));
}

void AHumanAIBase::BeginPlay()
{
	Super::BeginPlay();
	MoveComponent->OnWalk();
	//StateComponent->OnStateTypeChanged.AddDynamic(this, &AHumanAIBase::OnStateTypeChanged);

}

void AHumanAIBase::OnStateTypeChanged(EStateType InPrevType, EStateType InNewType)
{

}

