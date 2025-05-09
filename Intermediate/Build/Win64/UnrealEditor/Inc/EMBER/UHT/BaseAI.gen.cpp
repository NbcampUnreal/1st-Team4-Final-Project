// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/AI/BaseAI.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBaseAI() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UAIPerceptionComponent_NoRegister();
AIMODULE_API UClass* Z_Construct_UClass_UAISenseConfig_Sight_NoRegister();
EMBER_API UClass* Z_Construct_UClass_ABaseAI();
EMBER_API UClass* Z_Construct_UClass_ABaseAI_NoRegister();
EMBER_API UEnum* Z_Construct_UEnum_EMBER_AISoundCategory();
EMBER_API UEnum* Z_Construct_UEnum_EMBER_EAnimalType();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_ATargetPoint_NoRegister();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Enum AISoundCategory
static FEnumRegistrationInfo Z_Registration_Info_UEnum_AISoundCategory;
static UEnum* AISoundCategory_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_AISoundCategory.OuterSingleton)
	{
		Z_Registration_Info_UEnum_AISoundCategory.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EMBER_AISoundCategory, (UObject*)Z_Construct_UPackage__Script_EMBER(), TEXT("AISoundCategory"));
	}
	return Z_Registration_Info_UEnum_AISoundCategory.OuterSingleton;
}
template<> EMBER_API UEnum* StaticEnum<AISoundCategory>()
{
	return AISoundCategory_StaticEnum();
}
struct Z_Construct_UEnum_EMBER_AISoundCategory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AttackSound.DisplayName", "Attack" },
		{ "AttackSound.Name", "AISoundCategory::AttackSound" },
		{ "BlueprintType", "true" },
		{ "DeathSound.DisplayName", "Death" },
		{ "DeathSound.Name", "AISoundCategory::DeathSound" },
		{ "HitSound.DisplayName", "Hit" },
		{ "HitSound.Name", "AISoundCategory::HitSound" },
		{ "ModuleRelativePath", "AI/BaseAI.h" },
		{ "MoveSound.DisplayName", "Move" },
		{ "MoveSound.Name", "AISoundCategory::MoveSound" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "AISoundCategory::MoveSound", (int64)AISoundCategory::MoveSound },
		{ "AISoundCategory::AttackSound", (int64)AISoundCategory::AttackSound },
		{ "AISoundCategory::HitSound", (int64)AISoundCategory::HitSound },
		{ "AISoundCategory::DeathSound", (int64)AISoundCategory::DeathSound },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EMBER_AISoundCategory_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EMBER,
	nullptr,
	"AISoundCategory",
	"AISoundCategory",
	Z_Construct_UEnum_EMBER_AISoundCategory_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EMBER_AISoundCategory_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EMBER_AISoundCategory_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EMBER_AISoundCategory_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EMBER_AISoundCategory()
{
	if (!Z_Registration_Info_UEnum_AISoundCategory.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_AISoundCategory.InnerSingleton, Z_Construct_UEnum_EMBER_AISoundCategory_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_AISoundCategory.InnerSingleton;
}
// End Enum AISoundCategory

// Begin Class ABaseAI Function Attack
struct Z_Construct_UFunction_ABaseAI_Attack_Statics
{
	struct BaseAI_eventAttack_Parms
	{
		AActor* Target;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "AI/BaseAI.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABaseAI_Attack_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BaseAI_eventAttack_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABaseAI_Attack_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABaseAI_Attack_Statics::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseAI_Attack_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABaseAI_Attack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABaseAI, nullptr, "Attack", nullptr, nullptr, Z_Construct_UFunction_ABaseAI_Attack_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseAI_Attack_Statics::PropPointers), sizeof(Z_Construct_UFunction_ABaseAI_Attack_Statics::BaseAI_eventAttack_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseAI_Attack_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABaseAI_Attack_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ABaseAI_Attack_Statics::BaseAI_eventAttack_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ABaseAI_Attack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABaseAI_Attack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ABaseAI::execAttack)
{
	P_GET_OBJECT(AActor,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Attack(Z_Param_Target);
	P_NATIVE_END;
}
// End Class ABaseAI Function Attack

// Begin Class ABaseAI Function OnDeath
struct Z_Construct_UFunction_ABaseAI_OnDeath_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "AI/BaseAI.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABaseAI_OnDeath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABaseAI, nullptr, "OnDeath", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseAI_OnDeath_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABaseAI_OnDeath_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ABaseAI_OnDeath()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABaseAI_OnDeath_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ABaseAI::execOnDeath)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnDeath();
	P_NATIVE_END;
}
// End Class ABaseAI Function OnDeath

// Begin Class ABaseAI Function OnPerceptionUpdated
struct Z_Construct_UFunction_ABaseAI_OnPerceptionUpdated_Statics
{
	struct BaseAI_eventOnPerceptionUpdated_Parms
	{
		TArray<AActor*> UpdatedActors;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "AI/BaseAI.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UpdatedActors_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UpdatedActors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_UpdatedActors;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABaseAI_OnPerceptionUpdated_Statics::NewProp_UpdatedActors_Inner = { "UpdatedActors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ABaseAI_OnPerceptionUpdated_Statics::NewProp_UpdatedActors = { "UpdatedActors", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BaseAI_eventOnPerceptionUpdated_Parms, UpdatedActors), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UpdatedActors_MetaData), NewProp_UpdatedActors_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABaseAI_OnPerceptionUpdated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABaseAI_OnPerceptionUpdated_Statics::NewProp_UpdatedActors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABaseAI_OnPerceptionUpdated_Statics::NewProp_UpdatedActors,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseAI_OnPerceptionUpdated_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABaseAI_OnPerceptionUpdated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABaseAI, nullptr, "OnPerceptionUpdated", nullptr, nullptr, Z_Construct_UFunction_ABaseAI_OnPerceptionUpdated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseAI_OnPerceptionUpdated_Statics::PropPointers), sizeof(Z_Construct_UFunction_ABaseAI_OnPerceptionUpdated_Statics::BaseAI_eventOnPerceptionUpdated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseAI_OnPerceptionUpdated_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABaseAI_OnPerceptionUpdated_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ABaseAI_OnPerceptionUpdated_Statics::BaseAI_eventOnPerceptionUpdated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ABaseAI_OnPerceptionUpdated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABaseAI_OnPerceptionUpdated_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ABaseAI::execOnPerceptionUpdated)
{
	P_GET_TARRAY_REF(AActor*,Z_Param_Out_UpdatedActors);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnPerceptionUpdated(Z_Param_Out_UpdatedActors);
	P_NATIVE_END;
}
// End Class ABaseAI Function OnPerceptionUpdated

// Begin Class ABaseAI
void ABaseAI::StaticRegisterNativesABaseAI()
{
	UClass* Class = ABaseAI::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Attack", &ABaseAI::execAttack },
		{ "OnDeath", &ABaseAI::execOnDeath },
		{ "OnPerceptionUpdated", &ABaseAI::execOnPerceptionUpdated },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABaseAI);
UClass* Z_Construct_UClass_ABaseAI_NoRegister()
{
	return ABaseAI::StaticClass();
}
struct Z_Construct_UClass_ABaseAI_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "AI/BaseAI.h" },
		{ "ModuleRelativePath", "AI/BaseAI.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnimalType_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "AI/BaseAI.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackPower_MetaData[] = {
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "AI/BaseAI.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveSpeed_MetaData[] = {
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "AI/BaseAI.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AIPerception_MetaData[] = {
		{ "Category", "AI" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "AI/BaseAI.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SightConfig_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "AI/BaseAI.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_patrolpoint_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "AI/BaseAI.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_AnimalType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_AnimalType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackPower;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MoveSpeed;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AIPerception;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SightConfig;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_patrolpoint_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_patrolpoint;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ABaseAI_Attack, "Attack" }, // 4248190397
		{ &Z_Construct_UFunction_ABaseAI_OnDeath, "OnDeath" }, // 3871829049
		{ &Z_Construct_UFunction_ABaseAI_OnPerceptionUpdated, "OnPerceptionUpdated" }, // 226473128
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABaseAI>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ABaseAI_Statics::NewProp_AnimalType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ABaseAI_Statics::NewProp_AnimalType = { "AnimalType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABaseAI, AnimalType), Z_Construct_UEnum_EMBER_EAnimalType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnimalType_MetaData), NewProp_AnimalType_MetaData) }; // 324055089
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABaseAI_Statics::NewProp_AttackPower = { "AttackPower", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABaseAI, AttackPower), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackPower_MetaData), NewProp_AttackPower_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABaseAI_Statics::NewProp_MoveSpeed = { "MoveSpeed", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABaseAI, MoveSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveSpeed_MetaData), NewProp_MoveSpeed_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABaseAI_Statics::NewProp_AIPerception = { "AIPerception", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABaseAI, AIPerception), Z_Construct_UClass_UAIPerceptionComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AIPerception_MetaData), NewProp_AIPerception_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABaseAI_Statics::NewProp_SightConfig = { "SightConfig", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABaseAI, SightConfig), Z_Construct_UClass_UAISenseConfig_Sight_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SightConfig_MetaData), NewProp_SightConfig_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABaseAI_Statics::NewProp_patrolpoint_Inner = { "patrolpoint", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ATargetPoint_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ABaseAI_Statics::NewProp_patrolpoint = { "patrolpoint", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABaseAI, patrolpoint), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_patrolpoint_MetaData), NewProp_patrolpoint_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABaseAI_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseAI_Statics::NewProp_AnimalType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseAI_Statics::NewProp_AnimalType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseAI_Statics::NewProp_AttackPower,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseAI_Statics::NewProp_MoveSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseAI_Statics::NewProp_AIPerception,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseAI_Statics::NewProp_SightConfig,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseAI_Statics::NewProp_patrolpoint_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseAI_Statics::NewProp_patrolpoint,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABaseAI_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ABaseAI_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABaseAI_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABaseAI_Statics::ClassParams = {
	&ABaseAI::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ABaseAI_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ABaseAI_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABaseAI_Statics::Class_MetaDataParams), Z_Construct_UClass_ABaseAI_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABaseAI()
{
	if (!Z_Registration_Info_UClass_ABaseAI.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABaseAI.OuterSingleton, Z_Construct_UClass_ABaseAI_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABaseAI.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<ABaseAI>()
{
	return ABaseAI::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABaseAI);
ABaseAI::~ABaseAI() {}
// End Class ABaseAI

// Begin Registration
struct Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_AI_BaseAI_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ AISoundCategory_StaticEnum, TEXT("AISoundCategory"), &Z_Registration_Info_UEnum_AISoundCategory, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2822768623U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABaseAI, ABaseAI::StaticClass, TEXT("ABaseAI"), &Z_Registration_Info_UClass_ABaseAI, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABaseAI), 4177373684U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_AI_BaseAI_h_1533471773(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_AI_BaseAI_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_AI_BaseAI_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_AI_BaseAI_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_AI_BaseAI_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
