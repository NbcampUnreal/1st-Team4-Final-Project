// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/AI/BaseAIController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBaseAIController() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_AAIController();
EMBER_API UClass* Z_Construct_UClass_ABaseAIController();
EMBER_API UClass* Z_Construct_UClass_ABaseAIController_NoRegister();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Class ABaseAIController
void ABaseAIController::StaticRegisterNativesABaseAIController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABaseAIController);
UClass* Z_Construct_UClass_ABaseAIController_NoRegister()
{
	return ABaseAIController::StaticClass();
}
struct Z_Construct_UClass_ABaseAIController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "AI/BaseAIController.h" },
		{ "ModuleRelativePath", "AI/BaseAIController.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABaseAIController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ABaseAIController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AAIController,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABaseAIController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABaseAIController_Statics::ClassParams = {
	&ABaseAIController::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABaseAIController_Statics::Class_MetaDataParams), Z_Construct_UClass_ABaseAIController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABaseAIController()
{
	if (!Z_Registration_Info_UClass_ABaseAIController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABaseAIController.OuterSingleton, Z_Construct_UClass_ABaseAIController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABaseAIController.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<ABaseAIController>()
{
	return ABaseAIController::StaticClass();
}
ABaseAIController::ABaseAIController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABaseAIController);
ABaseAIController::~ABaseAIController() {}
// End Class ABaseAIController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_AI_BaseAIController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABaseAIController, ABaseAIController::StaticClass, TEXT("ABaseAIController"), &Z_Registration_Info_UClass_ABaseAIController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABaseAIController), 1848887059U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_AI_BaseAIController_h_294056140(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_AI_BaseAIController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_AI_BaseAIController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
