// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/AI/AnimInstance_Boar.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAnimInstance_Boar() {}

// Begin Cross Module References
EMBER_API UClass* Z_Construct_UClass_UAnimInstance_Boar();
EMBER_API UClass* Z_Construct_UClass_UAnimInstance_Boar_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Class UAnimInstance_Boar
void UAnimInstance_Boar::StaticRegisterNativesUAnimInstance_Boar()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAnimInstance_Boar);
UClass* Z_Construct_UClass_UAnimInstance_Boar_NoRegister()
{
	return UAnimInstance_Boar::StaticClass();
}
struct Z_Construct_UClass_UAnimInstance_Boar_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "AI/AnimInstance_Boar.h" },
		{ "ModuleRelativePath", "AI/AnimInstance_Boar.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAnimInstance_Boar>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UAnimInstance_Boar_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAnimInstance,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimInstance_Boar_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAnimInstance_Boar_Statics::ClassParams = {
	&UAnimInstance_Boar::StaticClass,
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
	0x009000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimInstance_Boar_Statics::Class_MetaDataParams), Z_Construct_UClass_UAnimInstance_Boar_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAnimInstance_Boar()
{
	if (!Z_Registration_Info_UClass_UAnimInstance_Boar.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAnimInstance_Boar.OuterSingleton, Z_Construct_UClass_UAnimInstance_Boar_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAnimInstance_Boar.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<UAnimInstance_Boar>()
{
	return UAnimInstance_Boar::StaticClass();
}
UAnimInstance_Boar::UAnimInstance_Boar(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UAnimInstance_Boar);
UAnimInstance_Boar::~UAnimInstance_Boar() {}
// End Class UAnimInstance_Boar

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_AI_AnimInstance_Boar_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAnimInstance_Boar, UAnimInstance_Boar::StaticClass, TEXT("UAnimInstance_Boar"), &Z_Registration_Info_UClass_UAnimInstance_Boar, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAnimInstance_Boar), 1719042264U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_AI_AnimInstance_Boar_h_1831797472(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_AI_AnimInstance_Boar_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_AI_AnimInstance_Boar_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
