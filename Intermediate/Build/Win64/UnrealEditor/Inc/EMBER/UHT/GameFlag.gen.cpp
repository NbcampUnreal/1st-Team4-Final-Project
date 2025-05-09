// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/GameInfo/GameFlag.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameFlag() {}

// Begin Cross Module References
EMBER_API UEnum* Z_Construct_UEnum_EMBER_EAICombatType();
EMBER_API UEnum* Z_Construct_UEnum_EMBER_EEffectType();
EMBER_API UEnum* Z_Construct_UEnum_EMBER_EEquipmentSlotType();
EMBER_API UEnum* Z_Construct_UEnum_EMBER_EEquipmentType();
EMBER_API UEnum* Z_Construct_UEnum_EMBER_EItemHandType();
EMBER_API UEnum* Z_Construct_UEnum_EMBER_EItemRarity();
EMBER_API UEnum* Z_Construct_UEnum_EMBER_ESoundCategory();
EMBER_API UEnum* Z_Construct_UEnum_EMBER_ESpeedType();
EMBER_API UEnum* Z_Construct_UEnum_EMBER_EStateType();
EMBER_API UEnum* Z_Construct_UEnum_EMBER_EUtilityType();
EMBER_API UEnum* Z_Construct_UEnum_EMBER_EWeaponType();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Enum ESpeedType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESpeedType;
static UEnum* ESpeedType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ESpeedType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ESpeedType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EMBER_ESpeedType, (UObject*)Z_Construct_UPackage__Script_EMBER(), TEXT("ESpeedType"));
	}
	return Z_Registration_Info_UEnum_ESpeedType.OuterSingleton;
}
template<> EMBER_API UEnum* StaticEnum<ESpeedType>()
{
	return ESpeedType_StaticEnum();
}
struct Z_Construct_UEnum_EMBER_ESpeedType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Max.DisplayName", "Max" },
		{ "Max.Name", "ESpeedType::Max" },
		{ "ModuleRelativePath", "GameInfo/GameFlag.h" },
		{ "Run.DisplayName", "Run" },
		{ "Run.Name", "ESpeedType::Run" },
		{ "Sprint.DisplayName", "Sprint" },
		{ "Sprint.Name", "ESpeedType::Sprint" },
		{ "Walk.DisplayName", "Walk" },
		{ "Walk.Name", "ESpeedType::Walk" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ESpeedType::Walk", (int64)ESpeedType::Walk },
		{ "ESpeedType::Run", (int64)ESpeedType::Run },
		{ "ESpeedType::Sprint", (int64)ESpeedType::Sprint },
		{ "ESpeedType::Max", (int64)ESpeedType::Max },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EMBER_ESpeedType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EMBER,
	nullptr,
	"ESpeedType",
	"ESpeedType",
	Z_Construct_UEnum_EMBER_ESpeedType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EMBER_ESpeedType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EMBER_ESpeedType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EMBER_ESpeedType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EMBER_ESpeedType()
{
	if (!Z_Registration_Info_UEnum_ESpeedType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESpeedType.InnerSingleton, Z_Construct_UEnum_EMBER_ESpeedType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ESpeedType.InnerSingleton;
}
// End Enum ESpeedType

// Begin Enum EStateType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EStateType;
static UEnum* EStateType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EStateType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EStateType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EMBER_EStateType, (UObject*)Z_Construct_UPackage__Script_EMBER(), TEXT("EStateType"));
	}
	return Z_Registration_Info_UEnum_EStateType.OuterSingleton;
}
template<> EMBER_API UEnum* StaticEnum<EStateType>()
{
	return EStateType_StaticEnum();
}
struct Z_Construct_UEnum_EMBER_EStateType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Action.DisplayName", "Action" },
		{ "Action.Name", "EStateType::Action" },
		{ "Dead.DisplayName", "Dead" },
		{ "Dead.Name", "EStateType::Dead" },
		{ "Equip.DisplayName", "Equip" },
		{ "Equip.Name", "EStateType::Equip" },
		{ "Hitted.DisplayName", "Hitted" },
		{ "Hitted.Name", "EStateType::Hitted" },
		{ "Idle.DisplayName", "Idle" },
		{ "Idle.Name", "EStateType::Idle" },
		{ "Max.DisplayName", "Max" },
		{ "Max.Name", "EStateType::Max" },
		{ "ModuleRelativePath", "GameInfo/GameFlag.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EStateType::Idle", (int64)EStateType::Idle },
		{ "EStateType::Equip", (int64)EStateType::Equip },
		{ "EStateType::Action", (int64)EStateType::Action },
		{ "EStateType::Hitted", (int64)EStateType::Hitted },
		{ "EStateType::Dead", (int64)EStateType::Dead },
		{ "EStateType::Max", (int64)EStateType::Max },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EMBER_EStateType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EMBER,
	nullptr,
	"EStateType",
	"EStateType",
	Z_Construct_UEnum_EMBER_EStateType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EMBER_EStateType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EMBER_EStateType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EMBER_EStateType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EMBER_EStateType()
{
	if (!Z_Registration_Info_UEnum_EStateType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EStateType.InnerSingleton, Z_Construct_UEnum_EMBER_EStateType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EStateType.InnerSingleton;
}
// End Enum EStateType

// Begin Enum EAICombatType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EAICombatType;
static UEnum* EAICombatType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EAICombatType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EAICombatType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EMBER_EAICombatType, (UObject*)Z_Construct_UPackage__Script_EMBER(), TEXT("EAICombatType"));
	}
	return Z_Registration_Info_UEnum_EAICombatType.OuterSingleton;
}
template<> EMBER_API UEnum* StaticEnum<EAICombatType>()
{
	return EAICombatType_StaticEnum();
}
struct Z_Construct_UEnum_EMBER_EAICombatType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Aggressive.DisplayName", "Aggressive" },
		{ "Aggressive.Name", "EAICombatType::Aggressive" },
		{ "Defensive.DisplayName", "Defensive" },
		{ "Defensive.Name", "EAICombatType::Defensive" },
		{ "Max.DisplayName", "Max" },
		{ "Max.Name", "EAICombatType::Max" },
		{ "ModuleRelativePath", "GameInfo/GameFlag.h" },
		{ "Passive.DisplayName", "Passive" },
		{ "Passive.Name", "EAICombatType::Passive" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EAICombatType::Passive", (int64)EAICombatType::Passive },
		{ "EAICombatType::Defensive", (int64)EAICombatType::Defensive },
		{ "EAICombatType::Aggressive", (int64)EAICombatType::Aggressive },
		{ "EAICombatType::Max", (int64)EAICombatType::Max },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EMBER_EAICombatType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EMBER,
	nullptr,
	"EAICombatType",
	"EAICombatType",
	Z_Construct_UEnum_EMBER_EAICombatType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EMBER_EAICombatType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EMBER_EAICombatType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EMBER_EAICombatType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EMBER_EAICombatType()
{
	if (!Z_Registration_Info_UEnum_EAICombatType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EAICombatType.InnerSingleton, Z_Construct_UEnum_EMBER_EAICombatType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EAICombatType.InnerSingleton;
}
// End Enum EAICombatType

// Begin Enum ESoundCategory
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESoundCategory;
static UEnum* ESoundCategory_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ESoundCategory.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ESoundCategory.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EMBER_ESoundCategory, (UObject*)Z_Construct_UPackage__Script_EMBER(), TEXT("ESoundCategory"));
	}
	return Z_Registration_Info_UEnum_ESoundCategory.OuterSingleton;
}
template<> EMBER_API UEnum* StaticEnum<ESoundCategory>()
{
	return ESoundCategory_StaticEnum();
}
struct Z_Construct_UEnum_EMBER_ESoundCategory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Attack.DisplayName", "Attack" },
		{ "Attack.Name", "ESoundCategory::Attack" },
		{ "Death.DisplayName", "Death" },
		{ "Death.Name", "ESoundCategory::Death" },
		{ "Hit.DisplayName", "Hit" },
		{ "Hit.Name", "ESoundCategory::Hit" },
		{ "Max.DisplayName", "Max" },
		{ "Max.Name", "ESoundCategory::Max" },
		{ "ModuleRelativePath", "GameInfo/GameFlag.h" },
		{ "Move.DisplayName", "Move" },
		{ "Move.Name", "ESoundCategory::Move" },
		{ "Roar.DisplayName", "Roar" },
		{ "Roar.Name", "ESoundCategory::Roar" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ESoundCategory::Move", (int64)ESoundCategory::Move },
		{ "ESoundCategory::Attack", (int64)ESoundCategory::Attack },
		{ "ESoundCategory::Hit", (int64)ESoundCategory::Hit },
		{ "ESoundCategory::Death", (int64)ESoundCategory::Death },
		{ "ESoundCategory::Roar", (int64)ESoundCategory::Roar },
		{ "ESoundCategory::Max", (int64)ESoundCategory::Max },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EMBER_ESoundCategory_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EMBER,
	nullptr,
	"ESoundCategory",
	"ESoundCategory",
	Z_Construct_UEnum_EMBER_ESoundCategory_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EMBER_ESoundCategory_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EMBER_ESoundCategory_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EMBER_ESoundCategory_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EMBER_ESoundCategory()
{
	if (!Z_Registration_Info_UEnum_ESoundCategory.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESoundCategory.InnerSingleton, Z_Construct_UEnum_EMBER_ESoundCategory_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ESoundCategory.InnerSingleton;
}
// End Enum ESoundCategory

// Begin Enum EEffectType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EEffectType;
static UEnum* EEffectType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EEffectType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EEffectType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EMBER_EEffectType, (UObject*)Z_Construct_UPackage__Script_EMBER(), TEXT("EEffectType"));
	}
	return Z_Registration_Info_UEnum_EEffectType.OuterSingleton;
}
template<> EMBER_API UEnum* StaticEnum<EEffectType>()
{
	return EEffectType_StaticEnum();
}
struct Z_Construct_UEnum_EMBER_EEffectType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "GameInfo/GameFlag.h" },
		{ "Niagara.Name", "EEffectType::Niagara" },
		{ "Particle.Name", "EEffectType::Particle" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EEffectType::Niagara", (int64)EEffectType::Niagara },
		{ "EEffectType::Particle", (int64)EEffectType::Particle },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EMBER_EEffectType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EMBER,
	nullptr,
	"EEffectType",
	"EEffectType",
	Z_Construct_UEnum_EMBER_EEffectType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EMBER_EEffectType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EMBER_EEffectType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EMBER_EEffectType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EMBER_EEffectType()
{
	if (!Z_Registration_Info_UEnum_EEffectType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EEffectType.InnerSingleton, Z_Construct_UEnum_EMBER_EEffectType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EEffectType.InnerSingleton;
}
// End Enum EEffectType

// Begin Enum EItemRarity
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EItemRarity;
static UEnum* EItemRarity_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EItemRarity.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EItemRarity.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EMBER_EItemRarity, (UObject*)Z_Construct_UPackage__Script_EMBER(), TEXT("EItemRarity"));
	}
	return Z_Registration_Info_UEnum_EItemRarity.OuterSingleton;
}
template<> EMBER_API UEnum* StaticEnum<EItemRarity>()
{
	return EItemRarity_StaticEnum();
}
struct Z_Construct_UEnum_EMBER_EItemRarity_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Common.Name", "EItemRarity::Common" },
		{ "Count.Hidden", "" },
		{ "Count.Name", "EItemRarity::Count" },
		{ "Legendary.Name", "EItemRarity::Legendary" },
		{ "ModuleRelativePath", "GameInfo/GameFlag.h" },
		{ "Poor.Name", "EItemRarity::Poor" },
		{ "Rare.Name", "EItemRarity::Rare" },
		{ "Uncommon.Name", "EItemRarity::Uncommon" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EItemRarity::Poor", (int64)EItemRarity::Poor },
		{ "EItemRarity::Common", (int64)EItemRarity::Common },
		{ "EItemRarity::Uncommon", (int64)EItemRarity::Uncommon },
		{ "EItemRarity::Rare", (int64)EItemRarity::Rare },
		{ "EItemRarity::Legendary", (int64)EItemRarity::Legendary },
		{ "EItemRarity::Count", (int64)EItemRarity::Count },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EMBER_EItemRarity_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EMBER,
	nullptr,
	"EItemRarity",
	"EItemRarity",
	Z_Construct_UEnum_EMBER_EItemRarity_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EMBER_EItemRarity_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EMBER_EItemRarity_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EMBER_EItemRarity_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EMBER_EItemRarity()
{
	if (!Z_Registration_Info_UEnum_EItemRarity.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EItemRarity.InnerSingleton, Z_Construct_UEnum_EMBER_EItemRarity_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EItemRarity.InnerSingleton;
}
// End Enum EItemRarity

// Begin Enum EEquipmentType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EEquipmentType;
static UEnum* EEquipmentType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EEquipmentType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EEquipmentType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EMBER_EEquipmentType, (UObject*)Z_Construct_UPackage__Script_EMBER(), TEXT("EEquipmentType"));
	}
	return Z_Registration_Info_UEnum_EEquipmentType.OuterSingleton;
}
template<> EMBER_API UEnum* StaticEnum<EEquipmentType>()
{
	return EEquipmentType_StaticEnum();
}
struct Z_Construct_UEnum_EMBER_EEquipmentType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Armor.Name", "EEquipmentType::Armor" },
		{ "BlueprintType", "true" },
		{ "Count.Hidden", "" },
		{ "Count.Name", "EEquipmentType::Count" },
		{ "ModuleRelativePath", "GameInfo/GameFlag.h" },
		{ "Utility.Name", "EEquipmentType::Utility" },
		{ "Weapon.Name", "EEquipmentType::Weapon" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EEquipmentType::Armor", (int64)EEquipmentType::Armor },
		{ "EEquipmentType::Weapon", (int64)EEquipmentType::Weapon },
		{ "EEquipmentType::Utility", (int64)EEquipmentType::Utility },
		{ "EEquipmentType::Count", (int64)EEquipmentType::Count },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EMBER_EEquipmentType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EMBER,
	nullptr,
	"EEquipmentType",
	"EEquipmentType",
	Z_Construct_UEnum_EMBER_EEquipmentType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EMBER_EEquipmentType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EMBER_EEquipmentType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EMBER_EEquipmentType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EMBER_EEquipmentType()
{
	if (!Z_Registration_Info_UEnum_EEquipmentType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EEquipmentType.InnerSingleton, Z_Construct_UEnum_EMBER_EEquipmentType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EEquipmentType.InnerSingleton;
}
// End Enum EEquipmentType

// Begin Enum EUtilityType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EUtilityType;
static UEnum* EUtilityType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EUtilityType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EUtilityType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EMBER_EUtilityType, (UObject*)Z_Construct_UPackage__Script_EMBER(), TEXT("EUtilityType"));
	}
	return Z_Registration_Info_UEnum_EUtilityType.OuterSingleton;
}
template<> EMBER_API UEnum* StaticEnum<EUtilityType>()
{
	return EUtilityType_StaticEnum();
}
struct Z_Construct_UEnum_EMBER_EUtilityType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Count.Hidden", "" },
		{ "Count.Name", "EUtilityType::Count" },
		{ "Drink.Name", "EUtilityType::Drink" },
		{ "LightSource.Name", "EUtilityType::LightSource" },
		{ "ModuleRelativePath", "GameInfo/GameFlag.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EUtilityType::Drink", (int64)EUtilityType::Drink },
		{ "EUtilityType::LightSource", (int64)EUtilityType::LightSource },
		{ "EUtilityType::Count", (int64)EUtilityType::Count },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EMBER_EUtilityType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EMBER,
	nullptr,
	"EUtilityType",
	"EUtilityType",
	Z_Construct_UEnum_EMBER_EUtilityType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EMBER_EUtilityType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EMBER_EUtilityType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EMBER_EUtilityType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EMBER_EUtilityType()
{
	if (!Z_Registration_Info_UEnum_EUtilityType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EUtilityType.InnerSingleton, Z_Construct_UEnum_EMBER_EUtilityType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EUtilityType.InnerSingleton;
}
// End Enum EUtilityType

// Begin Enum EItemHandType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EItemHandType;
static UEnum* EItemHandType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EItemHandType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EItemHandType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EMBER_EItemHandType, (UObject*)Z_Construct_UPackage__Script_EMBER(), TEXT("EItemHandType"));
	}
	return Z_Registration_Info_UEnum_EItemHandType.OuterSingleton;
}
template<> EMBER_API UEnum* StaticEnum<EItemHandType>()
{
	return EItemHandType_StaticEnum();
}
struct Z_Construct_UEnum_EMBER_EItemHandType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Count.Hidden", "" },
		{ "Count.Name", "EItemHandType::Count" },
		{ "LeftHand.Name", "EItemHandType::LeftHand" },
		{ "ModuleRelativePath", "GameInfo/GameFlag.h" },
		{ "RightHand.Name", "EItemHandType::RightHand" },
		{ "TwoHand.Name", "EItemHandType::TwoHand" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EItemHandType::LeftHand", (int64)EItemHandType::LeftHand },
		{ "EItemHandType::RightHand", (int64)EItemHandType::RightHand },
		{ "EItemHandType::TwoHand", (int64)EItemHandType::TwoHand },
		{ "EItemHandType::Count", (int64)EItemHandType::Count },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EMBER_EItemHandType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EMBER,
	nullptr,
	"EItemHandType",
	"EItemHandType",
	Z_Construct_UEnum_EMBER_EItemHandType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EMBER_EItemHandType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EMBER_EItemHandType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EMBER_EItemHandType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EMBER_EItemHandType()
{
	if (!Z_Registration_Info_UEnum_EItemHandType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EItemHandType.InnerSingleton, Z_Construct_UEnum_EMBER_EItemHandType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EItemHandType.InnerSingleton;
}
// End Enum EItemHandType

// Begin Enum EEquipmentSlotType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EEquipmentSlotType;
static UEnum* EEquipmentSlotType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EEquipmentSlotType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EEquipmentSlotType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EMBER_EEquipmentSlotType, (UObject*)Z_Construct_UPackage__Script_EMBER(), TEXT("EEquipmentSlotType"));
	}
	return Z_Registration_Info_UEnum_EEquipmentSlotType.OuterSingleton;
}
template<> EMBER_API UEnum* StaticEnum<EEquipmentSlotType>()
{
	return EEquipmentSlotType_StaticEnum();
}
struct Z_Construct_UEnum_EMBER_EEquipmentSlotType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Armor.Name", "EEquipmentSlotType::Armor" },
		{ "BlueprintType", "true" },
		{ "Count.Hidden", "" },
		{ "Count.Name", "EEquipmentSlotType::Count" },
		{ "ModuleRelativePath", "GameInfo/GameFlag.h" },
		{ "Primary_LeftHand.Name", "EEquipmentSlotType::Primary_LeftHand" },
		{ "Primary_RightHand.Name", "EEquipmentSlotType::Primary_RightHand" },
		{ "Primary_TwoHand.Name", "EEquipmentSlotType::Primary_TwoHand" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EEquipmentSlotType::Primary_LeftHand", (int64)EEquipmentSlotType::Primary_LeftHand },
		{ "EEquipmentSlotType::Primary_RightHand", (int64)EEquipmentSlotType::Primary_RightHand },
		{ "EEquipmentSlotType::Primary_TwoHand", (int64)EEquipmentSlotType::Primary_TwoHand },
		{ "EEquipmentSlotType::Armor", (int64)EEquipmentSlotType::Armor },
		{ "EEquipmentSlotType::Count", (int64)EEquipmentSlotType::Count },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EMBER_EEquipmentSlotType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EMBER,
	nullptr,
	"EEquipmentSlotType",
	"EEquipmentSlotType",
	Z_Construct_UEnum_EMBER_EEquipmentSlotType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EMBER_EEquipmentSlotType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EMBER_EEquipmentSlotType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EMBER_EEquipmentSlotType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EMBER_EEquipmentSlotType()
{
	if (!Z_Registration_Info_UEnum_EEquipmentSlotType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EEquipmentSlotType.InnerSingleton, Z_Construct_UEnum_EMBER_EEquipmentSlotType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EEquipmentSlotType.InnerSingleton;
}
// End Enum EEquipmentSlotType

// Begin Enum EWeaponType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EWeaponType;
static UEnum* EWeaponType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EWeaponType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EWeaponType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EMBER_EWeaponType, (UObject*)Z_Construct_UPackage__Script_EMBER(), TEXT("EWeaponType"));
	}
	return Z_Registration_Info_UEnum_EWeaponType.OuterSingleton;
}
template<> EMBER_API UEnum* StaticEnum<EWeaponType>()
{
	return EWeaponType_StaticEnum();
}
struct Z_Construct_UEnum_EMBER_EWeaponType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Count.Hidden", "" },
		{ "Count.Name", "EWeaponType::Count" },
		{ "ModuleRelativePath", "GameInfo/GameFlag.h" },
		{ "OneHandSword.Name", "EWeaponType::OneHandSword" },
		{ "Shield.Name", "EWeaponType::Shield" },
		{ "TwoHandSword.Name", "EWeaponType::TwoHandSword" },
		{ "Unarmed.Name", "EWeaponType::Unarmed" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EWeaponType::Unarmed", (int64)EWeaponType::Unarmed },
		{ "EWeaponType::OneHandSword", (int64)EWeaponType::OneHandSword },
		{ "EWeaponType::TwoHandSword", (int64)EWeaponType::TwoHandSword },
		{ "EWeaponType::Shield", (int64)EWeaponType::Shield },
		{ "EWeaponType::Count", (int64)EWeaponType::Count },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EMBER_EWeaponType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EMBER,
	nullptr,
	"EWeaponType",
	"EWeaponType",
	Z_Construct_UEnum_EMBER_EWeaponType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EMBER_EWeaponType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EMBER_EWeaponType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EMBER_EWeaponType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EMBER_EWeaponType()
{
	if (!Z_Registration_Info_UEnum_EWeaponType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EWeaponType.InnerSingleton, Z_Construct_UEnum_EMBER_EWeaponType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EWeaponType.InnerSingleton;
}
// End Enum EWeaponType

// Begin Registration
struct Z_CompiledInDeferFile_FID_1st_Team4_Final_Project_Source_EMBER_GameInfo_GameFlag_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ESpeedType_StaticEnum, TEXT("ESpeedType"), &Z_Registration_Info_UEnum_ESpeedType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1406011391U) },
		{ EStateType_StaticEnum, TEXT("EStateType"), &Z_Registration_Info_UEnum_EStateType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 344348180U) },
		{ EAICombatType_StaticEnum, TEXT("EAICombatType"), &Z_Registration_Info_UEnum_EAICombatType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2340011761U) },
		{ ESoundCategory_StaticEnum, TEXT("ESoundCategory"), &Z_Registration_Info_UEnum_ESoundCategory, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 271715881U) },
		{ EEffectType_StaticEnum, TEXT("EEffectType"), &Z_Registration_Info_UEnum_EEffectType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2298570349U) },
		{ EItemRarity_StaticEnum, TEXT("EItemRarity"), &Z_Registration_Info_UEnum_EItemRarity, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 731058631U) },
		{ EEquipmentType_StaticEnum, TEXT("EEquipmentType"), &Z_Registration_Info_UEnum_EEquipmentType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3886265678U) },
		{ EUtilityType_StaticEnum, TEXT("EUtilityType"), &Z_Registration_Info_UEnum_EUtilityType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1790384880U) },
		{ EItemHandType_StaticEnum, TEXT("EItemHandType"), &Z_Registration_Info_UEnum_EItemHandType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3043355517U) },
		{ EEquipmentSlotType_StaticEnum, TEXT("EEquipmentSlotType"), &Z_Registration_Info_UEnum_EEquipmentSlotType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3890792377U) },
		{ EWeaponType_StaticEnum, TEXT("EWeaponType"), &Z_Registration_Info_UEnum_EWeaponType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 638223766U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_1st_Team4_Final_Project_Source_EMBER_GameInfo_GameFlag_h_1695884684(TEXT("/Script/EMBER"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_1st_Team4_Final_Project_Source_EMBER_GameInfo_GameFlag_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_1st_Team4_Final_Project_Source_EMBER_GameInfo_GameFlag_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
