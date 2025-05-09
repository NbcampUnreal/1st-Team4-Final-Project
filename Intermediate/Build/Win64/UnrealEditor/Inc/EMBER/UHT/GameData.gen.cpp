// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/GameInfo/GameData.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameData() {}

// Begin Cross Module References
EMBER_API UEnum* Z_Construct_UEnum_EMBER_EEffectType();
EMBER_API UScriptStruct* Z_Construct_UScriptStruct_FAttackData();
EMBER_API UScriptStruct* Z_Construct_UScriptStruct_FCharacterStatus();
EMBER_API UScriptStruct* Z_Construct_UScriptStruct_FDamageData();
EMBER_API UScriptStruct* Z_Construct_UScriptStruct_FEffectData();
EMBER_API UScriptStruct* Z_Construct_UScriptStruct_FEquipment();
EMBER_API UScriptStruct* Z_Construct_UScriptStruct_FParryData();
EMBER_API UScriptStruct* Z_Construct_UScriptStruct_FSound2D();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UParticleSystem_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USoundWave_NoRegister();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin ScriptStruct FEffectData
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_EffectData;
class UScriptStruct* FEffectData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_EffectData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_EffectData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FEffectData, (UObject*)Z_Construct_UPackage__Script_EMBER(), TEXT("EffectData"));
	}
	return Z_Registration_Info_UScriptStruct_EffectData.OuterSingleton;
}
template<> EMBER_API UScriptStruct* StaticStruct<FEffectData>()
{
	return FEffectData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FEffectData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EffectType_MetaData[] = {
		{ "Category", "Effect" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NiagaraSystem_MetaData[] = {
		{ "Category", "Effect" },
		{ "EditCondition", "EffectType == EEffectType::Niagara" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParticleSystem_MetaData[] = {
		{ "Category", "Effect" },
		{ "EditCondition", "EffectType == EEffectType::Particle" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_EffectType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_EffectType;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NiagaraSystem;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ParticleSystem;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FEffectData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FEffectData_Statics::NewProp_EffectType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FEffectData_Statics::NewProp_EffectType = { "EffectType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEffectData, EffectType), Z_Construct_UEnum_EMBER_EEffectType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EffectType_MetaData), NewProp_EffectType_MetaData) }; // 2298570349
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FEffectData_Statics::NewProp_NiagaraSystem = { "NiagaraSystem", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEffectData, NiagaraSystem), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NiagaraSystem_MetaData), NewProp_NiagaraSystem_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FEffectData_Statics::NewProp_ParticleSystem = { "ParticleSystem", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEffectData, ParticleSystem), Z_Construct_UClass_UParticleSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParticleSystem_MetaData), NewProp_ParticleSystem_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FEffectData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEffectData_Statics::NewProp_EffectType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEffectData_Statics::NewProp_EffectType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEffectData_Statics::NewProp_NiagaraSystem,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEffectData_Statics::NewProp_ParticleSystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEffectData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FEffectData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
	nullptr,
	&NewStructOps,
	"EffectData",
	Z_Construct_UScriptStruct_FEffectData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEffectData_Statics::PropPointers),
	sizeof(FEffectData),
	alignof(FEffectData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEffectData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FEffectData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FEffectData()
{
	if (!Z_Registration_Info_UScriptStruct_EffectData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_EffectData.InnerSingleton, Z_Construct_UScriptStruct_FEffectData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_EffectData.InnerSingleton;
}
// End ScriptStruct FEffectData

// Begin ScriptStruct FSound2D
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_Sound2D;
class UScriptStruct* FSound2D::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_Sound2D.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_Sound2D.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSound2D, (UObject*)Z_Construct_UPackage__Script_EMBER(), TEXT("Sound2D"));
	}
	return Z_Registration_Info_UScriptStruct_Sound2D.OuterSingleton;
}
template<> EMBER_API UScriptStruct* StaticStruct<FSound2D>()
{
	return FSound2D::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSound2D_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Sound_MetaData[] = {
		{ "Category", "Sound2D" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Volume_MetaData[] = {
		{ "Category", "Sound2D" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// 2D \xec\x82\xac\xec\x9a\xb4\xeb\x93\x9c \xec\x97\x90\xec\x85\x8b\n" },
#endif
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "2D \xec\x82\xac\xec\x9a\xb4\xeb\x93\x9c \xec\x97\x90\xec\x85\x8b" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Pitch_MetaData[] = {
		{ "Category", "Sound2D" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xb3\xbc\xeb\xa5\xa8\n" },
#endif
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xb3\xbc\xeb\xa5\xa8" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Sound;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Volume;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Pitch;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSound2D>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FSound2D_Statics::NewProp_Sound = { "Sound", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSound2D, Sound), Z_Construct_UClass_USoundWave_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Sound_MetaData), NewProp_Sound_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSound2D_Statics::NewProp_Volume = { "Volume", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSound2D, Volume), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Volume_MetaData), NewProp_Volume_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSound2D_Statics::NewProp_Pitch = { "Pitch", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSound2D, Pitch), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Pitch_MetaData), NewProp_Pitch_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSound2D_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSound2D_Statics::NewProp_Sound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSound2D_Statics::NewProp_Volume,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSound2D_Statics::NewProp_Pitch,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSound2D_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSound2D_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
	nullptr,
	&NewStructOps,
	"Sound2D",
	Z_Construct_UScriptStruct_FSound2D_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSound2D_Statics::PropPointers),
	sizeof(FSound2D),
	alignof(FSound2D),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSound2D_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSound2D_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSound2D()
{
	if (!Z_Registration_Info_UScriptStruct_Sound2D.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_Sound2D.InnerSingleton, Z_Construct_UScriptStruct_FSound2D_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_Sound2D.InnerSingleton;
}
// End ScriptStruct FSound2D

// Begin ScriptStruct FParryData
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ParryData;
class UScriptStruct* FParryData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ParryData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ParryData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FParryData, (UObject*)Z_Construct_UPackage__Script_EMBER(), TEXT("ParryData"));
	}
	return Z_Registration_Info_UScriptStruct_ParryData.OuterSingleton;
}
template<> EMBER_API UScriptStruct* StaticStruct<FParryData>()
{
	return FParryData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FParryData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayRate_MetaData[] = {
		{ "Category", "ParryData" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitEffect_MetaData[] = {
		{ "Category", "ParryData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xea\xb3\xb5\xea\xb2\xa9\xec\x86\x8d\xeb\x8f\x84\n" },
#endif
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xea\xb3\xb5\xea\xb2\xa9\xec\x86\x8d\xeb\x8f\x84" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitSound_MetaData[] = {
		{ "Category", "ParryData" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Montages_MetaData[] = {
		{ "Category", "ParryData" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayRate;
	static const UECodeGen_Private::FStructPropertyParams NewProp_HitEffect;
	static const UECodeGen_Private::FStructPropertyParams NewProp_HitSound;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Montages_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Montages;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FParryData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FParryData_Statics::NewProp_PlayRate = { "PlayRate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FParryData, PlayRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayRate_MetaData), NewProp_PlayRate_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FParryData_Statics::NewProp_HitEffect = { "HitEffect", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FParryData, HitEffect), Z_Construct_UScriptStruct_FEffectData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitEffect_MetaData), NewProp_HitEffect_MetaData) }; // 1233497073
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FParryData_Statics::NewProp_HitSound = { "HitSound", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FParryData, HitSound), Z_Construct_UScriptStruct_FSound2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitSound_MetaData), NewProp_HitSound_MetaData) }; // 782392426
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FParryData_Statics::NewProp_Montages_Inner = { "Montages", nullptr, (EPropertyFlags)0x0104000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FParryData_Statics::NewProp_Montages = { "Montages", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FParryData, Montages), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Montages_MetaData), NewProp_Montages_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FParryData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FParryData_Statics::NewProp_PlayRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FParryData_Statics::NewProp_HitEffect,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FParryData_Statics::NewProp_HitSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FParryData_Statics::NewProp_Montages_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FParryData_Statics::NewProp_Montages,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FParryData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FParryData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
	nullptr,
	&NewStructOps,
	"ParryData",
	Z_Construct_UScriptStruct_FParryData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FParryData_Statics::PropPointers),
	sizeof(FParryData),
	alignof(FParryData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FParryData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FParryData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FParryData()
{
	if (!Z_Registration_Info_UScriptStruct_ParryData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ParryData.InnerSingleton, Z_Construct_UScriptStruct_FParryData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_ParryData.InnerSingleton;
}
// End ScriptStruct FParryData

// Begin ScriptStruct FEquipment
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_Equipment;
class UScriptStruct* FEquipment::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_Equipment.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_Equipment.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FEquipment, (UObject*)Z_Construct_UPackage__Script_EMBER(), TEXT("Equipment"));
	}
	return Z_Registration_Info_UScriptStruct_Equipment.OuterSingleton;
}
template<> EMBER_API UScriptStruct* StaticStruct<FEquipment>()
{
	return FEquipment::StaticStruct();
}
struct Z_Construct_UScriptStruct_FEquipment_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayRate_MetaData[] = {
		{ "Category", "Equipment" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EquipSound_MetaData[] = {
		{ "Category", "Equipment" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EquipMontage_MetaData[] = {
		{ "Category", "Equipment" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnEquipMontage_MetaData[] = {
		{ "Category", "Equipment" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayRate;
	static const UECodeGen_Private::FStructPropertyParams NewProp_EquipSound;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EquipMontage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UnEquipMontage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FEquipment>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEquipment_Statics::NewProp_PlayRate = { "PlayRate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEquipment, PlayRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayRate_MetaData), NewProp_PlayRate_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FEquipment_Statics::NewProp_EquipSound = { "EquipSound", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEquipment, EquipSound), Z_Construct_UScriptStruct_FSound2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EquipSound_MetaData), NewProp_EquipSound_MetaData) }; // 782392426
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FEquipment_Statics::NewProp_EquipMontage = { "EquipMontage", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEquipment, EquipMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EquipMontage_MetaData), NewProp_EquipMontage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FEquipment_Statics::NewProp_UnEquipMontage = { "UnEquipMontage", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEquipment, UnEquipMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnEquipMontage_MetaData), NewProp_UnEquipMontage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FEquipment_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEquipment_Statics::NewProp_PlayRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEquipment_Statics::NewProp_EquipSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEquipment_Statics::NewProp_EquipMontage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEquipment_Statics::NewProp_UnEquipMontage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEquipment_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FEquipment_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
	nullptr,
	&NewStructOps,
	"Equipment",
	Z_Construct_UScriptStruct_FEquipment_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEquipment_Statics::PropPointers),
	sizeof(FEquipment),
	alignof(FEquipment),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEquipment_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FEquipment_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FEquipment()
{
	if (!Z_Registration_Info_UScriptStruct_Equipment.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_Equipment.InnerSingleton, Z_Construct_UScriptStruct_FEquipment_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_Equipment.InnerSingleton;
}
// End ScriptStruct FEquipment

// Begin ScriptStruct FDamageData
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_DamageData;
class UScriptStruct* FDamageData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_DamageData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_DamageData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDamageData, (UObject*)Z_Construct_UPackage__Script_EMBER(), TEXT("DamageData"));
	}
	return Z_Registration_Info_UScriptStruct_DamageData.OuterSingleton;
}
template<> EMBER_API UScriptStruct* StaticStruct<FDamageData>()
{
	return FDamageData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FDamageData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Damage_MetaData[] = {
		{ "Category", "DamageData" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayRate_MetaData[] = {
		{ "Category", "DamageData" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitEffect_MetaData[] = {
		{ "Category", "DamageData" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitSound_MetaData[] = {
		{ "Category", "DamageData" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Montages_MetaData[] = {
		{ "Category", "DamageData" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Damage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayRate;
	static const UECodeGen_Private::FStructPropertyParams NewProp_HitEffect;
	static const UECodeGen_Private::FStructPropertyParams NewProp_HitSound;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Montages_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Montages;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDamageData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FDamageData_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDamageData, Damage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Damage_MetaData), NewProp_Damage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FDamageData_Statics::NewProp_PlayRate = { "PlayRate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDamageData, PlayRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayRate_MetaData), NewProp_PlayRate_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDamageData_Statics::NewProp_HitEffect = { "HitEffect", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDamageData, HitEffect), Z_Construct_UScriptStruct_FEffectData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitEffect_MetaData), NewProp_HitEffect_MetaData) }; // 1233497073
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDamageData_Statics::NewProp_HitSound = { "HitSound", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDamageData, HitSound), Z_Construct_UScriptStruct_FSound2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitSound_MetaData), NewProp_HitSound_MetaData) }; // 782392426
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FDamageData_Statics::NewProp_Montages_Inner = { "Montages", nullptr, (EPropertyFlags)0x0104000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FDamageData_Statics::NewProp_Montages = { "Montages", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDamageData, Montages), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Montages_MetaData), NewProp_Montages_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDamageData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDamageData_Statics::NewProp_Damage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDamageData_Statics::NewProp_PlayRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDamageData_Statics::NewProp_HitEffect,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDamageData_Statics::NewProp_HitSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDamageData_Statics::NewProp_Montages_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDamageData_Statics::NewProp_Montages,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDamageData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDamageData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
	nullptr,
	&NewStructOps,
	"DamageData",
	Z_Construct_UScriptStruct_FDamageData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDamageData_Statics::PropPointers),
	sizeof(FDamageData),
	alignof(FDamageData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDamageData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDamageData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDamageData()
{
	if (!Z_Registration_Info_UScriptStruct_DamageData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_DamageData.InnerSingleton, Z_Construct_UScriptStruct_FDamageData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_DamageData.InnerSingleton;
}
// End ScriptStruct FDamageData

// Begin ScriptStruct FAttackData
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AttackData;
class UScriptStruct* FAttackData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AttackData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AttackData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAttackData, (UObject*)Z_Construct_UPackage__Script_EMBER(), TEXT("AttackData"));
	}
	return Z_Registration_Info_UScriptStruct_AttackData.OuterSingleton;
}
template<> EMBER_API UScriptStruct* StaticStruct<FAttackData>()
{
	return FAttackData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FAttackData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayRate_MetaData[] = {
		{ "Category", "AttackData" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackEffect_MetaData[] = {
		{ "Category", "AttackData" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackSound_MetaData[] = {
		{ "Category", "AttackData" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Montages_MetaData[] = {
		{ "Category", "AttackData" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayRate;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AttackEffect;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AttackSound;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Montages_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Montages;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAttackData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAttackData_Statics::NewProp_PlayRate = { "PlayRate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAttackData, PlayRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayRate_MetaData), NewProp_PlayRate_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAttackData_Statics::NewProp_AttackEffect = { "AttackEffect", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAttackData, AttackEffect), Z_Construct_UScriptStruct_FEffectData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackEffect_MetaData), NewProp_AttackEffect_MetaData) }; // 1233497073
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAttackData_Statics::NewProp_AttackSound = { "AttackSound", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAttackData, AttackSound), Z_Construct_UScriptStruct_FSound2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackSound_MetaData), NewProp_AttackSound_MetaData) }; // 782392426
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FAttackData_Statics::NewProp_Montages_Inner = { "Montages", nullptr, (EPropertyFlags)0x0104000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FAttackData_Statics::NewProp_Montages = { "Montages", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAttackData, Montages), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Montages_MetaData), NewProp_Montages_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAttackData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAttackData_Statics::NewProp_PlayRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAttackData_Statics::NewProp_AttackEffect,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAttackData_Statics::NewProp_AttackSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAttackData_Statics::NewProp_Montages_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAttackData_Statics::NewProp_Montages,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAttackData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAttackData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
	nullptr,
	&NewStructOps,
	"AttackData",
	Z_Construct_UScriptStruct_FAttackData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAttackData_Statics::PropPointers),
	sizeof(FAttackData),
	alignof(FAttackData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAttackData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAttackData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAttackData()
{
	if (!Z_Registration_Info_UScriptStruct_AttackData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AttackData.InnerSingleton, Z_Construct_UScriptStruct_FAttackData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_AttackData.InnerSingleton;
}
// End ScriptStruct FAttackData

// Begin ScriptStruct FCharacterStatus
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_CharacterStatus;
class UScriptStruct* FCharacterStatus::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_CharacterStatus.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_CharacterStatus.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCharacterStatus, (UObject*)Z_Construct_UPackage__Script_EMBER(), TEXT("CharacterStatus"));
	}
	return Z_Registration_Info_UScriptStruct_CharacterStatus.OuterSingleton;
}
template<> EMBER_API UScriptStruct* StaticStruct<FCharacterStatus>()
{
	return FCharacterStatus::StaticStruct();
}
struct Z_Construct_UScriptStruct_FCharacterStatus_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentHP_MetaData[] = {
		{ "Category", "CharacterStatus" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxHP_MetaData[] = {
		{ "Category", "CharacterStatus" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentStamina_MetaData[] = {
		{ "Category", "CharacterStatus" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxStamina_MetaData[] = {
		{ "Category", "CharacterStatus" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentTemperature_MetaData[] = {
		{ "Category", "CharacterStatus" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxTemperature_MetaData[] = {
		{ "Category", "CharacterStatus" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentFatigueLevel_MetaData[] = {
		{ "Category", "CharacterStatus" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxFatigueLevel_MetaData[] = {
		{ "Category", "CharacterStatus" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentWeight_MetaData[] = {
		{ "Category", "CharacterStatus" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxWeight_MetaData[] = {
		{ "Category", "CharacterStatus" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentEnergy_MetaData[] = {
		{ "Category", "CharacterStatus" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxEnergy_MetaData[] = {
		{ "Category", "CharacterStatus" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentPhysicalStrength_MetaData[] = {
		{ "Category", "CharacterStatus" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxPhysicalStrength_MetaData[] = {
		{ "Category", "CharacterStatus" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentDexterity_MetaData[] = {
		{ "Category", "CharacterStatus" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxDexterity_MetaData[] = {
		{ "Category", "CharacterStatus" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentXP_MetaData[] = {
		{ "Category", "CharacterStatus" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxXP_MetaData[] = {
		{ "Category", "CharacterStatus" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Level_MetaData[] = {
		{ "Category", "CharacterStatus" },
		{ "ModuleRelativePath", "GameInfo/GameData.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentHP;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxHP;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentStamina;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxStamina;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentTemperature;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxTemperature;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentFatigueLevel;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxFatigueLevel;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentWeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxWeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentEnergy;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxEnergy;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentPhysicalStrength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxPhysicalStrength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentDexterity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxDexterity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentXP;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxXP;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Level;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCharacterStatus>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_CurrentHP = { "CurrentHP", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterStatus, CurrentHP), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentHP_MetaData), NewProp_CurrentHP_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_MaxHP = { "MaxHP", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterStatus, MaxHP), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxHP_MetaData), NewProp_MaxHP_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_CurrentStamina = { "CurrentStamina", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterStatus, CurrentStamina), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentStamina_MetaData), NewProp_CurrentStamina_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_MaxStamina = { "MaxStamina", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterStatus, MaxStamina), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxStamina_MetaData), NewProp_MaxStamina_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_CurrentTemperature = { "CurrentTemperature", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterStatus, CurrentTemperature), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentTemperature_MetaData), NewProp_CurrentTemperature_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_MaxTemperature = { "MaxTemperature", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterStatus, MaxTemperature), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxTemperature_MetaData), NewProp_MaxTemperature_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_CurrentFatigueLevel = { "CurrentFatigueLevel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterStatus, CurrentFatigueLevel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentFatigueLevel_MetaData), NewProp_CurrentFatigueLevel_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_MaxFatigueLevel = { "MaxFatigueLevel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterStatus, MaxFatigueLevel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxFatigueLevel_MetaData), NewProp_MaxFatigueLevel_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_CurrentWeight = { "CurrentWeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterStatus, CurrentWeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentWeight_MetaData), NewProp_CurrentWeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_MaxWeight = { "MaxWeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterStatus, MaxWeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxWeight_MetaData), NewProp_MaxWeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_CurrentEnergy = { "CurrentEnergy", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterStatus, CurrentEnergy), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentEnergy_MetaData), NewProp_CurrentEnergy_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_MaxEnergy = { "MaxEnergy", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterStatus, MaxEnergy), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxEnergy_MetaData), NewProp_MaxEnergy_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_CurrentPhysicalStrength = { "CurrentPhysicalStrength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterStatus, CurrentPhysicalStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentPhysicalStrength_MetaData), NewProp_CurrentPhysicalStrength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_MaxPhysicalStrength = { "MaxPhysicalStrength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterStatus, MaxPhysicalStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxPhysicalStrength_MetaData), NewProp_MaxPhysicalStrength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_CurrentDexterity = { "CurrentDexterity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterStatus, CurrentDexterity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentDexterity_MetaData), NewProp_CurrentDexterity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_MaxDexterity = { "MaxDexterity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterStatus, MaxDexterity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxDexterity_MetaData), NewProp_MaxDexterity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_CurrentXP = { "CurrentXP", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterStatus, CurrentXP), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentXP_MetaData), NewProp_CurrentXP_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_MaxXP = { "MaxXP", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterStatus, MaxXP), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxXP_MetaData), NewProp_MaxXP_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_Level = { "Level", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterStatus, Level), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Level_MetaData), NewProp_Level_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCharacterStatus_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_CurrentHP,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_MaxHP,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_CurrentStamina,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_MaxStamina,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_CurrentTemperature,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_MaxTemperature,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_CurrentFatigueLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_MaxFatigueLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_CurrentWeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_MaxWeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_CurrentEnergy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_MaxEnergy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_CurrentPhysicalStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_MaxPhysicalStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_CurrentDexterity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_MaxDexterity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_CurrentXP,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_MaxXP,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewProp_Level,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharacterStatus_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCharacterStatus_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
	nullptr,
	&NewStructOps,
	"CharacterStatus",
	Z_Construct_UScriptStruct_FCharacterStatus_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharacterStatus_Statics::PropPointers),
	sizeof(FCharacterStatus),
	alignof(FCharacterStatus),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharacterStatus_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCharacterStatus_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCharacterStatus()
{
	if (!Z_Registration_Info_UScriptStruct_CharacterStatus.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_CharacterStatus.InnerSingleton, Z_Construct_UScriptStruct_FCharacterStatus_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_CharacterStatus.InnerSingleton;
}
// End ScriptStruct FCharacterStatus

// Begin Registration
struct Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_GameInfo_GameData_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FEffectData::StaticStruct, Z_Construct_UScriptStruct_FEffectData_Statics::NewStructOps, TEXT("EffectData"), &Z_Registration_Info_UScriptStruct_EffectData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FEffectData), 1233497073U) },
		{ FSound2D::StaticStruct, Z_Construct_UScriptStruct_FSound2D_Statics::NewStructOps, TEXT("Sound2D"), &Z_Registration_Info_UScriptStruct_Sound2D, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSound2D), 782392426U) },
		{ FParryData::StaticStruct, Z_Construct_UScriptStruct_FParryData_Statics::NewStructOps, TEXT("ParryData"), &Z_Registration_Info_UScriptStruct_ParryData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FParryData), 3490992741U) },
		{ FEquipment::StaticStruct, Z_Construct_UScriptStruct_FEquipment_Statics::NewStructOps, TEXT("Equipment"), &Z_Registration_Info_UScriptStruct_Equipment, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FEquipment), 2917243194U) },
		{ FDamageData::StaticStruct, Z_Construct_UScriptStruct_FDamageData_Statics::NewStructOps, TEXT("DamageData"), &Z_Registration_Info_UScriptStruct_DamageData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDamageData), 1163867478U) },
		{ FAttackData::StaticStruct, Z_Construct_UScriptStruct_FAttackData_Statics::NewStructOps, TEXT("AttackData"), &Z_Registration_Info_UScriptStruct_AttackData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAttackData), 2667999302U) },
		{ FCharacterStatus::StaticStruct, Z_Construct_UScriptStruct_FCharacterStatus_Statics::NewStructOps, TEXT("CharacterStatus"), &Z_Registration_Info_UScriptStruct_CharacterStatus, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCharacterStatus), 3677320349U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_GameInfo_GameData_h_2356651681(TEXT("/Script/EMBER"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_GameInfo_GameData_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_GameInfo_GameData_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
