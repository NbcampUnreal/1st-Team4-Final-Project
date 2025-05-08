#include "C_CharacterStatusComponent.h"

UC_CharacterStatusComponent::UC_CharacterStatusComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UC_CharacterStatusComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UC_CharacterStatusComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

float UC_CharacterStatusComponent::GetCurrentHP() const
{
	return Status.CurrentHP;
}

float UC_CharacterStatusComponent::GetMaxHP() const
{
	return Status.MaxHP;
}

float UC_CharacterStatusComponent::GetCurrentStamina() const
{
	return Status.CurrentStamina;
}

float UC_CharacterStatusComponent::GetMaxStamina() const
{
	return Status.MaxStamina;
}

float UC_CharacterStatusComponent::GetCurrentTemperature() const
{
	return Status.CurrentTemperature;
}

float UC_CharacterStatusComponent::GetMaxTemperature() const
{
	return Status.MaxTemperature;
}

float UC_CharacterStatusComponent::GetCurrentFatigueLevel() const
{
	return Status.CurrentFatigueLevel;
}

float UC_CharacterStatusComponent::GetMaxFatigueLevel() const
{
	return Status.MaxFatigueLevel;
}

float UC_CharacterStatusComponent::GetCurrentWeight() const
{
	return Status.CurrentWeight;
}

float UC_CharacterStatusComponent::GetMaxWeight() const
{
	return Status.MaxWeight;
}

float UC_CharacterStatusComponent::GetCurrentEnergy() const
{
	return Status.CurrentEnergy;
}

float UC_CharacterStatusComponent::GetMaxEnergy() const
{
	return Status.MaxEnergy;
}

float UC_CharacterStatusComponent::GetCurrentPhysicalStrength() const
{
	return Status.CurrentPhysicalStrength;
}

float UC_CharacterStatusComponent::GetMaxPhysicalStrength() const
{
	return Status.MaxPhysicalStrength;
}

float UC_CharacterStatusComponent::GetCurrentDexterity() const
{
	return Status.CurrentDexterity;
}

float UC_CharacterStatusComponent::GetMaxDexterity() const
{
	return Status.MaxDexterity;
}

float UC_CharacterStatusComponent::GetCurrentXP() const
{
	return Status.CurrentXP;
}

float UC_CharacterStatusComponent::GetMaxXP() const
{
	return Status.MaxHP;
}

int32 UC_CharacterStatusComponent::GetLevel() const
{
	return Status.Level;
}

void UC_CharacterStatusComponent::SetCurrentHP(const float Amount)
{
	Status.CurrentHP = Amount;
}

void UC_CharacterStatusComponent::SetMaxHP(const float Amount)
{
	Status.MaxHP = Amount;
}

void UC_CharacterStatusComponent::SetCurrentStamina(const float Amount)
{
	Status.CurrentStamina = Amount;
}

void UC_CharacterStatusComponent::SetMaxStamina(const float Amount)
{
	Status.MaxStamina = Amount;
}

void UC_CharacterStatusComponent::SetMaxTemperature(const float Amount)
{
	Status.MaxTemperature = Amount;
}

void UC_CharacterStatusComponent::SetMaxFatigueLevel(const float Amount)
{
	Status.MaxFatigueLevel = Amount;
}

void UC_CharacterStatusComponent::SetCurrentWeight(const float Amount)
{
	Status.CurrentWeight = Amount;
}

void UC_CharacterStatusComponent::SetCurrentEnergy(const float Amount)
{
	Status.CurrentEnergy = Amount;
}

void UC_CharacterStatusComponent::SetMaxEnergy(const float Amount)
{
	Status.MaxEnergy = Amount;
}

void UC_CharacterStatusComponent::SetCurrentPhysicalStrength(const float Amount)
{
	Status.CurrentPhysicalStrength = Amount;
}

void UC_CharacterStatusComponent::SetMaxPhysicalStrength(const float Amount)
{
	Status.MaxPhysicalStrength = Amount;
}

void UC_CharacterStatusComponent::SetCurrentDexterity(const float Amount)
{
	Status.CurrentDexterity = Amount;
}

void UC_CharacterStatusComponent::SetMaxDexterity(const float Amount)
{
	Status.MaxDexterity = Amount;
}

void UC_CharacterStatusComponent::SetMaxXP(const float Amount)
{
	Status.MaxXP = Amount;
}

void UC_CharacterStatusComponent::LevelUp()
{
	++Status.Level;
}

void UC_CharacterStatusComponent::AddTemperature(const float Amount)
{
	float Origin = Status.CurrentTemperature;
	float Max = Status.MaxTemperature;
	Status.CurrentTemperature = FMath::Clamp(Origin+Amount,0.f, Max);
}

void UC_CharacterStatusComponent::AddFatigueLevel(const float Amount)
{
	float Origin = Status.CurrentFatigueLevel;
	float Max = Status.MaxFatigueLevel;
	Status.CurrentFatigueLevel = FMath::Clamp(Origin + Amount, 0.f, Max);
}

void UC_CharacterStatusComponent::AddWeight(const float Amount)
{
	float Origin = Status.CurrentWeight;
	Status.CurrentWeight = Origin + Amount;
}

void UC_CharacterStatusComponent::UseEnergy(const float Amount)
{
	float Origin = Status.CurrentEnergy;
	float Max = Status.MaxEnergy;
	Status.CurrentEnergy = FMath::Clamp(Origin - Amount, 0.f, Max);
}

void UC_CharacterStatusComponent::AddPhysicalStrength(const float Amount)
{
	float Origin = Status.CurrentPhysicalStrength;
	float Max = Status.MaxPhysicalStrength;
	Status.CurrentPhysicalStrength = FMath::Clamp(Origin + Amount, 0.f, Max);
}

void UC_CharacterStatusComponent::AddDexterity(const float Amount)
{
	float Origin = Status.CurrentDexterity;
	float Max = Status.MaxDexterity;
	Status.CurrentDexterity = FMath::Clamp(Origin + Amount, 0.f, Max);
}

void UC_CharacterStatusComponent::AddXp(const float Amount)
{
	float Origin = Status.CurrentXP;
	float Max = Status.MaxXP;
	Status.CurrentXP = FMath::Clamp(Origin + Amount, 0.f, Max);

	if (Status.CurrentXP == Max)
	{
		LevelUp();
	}
}

