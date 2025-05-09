// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/UI/Data/EmberUIData.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEmberUIData() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
EMBER_API UClass* Z_Construct_UClass_UEmberUIData();
EMBER_API UClass* Z_Construct_UClass_UEmberUIData_NoRegister();
EMBER_API UClass* Z_Construct_UClass_UInventorySlotWidget_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Class UEmberUIData
void UEmberUIData::StaticRegisterNativesUEmberUIData()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UEmberUIData);
UClass* Z_Construct_UClass_UEmberUIData_NoRegister()
{
	return UEmberUIData::StaticClass();
}
struct Z_Construct_UClass_UEmberUIData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "UI/Data/EmberUIData.h" },
		{ "ModuleRelativePath", "UI/Data/EmberUIData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InventorySlotWidgetClass_MetaData[] = {
		{ "Category", "EmberUIData" },
		{ "ModuleRelativePath", "UI/Data/EmberUIData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnitInventorySlotSize_MetaData[] = {
		{ "Category", "EmberUIData" },
		{ "ModuleRelativePath", "UI/Data/EmberUIData.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_InventorySlotWidgetClass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_UnitInventorySlotSize;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEmberUIData>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UEmberUIData_Statics::NewProp_InventorySlotWidgetClass = { "InventorySlotWidgetClass", nullptr, (EPropertyFlags)0x0014000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEmberUIData, InventorySlotWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UInventorySlotWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InventorySlotWidgetClass_MetaData), NewProp_InventorySlotWidgetClass_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEmberUIData_Statics::NewProp_UnitInventorySlotSize = { "UnitInventorySlotSize", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEmberUIData, UnitInventorySlotSize), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnitInventorySlotSize_MetaData), NewProp_UnitInventorySlotSize_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEmberUIData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEmberUIData_Statics::NewProp_InventorySlotWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEmberUIData_Statics::NewProp_UnitInventorySlotSize,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEmberUIData_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEmberUIData_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEmberUIData_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEmberUIData_Statics::ClassParams = {
	&UEmberUIData::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UEmberUIData_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UEmberUIData_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEmberUIData_Statics::Class_MetaDataParams), Z_Construct_UClass_UEmberUIData_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEmberUIData()
{
	if (!Z_Registration_Info_UClass_UEmberUIData.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEmberUIData.OuterSingleton, Z_Construct_UClass_UEmberUIData_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEmberUIData.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<UEmberUIData>()
{
	return UEmberUIData::StaticClass();
}
UEmberUIData::UEmberUIData(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEmberUIData);
UEmberUIData::~UEmberUIData() {}
// End Class UEmberUIData

// Begin Registration
struct Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_UI_Data_EmberUIData_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEmberUIData, UEmberUIData::StaticClass, TEXT("UEmberUIData"), &Z_Registration_Info_UClass_UEmberUIData, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEmberUIData), 3860736241U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_UI_Data_EmberUIData_h_2213205974(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_UI_Data_EmberUIData_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_UI_Data_EmberUIData_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
