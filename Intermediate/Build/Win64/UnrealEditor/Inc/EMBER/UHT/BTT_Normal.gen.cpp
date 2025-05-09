// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/AI/Task/BTT_Normal.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTT_Normal() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UBTTask_BlackboardBase();
EMBER_API UClass* Z_Construct_UClass_UBTT_Normal();
EMBER_API UClass* Z_Construct_UClass_UBTT_Normal_NoRegister();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Class UBTT_Normal
void UBTT_Normal::StaticRegisterNativesUBTT_Normal()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBTT_Normal);
UClass* Z_Construct_UClass_UBTT_Normal_NoRegister()
{
	return UBTT_Normal::StaticClass();
}
struct Z_Construct_UClass_UBTT_Normal_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "AI/Task/BTT_Normal.h" },
		{ "ModuleRelativePath", "AI/Task/BTT_Normal.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTT_Normal>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UBTT_Normal_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBTTask_BlackboardBase,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTT_Normal_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTT_Normal_Statics::ClassParams = {
	&UBTT_Normal::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTT_Normal_Statics::Class_MetaDataParams), Z_Construct_UClass_UBTT_Normal_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UBTT_Normal()
{
	if (!Z_Registration_Info_UClass_UBTT_Normal.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTT_Normal.OuterSingleton, Z_Construct_UClass_UBTT_Normal_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBTT_Normal.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<UBTT_Normal>()
{
	return UBTT_Normal::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UBTT_Normal);
UBTT_Normal::~UBTT_Normal() {}
// End Class UBTT_Normal

// Begin Registration
struct Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_AI_Task_BTT_Normal_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBTT_Normal, UBTT_Normal::StaticClass, TEXT("UBTT_Normal"), &Z_Registration_Info_UClass_UBTT_Normal, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTT_Normal), 4139227750U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_AI_Task_BTT_Normal_h_872056298(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_AI_Task_BTT_Normal_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_AI_Task_BTT_Normal_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
