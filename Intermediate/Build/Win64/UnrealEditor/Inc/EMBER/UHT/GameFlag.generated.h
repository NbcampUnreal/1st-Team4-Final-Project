// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GameInfo/GameFlag.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef EMBER_GameFlag_generated_h
#error "GameFlag.generated.h already included, missing '#pragma once' in GameFlag.h"
#endif
#define EMBER_GameFlag_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_PJ_Ember_Source_EMBER_GameInfo_GameFlag_h


#define FOREACH_ENUM_ESPEEDTYPE(op) \
	op(ESpeedType::Walk) \
	op(ESpeedType::Run) \
	op(ESpeedType::Sprint) \
	op(ESpeedType::Max) 

enum class ESpeedType : uint8;
template<> struct TIsUEnumClass<ESpeedType> { enum { Value = true }; };
template<> EMBER_API UEnum* StaticEnum<ESpeedType>();

#define FOREACH_ENUM_ESTATETYPE(op) \
	op(EStateType::Idle) \
	op(EStateType::Equip) \
	op(EStateType::Action) \
	op(EStateType::Hitted) \
	op(EStateType::Dead) \
	op(EStateType::Max) 

enum class EStateType : uint8;
template<> struct TIsUEnumClass<EStateType> { enum { Value = true }; };
template<> EMBER_API UEnum* StaticEnum<EStateType>();

#define FOREACH_ENUM_EAICOMBATTYPE(op) \
	op(EAICombatType::Passive) \
	op(EAICombatType::Defensive) \
	op(EAICombatType::Aggressive) \
	op(EAICombatType::Max) 

enum class EAICombatType : uint8;
template<> struct TIsUEnumClass<EAICombatType> { enum { Value = true }; };
template<> EMBER_API UEnum* StaticEnum<EAICombatType>();

#define FOREACH_ENUM_ESOUNDCATEGORY(op) \
	op(ESoundCategory::Move) \
	op(ESoundCategory::Attack) \
	op(ESoundCategory::Hit) \
	op(ESoundCategory::Death) \
	op(ESoundCategory::Roar) \
	op(ESoundCategory::Max) 

enum class ESoundCategory : uint8;
template<> struct TIsUEnumClass<ESoundCategory> { enum { Value = true }; };
template<> EMBER_API UEnum* StaticEnum<ESoundCategory>();

#define FOREACH_ENUM_EEFFECTTYPE(op) \
	op(EEffectType::Niagara) \
	op(EEffectType::Particle) 

enum class EEffectType : uint8;
template<> struct TIsUEnumClass<EEffectType> { enum { Value = true }; };
template<> EMBER_API UEnum* StaticEnum<EEffectType>();

#define FOREACH_ENUM_EITEMRARITY(op) \
	op(EItemRarity::Poor) \
	op(EItemRarity::Common) \
	op(EItemRarity::Uncommon) \
	op(EItemRarity::Rare) \
	op(EItemRarity::Legendary) \
	op(EItemRarity::Count) 

enum class EItemRarity : uint8;
template<> struct TIsUEnumClass<EItemRarity> { enum { Value = true }; };
template<> EMBER_API UEnum* StaticEnum<EItemRarity>();

#define FOREACH_ENUM_EEQUIPMENTTYPE(op) \
	op(EEquipmentType::Armor) \
	op(EEquipmentType::Weapon) \
	op(EEquipmentType::Utility) \
	op(EEquipmentType::Count) 

enum class EEquipmentType : uint8;
template<> struct TIsUEnumClass<EEquipmentType> { enum { Value = true }; };
template<> EMBER_API UEnum* StaticEnum<EEquipmentType>();

#define FOREACH_ENUM_EUTILITYTYPE(op) \
	op(EUtilityType::Drink) \
	op(EUtilityType::LightSource) \
	op(EUtilityType::Count) 

enum class EUtilityType : uint8;
template<> struct TIsUEnumClass<EUtilityType> { enum { Value = true }; };
template<> EMBER_API UEnum* StaticEnum<EUtilityType>();

#define FOREACH_ENUM_EITEMHANDTYPE(op) \
	op(EItemHandType::LeftHand) \
	op(EItemHandType::RightHand) \
	op(EItemHandType::TwoHand) \
	op(EItemHandType::Count) 

enum class EItemHandType : uint8;
template<> struct TIsUEnumClass<EItemHandType> { enum { Value = true }; };
template<> EMBER_API UEnum* StaticEnum<EItemHandType>();

#define FOREACH_ENUM_EEQUIPMENTSLOTTYPE(op) \
	op(EEquipmentSlotType::Primary_LeftHand) \
	op(EEquipmentSlotType::Primary_RightHand) \
	op(EEquipmentSlotType::Primary_TwoHand) \
	op(EEquipmentSlotType::Armor) \
	op(EEquipmentSlotType::Count) 

enum class EEquipmentSlotType : uint8;
template<> struct TIsUEnumClass<EEquipmentSlotType> { enum { Value = true }; };
template<> EMBER_API UEnum* StaticEnum<EEquipmentSlotType>();

#define FOREACH_ENUM_EWEAPONTYPE(op) \
	op(EWeaponType::Unarmed) \
	op(EWeaponType::OneHandSword) \
	op(EWeaponType::TwoHandSword) \
	op(EWeaponType::Shield) \
	op(EWeaponType::Count) 

enum class EWeaponType : uint8;
template<> struct TIsUEnumClass<EWeaponType> { enum { Value = true }; };
template<> EMBER_API UEnum* StaticEnum<EWeaponType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
