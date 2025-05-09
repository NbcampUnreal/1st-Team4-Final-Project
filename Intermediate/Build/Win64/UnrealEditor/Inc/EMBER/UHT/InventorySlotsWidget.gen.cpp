// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/UI/Inventory/InventorySlotsWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventorySlotsWidget() {}

// Begin Cross Module References
EMBER_API UClass* Z_Construct_UClass_UInventorySlotsWidget();
EMBER_API UClass* Z_Construct_UClass_UInventorySlotsWidget_NoRegister();
EMBER_API UClass* Z_Construct_UClass_UInventorySlotWidget_NoRegister();
UMG_API UClass* Z_Construct_UClass_UCanvasPanel_NoRegister();
UMG_API UClass* Z_Construct_UClass_UOverlay_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUniformGridPanel_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Class UInventorySlotsWidget
void UInventorySlotsWidget::StaticRegisterNativesUInventorySlotsWidget()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInventorySlotsWidget);
UClass* Z_Construct_UClass_UInventorySlotsWidget_NoRegister()
{
	return UInventorySlotsWidget::StaticClass();
}
struct Z_Construct_UClass_UInventorySlotsWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "UI/Inventory/InventorySlotsWidget.h" },
		{ "ModuleRelativePath", "UI/Inventory/InventorySlotsWidget.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TitleText_MetaData[] = {
		{ "Category", "InventorySlotsWidget" },
		{ "ModuleRelativePath", "UI/Inventory/InventorySlotsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotWidgets_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Inventory/InventorySlotsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_Title_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Inventory/InventorySlotsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Overlay_Slots_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Inventory/InventorySlotsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridPanel_Slots_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Inventory/InventorySlotsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CanvasPanel_Entries_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Inventory/InventorySlotsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridPanel_ValidSlots_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Inventory/InventorySlotsWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FTextPropertyParams NewProp_TitleText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SlotWidgets_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SlotWidgets;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Text_Title;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Overlay_Slots;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GridPanel_Slots;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CanvasPanel_Entries;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GridPanel_ValidSlots;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventorySlotsWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UInventorySlotsWidget_Statics::NewProp_TitleText = { "TitleText", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySlotsWidget, TitleText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TitleText_MetaData), NewProp_TitleText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventorySlotsWidget_Statics::NewProp_SlotWidgets_Inner = { "SlotWidgets", nullptr, (EPropertyFlags)0x0104000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UInventorySlotWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UInventorySlotsWidget_Statics::NewProp_SlotWidgets = { "SlotWidgets", nullptr, (EPropertyFlags)0x0144008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySlotsWidget, SlotWidgets), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotWidgets_MetaData), NewProp_SlotWidgets_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventorySlotsWidget_Statics::NewProp_Text_Title = { "Text_Title", nullptr, (EPropertyFlags)0x0144000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySlotsWidget, Text_Title), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_Title_MetaData), NewProp_Text_Title_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventorySlotsWidget_Statics::NewProp_Overlay_Slots = { "Overlay_Slots", nullptr, (EPropertyFlags)0x0144000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySlotsWidget, Overlay_Slots), Z_Construct_UClass_UOverlay_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Overlay_Slots_MetaData), NewProp_Overlay_Slots_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventorySlotsWidget_Statics::NewProp_GridPanel_Slots = { "GridPanel_Slots", nullptr, (EPropertyFlags)0x0144000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySlotsWidget, GridPanel_Slots), Z_Construct_UClass_UUniformGridPanel_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridPanel_Slots_MetaData), NewProp_GridPanel_Slots_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventorySlotsWidget_Statics::NewProp_CanvasPanel_Entries = { "CanvasPanel_Entries", nullptr, (EPropertyFlags)0x0144000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySlotsWidget, CanvasPanel_Entries), Z_Construct_UClass_UCanvasPanel_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CanvasPanel_Entries_MetaData), NewProp_CanvasPanel_Entries_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventorySlotsWidget_Statics::NewProp_GridPanel_ValidSlots = { "GridPanel_ValidSlots", nullptr, (EPropertyFlags)0x0144000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySlotsWidget, GridPanel_ValidSlots), Z_Construct_UClass_UUniformGridPanel_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridPanel_ValidSlots_MetaData), NewProp_GridPanel_ValidSlots_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInventorySlotsWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotsWidget_Statics::NewProp_TitleText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotsWidget_Statics::NewProp_SlotWidgets_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotsWidget_Statics::NewProp_SlotWidgets,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotsWidget_Statics::NewProp_Text_Title,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotsWidget_Statics::NewProp_Overlay_Slots,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotsWidget_Statics::NewProp_GridPanel_Slots,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotsWidget_Statics::NewProp_CanvasPanel_Entries,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotsWidget_Statics::NewProp_GridPanel_ValidSlots,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotsWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UInventorySlotsWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotsWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UInventorySlotsWidget_Statics::ClassParams = {
	&UInventorySlotsWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UInventorySlotsWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotsWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotsWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UInventorySlotsWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UInventorySlotsWidget()
{
	if (!Z_Registration_Info_UClass_UInventorySlotsWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInventorySlotsWidget.OuterSingleton, Z_Construct_UClass_UInventorySlotsWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UInventorySlotsWidget.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<UInventorySlotsWidget>()
{
	return UInventorySlotsWidget::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UInventorySlotsWidget);
UInventorySlotsWidget::~UInventorySlotsWidget() {}
// End Class UInventorySlotsWidget

// Begin Registration
struct Z_CompiledInDeferFile_FID_1st_Team4_Final_Project_Source_EMBER_UI_Inventory_InventorySlotsWidget_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UInventorySlotsWidget, UInventorySlotsWidget::StaticClass, TEXT("UInventorySlotsWidget"), &Z_Registration_Info_UClass_UInventorySlotsWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInventorySlotsWidget), 200785792U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_1st_Team4_Final_Project_Source_EMBER_UI_Inventory_InventorySlotsWidget_h_62879054(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_1st_Team4_Final_Project_Source_EMBER_UI_Inventory_InventorySlotsWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_1st_Team4_Final_Project_Source_EMBER_UI_Inventory_InventorySlotsWidget_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
