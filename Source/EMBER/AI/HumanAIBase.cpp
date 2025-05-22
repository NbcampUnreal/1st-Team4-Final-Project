#include "AI/HumanAIBase.h"

#include "C_StateComponent.h"
#include "StatusComponent.h"

AHumanAIBase::AHumanAIBase()
{
	StateComponent = CreateDefaultSubobject<UC_StateComponent>(TEXT("State Component"));
}

void AHumanAIBase::BeginPlay()
{
	Super::BeginPlay();
	if(MaxHP != 0)
		StatusComponent.Get()->SetMaxHp(MaxHP);
}

