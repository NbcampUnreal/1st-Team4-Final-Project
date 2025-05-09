// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/AI/BaseAIController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBaseAIController() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_AAIController();
AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTree_NoRegister();
AIMODULE_API UClass* Z_Construct_UClass_UBlackboardComponent_NoRegister();
AIMODULE_API UClass* Z_Construct_UClass_UBlackboardData_NoRegister();
EMBER_API UClass* Z_Construct_UClass_ABaseAIController();
EMBER_API UClass* Z_Construct_UClass_ABaseAIController_NoRegister();
EMBER_API UEnum* Z_Construct_UEnum_EMBER_EAnimalType();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Enum EAnimalType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EAnimalType;
static UEnum* EAnimalType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EAnimalType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EAnimalType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EMBER_EAnimalType, (UObject*)Z_Construct_UPackage__Script_EMBER(), TEXT("EAnimalType"));
	}
	return Z_Registration_Info_UEnum_EAnimalType.OuterSingleton;
}
template<> EMBER_API UEnum* StaticEnum<EAnimalType>()
{
	return EAnimalType_StaticEnum();
}
struct Z_Construct_UEnum_EMBER_EAnimalType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Aggressive.DisplayName", "Aggressive" },
		{ "Aggressive.Name", "EAnimalType::Aggressive" },
		{ "BlueprintType", "true" },
		{ "Defensive.DisplayName", "Defensive" },
		{ "Defensive.Name", "EAnimalType::Defensive" },
		{ "ModuleRelativePath", "AI/BaseAIController.h" },
		{ "Passive.DisplayName", "Passive" },
		{ "Passive.Name", "EAnimalType::Passive" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EAnimalType::Passive", (int64)EAnimalType::Passive },
		{ "EAnimalType::Defensive", (int64)EAnimalType::Defensive },
		{ "EAnimalType::Aggressive", (int64)EAnimalType::Aggressive },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EMBER_EAnimalType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EMBER,
	nullptr,
	"EAnimalType",
	"EAnimalType",
	Z_Construct_UEnum_EMBER_EAnimalType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EMBER_EAnimalType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EMBER_EAnimalType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EMBER_EAnimalType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EMBER_EAnimalType()
{
	if (!Z_Registration_Info_UEnum_EAnimalType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EAnimalType.InnerSingleton, Z_Construct_UEnum_EMBER_EAnimalType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EAnimalType.InnerSingleton;
}
// End Enum EAnimalType

// Begin Class ABaseAIController
void ABaseAIController::StaticRegisterNativesABaseAIController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABaseAIController);
UClass* Z_Construct_UClass_ABaseAIController_NoRegister()
{
	return ABaseAIController::StaticClass();
}
struct Z_Construct_UClass_ABaseAIController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "AI/BaseAIController.h" },
		{ "ModuleRelativePath", "AI/BaseAIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlackboardAsset_MetaData[] = {
		{ "Category", "AI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xb8\x94\xeb\x9e\x99\xeb\xb3\xb4\xeb\x93\x9c \xeb\x8d\xb0\xec\x9d\xb4\xed\x84\xb0 (\xec\x97\x90\xeb\x94\x94\xed\x84\xb0\xec\x97\x90\xec\x84\x9c \xec\x84\xa4\xec\xa0\x95)\n" },
#endif
		{ "ModuleRelativePath", "AI/BaseAIController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xb8\x94\xeb\x9e\x99\xeb\xb3\xb4\xeb\x93\x9c \xeb\x8d\xb0\xec\x9d\xb4\xed\x84\xb0 (\xec\x97\x90\xeb\x94\x94\xed\x84\xb0\xec\x97\x90\xec\x84\x9c \xec\x84\xa4\xec\xa0\x95)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlackboardComp_MetaData[] = {
		{ "Category", "AI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xb8\x94\xeb\x9e\x99\xeb\xb3\xb4\xeb\x93\x9c \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8 (UseBlackboard()\xeb\xa5\xbc \xed\x86\xb5\xed\x95\xb4 \xec\xb0\xb8\xec\xa1\xb0)\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "AI/BaseAIController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xb8\x94\xeb\x9e\x99\xeb\xb3\xb4\xeb\x93\x9c \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8 (UseBlackboard()\xeb\xa5\xbc \xed\x86\xb5\xed\x95\xb4 \xec\xb0\xb8\xec\xa1\xb0)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PassiveBT_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "AI/BaseAIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefensiveBT_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "AI/BaseAIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AggressiveBT_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "AI/BaseAIController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BlackboardAsset;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BlackboardComp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PassiveBT;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefensiveBT;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AggressiveBT;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABaseAIController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABaseAIController_Statics::NewProp_BlackboardAsset = { "BlackboardAsset", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABaseAIController, BlackboardAsset), Z_Construct_UClass_UBlackboardData_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlackboardAsset_MetaData), NewProp_BlackboardAsset_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABaseAIController_Statics::NewProp_BlackboardComp = { "BlackboardComp", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABaseAIController, BlackboardComp), Z_Construct_UClass_UBlackboardComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlackboardComp_MetaData), NewProp_BlackboardComp_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABaseAIController_Statics::NewProp_PassiveBT = { "PassiveBT", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABaseAIController, PassiveBT), Z_Construct_UClass_UBehaviorTree_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PassiveBT_MetaData), NewProp_PassiveBT_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABaseAIController_Statics::NewProp_DefensiveBT = { "DefensiveBT", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABaseAIController, DefensiveBT), Z_Construct_UClass_UBehaviorTree_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefensiveBT_MetaData), NewProp_DefensiveBT_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABaseAIController_Statics::NewProp_AggressiveBT = { "AggressiveBT", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABaseAIController, AggressiveBT), Z_Construct_UClass_UBehaviorTree_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AggressiveBT_MetaData), NewProp_AggressiveBT_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABaseAIController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseAIController_Statics::NewProp_BlackboardAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseAIController_Statics::NewProp_BlackboardComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseAIController_Statics::NewProp_PassiveBT,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseAIController_Statics::NewProp_DefensiveBT,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseAIController_Statics::NewProp_AggressiveBT,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABaseAIController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ABaseAIController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AAIController,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABaseAIController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABaseAIController_Statics::ClassParams = {
	&ABaseAIController::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ABaseAIController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ABaseAIController_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABaseAIController_Statics::Class_MetaDataParams), Z_Construct_UClass_ABaseAIController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABaseAIController()
{
	if (!Z_Registration_Info_UClass_ABaseAIController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABaseAIController.OuterSingleton, Z_Construct_UClass_ABaseAIController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABaseAIController.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<ABaseAIController>()
{
	return ABaseAIController::StaticClass();
}
ABaseAIController::ABaseAIController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABaseAIController);
ABaseAIController::~ABaseAIController() {}
// End Class ABaseAIController

// Begin Registration
struct Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_AI_BaseAIController_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EAnimalType_StaticEnum, TEXT("EAnimalType"), &Z_Registration_Info_UEnum_EAnimalType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 324055089U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABaseAIController, ABaseAIController::StaticClass, TEXT("ABaseAIController"), &Z_Registration_Info_UClass_ABaseAIController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABaseAIController), 1097048262U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_AI_BaseAIController_h_3613580968(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_AI_BaseAIController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_AI_BaseAIController_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_AI_BaseAIController_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_AI_BaseAIController_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
