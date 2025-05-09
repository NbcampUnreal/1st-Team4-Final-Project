// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/System/EmberAssetManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEmberAssetManager() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
EMBER_API UClass* Z_Construct_UClass_UEmberAssetManager();
EMBER_API UClass* Z_Construct_UClass_UEmberAssetManager_NoRegister();
EMBER_API UClass* Z_Construct_UClass_UEmberItemData_NoRegister();
EMBER_API UClass* Z_Construct_UClass_UEmberUIData_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UAssetManager();
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset_NoRegister();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Class UEmberAssetManager
void UEmberAssetManager::StaticRegisterNativesUEmberAssetManager()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UEmberAssetManager);
UClass* Z_Construct_UClass_UEmberAssetManager_NoRegister()
{
	return UEmberAssetManager::StaticClass();
}
struct Z_Construct_UClass_UEmberAssetManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "System/EmberAssetManager.h" },
		{ "ModuleRelativePath", "System/EmberAssetManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UIDataPath_MetaData[] = {
		{ "ModuleRelativePath", "System/EmberAssetManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemDataPath_MetaData[] = {
		{ "ModuleRelativePath", "System/EmberAssetManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GameDataMap_MetaData[] = {
		{ "ModuleRelativePath", "System/EmberAssetManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_UIDataPath;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_ItemDataPath;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GameDataMap_ValueProp;
	static const UECodeGen_Private::FClassPropertyParams NewProp_GameDataMap_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_GameDataMap;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEmberAssetManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UEmberAssetManager_Statics::NewProp_UIDataPath = { "UIDataPath", nullptr, (EPropertyFlags)0x0024080000004000, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEmberAssetManager, UIDataPath), Z_Construct_UClass_UEmberUIData_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UIDataPath_MetaData), NewProp_UIDataPath_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UEmberAssetManager_Statics::NewProp_ItemDataPath = { "ItemDataPath", nullptr, (EPropertyFlags)0x0024080000004000, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEmberAssetManager, ItemDataPath), Z_Construct_UClass_UEmberItemData_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemDataPath_MetaData), NewProp_ItemDataPath_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEmberAssetManager_Statics::NewProp_GameDataMap_ValueProp = { "GameDataMap", nullptr, (EPropertyFlags)0x0104000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UPrimaryDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UEmberAssetManager_Statics::NewProp_GameDataMap_Key_KeyProp = { "GameDataMap_Key", nullptr, (EPropertyFlags)0x0104000000000000, UECodeGen_Private::EPropertyGenFlags::Class | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UEmberAssetManager_Statics::NewProp_GameDataMap = { "GameDataMap", nullptr, (EPropertyFlags)0x0124080000002000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEmberAssetManager, GameDataMap), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GameDataMap_MetaData), NewProp_GameDataMap_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEmberAssetManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEmberAssetManager_Statics::NewProp_UIDataPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEmberAssetManager_Statics::NewProp_ItemDataPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEmberAssetManager_Statics::NewProp_GameDataMap_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEmberAssetManager_Statics::NewProp_GameDataMap_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEmberAssetManager_Statics::NewProp_GameDataMap,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEmberAssetManager_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEmberAssetManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAssetManager,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEmberAssetManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEmberAssetManager_Statics::ClassParams = {
	&UEmberAssetManager::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UEmberAssetManager_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UEmberAssetManager_Statics::PropPointers),
	0,
	0x001000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEmberAssetManager_Statics::Class_MetaDataParams), Z_Construct_UClass_UEmberAssetManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEmberAssetManager()
{
	if (!Z_Registration_Info_UClass_UEmberAssetManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEmberAssetManager.OuterSingleton, Z_Construct_UClass_UEmberAssetManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEmberAssetManager.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<UEmberAssetManager>()
{
	return UEmberAssetManager::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEmberAssetManager);
UEmberAssetManager::~UEmberAssetManager() {}
// End Class UEmberAssetManager

// Begin Registration
struct Z_CompiledInDeferFile_FID_1st_Team4_Final_Project_Source_EMBER_System_EmberAssetManager_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEmberAssetManager, UEmberAssetManager::StaticClass, TEXT("UEmberAssetManager"), &Z_Registration_Info_UClass_UEmberAssetManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEmberAssetManager), 1574680149U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_1st_Team4_Final_Project_Source_EMBER_System_EmberAssetManager_h_2164830051(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_1st_Team4_Final_Project_Source_EMBER_System_EmberAssetManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_1st_Team4_Final_Project_Source_EMBER_System_EmberAssetManager_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
