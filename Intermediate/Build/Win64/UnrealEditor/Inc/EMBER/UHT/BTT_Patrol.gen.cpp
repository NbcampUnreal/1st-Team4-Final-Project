// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/AI/BTT_Patrol.h"
#include "Runtime/AIModule/Classes/AITypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTT_Patrol() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UBTTask_BlackboardBase();
AIMODULE_API UEnum* Z_Construct_UEnum_AIModule_EPathFollowingResult();
AIMODULE_API UScriptStruct* Z_Construct_UScriptStruct_FAIRequestID();
EMBER_API UClass* Z_Construct_UClass_UBTT_Patrol();
EMBER_API UClass* Z_Construct_UClass_UBTT_Patrol_NoRegister();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Class UBTT_Patrol Function OnMoveCompleted
struct Z_Construct_UFunction_UBTT_Patrol_OnMoveCompleted_Statics
{
	struct BTT_Patrol_eventOnMoveCompleted_Parms
	{
		FAIRequestID RequestID;
		TEnumAsByte<EPathFollowingResult::Type> Result;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "AI/BTT_Patrol.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_RequestID;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Result;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBTT_Patrol_OnMoveCompleted_Statics::NewProp_RequestID = { "RequestID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BTT_Patrol_eventOnMoveCompleted_Parms, RequestID), Z_Construct_UScriptStruct_FAIRequestID, METADATA_PARAMS(0, nullptr) }; // 2000238872
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBTT_Patrol_OnMoveCompleted_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BTT_Patrol_eventOnMoveCompleted_Parms, Result), Z_Construct_UEnum_AIModule_EPathFollowingResult, METADATA_PARAMS(0, nullptr) }; // 3125870747
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBTT_Patrol_OnMoveCompleted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBTT_Patrol_OnMoveCompleted_Statics::NewProp_RequestID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBTT_Patrol_OnMoveCompleted_Statics::NewProp_Result,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBTT_Patrol_OnMoveCompleted_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBTT_Patrol_OnMoveCompleted_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UBTT_Patrol, nullptr, "OnMoveCompleted", nullptr, nullptr, Z_Construct_UFunction_UBTT_Patrol_OnMoveCompleted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UBTT_Patrol_OnMoveCompleted_Statics::PropPointers), sizeof(Z_Construct_UFunction_UBTT_Patrol_OnMoveCompleted_Statics::BTT_Patrol_eventOnMoveCompleted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBTT_Patrol_OnMoveCompleted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBTT_Patrol_OnMoveCompleted_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UBTT_Patrol_OnMoveCompleted_Statics::BTT_Patrol_eventOnMoveCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBTT_Patrol_OnMoveCompleted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBTT_Patrol_OnMoveCompleted_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBTT_Patrol::execOnMoveCompleted)
{
	P_GET_STRUCT(FAIRequestID,Z_Param_RequestID);
	P_GET_PROPERTY(FByteProperty,Z_Param_Result);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnMoveCompleted(Z_Param_RequestID,EPathFollowingResult::Type(Z_Param_Result));
	P_NATIVE_END;
}
// End Class UBTT_Patrol Function OnMoveCompleted

// Begin Class UBTT_Patrol
void UBTT_Patrol::StaticRegisterNativesUBTT_Patrol()
{
	UClass* Class = UBTT_Patrol::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnMoveCompleted", &UBTT_Patrol::execOnMoveCompleted },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBTT_Patrol);
UClass* Z_Construct_UClass_UBTT_Patrol_NoRegister()
{
	return UBTT_Patrol::StaticClass();
}
struct Z_Construct_UClass_UBTT_Patrol_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "AI/BTT_Patrol.h" },
		{ "ModuleRelativePath", "AI/BTT_Patrol.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UBTT_Patrol_OnMoveCompleted, "OnMoveCompleted" }, // 4059957550
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTT_Patrol>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UBTT_Patrol_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBTTask_BlackboardBase,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTT_Patrol_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTT_Patrol_Statics::ClassParams = {
	&UBTT_Patrol::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTT_Patrol_Statics::Class_MetaDataParams), Z_Construct_UClass_UBTT_Patrol_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UBTT_Patrol()
{
	if (!Z_Registration_Info_UClass_UBTT_Patrol.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTT_Patrol.OuterSingleton, Z_Construct_UClass_UBTT_Patrol_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBTT_Patrol.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<UBTT_Patrol>()
{
	return UBTT_Patrol::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UBTT_Patrol);
UBTT_Patrol::~UBTT_Patrol() {}
// End Class UBTT_Patrol

// Begin Registration
struct Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_AI_BTT_Patrol_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBTT_Patrol, UBTT_Patrol::StaticClass, TEXT("UBTT_Patrol"), &Z_Registration_Info_UClass_UBTT_Patrol, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTT_Patrol), 2516386874U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_AI_BTT_Patrol_h_3078046618(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_AI_BTT_Patrol_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_AI_BTT_Patrol_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
