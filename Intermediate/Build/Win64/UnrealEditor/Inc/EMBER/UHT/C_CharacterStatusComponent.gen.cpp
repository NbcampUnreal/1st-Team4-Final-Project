// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/Component/C_CharacterStatusComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeC_CharacterStatusComponent() {}

// Begin Cross Module References
EMBER_API UClass* Z_Construct_UClass_UC_CharacterStatusComponent();
EMBER_API UClass* Z_Construct_UClass_UC_CharacterStatusComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Class UC_CharacterStatusComponent
void UC_CharacterStatusComponent::StaticRegisterNativesUC_CharacterStatusComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UC_CharacterStatusComponent);
UClass* Z_Construct_UClass_UC_CharacterStatusComponent_NoRegister()
{
	return UC_CharacterStatusComponent::StaticClass();
}
struct Z_Construct_UClass_UC_CharacterStatusComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Component/C_CharacterStatusComponent.h" },
		{ "ModuleRelativePath", "Component/C_CharacterStatusComponent.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UC_CharacterStatusComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UC_CharacterStatusComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UC_CharacterStatusComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UC_CharacterStatusComponent_Statics::ClassParams = {
	&UC_CharacterStatusComponent::StaticClass,
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
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UC_CharacterStatusComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UC_CharacterStatusComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UC_CharacterStatusComponent()
{
	if (!Z_Registration_Info_UClass_UC_CharacterStatusComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UC_CharacterStatusComponent.OuterSingleton, Z_Construct_UClass_UC_CharacterStatusComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UC_CharacterStatusComponent.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<UC_CharacterStatusComponent>()
{
	return UC_CharacterStatusComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UC_CharacterStatusComponent);
UC_CharacterStatusComponent::~UC_CharacterStatusComponent() {}
// End Class UC_CharacterStatusComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Component_C_CharacterStatusComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UC_CharacterStatusComponent, UC_CharacterStatusComponent::StaticClass, TEXT("UC_CharacterStatusComponent"), &Z_Registration_Info_UClass_UC_CharacterStatusComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UC_CharacterStatusComponent), 3054607116U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Component_C_CharacterStatusComponent_h_2423749999(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Component_C_CharacterStatusComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Component_C_CharacterStatusComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
