// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/Crafting/CraftingRecipeManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCraftingRecipeManager() {}

// Begin Cross Module References
EMBER_API UClass* Z_Construct_UClass_UCraftingRecipe_NoRegister();
EMBER_API UClass* Z_Construct_UClass_UCraftingRecipeManager();
EMBER_API UClass* Z_Construct_UClass_UCraftingRecipeManager_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Class UCraftingRecipeManager Function GetRecipeByName
struct Z_Construct_UFunction_UCraftingRecipeManager_GetRecipeByName_Statics
{
	struct CraftingRecipeManager_eventGetRecipeByName_Parms
	{
		FString RecipeName;
		UCraftingRecipe* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Crafting" },
		{ "ModuleRelativePath", "Crafting/CraftingRecipeManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RecipeName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_RecipeName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCraftingRecipeManager_GetRecipeByName_Statics::NewProp_RecipeName = { "RecipeName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CraftingRecipeManager_eventGetRecipeByName_Parms, RecipeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RecipeName_MetaData), NewProp_RecipeName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCraftingRecipeManager_GetRecipeByName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CraftingRecipeManager_eventGetRecipeByName_Parms, ReturnValue), Z_Construct_UClass_UCraftingRecipe_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCraftingRecipeManager_GetRecipeByName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCraftingRecipeManager_GetRecipeByName_Statics::NewProp_RecipeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCraftingRecipeManager_GetRecipeByName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCraftingRecipeManager_GetRecipeByName_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCraftingRecipeManager_GetRecipeByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCraftingRecipeManager, nullptr, "GetRecipeByName", nullptr, nullptr, Z_Construct_UFunction_UCraftingRecipeManager_GetRecipeByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCraftingRecipeManager_GetRecipeByName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCraftingRecipeManager_GetRecipeByName_Statics::CraftingRecipeManager_eventGetRecipeByName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCraftingRecipeManager_GetRecipeByName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCraftingRecipeManager_GetRecipeByName_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCraftingRecipeManager_GetRecipeByName_Statics::CraftingRecipeManager_eventGetRecipeByName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCraftingRecipeManager_GetRecipeByName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCraftingRecipeManager_GetRecipeByName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCraftingRecipeManager::execGetRecipeByName)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_RecipeName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UCraftingRecipe**)Z_Param__Result=P_THIS->GetRecipeByName(Z_Param_RecipeName);
	P_NATIVE_END;
}
// End Class UCraftingRecipeManager Function GetRecipeByName

// Begin Class UCraftingRecipeManager
void UCraftingRecipeManager::StaticRegisterNativesUCraftingRecipeManager()
{
	UClass* Class = UCraftingRecipeManager::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetRecipeByName", &UCraftingRecipeManager::execGetRecipeByName },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCraftingRecipeManager);
UClass* Z_Construct_UClass_UCraftingRecipeManager_NoRegister()
{
	return UCraftingRecipeManager::StaticClass();
}
struct Z_Construct_UClass_UCraftingRecipeManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Crafting/CraftingRecipeManager.h" },
		{ "ModuleRelativePath", "Crafting/CraftingRecipeManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Recipes_Inner_MetaData[] = {
		{ "Category", "Crafting" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Crafting/CraftingRecipeManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Recipes_MetaData[] = {
		{ "Category", "Crafting" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Crafting/CraftingRecipeManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Recipes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Recipes;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCraftingRecipeManager_GetRecipeByName, "GetRecipeByName" }, // 2385216443
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCraftingRecipeManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCraftingRecipeManager_Statics::NewProp_Recipes_Inner = { "Recipes", nullptr, (EPropertyFlags)0x0002000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UCraftingRecipe_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Recipes_Inner_MetaData), NewProp_Recipes_Inner_MetaData) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UCraftingRecipeManager_Statics::NewProp_Recipes = { "Recipes", nullptr, (EPropertyFlags)0x001000800000000d, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCraftingRecipeManager, Recipes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Recipes_MetaData), NewProp_Recipes_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCraftingRecipeManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCraftingRecipeManager_Statics::NewProp_Recipes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCraftingRecipeManager_Statics::NewProp_Recipes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCraftingRecipeManager_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCraftingRecipeManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCraftingRecipeManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCraftingRecipeManager_Statics::ClassParams = {
	&UCraftingRecipeManager::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCraftingRecipeManager_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCraftingRecipeManager_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCraftingRecipeManager_Statics::Class_MetaDataParams), Z_Construct_UClass_UCraftingRecipeManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCraftingRecipeManager()
{
	if (!Z_Registration_Info_UClass_UCraftingRecipeManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCraftingRecipeManager.OuterSingleton, Z_Construct_UClass_UCraftingRecipeManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCraftingRecipeManager.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<UCraftingRecipeManager>()
{
	return UCraftingRecipeManager::StaticClass();
}
UCraftingRecipeManager::UCraftingRecipeManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCraftingRecipeManager);
UCraftingRecipeManager::~UCraftingRecipeManager() {}
// End Class UCraftingRecipeManager

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingRecipeManager_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCraftingRecipeManager, UCraftingRecipeManager::StaticClass, TEXT("UCraftingRecipeManager"), &Z_Registration_Info_UClass_UCraftingRecipeManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCraftingRecipeManager), 1447396175U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingRecipeManager_h_865827950(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingRecipeManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingRecipeManager_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
