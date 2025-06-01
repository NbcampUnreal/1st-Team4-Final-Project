#include "Component/EmberLevelComponent.h"
#include "LevelBase.h"
UEmberLevelComponent::UEmberLevelComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UEmberLevelComponent::AddExpToCategory(ESkillCategory Category, int32 Amount)
{
    if (!CategoryLevel.Contains(Category))
    {
        ULevelBase* NewLevel = NewObject<ULevelBase>(this);
        NewLevel->SetCategory(Category);
        CategoryLevel.Add(Category, NewLevel);
    }

    CategoryLevel[Category]->AddExp(Amount);
}

int32 UEmberLevelComponent::GetAvailablePoints(ESkillCategory Category) const
{
	return int32();
}

bool UEmberLevelComponent::SpendPoint(ESkillCategory Category)
{
	return false;
}

void UEmberLevelComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UEmberLevelComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}