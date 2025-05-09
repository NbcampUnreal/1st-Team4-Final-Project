// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/Item/Fragments/ItemFragment_Equipable_Utility.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeItemFragment_Equipable_Utility() {}

// Begin Cross Module References
EMBER_API UClass* Z_Construct_UClass_UItemFragment_Equipable_Attachment();
EMBER_API UClass* Z_Construct_UClass_UItemFragment_Equipable_Utility();
EMBER_API UClass* Z_Construct_UClass_UItemFragment_Equipable_Utility_NoRegister();
EMBER_API UEnum* Z_Construct_UEnum_EMBER_EUtilityType();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Class UItemFragment_Equipable_Utility
void UItemFragment_Equipable_Utility::StaticRegisterNativesUItemFragment_Equipable_Utility()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UItemFragment_Equipable_Utility);
UClass* Z_Construct_UClass_UItemFragment_Equipable_Utility_NoRegister()
{
	return UItemFragment_Equipable_Utility::StaticClass();
}
struct Z_Construct_UClass_UItemFragment_Equipable_Utility_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Item/Fragments/ItemFragment_Equipable_Utility.h" },
		{ "ModuleRelativePath", "Item/Fragments/ItemFragment_Equipable_Utility.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UtilityType_MetaData[] = {
		{ "Category", "ItemFragment_Equipable_Utility" },
		{ "ModuleRelativePath", "Item/Fragments/ItemFragment_Equipable_Utility.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_UtilityType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_UtilityType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UItemFragment_Equipable_Utility>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UItemFragment_Equipable_Utility_Statics::NewProp_UtilityType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UItemFragment_Equipable_Utility_Statics::NewProp_UtilityType = { "UtilityType", nullptr, (EPropertyFlags)0x0010000000010011, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemFragment_Equipable_Utility, UtilityType), Z_Construct_UEnum_EMBER_EUtilityType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UtilityType_MetaData), NewProp_UtilityType_MetaData) }; // 1790384880
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UItemFragment_Equipable_Utility_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemFragment_Equipable_Utility_Statics::NewProp_UtilityType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemFragment_Equipable_Utility_Statics::NewProp_UtilityType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UItemFragment_Equipable_Utility_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UItemFragment_Equipable_Utility_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UItemFragment_Equipable_Attachment,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UItemFragment_Equipable_Utility_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UItemFragment_Equipable_Utility_Statics::ClassParams = {
	&UItemFragment_Equipable_Utility::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UItemFragment_Equipable_Utility_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UItemFragment_Equipable_Utility_Statics::PropPointers),
	0,
	0x003110A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UItemFragment_Equipable_Utility_Statics::Class_MetaDataParams), Z_Construct_UClass_UItemFragment_Equipable_Utility_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UItemFragment_Equipable_Utility()
{
	if (!Z_Registration_Info_UClass_UItemFragment_Equipable_Utility.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UItemFragment_Equipable_Utility.OuterSingleton, Z_Construct_UClass_UItemFragment_Equipable_Utility_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UItemFragment_Equipable_Utility.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<UItemFragment_Equipable_Utility>()
{
	return UItemFragment_Equipable_Utility::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UItemFragment_Equipable_Utility);
UItemFragment_Equipable_Utility::~UItemFragment_Equipable_Utility() {}
// End Class UItemFragment_Equipable_Utility

// Begin Registration
struct Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_Item_Fragments_ItemFragment_Equipable_Utility_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UItemFragment_Equipable_Utility, UItemFragment_Equipable_Utility::StaticClass, TEXT("UItemFragment_Equipable_Utility"), &Z_Registration_Info_UClass_UItemFragment_Equipable_Utility, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UItemFragment_Equipable_Utility), 3682745240U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_Item_Fragments_ItemFragment_Equipable_Utility_h_2603909326(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_Item_Fragments_ItemFragment_Equipable_Utility_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_Item_Fragments_ItemFragment_Equipable_Utility_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
