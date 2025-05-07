#pragma once
#include "CoreMinimal.h"

UENUM()
enum class ESpeedType : uint8
{
	Walk UMETA(DisplayName = "Walk"),
	Run UMETA(DisplayName = "Run"),
	Sprint UMETA(DisplayName = "Sprint"),
	Max UMETA(DisplayName = "Max")
};

UENUM()
enum class EStateType : uint8
{
	Idle UMETA(DisplayName = "Idle"),
	Equip UMETA(DisplayName = "Equip"),
	Action UMETA(DisplayName = "Action"),
	Hitted UMETA(DisplayName = "Hitted"),
	Dead UMETA(DisplayName = "Dead"),
	Max UMETA(DisplayName = "Max")
};

UENUM()
enum class EAICombatType : uint8
{
	Passive UMETA(DisplayName = "Passive"),
	Defensive UMETA(DisplayName = "Defensive"),
	Aggressive UMETA(DisplayName = "Aggressive"),
	Max UMETA(DisplayName = "Max")
};

UENUM()
enum class ESoundCategory : uint8
{
	Move UMETA(DisplayName = "Move"),
	Attack UMETA(DisplayName = "Attack"),
	Hit UMETA(DisplayName = "Hit"),
	Death UMETA(DisplayName = "Death"),
	Roar UMETA(DisplayName = "Roar"),
	Max UMETA(DisplayName = "Max")
};

UENUM(BlueprintType)
enum class EEffectType : uint8
{
	Niagara,
	Particle
};