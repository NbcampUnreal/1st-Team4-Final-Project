// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/Item/Equipment/EquipmentBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEquipmentBase() {}

// Begin Cross Module References
EMBER_API UClass* Z_Construct_UClass_AEquipmentBase();
EMBER_API UClass* Z_Construct_UClass_AEquipmentBase_NoRegister();
EMBER_API UEnum* Z_Construct_UEnum_EMBER_EEquipmentSlotType();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UArrowComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Class AEquipmentBase Function OnRep_EquipmentSlotType
struct Z_Construct_UFunction_AEquipmentBase_OnRep_EquipmentSlotType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Item/Equipment/EquipmentBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEquipmentBase_OnRep_EquipmentSlotType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEquipmentBase, nullptr, "OnRep_EquipmentSlotType", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEquipmentBase_OnRep_EquipmentSlotType_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEquipmentBase_OnRep_EquipmentSlotType_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AEquipmentBase_OnRep_EquipmentSlotType()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEquipmentBase_OnRep_EquipmentSlotType_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEquipmentBase::execOnRep_EquipmentSlotType)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_EquipmentSlotType();
	P_NATIVE_END;
}
// End Class AEquipmentBase Function OnRep_EquipmentSlotType

// Begin Class AEquipmentBase Function OnRep_ItemTemplateID
struct Z_Construct_UFunction_AEquipmentBase_OnRep_ItemTemplateID_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Item/Equipment/EquipmentBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEquipmentBase_OnRep_ItemTemplateID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEquipmentBase, nullptr, "OnRep_ItemTemplateID", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEquipmentBase_OnRep_ItemTemplateID_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEquipmentBase_OnRep_ItemTemplateID_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AEquipmentBase_OnRep_ItemTemplateID()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEquipmentBase_OnRep_ItemTemplateID_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEquipmentBase::execOnRep_ItemTemplateID)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_ItemTemplateID();
	P_NATIVE_END;
}
// End Class AEquipmentBase Function OnRep_ItemTemplateID

// Begin Class AEquipmentBase
void AEquipmentBase::StaticRegisterNativesAEquipmentBase()
{
	UClass* Class = AEquipmentBase::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnRep_EquipmentSlotType", &AEquipmentBase::execOnRep_EquipmentSlotType },
		{ "OnRep_ItemTemplateID", &AEquipmentBase::execOnRep_ItemTemplateID },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEquipmentBase);
UClass* Z_Construct_UClass_AEquipmentBase_NoRegister()
{
	return AEquipmentBase::StaticClass();
}
struct Z_Construct_UClass_AEquipmentBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Item/Equipment/EquipmentBase.h" },
		{ "ModuleRelativePath", "Item/Equipment/EquipmentBase.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArrowComponent_MetaData[] = {
		{ "Category", "EquipmentBase" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Item/Equipment/EquipmentBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MeshComponent_MetaData[] = {
		{ "Category", "EquipmentBase" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Item/Equipment/EquipmentBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemTemplateID_MetaData[] = {
		{ "ModuleRelativePath", "Item/Equipment/EquipmentBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EquipmentSlotType_MetaData[] = {
		{ "ModuleRelativePath", "Item/Equipment/EquipmentBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ArrowComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MeshComponent;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ItemTemplateID;
	static const UECodeGen_Private::FBytePropertyParams NewProp_EquipmentSlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_EquipmentSlotType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AEquipmentBase_OnRep_EquipmentSlotType, "OnRep_EquipmentSlotType" }, // 2618550835
		{ &Z_Construct_UFunction_AEquipmentBase_OnRep_ItemTemplateID, "OnRep_ItemTemplateID" }, // 844587713
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEquipmentBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEquipmentBase_Statics::NewProp_ArrowComponent = { "ArrowComponent", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEquipmentBase, ArrowComponent), Z_Construct_UClass_UArrowComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArrowComponent_MetaData), NewProp_ArrowComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEquipmentBase_Statics::NewProp_MeshComponent = { "MeshComponent", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEquipmentBase, MeshComponent), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MeshComponent_MetaData), NewProp_MeshComponent_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AEquipmentBase_Statics::NewProp_ItemTemplateID = { "ItemTemplateID", "OnRep_ItemTemplateID", (EPropertyFlags)0x0020080100000020, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEquipmentBase, ItemTemplateID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemTemplateID_MetaData), NewProp_ItemTemplateID_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AEquipmentBase_Statics::NewProp_EquipmentSlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AEquipmentBase_Statics::NewProp_EquipmentSlotType = { "EquipmentSlotType", "OnRep_EquipmentSlotType", (EPropertyFlags)0x0020080100000020, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEquipmentBase, EquipmentSlotType), Z_Construct_UEnum_EMBER_EEquipmentSlotType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EquipmentSlotType_MetaData), NewProp_EquipmentSlotType_MetaData) }; // 3890792377
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEquipmentBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEquipmentBase_Statics::NewProp_ArrowComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEquipmentBase_Statics::NewProp_MeshComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEquipmentBase_Statics::NewProp_ItemTemplateID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEquipmentBase_Statics::NewProp_EquipmentSlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEquipmentBase_Statics::NewProp_EquipmentSlotType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEquipmentBase_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEquipmentBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEquipmentBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEquipmentBase_Statics::ClassParams = {
	&AEquipmentBase::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AEquipmentBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AEquipmentBase_Statics::PropPointers),
	0,
	0x009000A5u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEquipmentBase_Statics::Class_MetaDataParams), Z_Construct_UClass_AEquipmentBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEquipmentBase()
{
	if (!Z_Registration_Info_UClass_AEquipmentBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEquipmentBase.OuterSingleton, Z_Construct_UClass_AEquipmentBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEquipmentBase.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<AEquipmentBase>()
{
	return AEquipmentBase::StaticClass();
}
void AEquipmentBase::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static const FName Name_ItemTemplateID(TEXT("ItemTemplateID"));
	static const FName Name_EquipmentSlotType(TEXT("EquipmentSlotType"));
	const bool bIsValid = true
		&& Name_ItemTemplateID == ClassReps[(int32)ENetFields_Private::ItemTemplateID].Property->GetFName()
		&& Name_EquipmentSlotType == ClassReps[(int32)ENetFields_Private::EquipmentSlotType].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AEquipmentBase"));
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEquipmentBase);
AEquipmentBase::~AEquipmentBase() {}
// End Class AEquipmentBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Item_Equipment_EquipmentBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEquipmentBase, AEquipmentBase::StaticClass, TEXT("AEquipmentBase"), &Z_Registration_Info_UClass_AEquipmentBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEquipmentBase), 4043523821U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Item_Equipment_EquipmentBase_h_2420040282(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Item_Equipment_EquipmentBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Item_Equipment_EquipmentBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
