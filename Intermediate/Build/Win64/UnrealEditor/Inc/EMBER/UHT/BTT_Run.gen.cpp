// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/AI/BTT_Run.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTT_Run() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UBTTask_BlackboardBase();
EMBER_API UClass* Z_Construct_UClass_UBTT_Run();
EMBER_API UClass* Z_Construct_UClass_UBTT_Run_NoRegister();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Class UBTT_Run
void UBTT_Run::StaticRegisterNativesUBTT_Run()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBTT_Run);
UClass* Z_Construct_UClass_UBTT_Run_NoRegister()
{
	return UBTT_Run::StaticClass();
}
struct Z_Construct_UClass_UBTT_Run_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AI/BTT_Run.h" },
		{ "ModuleRelativePath", "AI/BTT_Run.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTT_Run>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UBTT_Run_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBTTask_BlackboardBase,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTT_Run_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTT_Run_Statics::ClassParams = {
	&UBTT_Run::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTT_Run_Statics::Class_MetaDataParams), Z_Construct_UClass_UBTT_Run_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UBTT_Run()
{
	if (!Z_Registration_Info_UClass_UBTT_Run.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTT_Run.OuterSingleton, Z_Construct_UClass_UBTT_Run_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBTT_Run.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<UBTT_Run>()
{
	return UBTT_Run::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UBTT_Run);
UBTT_Run::~UBTT_Run() {}
// End Class UBTT_Run

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_AI_BTT_Run_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBTT_Run, UBTT_Run::StaticClass, TEXT("UBTT_Run"), &Z_Registration_Info_UClass_UBTT_Run, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTT_Run), 2824347603U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_AI_BTT_Run_h_3103766088(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_AI_BTT_Run_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_AI_BTT_Run_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
