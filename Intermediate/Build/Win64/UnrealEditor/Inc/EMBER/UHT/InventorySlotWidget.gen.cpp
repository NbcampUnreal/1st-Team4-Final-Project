// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/UI/Inventory/InventorySlotWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventorySlotWidget() {}

// Begin Cross Module References
EMBER_API UClass* Z_Construct_UClass_UInventorySlotWidget();
EMBER_API UClass* Z_Construct_UClass_UInventorySlotWidget_NoRegister();
UMG_API UClass* Z_Construct_UClass_USizeBox_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Class UInventorySlotWidget
void UInventorySlotWidget::StaticRegisterNativesUInventorySlotWidget()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInventorySlotWidget);
UClass* Z_Construct_UClass_UInventorySlotWidget_NoRegister()
{
	return UInventorySlotWidget::StaticClass();
}
struct Z_Construct_UClass_UInventorySlotWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "UI/Inventory/InventorySlotWidget.h" },
		{ "ModuleRelativePath", "UI/Inventory/InventorySlotWidget.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SizeBox_Root_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Inventory/InventorySlotWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SizeBox_Root;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventorySlotWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_SizeBox_Root = { "SizeBox_Root", nullptr, (EPropertyFlags)0x0114000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySlotWidget, SizeBox_Root), Z_Construct_UClass_USizeBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SizeBox_Root_MetaData), NewProp_SizeBox_Root_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInventorySlotWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_SizeBox_Root,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UInventorySlotWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UInventorySlotWidget_Statics::ClassParams = {
	&UInventorySlotWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UInventorySlotWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UInventorySlotWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UInventorySlotWidget()
{
	if (!Z_Registration_Info_UClass_UInventorySlotWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInventorySlotWidget.OuterSingleton, Z_Construct_UClass_UInventorySlotWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UInventorySlotWidget.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<UInventorySlotWidget>()
{
	return UInventorySlotWidget::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UInventorySlotWidget);
UInventorySlotWidget::~UInventorySlotWidget() {}
// End Class UInventorySlotWidget

// Begin Registration
struct Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_UI_Inventory_InventorySlotWidget_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UInventorySlotWidget, UInventorySlotWidget::StaticClass, TEXT("UInventorySlotWidget"), &Z_Registration_Info_UClass_UInventorySlotWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInventorySlotWidget), 111471195U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_UI_Inventory_InventorySlotWidget_h_1455385953(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_UI_Inventory_InventorySlotWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_UI_Inventory_InventorySlotWidget_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
