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
EMBER_API UEnum* Z_Construct_UEnum_EMBER_EItemRarity();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Class UItemInstance Function GetItemRarity
struct Z_Construct_UFunction_UItemInstance_GetItemRarity_Statics
{
	struct ItemInstance_eventGetItemRarity_Parms
	{
		EItemRarity ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Item/ItemInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UItemInstance_GetItemRarity_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UItemInstance_GetItemRarity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ItemInstance_eventGetItemRarity_Parms, ReturnValue), Z_Construct_UEnum_EMBER_EItemRarity, METADATA_PARAMS(0, nullptr) }; // 731058631
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UItemInstance_GetItemRarity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UItemInstance_GetItemRarity_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UItemInstance_GetItemRarity_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UItemInstance_GetItemRarity_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UItemInstance_GetItemRarity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UItemInstance, nullptr, "GetItemRarity", nullptr, nullptr, Z_Construct_UFunction_UItemInstance_GetItemRarity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UItemInstance_GetItemRarity_Statics::PropPointers), sizeof(Z_Construct_UFunction_UItemInstance_GetItemRarity_Statics::ItemInstance_eventGetItemRarity_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UItemInstance_GetItemRarity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UItemInstance_GetItemRarity_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UItemInstance_GetItemRarity_Statics::ItemInstance_eventGetItemRarity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UItemInstance_GetItemRarity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UItemInstance_GetItemRarity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UItemInstance::execGetItemRarity)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EItemRarity*)Z_Param__Result=P_THIS->GetItemRarity();
	P_NATIVE_END;
}
// End Class UItemInstance Function GetItemRarity

// Begin Class UItemInstance Function GetItemTemplateID
struct Z_Construct_UFunction_UItemInstance_GetItemTemplateID_Statics
{
	struct ItemInstance_eventGetItemTemplateID_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Item/ItemInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UItemInstance_GetItemTemplateID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ItemInstance_eventGetItemTemplateID_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UItemInstance_GetItemTemplateID_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UItemInstance_GetItemTemplateID_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UItemInstance_GetItemTemplateID_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UItemInstance_GetItemTemplateID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UItemInstance, nullptr, "GetItemTemplateID", nullptr, nullptr, Z_Construct_UFunction_UItemInstance_GetItemTemplateID_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UItemInstance_GetItemTemplateID_Statics::PropPointers), sizeof(Z_Construct_UFunction_UItemInstance_GetItemTemplateID_Statics::ItemInstance_eventGetItemTemplateID_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UItemInstance_GetItemTemplateID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UItemInstance_GetItemTemplateID_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UItemInstance_GetItemTemplateID_Statics::ItemInstance_eventGetItemTemplateID_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UItemInstance_GetItemTemplateID()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UItemInstance_GetItemTemplateID_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UItemInstance::execGetItemTemplateID)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetItemTemplateID();
	P_NATIVE_END;
}
// End Class UItemInstance Function GetItemTemplateID

// Begin Class UItemInstance
void UItemInstance::StaticRegisterNativesUItemInstance()
{
	UClass* Class = UItemInstance::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetItemRarity", &UItemInstance::execGetItemRarity },
		{ "GetItemTemplateID", &UItemInstance::execGetItemTemplateID },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
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
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Item/ItemInstance.h" },
		{ "ModuleRelativePath", "Item/ItemInstance.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemTemplateID_MetaData[] = {
		{ "ModuleRelativePath", "Item/ItemInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemRarity_MetaData[] = {
		{ "ModuleRelativePath", "Item/ItemInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ItemTemplateID;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ItemRarity_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ItemRarity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UItemInstance_GetItemRarity, "GetItemRarity" }, // 1939108468
		{ &Z_Construct_UFunction_UItemInstance_GetItemTemplateID, "GetItemTemplateID" }, // 1787531700
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UItemInstance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UItemInstance_Statics::NewProp_ItemTemplateID = { "ItemTemplateID", nullptr, (EPropertyFlags)0x0040000000000020, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemInstance, ItemTemplateID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemTemplateID_MetaData), NewProp_ItemTemplateID_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UItemInstance_Statics::NewProp_ItemRarity_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UItemInstance_Statics::NewProp_ItemRarity = { "ItemRarity", nullptr, (EPropertyFlags)0x0040000000000020, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemInstance, ItemRarity), Z_Construct_UEnum_EMBER_EItemRarity, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemRarity_MetaData), NewProp_ItemRarity_MetaData) }; // 731058631
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UItemInstance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemInstance_Statics::NewProp_ItemTemplateID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemInstance_Statics::NewProp_ItemRarity_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemInstance_Statics::NewProp_ItemRarity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UItemInstance_Statics::PropPointers) < 2048);
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
	FuncInfo,
	Z_Construct_UClass_UItemInstance_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UItemInstance_Statics::PropPointers),
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
void UItemInstance::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static const FName Name_ItemTemplateID(TEXT("ItemTemplateID"));
	static const FName Name_ItemRarity(TEXT("ItemRarity"));
	const bool bIsValid = true
		&& Name_ItemTemplateID == ClassReps[(int32)ENetFields_Private::ItemTemplateID].Property->GetFName()
		&& Name_ItemRarity == ClassReps[(int32)ENetFields_Private::ItemRarity].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in UItemInstance"));
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UItemInstance);
UItemInstance::~UItemInstance() {}
// End Class UItemInstance

// Begin Registration
struct Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Item_ItemInstance_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UItemInstance, UItemInstance::StaticClass, TEXT("UItemInstance"), &Z_Registration_Info_UClass_UItemInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UItemInstance), 3463556696U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Item_ItemInstance_h_3345945923(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Item_ItemInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Item_ItemInstance_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
