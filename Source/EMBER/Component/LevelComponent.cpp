#include "Component/LevelComponent.h"
#include "LevelBase.h"
ULevelComponent::ULevelComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void ULevelComponent::AddExpToCategory(ESkillCategory Category, int32 Amount)
{
    if (!CategoryLevel.Contains(Category))
    {
        ULevelBase* NewLevel = NewObject<ULevelBase>(this);
        NewLevel->SetCategory(Category);
        CategoryLevel.Add(Category, NewLevel);
    }

    CategoryLevel[Category]->AddExp(Amount);
}

int32 ULevelComponent::GetAvailablePoints(ESkillCategory Category) const
{
	return int32();
}

bool ULevelComponent::SpendPoint(ESkillCategory Category)
{
	return false;
}

void ULevelComponent::BeginPlay()
{
	Super::BeginPlay();
}

void ULevelComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}