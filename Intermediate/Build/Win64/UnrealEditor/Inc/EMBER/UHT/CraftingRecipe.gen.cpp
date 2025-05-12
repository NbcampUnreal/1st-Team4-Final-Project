// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/Crafting/CraftingRecipe.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCraftingRecipe() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
EMBER_API UClass* Z_Construct_UClass_UCraftingRecipe();
EMBER_API UClass* Z_Construct_UClass_UCraftingRecipe_NoRegister();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Class UCraftingRecipe Function CanCombine
struct Z_Construct_UFunction_UCraftingRecipe_CanCombine_Statics
{
	struct CraftingRecipe_eventCanCombine_Parms
	{
		TMap<FString,int32> AvailableIngredients;
		int32 PlayerCraftingLevel;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Crafting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\xa0\x9c\xec\x9e\x91 \xea\xb0\x80\xeb\x8a\xa5\xed\x95\x9c\xec\xa7\x80 \xea\xb2\x80\xec\x82\xac    \n" },
#endif
		{ "ModuleRelativePath", "Crafting/CraftingRecipe.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xa0\x9c\xec\x9e\x91 \xea\xb0\x80\xeb\x8a\xa5\xed\x95\x9c\xec\xa7\x80 \xea\xb2\x80\xec\x82\xac" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AvailableIngredients_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_AvailableIngredients_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AvailableIngredients_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_AvailableIngredients;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PlayerCraftingLevel;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCraftingRecipe_CanCombine_Statics::NewProp_AvailableIngredients_ValueProp = { "AvailableIngredients", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCraftingRecipe_CanCombine_Statics::NewProp_AvailableIngredients_Key_KeyProp = { "AvailableIngredients_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UCraftingRecipe_CanCombine_Statics::NewProp_AvailableIngredients = { "AvailableIngredients", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CraftingRecipe_eventCanCombine_Parms, AvailableIngredients), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AvailableIngredients_MetaData), NewProp_AvailableIngredients_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCraftingRecipe_CanCombine_Statics::NewProp_PlayerCraftingLevel = { "PlayerCraftingLevel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CraftingRecipe_eventCanCombine_Parms, PlayerCraftingLevel), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UCraftingRecipe_CanCombine_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((CraftingRecipe_eventCanCombine_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCraftingRecipe_CanCombine_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CraftingRecipe_eventCanCombine_Parms), &Z_Construct_UFunction_UCraftingRecipe_CanCombine_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCraftingRecipe_CanCombine_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCraftingRecipe_CanCombine_Statics::NewProp_AvailableIngredients_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCraftingRecipe_CanCombine_Statics::NewProp_AvailableIngredients_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCraftingRecipe_CanCombine_Statics::NewProp_AvailableIngredients,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCraftingRecipe_CanCombine_Statics::NewProp_PlayerCraftingLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCraftingRecipe_CanCombine_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCraftingRecipe_CanCombine_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCraftingRecipe_CanCombine_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCraftingRecipe, nullptr, "CanCombine", nullptr, nullptr, Z_Construct_UFunction_UCraftingRecipe_CanCombine_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCraftingRecipe_CanCombine_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCraftingRecipe_CanCombine_Statics::CraftingRecipe_eventCanCombine_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCraftingRecipe_CanCombine_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCraftingRecipe_CanCombine_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCraftingRecipe_CanCombine_Statics::CraftingRecipe_eventCanCombine_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCraftingRecipe_CanCombine()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCraftingRecipe_CanCombine_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCraftingRecipe::execCanCombine)
{
	P_GET_TMAP_REF(FString,int32,Z_Param_Out_AvailableIngredients);
	P_GET_PROPERTY(FIntProperty,Z_Param_PlayerCraftingLevel);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanCombine(Z_Param_Out_AvailableIngredients,Z_Param_PlayerCraftingLevel);
	P_NATIVE_END;
}
// End Class UCraftingRecipe Function CanCombine

// Begin Class UCraftingRecipe
void UCraftingRecipe::StaticRegisterNativesUCraftingRecipe()
{
	UClass* Class = UCraftingRecipe::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CanCombine", &UCraftingRecipe::execCanCombine },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCraftingRecipe);
UClass* Z_Construct_UClass_UCraftingRecipe_NoRegister()
{
	return UCraftingRecipe::StaticClass();
}
struct Z_Construct_UClass_UCraftingRecipe_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Crafting/CraftingRecipe.h" },
		{ "ModuleRelativePath", "Crafting/CraftingRecipe.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemName_MetaData[] = {
		{ "Category", "Crafting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\xa0\x9c\xec\x9e\x91\xeb\x90\xa0 \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xec\x9d\xb4\xeb\xa6\x84 (\xec\x98\x88: \"\xec\x96\x91\xec\x86\x90\xea\xb2\x80\")\n" },
#endif
		{ "ModuleRelativePath", "Crafting/CraftingRecipe.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xa0\x9c\xec\x9e\x91\xeb\x90\xa0 \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xec\x9d\xb4\xeb\xa6\x84 (\xec\x98\x88: \"\xec\x96\x91\xec\x86\x90\xea\xb2\x80\")" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Ingredients_MetaData[] = {
		{ "Category", "Crafting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xed\x95\x84\xec\x9a\x94\xed\x95\x9c \xec\x9e\xac\xeb\xa3\x8c\xec\x99\x80 \xec\x88\x98\xeb\x9f\x89 (\xec\x98\x88: { \"\xeb\x82\x98\xeb\xac\xb4\": 1, \"\xeb\x81\x88\": 1, \"\xec\xa3\xbc\xec\x9e\xac\xeb\xa3\x8c\": 2 })\n" },
#endif
		{ "ModuleRelativePath", "Crafting/CraftingRecipe.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x95\x84\xec\x9a\x94\xed\x95\x9c \xec\x9e\xac\xeb\xa3\x8c\xec\x99\x80 \xec\x88\x98\xeb\x9f\x89 (\xec\x98\x88: { \"\xeb\x82\x98\xeb\xac\xb4\": 1, \"\xeb\x81\x88\": 1, \"\xec\xa3\xbc\xec\x9e\xac\xeb\xa3\x8c\": 2 })" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RequiredCraftingLevel_MetaData[] = {
		{ "Category", "Crafting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\xb5\x9c\xec\x86\x8c \xec\xa0\x9c\xec\x9e\x91 \xeb\xa0\x88\xeb\xb2\xa8 (\xec\x98\x88: 5)\n" },
#endif
		{ "ModuleRelativePath", "Crafting/CraftingRecipe.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xb5\x9c\xec\x86\x8c \xec\xa0\x9c\xec\x9e\x91 \xeb\xa0\x88\xeb\xb2\xa8 (\xec\x98\x88: 5)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CraftingTime_MetaData[] = {
		{ "Category", "Crafting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\xa0\x9c\xec\x9e\x91\xec\x97\x90 \xea\xb1\xb8\xeb\xa6\xac\xeb\x8a\x94 \xec\x8b\x9c\xea\xb0\x84 (\xec\xb4\x88, \xec\x98\x88: 10.0)\n" },
#endif
		{ "ModuleRelativePath", "Crafting/CraftingRecipe.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xa0\x9c\xec\x9e\x91\xec\x97\x90 \xea\xb1\xb8\xeb\xa6\xac\xeb\x8a\x94 \xec\x8b\x9c\xea\xb0\x84 (\xec\xb4\x88, \xec\x98\x88: 10.0)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ItemName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Ingredients_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Ingredients_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_Ingredients;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RequiredCraftingLevel;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CraftingTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCraftingRecipe_CanCombine, "CanCombine" }, // 977279374
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCraftingRecipe>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UCraftingRecipe_Statics::NewProp_ItemName = { "ItemName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCraftingRecipe, ItemName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemName_MetaData), NewProp_ItemName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UCraftingRecipe_Statics::NewProp_Ingredients_ValueProp = { "Ingredients", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UCraftingRecipe_Statics::NewProp_Ingredients_Key_KeyProp = { "Ingredients_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UCraftingRecipe_Statics::NewProp_Ingredients = { "Ingredients", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCraftingRecipe, Ingredients), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Ingredients_MetaData), NewProp_Ingredients_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UCraftingRecipe_Statics::NewProp_RequiredCraftingLevel = { "RequiredCraftingLevel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCraftingRecipe, RequiredCraftingLevel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RequiredCraftingLevel_MetaData), NewProp_RequiredCraftingLevel_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCraftingRecipe_Statics::NewProp_CraftingTime = { "CraftingTime", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCraftingRecipe, CraftingTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CraftingTime_MetaData), NewProp_CraftingTime_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCraftingRecipe_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCraftingRecipe_Statics::NewProp_ItemName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCraftingRecipe_Statics::NewProp_Ingredients_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCraftingRecipe_Statics::NewProp_Ingredients_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCraftingRecipe_Statics::NewProp_Ingredients,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCraftingRecipe_Statics::NewProp_RequiredCraftingLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCraftingRecipe_Statics::NewProp_CraftingTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCraftingRecipe_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCraftingRecipe_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCraftingRecipe_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCraftingRecipe_Statics::ClassParams = {
	&UCraftingRecipe::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCraftingRecipe_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCraftingRecipe_Statics::PropPointers),
	0,
	0x001010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCraftingRecipe_Statics::Class_MetaDataParams), Z_Construct_UClass_UCraftingRecipe_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCraftingRecipe()
{
	if (!Z_Registration_Info_UClass_UCraftingRecipe.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCraftingRecipe.OuterSingleton, Z_Construct_UClass_UCraftingRecipe_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCraftingRecipe.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<UCraftingRecipe>()
{
	return UCraftingRecipe::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCraftingRecipe);
UCraftingRecipe::~UCraftingRecipe() {}
// End Class UCraftingRecipe

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingRecipe_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCraftingRecipe, UCraftingRecipe::StaticClass, TEXT("UCraftingRecipe"), &Z_Registration_Info_UClass_UCraftingRecipe, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCraftingRecipe), 1807926311U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingRecipe_h_109245380(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingRecipe_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingRecipe_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
