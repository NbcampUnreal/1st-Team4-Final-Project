// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/Component/C_CameraComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeC_CameraComponent() {}

// Begin Cross Module References
EMBER_API UClass* Z_Construct_UClass_UC_CameraComponent();
EMBER_API UClass* Z_Construct_UClass_UC_CameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Class UC_CameraComponent
void UC_CameraComponent::StaticRegisterNativesUC_CameraComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UC_CameraComponent);
UClass* Z_Construct_UClass_UC_CameraComponent_NoRegister()
{
	return UC_CameraComponent::StaticClass();
}
struct Z_Construct_UClass_UC_CameraComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Component/C_CameraComponent.h" },
		{ "ModuleRelativePath", "Component/C_CameraComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HorizontalLook_MetaData[] = {
		{ "Category", "CameraSpeed" },
		{ "ModuleRelativePath", "Component/C_CameraComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VerticalLook_MetaData[] = {
		{ "Category", "CameraSpeed" },
		{ "ModuleRelativePath", "Component/C_CameraComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HorizontalLook;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_VerticalLook;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UC_CameraComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UC_CameraComponent_Statics::NewProp_HorizontalLook = { "HorizontalLook", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UC_CameraComponent, HorizontalLook), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HorizontalLook_MetaData), NewProp_HorizontalLook_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UC_CameraComponent_Statics::NewProp_VerticalLook = { "VerticalLook", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UC_CameraComponent, VerticalLook), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VerticalLook_MetaData), NewProp_VerticalLook_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UC_CameraComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UC_CameraComponent_Statics::NewProp_HorizontalLook,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UC_CameraComponent_Statics::NewProp_VerticalLook,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UC_CameraComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UC_CameraComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UC_CameraComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UC_CameraComponent_Statics::ClassParams = {
	&UC_CameraComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UC_CameraComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UC_CameraComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UC_CameraComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UC_CameraComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UC_CameraComponent()
{
	if (!Z_Registration_Info_UClass_UC_CameraComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UC_CameraComponent.OuterSingleton, Z_Construct_UClass_UC_CameraComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UC_CameraComponent.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<UC_CameraComponent>()
{
	return UC_CameraComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UC_CameraComponent);
UC_CameraComponent::~UC_CameraComponent() {}
// End Class UC_CameraComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_1st_Team4_Final_Project_Source_EMBER_Component_C_CameraComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UC_CameraComponent, UC_CameraComponent::StaticClass, TEXT("UC_CameraComponent"), &Z_Registration_Info_UClass_UC_CameraComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UC_CameraComponent), 2988076587U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_1st_Team4_Final_Project_Source_EMBER_Component_C_CameraComponent_h_3882747417(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_1st_Team4_Final_Project_Source_EMBER_Component_C_CameraComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_1st_Team4_Final_Project_Source_EMBER_Component_C_CameraComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
