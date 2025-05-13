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

UENUM(BlueprintType)
enum class EItemRarity : uint8
{
	Poor,
	Common,
	Uncommon,
	Rare,
	Legendary,

	Count	UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EEquipmentType : uint8
{
	Armor,
	Weapon,
	Utility,
	
	Count	UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EUtilityType : uint8
{
	Drink,
	LightSource,

	Count	UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EItemHandType : uint8
{
	LeftHand,
	RightHand,
	TwoHand,

	Count	UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EEquipmentSlotType : uint8
{
	Primary_LeftHand,
	Primary_RightHand,
	Primary_TwoHand,
	
	Armor,
	
	Count	UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	Unarmed,
	OneHandSword,
	TwoHandSword,
	Shield,

	Count	UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EArmorType : uint8
{
	Helmet,
	Chest,
	Legs,
	Hands,
	Foot,

	Count	UMETA(Hidden)
};

UENUM(BlueprintType)
enum class ESlotState : uint8
{
	Default,
	Invalid,
	Valid
};

UENUM(BlueprintType)
enum class EWeaponSlotType : uint8
{
	Primary,
	Secondary,

	Count	UMETA(Hidden)
};