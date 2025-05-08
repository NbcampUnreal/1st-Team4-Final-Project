#pragma once
#include "EMBER.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "C_CharacterStatusComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EMBER_API UC_CharacterStatusComponent : public UActorComponent
{
	GENERATED_BODY()
public:	
	UC_CharacterStatusComponent();
protected:	//재정의
	virtual void BeginPlay() override;
public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
private:
	FCharacterStatus Status;
public:
    float GetCurrentHP() const;
    float GetMaxHP() const;
    float GetCurrentStamina() const;
    float GetMaxStamina() const;
    float GetCurrentTemperature() const;
    float GetMaxTemperature() const;
    float GetCurrentFatigueLevel() const;
    float GetMaxFatigueLevel() const;
    float GetCurrentWeight() const;
    float GetMaxWeight() const;
    float GetCurrentEnergy() const;
    float GetMaxEnergy() const;
    float GetCurrentPhysicalStrength() const;
    float GetMaxPhysicalStrength() const;
    float GetCurrentDexterity() const;
    float GetMaxDexterity() const;
    float GetCurrentXP() const;
    float GetMaxXP() const;
    int32 GetLevel() const;
public:
    void SetCurrentHP(const float Amount);
    void SetMaxHP(const float Amount);
    void SetCurrentStamina(const float Amount);
    void SetMaxStamina(const float Amount);
    void SetMaxTemperature(const float Amount);
    void SetMaxFatigueLevel(const float Amount);
    void SetCurrentWeight(const float Amount);
    void SetCurrentEnergy(const float Amount);
    void SetMaxEnergy(const float Amount);
    void SetCurrentPhysicalStrength(const float Amount);
    void SetMaxPhysicalStrength(const float Amount);
    void SetCurrentDexterity(const float Amount);
    void SetMaxDexterity(const float Amount);
    void SetMaxXP(const float Amount);
private:
    void LevelUp();
public:
    void AddTemperature(const float Amount);
    void AddFatigueLevel(const float Amount);
    void AddWeight(const float Amount);
    void UseEnergy(const float Amount);
    void AddPhysicalStrength(const float Amount);
    void AddDexterity(const float Amount);
    void AddXp(const float Amount);
};
