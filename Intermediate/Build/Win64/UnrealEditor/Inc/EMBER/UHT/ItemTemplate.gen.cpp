// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/Item/ItemTemplate.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeItemTemplate() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
EMBER_API UClass* Z_Construct_UClass_UItemFragment();
EMBER_API UClass* Z_Construct_UClass_UItemFragment_NoRegister();
EMBER_API UClass* Z_Construct_UClass_UItemTemplate();
EMBER_API UClass* Z_Construct_UClass_UItemTemplate_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Class UItemFragment
void UItemFragment::StaticRegisterNativesUItemFragment()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UItemFragment);
UClass* Z_Construct_UClass_UItemFragment_NoRegister()
{
	return UItemFragment::StaticClass();
}
struct Z_Construct_UClass_UItemFragment_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Item/ItemTemplate.h" },
		{ "ModuleRelativePath", "Item/ItemTemplate.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UItemFragment>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UItemFragment_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UItemFragment_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UItemFragment_Statics::ClassParams = {
	&UItemFragment::StaticClass,
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
	0x002010A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UItemFragment_Statics::Class_MetaDataParams), Z_Construct_UClass_UItemFragment_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UItemFragment()
{
	if (!Z_Registration_Info_UClass_UItemFragment.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UItemFragment.OuterSingleton, Z_Construct_UClass_UItemFragment_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UItemFragment.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<UItemFragment>()
{
	return UItemFragment::StaticClass();
}
UItemFragment::UItemFragment(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UItemFragment);
UItemFragment::~UItemFragment() {}
// End Class UItemFragment

// Begin Class UItemTemplate Function FindFragmentByClass
struct Z_Construct_UFunction_UItemTemplate_FindFragmentByClass_Statics
{
	struct ItemTemplate_eventFindFragmentByClass_Parms
	{
		TSubclassOf<UItemFragment> FragmentClass;
		const UItemFragment* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Item/ItemTemplate.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_FragmentClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UItemTemplate_FindFragmentByClass_Statics::NewProp_FragmentClass = { "FragmentClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ItemTemplate_eventFindFragmentByClass_Parms, FragmentClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UItemFragment_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UItemTemplate_FindFragmentByClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x001000000008058a, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ItemTemplate_eventFindFragmentByClass_Parms, ReturnValue), Z_Construct_UClass_UItemFragment_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UItemTemplate_FindFragmentByClass_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UItemTemplate_FindFragmentByClass_Statics::NewProp_FragmentClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UItemTemplate_FindFragmentByClass_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UItemTemplate_FindFragmentByClass_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UItemTemplate_FindFragmentByClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UItemTemplate, nullptr, "FindFragmentByClass", nullptr, nullptr, Z_Construct_UFunction_UItemTemplate_FindFragmentByClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UItemTemplate_FindFragmentByClass_Statics::PropPointers), sizeof(Z_Construct_UFunction_UItemTemplate_FindFragmentByClass_Statics::ItemTemplate_eventFindFragmentByClass_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UItemTemplate_FindFragmentByClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UItemTemplate_FindFragmentByClass_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UItemTemplate_FindFragmentByClass_Statics::ItemTemplate_eventFindFragmentByClass_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UItemTemplate_FindFragmentByClass()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UItemTemplate_FindFragmentByClass_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UItemTemplate::execFindFragmentByClass)
{
	P_GET_OBJECT(UClass,Z_Param_FragmentClass);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(const UItemFragment**)Z_Param__Result=P_THIS->FindFragmentByClass(Z_Param_FragmentClass);
	P_NATIVE_END;
}
// End Class UItemTemplate Function FindFragmentByClass

// Begin Class UItemTemplate
void UItemTemplate::StaticRegisterNativesUItemTemplate()
{
	UClass* Class = UItemTemplate::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "FindFragmentByClass", &UItemTemplate::execFindFragmentByClass },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UItemTemplate);
UClass* Z_Construct_UClass_UItemTemplate_NoRegister()
{
	return UItemTemplate::StaticClass();
}
struct Z_Construct_UClass_UItemTemplate_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Item/ItemTemplate.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Item/ItemTemplate.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotCount_MetaData[] = {
		{ "Category", "ItemTemplate" },
		{ "ModuleRelativePath", "Item/ItemTemplate.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxStackCount_MetaData[] = {
		{ "Category", "ItemTemplate" },
		{ "ModuleRelativePath", "Item/ItemTemplate.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayName_MetaData[] = {
		{ "Category", "ItemTemplate" },
		{ "ModuleRelativePath", "Item/ItemTemplate.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "Category", "ItemTemplate" },
		{ "ModuleRelativePath", "Item/ItemTemplate.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IconTexture_MetaData[] = {
		{ "Category", "ItemTemplate" },
		{ "ModuleRelativePath", "Item/ItemTemplate.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PickupableMesh_MetaData[] = {
		{ "Category", "ItemTemplate" },
		{ "ModuleRelativePath", "Item/ItemTemplate.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Fragments_Inner_MetaData[] = {
		{ "Category", "ItemTemplate" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Item/ItemTemplate.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Fragments_MetaData[] = {
		{ "Category", "ItemTemplate" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Item/ItemTemplate.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_SlotCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxStackCount;
	static const UECodeGen_Private::FTextPropertyParams NewProp_DisplayName;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Description;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IconTexture;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_PickupableMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Fragments_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Fragments;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UItemTemplate_FindFragmentByClass, "FindFragmentByClass" }, // 158388870
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UItemTemplate>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UItemTemplate_Statics::NewProp_SlotCount = { "SlotCount", nullptr, (EPropertyFlags)0x0010000000010011, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemTemplate, SlotCount), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotCount_MetaData), NewProp_SlotCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UItemTemplate_Statics::NewProp_MaxStackCount = { "MaxStackCount", nullptr, (EPropertyFlags)0x0010000000010011, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemTemplate, MaxStackCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxStackCount_MetaData), NewProp_MaxStackCount_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UItemTemplate_Statics::NewProp_DisplayName = { "DisplayName", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemTemplate, DisplayName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayName_MetaData), NewProp_DisplayName_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UItemTemplate_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemTemplate, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UItemTemplate_Statics::NewProp_IconTexture = { "IconTexture", nullptr, (EPropertyFlags)0x0114000000010015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemTemplate, IconTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IconTexture_MetaData), NewProp_IconTexture_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UItemTemplate_Statics::NewProp_PickupableMesh = { "PickupableMesh", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemTemplate, PickupableMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PickupableMesh_MetaData), NewProp_PickupableMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UItemTemplate_Statics::NewProp_Fragments_Inner = { "Fragments", nullptr, (EPropertyFlags)0x0106000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UItemFragment_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Fragments_Inner_MetaData), NewProp_Fragments_Inner_MetaData) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UItemTemplate_Statics::NewProp_Fragments = { "Fragments", nullptr, (EPropertyFlags)0x011400800001001d, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemTemplate, Fragments), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Fragments_MetaData), NewProp_Fragments_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UItemTemplate_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemTemplate_Statics::NewProp_SlotCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemTemplate_Statics::NewProp_MaxStackCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemTemplate_Statics::NewProp_DisplayName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemTemplate_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemTemplate_Statics::NewProp_IconTexture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemTemplate_Statics::NewProp_PickupableMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemTemplate_Statics::NewProp_Fragments_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemTemplate_Statics::NewProp_Fragments,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UItemTemplate_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UItemTemplate_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UItemTemplate_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UItemTemplate_Statics::ClassParams = {
	&UItemTemplate::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UItemTemplate_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UItemTemplate_Statics::PropPointers),
	0,
	0x009100A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UItemTemplate_Statics::Class_MetaDataParams), Z_Construct_UClass_UItemTemplate_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UItemTemplate()
{
	if (!Z_Registration_Info_UClass_UItemTemplate.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UItemTemplate.OuterSingleton, Z_Construct_UClass_UItemTemplate_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UItemTemplate.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<UItemTemplate>()
{
	return UItemTemplate::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UItemTemplate);
UItemTemplate::~UItemTemplate() {}
// End Class UItemTemplate

// Begin Registration
struct Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_Item_ItemTemplate_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UItemFragment, UItemFragment::StaticClass, TEXT("UItemFragment"), &Z_Registration_Info_UClass_UItemFragment, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UItemFragment), 330995473U) },
		{ Z_Construct_UClass_UItemTemplate, UItemTemplate::StaticClass, TEXT("UItemTemplate"), &Z_Registration_Info_UClass_UItemTemplate, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UItemTemplate), 3832267027U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_Item_ItemTemplate_h_1515196496(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_Item_ItemTemplate_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_Item_ItemTemplate_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
