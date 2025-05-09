// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/AI/BTT_Guard.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTT_Guard() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UBTTask_BlackboardBase();
EMBER_API UClass* Z_Construct_UClass_UBTT_Guard();
EMBER_API UClass* Z_Construct_UClass_UBTT_Guard_NoRegister();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Class UBTT_Guard
void UBTT_Guard::StaticRegisterNativesUBTT_Guard()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBTT_Guard);
UClass* Z_Construct_UClass_UBTT_Guard_NoRegister()
{
	return UBTT_Guard::StaticClass();
}
struct Z_Construct_UClass_UBTT_Guard_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "AI/BTT_Guard.h" },
		{ "ModuleRelativePath", "AI/BTT_Guard.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTT_Guard>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UBTT_Guard_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBTTask_BlackboardBase,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTT_Guard_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTT_Guard_Statics::ClassParams = {
	&UBTT_Guard::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTT_Guard_Statics::Class_MetaDataParams), Z_Construct_UClass_UBTT_Guard_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UBTT_Guard()
{
	if (!Z_Registration_Info_UClass_UBTT_Guard.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTT_Guard.OuterSingleton, Z_Construct_UClass_UBTT_Guard_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBTT_Guard.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<UBTT_Guard>()
{
	return UBTT_Guard::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UBTT_Guard);
UBTT_Guard::~UBTT_Guard() {}
// End Class UBTT_Guard

// Begin Registration
struct Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_AI_BTT_Guard_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBTT_Guard, UBTT_Guard::StaticClass, TEXT("UBTT_Guard"), &Z_Registration_Info_UClass_UBTT_Guard, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTT_Guard), 1472496326U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_AI_BTT_Guard_h_1252947950(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_AI_BTT_Guard_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_AI_BTT_Guard_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
