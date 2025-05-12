// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/Item/ItemInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeItemInstance() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
EMBER_API UClass* Z_Construct_UClass_UItemInstance();
EMBER_API UClass* Z_Construct_UClass_UItemInstance_NoRegister();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Class UItemInstance
void UItemInstance::StaticRegisterNativesUItemInstance()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UItemInstance);
UClass* Z_Construct_UClass_UItemInstance_NoRegister()
{
	return UItemInstance::StaticClass();
}
struct Z_Construct_UClass_UItemInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Item/ItemInstance.h" },
		{ "ModuleRelativePath", "Item/ItemInstance.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UItemInstance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UItemInstance_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UItemInstance_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UItemInstance_Statics::ClassParams = {
	&UItemInstance::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UItemInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UItemInstance_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UItemInstance()
{
	if (!Z_Registration_Info_UClass_UItemInstance.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UItemInstance.OuterSingleton, Z_Construct_UClass_UItemInstance_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UItemInstance.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<UItemInstance>()
{
	return UItemInstance::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UItemInstance);
UItemInstance::~UItemInstance() {}
// End Class UItemInstance

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_Item_ItemInstance_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UItemInstance, UItemInstance::StaticClass, TEXT("UItemInstance"), &Z_Registration_Info_UClass_UItemInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UItemInstance), 4081983744U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_Item_ItemInstance_h_226261947(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_Item_ItemInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_Item_ItemInstance_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
