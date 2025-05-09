// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/UI/Data/EmberItemData.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEmberItemData() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
EMBER_API UClass* Z_Construct_UClass_UEmberItemData();
EMBER_API UClass* Z_Construct_UClass_UEmberItemData_NoRegister();
EMBER_API UClass* Z_Construct_UClass_UItemTemplate_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Class UEmberItemData
void UEmberItemData::StaticRegisterNativesUEmberItemData()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UEmberItemData);
UClass* Z_Construct_UClass_UEmberItemData_NoRegister()
{
	return UEmberItemData::StaticClass();
}
struct Z_Construct_UClass_UEmberItemData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "UI/Data/EmberItemData.h" },
		{ "ModuleRelativePath", "UI/Data/EmberItemData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemTemplateIDToClass_MetaData[] = {
		{ "Category", "EmberItemData" },
		{ "ModuleRelativePath", "UI/Data/EmberItemData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemTemplateClassToID_MetaData[] = {
		{ "ModuleRelativePath", "UI/Data/EmberItemData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WeaponItemTemplateClasses_MetaData[] = {
		{ "ModuleRelativePath", "UI/Data/EmberItemData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArmorItemTemplateClasses_MetaData[] = {
		{ "ModuleRelativePath", "UI/Data/EmberItemData.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_ItemTemplateIDToClass_ValueProp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ItemTemplateIDToClass_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ItemTemplateIDToClass;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ItemTemplateClassToID_ValueProp;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ItemTemplateClassToID_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ItemTemplateClassToID;
	static const UECodeGen_Private::FClassPropertyParams NewProp_WeaponItemTemplateClasses_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_WeaponItemTemplateClasses;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ArmorItemTemplateClasses_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ArmorItemTemplateClasses;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEmberItemData>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UEmberItemData_Statics::NewProp_ItemTemplateIDToClass_ValueProp = { "ItemTemplateIDToClass", nullptr, (EPropertyFlags)0x0004000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UClass, Z_Construct_UClass_UItemTemplate_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UEmberItemData_Statics::NewProp_ItemTemplateIDToClass_Key_KeyProp = { "ItemTemplateIDToClass_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UEmberItemData_Statics::NewProp_ItemTemplateIDToClass = { "ItemTemplateIDToClass", nullptr, (EPropertyFlags)0x0044000000010011, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEmberItemData, ItemTemplateIDToClass), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemTemplateIDToClass_MetaData), NewProp_ItemTemplateIDToClass_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UEmberItemData_Statics::NewProp_ItemTemplateClassToID_ValueProp = { "ItemTemplateClassToID", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UEmberItemData_Statics::NewProp_ItemTemplateClassToID_Key_KeyProp = { "ItemTemplateClassToID_Key", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_UItemTemplate_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UEmberItemData_Statics::NewProp_ItemTemplateClassToID = { "ItemTemplateClassToID", nullptr, (EPropertyFlags)0x0040000000000010, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEmberItemData, ItemTemplateClassToID), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemTemplateClassToID_MetaData), NewProp_ItemTemplateClassToID_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UEmberItemData_Statics::NewProp_WeaponItemTemplateClasses_Inner = { "WeaponItemTemplateClasses", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_UItemTemplate_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UEmberItemData_Statics::NewProp_WeaponItemTemplateClasses = { "WeaponItemTemplateClasses", nullptr, (EPropertyFlags)0x0044000000000010, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEmberItemData, WeaponItemTemplateClasses), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WeaponItemTemplateClasses_MetaData), NewProp_WeaponItemTemplateClasses_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UEmberItemData_Statics::NewProp_ArmorItemTemplateClasses_Inner = { "ArmorItemTemplateClasses", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_UItemTemplate_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UEmberItemData_Statics::NewProp_ArmorItemTemplateClasses = { "ArmorItemTemplateClasses", nullptr, (EPropertyFlags)0x0044000000000010, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEmberItemData, ArmorItemTemplateClasses), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArmorItemTemplateClasses_MetaData), NewProp_ArmorItemTemplateClasses_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEmberItemData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEmberItemData_Statics::NewProp_ItemTemplateIDToClass_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEmberItemData_Statics::NewProp_ItemTemplateIDToClass_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEmberItemData_Statics::NewProp_ItemTemplateIDToClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEmberItemData_Statics::NewProp_ItemTemplateClassToID_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEmberItemData_Statics::NewProp_ItemTemplateClassToID_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEmberItemData_Statics::NewProp_ItemTemplateClassToID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEmberItemData_Statics::NewProp_WeaponItemTemplateClasses_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEmberItemData_Statics::NewProp_WeaponItemTemplateClasses,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEmberItemData_Statics::NewProp_ArmorItemTemplateClasses_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEmberItemData_Statics::NewProp_ArmorItemTemplateClasses,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEmberItemData_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEmberItemData_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEmberItemData_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEmberItemData_Statics::ClassParams = {
	&UEmberItemData::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UEmberItemData_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UEmberItemData_Statics::PropPointers),
	0,
	0x001100A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEmberItemData_Statics::Class_MetaDataParams), Z_Construct_UClass_UEmberItemData_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEmberItemData()
{
	if (!Z_Registration_Info_UClass_UEmberItemData.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEmberItemData.OuterSingleton, Z_Construct_UClass_UEmberItemData_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEmberItemData.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<UEmberItemData>()
{
	return UEmberItemData::StaticClass();
}
UEmberItemData::UEmberItemData(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEmberItemData);
UEmberItemData::~UEmberItemData() {}
// End Class UEmberItemData

// Begin Registration
struct Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_UI_Data_EmberItemData_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEmberItemData, UEmberItemData::StaticClass, TEXT("UEmberItemData"), &Z_Registration_Info_UClass_UEmberItemData, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEmberItemData), 2150216810U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_UI_Data_EmberItemData_h_52786879(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_UI_Data_EmberItemData_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_UI_Data_EmberItemData_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
