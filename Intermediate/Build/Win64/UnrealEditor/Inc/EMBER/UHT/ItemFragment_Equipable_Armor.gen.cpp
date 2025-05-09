// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/Item/Fragments/ItemFragment_Equipable_Armor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeItemFragment_Equipable_Armor() {}

// Begin Cross Module References
EMBER_API UClass* Z_Construct_UClass_UItemFragment_Equipable();
EMBER_API UClass* Z_Construct_UClass_UItemFragment_Equipable_Armor();
EMBER_API UClass* Z_Construct_UClass_UItemFragment_Equipable_Armor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USkeletalMesh_NoRegister();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Class UItemFragment_Equipable_Armor
void UItemFragment_Equipable_Armor::StaticRegisterNativesUItemFragment_Equipable_Armor()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UItemFragment_Equipable_Armor);
UClass* Z_Construct_UClass_UItemFragment_Equipable_Armor_NoRegister()
{
	return UItemFragment_Equipable_Armor::StaticClass();
}
struct Z_Construct_UClass_UItemFragment_Equipable_Armor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Item/Fragments/ItemFragment_Equipable_Armor.h" },
		{ "ModuleRelativePath", "Item/Fragments/ItemFragment_Equipable_Armor.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArmorMesh_MetaData[] = {
		{ "Category", "ItemFragment_Equipable_Armor" },
		{ "ModuleRelativePath", "Item/Fragments/ItemFragment_Equipable_Armor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_ArmorMesh;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UItemFragment_Equipable_Armor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UItemFragment_Equipable_Armor_Statics::NewProp_ArmorMesh = { "ArmorMesh", nullptr, (EPropertyFlags)0x0014000000010011, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemFragment_Equipable_Armor, ArmorMesh), Z_Construct_UClass_USkeletalMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArmorMesh_MetaData), NewProp_ArmorMesh_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UItemFragment_Equipable_Armor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemFragment_Equipable_Armor_Statics::NewProp_ArmorMesh,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UItemFragment_Equipable_Armor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UItemFragment_Equipable_Armor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UItemFragment_Equipable,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UItemFragment_Equipable_Armor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UItemFragment_Equipable_Armor_Statics::ClassParams = {
	&UItemFragment_Equipable_Armor::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UItemFragment_Equipable_Armor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UItemFragment_Equipable_Armor_Statics::PropPointers),
	0,
	0x003110A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UItemFragment_Equipable_Armor_Statics::Class_MetaDataParams), Z_Construct_UClass_UItemFragment_Equipable_Armor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UItemFragment_Equipable_Armor()
{
	if (!Z_Registration_Info_UClass_UItemFragment_Equipable_Armor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UItemFragment_Equipable_Armor.OuterSingleton, Z_Construct_UClass_UItemFragment_Equipable_Armor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UItemFragment_Equipable_Armor.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<UItemFragment_Equipable_Armor>()
{
	return UItemFragment_Equipable_Armor::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UItemFragment_Equipable_Armor);
UItemFragment_Equipable_Armor::~UItemFragment_Equipable_Armor() {}
// End Class UItemFragment_Equipable_Armor

// Begin Registration
struct Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Item_Fragments_ItemFragment_Equipable_Armor_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UItemFragment_Equipable_Armor, UItemFragment_Equipable_Armor::StaticClass, TEXT("UItemFragment_Equipable_Armor"), &Z_Registration_Info_UClass_UItemFragment_Equipable_Armor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UItemFragment_Equipable_Armor), 39727948U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Item_Fragments_ItemFragment_Equipable_Armor_h_90010239(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Item_Fragments_ItemFragment_Equipable_Armor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Item_Fragments_ItemFragment_Equipable_Armor_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
