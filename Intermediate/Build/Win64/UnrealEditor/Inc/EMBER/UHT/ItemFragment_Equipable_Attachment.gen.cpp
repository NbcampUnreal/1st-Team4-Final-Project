// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/Item/Fragments/ItemFragment_Equipable_Attachment.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeItemFragment_Equipable_Attachment() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
EMBER_API UClass* Z_Construct_UClass_AEquipmentBase_NoRegister();
EMBER_API UClass* Z_Construct_UClass_UItemFragment_Equipable();
EMBER_API UClass* Z_Construct_UClass_UItemFragment_Equipable_Attachment();
EMBER_API UClass* Z_Construct_UClass_UItemFragment_Equipable_Attachment_NoRegister();
EMBER_API UEnum* Z_Construct_UEnum_EMBER_EItemHandType();
EMBER_API UScriptStruct* Z_Construct_UScriptStruct_FItemAttachInfo();
ENGINE_API UClass* Z_Construct_UClass_UAnimInstance_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin ScriptStruct FItemAttachInfo
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ItemAttachInfo;
class UScriptStruct* FItemAttachInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ItemAttachInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ItemAttachInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FItemAttachInfo, (UObject*)Z_Construct_UPackage__Script_EMBER(), TEXT("ItemAttachInfo"));
	}
	return Z_Registration_Info_UScriptStruct_ItemAttachInfo.OuterSingleton;
}
template<> EMBER_API UScriptStruct* StaticStruct<FItemAttachInfo>()
{
	return FItemAttachInfo::StaticStruct();
}
struct Z_Construct_UScriptStruct_FItemAttachInfo_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Item/Fragments/ItemFragment_Equipable_Attachment.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnEquipmentClass_MetaData[] = {
		{ "Category", "ItemAttachInfo" },
		{ "ModuleRelativePath", "Item/Fragments/ItemFragment_Equipable_Attachment.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttachSocket_MetaData[] = {
		{ "Category", "ItemAttachInfo" },
		{ "ModuleRelativePath", "Item/Fragments/ItemFragment_Equipable_Attachment.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttachTransform_MetaData[] = {
		{ "Category", "ItemAttachInfo" },
		{ "ModuleRelativePath", "Item/Fragments/ItemFragment_Equipable_Attachment.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_SpawnEquipmentClass;
	static const UECodeGen_Private::FNamePropertyParams NewProp_AttachSocket;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AttachTransform;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FItemAttachInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FItemAttachInfo_Statics::NewProp_SpawnEquipmentClass = { "SpawnEquipmentClass", nullptr, (EPropertyFlags)0x0014000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FItemAttachInfo, SpawnEquipmentClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AEquipmentBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnEquipmentClass_MetaData), NewProp_SpawnEquipmentClass_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FItemAttachInfo_Statics::NewProp_AttachSocket = { "AttachSocket", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FItemAttachInfo, AttachSocket), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttachSocket_MetaData), NewProp_AttachSocket_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FItemAttachInfo_Statics::NewProp_AttachTransform = { "AttachTransform", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FItemAttachInfo, AttachTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttachTransform_MetaData), NewProp_AttachTransform_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FItemAttachInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemAttachInfo_Statics::NewProp_SpawnEquipmentClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemAttachInfo_Statics::NewProp_AttachSocket,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemAttachInfo_Statics::NewProp_AttachTransform,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemAttachInfo_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FItemAttachInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
	nullptr,
	&NewStructOps,
	"ItemAttachInfo",
	Z_Construct_UScriptStruct_FItemAttachInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemAttachInfo_Statics::PropPointers),
	sizeof(FItemAttachInfo),
	alignof(FItemAttachInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemAttachInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FItemAttachInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FItemAttachInfo()
{
	if (!Z_Registration_Info_UScriptStruct_ItemAttachInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ItemAttachInfo.InnerSingleton, Z_Construct_UScriptStruct_FItemAttachInfo_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_ItemAttachInfo.InnerSingleton;
}
// End ScriptStruct FItemAttachInfo

// Begin Class UItemFragment_Equipable_Attachment
void UItemFragment_Equipable_Attachment::StaticRegisterNativesUItemFragment_Equipable_Attachment()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UItemFragment_Equipable_Attachment);
UClass* Z_Construct_UClass_UItemFragment_Equipable_Attachment_NoRegister()
{
	return UItemFragment_Equipable_Attachment::StaticClass();
}
struct Z_Construct_UClass_UItemFragment_Equipable_Attachment_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Item/Fragments/ItemFragment_Equipable_Attachment.h" },
		{ "ModuleRelativePath", "Item/Fragments/ItemFragment_Equipable_Attachment.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemHandType_MetaData[] = {
		{ "Category", "ItemFragment_Equipable_Attachment" },
		{ "ModuleRelativePath", "Item/Fragments/ItemFragment_Equipable_Attachment.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemAttachInfo_MetaData[] = {
		{ "Category", "ItemFragment_Equipable_Attachment" },
		{ "ModuleRelativePath", "Item/Fragments/ItemFragment_Equipable_Attachment.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnimInstanceClass_MetaData[] = {
		{ "Category", "ItemFragment_Equipable_Attachment" },
		{ "ModuleRelativePath", "Item/Fragments/ItemFragment_Equipable_Attachment.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EquipMontage_MetaData[] = {
		{ "Category", "ItemFragment_Equipable_Attachment" },
		{ "ModuleRelativePath", "Item/Fragments/ItemFragment_Equipable_Attachment.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ItemHandType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ItemHandType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ItemAttachInfo;
	static const UECodeGen_Private::FClassPropertyParams NewProp_AnimInstanceClass;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_EquipMontage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UItemFragment_Equipable_Attachment>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UItemFragment_Equipable_Attachment_Statics::NewProp_ItemHandType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UItemFragment_Equipable_Attachment_Statics::NewProp_ItemHandType = { "ItemHandType", nullptr, (EPropertyFlags)0x0010000000010011, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemFragment_Equipable_Attachment, ItemHandType), Z_Construct_UEnum_EMBER_EItemHandType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemHandType_MetaData), NewProp_ItemHandType_MetaData) }; // 3043355517
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UItemFragment_Equipable_Attachment_Statics::NewProp_ItemAttachInfo = { "ItemAttachInfo", nullptr, (EPropertyFlags)0x0010000000010011, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemFragment_Equipable_Attachment, ItemAttachInfo), Z_Construct_UScriptStruct_FItemAttachInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemAttachInfo_MetaData), NewProp_ItemAttachInfo_MetaData) }; // 276048289
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UItemFragment_Equipable_Attachment_Statics::NewProp_AnimInstanceClass = { "AnimInstanceClass", nullptr, (EPropertyFlags)0x0014000000010011, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemFragment_Equipable_Attachment, AnimInstanceClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UAnimInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnimInstanceClass_MetaData), NewProp_AnimInstanceClass_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UItemFragment_Equipable_Attachment_Statics::NewProp_EquipMontage = { "EquipMontage", nullptr, (EPropertyFlags)0x0014000000010011, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemFragment_Equipable_Attachment, EquipMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EquipMontage_MetaData), NewProp_EquipMontage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UItemFragment_Equipable_Attachment_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemFragment_Equipable_Attachment_Statics::NewProp_ItemHandType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemFragment_Equipable_Attachment_Statics::NewProp_ItemHandType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemFragment_Equipable_Attachment_Statics::NewProp_ItemAttachInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemFragment_Equipable_Attachment_Statics::NewProp_AnimInstanceClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemFragment_Equipable_Attachment_Statics::NewProp_EquipMontage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UItemFragment_Equipable_Attachment_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UItemFragment_Equipable_Attachment_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UItemFragment_Equipable,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UItemFragment_Equipable_Attachment_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UItemFragment_Equipable_Attachment_Statics::ClassParams = {
	&UItemFragment_Equipable_Attachment::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UItemFragment_Equipable_Attachment_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UItemFragment_Equipable_Attachment_Statics::PropPointers),
	0,
	0x003110A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UItemFragment_Equipable_Attachment_Statics::Class_MetaDataParams), Z_Construct_UClass_UItemFragment_Equipable_Attachment_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UItemFragment_Equipable_Attachment()
{
	if (!Z_Registration_Info_UClass_UItemFragment_Equipable_Attachment.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UItemFragment_Equipable_Attachment.OuterSingleton, Z_Construct_UClass_UItemFragment_Equipable_Attachment_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UItemFragment_Equipable_Attachment.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<UItemFragment_Equipable_Attachment>()
{
	return UItemFragment_Equipable_Attachment::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UItemFragment_Equipable_Attachment);
UItemFragment_Equipable_Attachment::~UItemFragment_Equipable_Attachment() {}
// End Class UItemFragment_Equipable_Attachment

// Begin Registration
struct Z_CompiledInDeferFile_FID_1st_Team4_Final_Project_Source_EMBER_Item_Fragments_ItemFragment_Equipable_Attachment_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FItemAttachInfo::StaticStruct, Z_Construct_UScriptStruct_FItemAttachInfo_Statics::NewStructOps, TEXT("ItemAttachInfo"), &Z_Registration_Info_UScriptStruct_ItemAttachInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FItemAttachInfo), 276048289U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UItemFragment_Equipable_Attachment, UItemFragment_Equipable_Attachment::StaticClass, TEXT("UItemFragment_Equipable_Attachment"), &Z_Registration_Info_UClass_UItemFragment_Equipable_Attachment, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UItemFragment_Equipable_Attachment), 4109011591U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_1st_Team4_Final_Project_Source_EMBER_Item_Fragments_ItemFragment_Equipable_Attachment_h_421614446(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_1st_Team4_Final_Project_Source_EMBER_Item_Fragments_ItemFragment_Equipable_Attachment_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_1st_Team4_Final_Project_Source_EMBER_Item_Fragments_ItemFragment_Equipable_Attachment_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_1st_Team4_Final_Project_Source_EMBER_Item_Fragments_ItemFragment_Equipable_Attachment_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_1st_Team4_Final_Project_Source_EMBER_Item_Fragments_ItemFragment_Equipable_Attachment_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
