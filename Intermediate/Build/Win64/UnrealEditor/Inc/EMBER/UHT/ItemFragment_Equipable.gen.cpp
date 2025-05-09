// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/Item/Fragments/ItemFragment_Equipable.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeItemFragment_Equipable() {}

// Begin Cross Module References
EMBER_API UClass* Z_Construct_UClass_UItemFragment();
EMBER_API UClass* Z_Construct_UClass_UItemFragment_Equipable();
EMBER_API UClass* Z_Construct_UClass_UItemFragment_Equipable_NoRegister();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Class UItemFragment_Equipable
void UItemFragment_Equipable::StaticRegisterNativesUItemFragment_Equipable()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UItemFragment_Equipable);
UClass* Z_Construct_UClass_UItemFragment_Equipable_NoRegister()
{
	return UItemFragment_Equipable::StaticClass();
}
struct Z_Construct_UClass_UItemFragment_Equipable_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Item/Fragments/ItemFragment_Equipable.h" },
		{ "ModuleRelativePath", "Item/Fragments/ItemFragment_Equipable.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UItemFragment_Equipable>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UItemFragment_Equipable_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UItemFragment,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UItemFragment_Equipable_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UItemFragment_Equipable_Statics::ClassParams = {
	&UItemFragment_Equipable::StaticClass,
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
	0x003110A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UItemFragment_Equipable_Statics::Class_MetaDataParams), Z_Construct_UClass_UItemFragment_Equipable_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UItemFragment_Equipable()
{
	if (!Z_Registration_Info_UClass_UItemFragment_Equipable.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UItemFragment_Equipable.OuterSingleton, Z_Construct_UClass_UItemFragment_Equipable_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UItemFragment_Equipable.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<UItemFragment_Equipable>()
{
	return UItemFragment_Equipable::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UItemFragment_Equipable);
UItemFragment_Equipable::~UItemFragment_Equipable() {}
// End Class UItemFragment_Equipable

// Begin Registration
struct Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Item_Fragments_ItemFragment_Equipable_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UItemFragment_Equipable, UItemFragment_Equipable::StaticClass, TEXT("UItemFragment_Equipable"), &Z_Registration_Info_UClass_UItemFragment_Equipable, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UItemFragment_Equipable), 2459729731U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Item_Fragments_ItemFragment_Equipable_h_3436051864(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Item_Fragments_ItemFragment_Equipable_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Item_Fragments_ItemFragment_Equipable_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
