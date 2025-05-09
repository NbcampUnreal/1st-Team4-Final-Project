// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/Crafting/CraftingSystem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCraftingSystem() {}

// Begin Cross Module References
EMBER_API UClass* Z_Construct_UClass_AEmberPlayerCharacter_NoRegister();
EMBER_API UClass* Z_Construct_UClass_UCraftingSystem();
EMBER_API UClass* Z_Construct_UClass_UCraftingSystem_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Class UCraftingSystem Function AggregateIngredients
struct Z_Construct_UFunction_UCraftingSystem_AggregateIngredients_Statics
{
	struct CraftingSystem_eventAggregateIngredients_Parms
	{
		AEmberPlayerCharacter* Player;
		TMap<FString,int32> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Crafting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x9d\xb8\xeb\xb2\xa4\xed\x86\xa0\xeb\xa6\xac, \xec\xa3\xbc\xeb\xb3\x80 \xec\x83\x81\xec\x9e\x90 \xec\x9e\xac\xeb\xa3\x8c \xec\xb0\xbe\xea\xb8\xb0\n" },
#endif
		{ "ModuleRelativePath", "Crafting/CraftingSystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9d\xb8\xeb\xb2\xa4\xed\x86\xa0\xeb\xa6\xac, \xec\xa3\xbc\xeb\xb3\x80 \xec\x83\x81\xec\x9e\x90 \xec\x9e\xac\xeb\xa3\x8c \xec\xb0\xbe\xea\xb8\xb0" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Player;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCraftingSystem_AggregateIngredients_Statics::NewProp_Player = { "Player", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CraftingSystem_eventAggregateIngredients_Parms, Player), Z_Construct_UClass_AEmberPlayerCharacter_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCraftingSystem_AggregateIngredients_Statics::NewProp_ReturnValue_ValueProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCraftingSystem_AggregateIngredients_Statics::NewProp_ReturnValue_Key_KeyProp = { "ReturnValue_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UCraftingSystem_AggregateIngredients_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CraftingSystem_eventAggregateIngredients_Parms, ReturnValue), EMapPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCraftingSystem_AggregateIngredients_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCraftingSystem_AggregateIngredients_Statics::NewProp_Player,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCraftingSystem_AggregateIngredients_Statics::NewProp_ReturnValue_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCraftingSystem_AggregateIngredients_Statics::NewProp_ReturnValue_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCraftingSystem_AggregateIngredients_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCraftingSystem_AggregateIngredients_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCraftingSystem_AggregateIngredients_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCraftingSystem, nullptr, "AggregateIngredients", nullptr, nullptr, Z_Construct_UFunction_UCraftingSystem_AggregateIngredients_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCraftingSystem_AggregateIngredients_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCraftingSystem_AggregateIngredients_Statics::CraftingSystem_eventAggregateIngredients_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCraftingSystem_AggregateIngredients_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCraftingSystem_AggregateIngredients_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCraftingSystem_AggregateIngredients_Statics::CraftingSystem_eventAggregateIngredients_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCraftingSystem_AggregateIngredients()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCraftingSystem_AggregateIngredients_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCraftingSystem::execAggregateIngredients)
{
	P_GET_OBJECT(AEmberPlayerCharacter,Z_Param_Player);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TMap<FString,int32>*)Z_Param__Result=P_THIS->AggregateIngredients(Z_Param_Player);
	P_NATIVE_END;
}
// End Class UCraftingSystem Function AggregateIngredients

// Begin Class UCraftingSystem Function StartCrafting
struct Z_Construct_UFunction_UCraftingSystem_StartCrafting_Statics
{
	struct CraftingSystem_eventStartCrafting_Parms
	{
		AEmberPlayerCharacter* Player;
		FString ItemName;
		float ProcessTime;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Crafting" },
		{ "ModuleRelativePath", "Crafting/CraftingSystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Player;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ItemName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ProcessTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCraftingSystem_StartCrafting_Statics::NewProp_Player = { "Player", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CraftingSystem_eventStartCrafting_Parms, Player), Z_Construct_UClass_AEmberPlayerCharacter_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCraftingSystem_StartCrafting_Statics::NewProp_ItemName = { "ItemName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CraftingSystem_eventStartCrafting_Parms, ItemName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemName_MetaData), NewProp_ItemName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCraftingSystem_StartCrafting_Statics::NewProp_ProcessTime = { "ProcessTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CraftingSystem_eventStartCrafting_Parms, ProcessTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCraftingSystem_StartCrafting_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCraftingSystem_StartCrafting_Statics::NewProp_Player,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCraftingSystem_StartCrafting_Statics::NewProp_ItemName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCraftingSystem_StartCrafting_Statics::NewProp_ProcessTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCraftingSystem_StartCrafting_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCraftingSystem_StartCrafting_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCraftingSystem, nullptr, "StartCrafting", nullptr, nullptr, Z_Construct_UFunction_UCraftingSystem_StartCrafting_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCraftingSystem_StartCrafting_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCraftingSystem_StartCrafting_Statics::CraftingSystem_eventStartCrafting_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCraftingSystem_StartCrafting_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCraftingSystem_StartCrafting_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCraftingSystem_StartCrafting_Statics::CraftingSystem_eventStartCrafting_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCraftingSystem_StartCrafting()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCraftingSystem_StartCrafting_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCraftingSystem::execStartCrafting)
{
	P_GET_OBJECT(AEmberPlayerCharacter,Z_Param_Player);
	P_GET_PROPERTY(FStrProperty,Z_Param_ItemName);
	P_GET_PROPERTY(FFloatProperty,Z_Param_ProcessTime);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartCrafting(Z_Param_Player,Z_Param_ItemName,Z_Param_ProcessTime);
	P_NATIVE_END;
}
// End Class UCraftingSystem Function StartCrafting

// Begin Class UCraftingSystem
void UCraftingSystem::StaticRegisterNativesUCraftingSystem()
{
	UClass* Class = UCraftingSystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AggregateIngredients", &UCraftingSystem::execAggregateIngredients },
		{ "StartCrafting", &UCraftingSystem::execStartCrafting },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCraftingSystem);
UClass* Z_Construct_UClass_UCraftingSystem_NoRegister()
{
	return UCraftingSystem::StaticClass();
}
struct Z_Construct_UClass_UCraftingSystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Crafting/CraftingSystem.h" },
		{ "ModuleRelativePath", "Crafting/CraftingSystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProcessingAnimation_MetaData[] = {
		{ "Category", "Crafting" },
		{ "ModuleRelativePath", "Crafting/CraftingSystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ProcessingAnimation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCraftingSystem_AggregateIngredients, "AggregateIngredients" }, // 356648466
		{ &Z_Construct_UFunction_UCraftingSystem_StartCrafting, "StartCrafting" }, // 2442661789
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCraftingSystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCraftingSystem_Statics::NewProp_ProcessingAnimation = { "ProcessingAnimation", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCraftingSystem, ProcessingAnimation), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProcessingAnimation_MetaData), NewProp_ProcessingAnimation_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCraftingSystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCraftingSystem_Statics::NewProp_ProcessingAnimation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCraftingSystem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCraftingSystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCraftingSystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCraftingSystem_Statics::ClassParams = {
	&UCraftingSystem::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCraftingSystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCraftingSystem_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCraftingSystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UCraftingSystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCraftingSystem()
{
	if (!Z_Registration_Info_UClass_UCraftingSystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCraftingSystem.OuterSingleton, Z_Construct_UClass_UCraftingSystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCraftingSystem.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<UCraftingSystem>()
{
	return UCraftingSystem::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCraftingSystem);
UCraftingSystem::~UCraftingSystem() {}
// End Class UCraftingSystem

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingSystem_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCraftingSystem, UCraftingSystem::StaticClass, TEXT("UCraftingSystem"), &Z_Registration_Info_UClass_UCraftingSystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCraftingSystem), 3852763194U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingSystem_h_1526162815(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingSystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingSystem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
