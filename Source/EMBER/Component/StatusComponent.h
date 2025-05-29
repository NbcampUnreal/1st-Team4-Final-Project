#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StatusComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class EMBER_API UStatusComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	FORCEINLINE float GetMaxHp() { return MaxHP; }
	FORCEINLINE float GetHp() { return HP; }
	FORCEINLINE float GetMaxStamina() { return MaxStamina; }
	FORCEINLINE float GetStamina() { return Stamina; }
	FORCEINLINE float GetMaxTemperature() { return MaxTemperature; }
	FORCEINLINE float GetTemperature() { return Temperature; }
	FORCEINLINE float GetMaxFatigueLevel() { return MaxFatigueLevel; }
	FORCEINLINE float GetFatigueLevel() { return FatigueLevel; }
	FORCEINLINE float GetMaxWeight() { return MaxWeight; }
	FORCEINLINE float GetWeight() { return Weight; }
	FORCEINLINE float GetMaxEnergy() { return MaxEnergy; }
	FORCEINLINE float GetEnergy() { return Energy; }
	FORCEINLINE float GetMaxPhysicalStrength() { return MaxPhysicalStrength; }
	FORCEINLINE float GetPhysicalStrength() { return PhysicalStrength; }
	FORCEINLINE float GetMaxDexterity() { return MaxDexterity; }
	FORCEINLINE float GetDexterity() { return Dexterity; }
	FORCEINLINE float GetMaxXP() { return MaxXP; }
	FORCEINLINE float GetXP() { return XP; }
	FORCEINLINE float GetMaxLevel() { return MaxLevel; }
	FORCEINLINE float GetLevel() { return Level; }

public:
	UStatusComponent();

protected:
	virtual void BeginPlay() override;

public:
	void SetMaxHp(float InAmount);
	void SetMaxStamina(float InAmount);
	void SetMaxTemperature(float InAmount);
	void SetMaxFatigueLevel(float InAmount);
	void SetMaxWeight(float InAmount);
	void SetMaxEnergy(float InAmount);
	void SetMaxPhysicalStrength(float InAmount);
	void SetMaxDexterity(int32 InAmount);
	void SetMaxXp(int32 InAmount);
	void SetMaxLevel(int32 InAmount);

	void Damage(float InAmount);
	void UseStamina(float InAmount);
	void UseTemperature(float InAmount);
	void AddFatigueLevel(float InAmount);
	void AddWeight(float InAmount);
	void UseEnergy(float InAmount);
	void AddPhysicalStrength(float InAmount);
	void AddDexterity(float InAmount);
	void AddXp(float InAmount);
	void LevelUp();

private:
	UPROPERTY(EditAnywhere, Category = "Status")
	float MaxHP;
	UPROPERTY(EditAnywhere, Category = "Status")
	float MaxStamina;
	UPROPERTY(EditAnywhere, Category = "Status")
	float MaxTemperature = 100.0f;
	UPROPERTY(EditAnywhere, Category = "Status")
	float MaxFatigueLevel = 100.0f;
	UPROPERTY(EditAnywhere, Category = "Status")
	float MaxWeight = 100.0f;
	UPROPERTY(EditAnywhere, Category = "Status")
	float MaxEnergy = 100.0f;
	UPROPERTY(EditAnywhere, Category = "Status")
	float MaxPhysicalStrength = 100.0f;
	UPROPERTY(EditAnywhere, Category = "Status")
	float MaxDexterity = 100.0f;
	UPROPERTY(EditAnywhere, Category = "Status")
	float MaxXP = 100.0f;
	UPROPERTY(EditAnywhere, Category = "Status")
	int32 MaxLevel = 30;

private:
	float HP;
	float Stamina;
	float Temperature;
	float FatigueLevel = 0.0f;
	float Weight = 0.0f;
	float Energy;
	float PhysicalStrength;
	float Dexterity;
	float XP = 0.0f;

	ACharacter* OwnerCharacter;

	int32 Level;
};