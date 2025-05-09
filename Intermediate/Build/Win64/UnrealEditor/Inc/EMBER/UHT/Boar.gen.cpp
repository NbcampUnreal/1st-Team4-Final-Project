// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/AI/Animal/Boar.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBoar() {}

// Begin Cross Module References
EMBER_API UClass* Z_Construct_UClass_ABaseAI();
EMBER_API UClass* Z_Construct_UClass_ABoar();
EMBER_API UClass* Z_Construct_UClass_ABoar_NoRegister();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Class ABoar
void ABoar::StaticRegisterNativesABoar()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABoar);
UClass* Z_Construct_UClass_ABoar_NoRegister()
{
	return ABoar::StaticClass();
}
struct Z_Construct_UClass_ABoar_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "AI/Animal/Boar.h" },
		{ "ModuleRelativePath", "AI/Animal/Boar.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABoar>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ABoar_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABaseAI,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABoar_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABoar_Statics::ClassParams = {
	&ABoar::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABoar_Statics::Class_MetaDataParams), Z_Construct_UClass_ABoar_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABoar()
{
	if (!Z_Registration_Info_UClass_ABoar.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABoar.OuterSingleton, Z_Construct_UClass_ABoar_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABoar.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<ABoar>()
{
	return ABoar::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABoar);
ABoar::~ABoar() {}
// End Class ABoar

// Begin Registration
struct Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_AI_Animal_Boar_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABoar, ABoar::StaticClass, TEXT("ABoar"), &Z_Registration_Info_UClass_ABoar, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABoar), 2016275152U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_AI_Animal_Boar_h_432379280(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_AI_Animal_Boar_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_AI_Animal_Boar_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
