// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/AI/Animal/Deer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDeer() {}

// Begin Cross Module References
EMBER_API UClass* Z_Construct_UClass_ABaseAI();
EMBER_API UClass* Z_Construct_UClass_ADeer();
EMBER_API UClass* Z_Construct_UClass_ADeer_NoRegister();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Class ADeer
void ADeer::StaticRegisterNativesADeer()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADeer);
UClass* Z_Construct_UClass_ADeer_NoRegister()
{
	return ADeer::StaticClass();
}
struct Z_Construct_UClass_ADeer_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "AI/Animal/Deer.h" },
		{ "ModuleRelativePath", "AI/Animal/Deer.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADeer>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ADeer_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABaseAI,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADeer_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ADeer_Statics::ClassParams = {
	&ADeer::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADeer_Statics::Class_MetaDataParams), Z_Construct_UClass_ADeer_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ADeer()
{
	if (!Z_Registration_Info_UClass_ADeer.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADeer.OuterSingleton, Z_Construct_UClass_ADeer_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ADeer.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<ADeer>()
{
	return ADeer::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ADeer);
ADeer::~ADeer() {}
// End Class ADeer

// Begin Registration
struct Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_AI_Animal_Deer_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADeer, ADeer::StaticClass, TEXT("ADeer"), &Z_Registration_Info_UClass_ADeer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADeer), 2784519585U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_AI_Animal_Deer_h_107612527(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_AI_Animal_Deer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_AI_Animal_Deer_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
