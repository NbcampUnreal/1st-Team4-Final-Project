// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/Component/C_StateComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeC_StateComponent() {}

// Begin Cross Module References
EMBER_API UClass* Z_Construct_UClass_UC_StateComponent();
EMBER_API UClass* Z_Construct_UClass_UC_StateComponent_NoRegister();
EMBER_API UEnum* Z_Construct_UEnum_EMBER_EStateType();
EMBER_API UFunction* Z_Construct_UDelegateFunction_EMBER_StateTypeChanged__DelegateSignature();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Delegate FStateTypeChanged
struct Z_Construct_UDelegateFunction_EMBER_StateTypeChanged__DelegateSignature_Statics
{
	struct _Script_EMBER_eventStateTypeChanged_Parms
	{
		EStateType InPrevType;
		EStateType InNewType;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Component/C_StateComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_InPrevType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InPrevType;
	static const UECodeGen_Private::FBytePropertyParams NewProp_InNewType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InNewType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_EMBER_StateTypeChanged__DelegateSignature_Statics::NewProp_InPrevType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_EMBER_StateTypeChanged__DelegateSignature_Statics::NewProp_InPrevType = { "InPrevType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_EMBER_eventStateTypeChanged_Parms, InPrevType), Z_Construct_UEnum_EMBER_EStateType, METADATA_PARAMS(0, nullptr) }; // 344348180
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_EMBER_StateTypeChanged__DelegateSignature_Statics::NewProp_InNewType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_EMBER_StateTypeChanged__DelegateSignature_Statics::NewProp_InNewType = { "InNewType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_EMBER_eventStateTypeChanged_Parms, InNewType), Z_Construct_UEnum_EMBER_EStateType, METADATA_PARAMS(0, nullptr) }; // 344348180
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_EMBER_StateTypeChanged__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_EMBER_StateTypeChanged__DelegateSignature_Statics::NewProp_InPrevType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_EMBER_StateTypeChanged__DelegateSignature_Statics::NewProp_InPrevType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_EMBER_StateTypeChanged__DelegateSignature_Statics::NewProp_InNewType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_EMBER_StateTypeChanged__DelegateSignature_Statics::NewProp_InNewType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_EMBER_StateTypeChanged__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_EMBER_StateTypeChanged__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_EMBER, nullptr, "StateTypeChanged__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_EMBER_StateTypeChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_EMBER_StateTypeChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_EMBER_StateTypeChanged__DelegateSignature_Statics::_Script_EMBER_eventStateTypeChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_EMBER_StateTypeChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_EMBER_StateTypeChanged__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_EMBER_StateTypeChanged__DelegateSignature_Statics::_Script_EMBER_eventStateTypeChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_EMBER_StateTypeChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_EMBER_StateTypeChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FStateTypeChanged_DelegateWrapper(const FMulticastScriptDelegate& StateTypeChanged, EStateType InPrevType, EStateType InNewType)
{
	struct _Script_EMBER_eventStateTypeChanged_Parms
	{
		EStateType InPrevType;
		EStateType InNewType;
	};
	_Script_EMBER_eventStateTypeChanged_Parms Parms;
	Parms.InPrevType=InPrevType;
	Parms.InNewType=InNewType;
	StateTypeChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FStateTypeChanged

// Begin Class UC_StateComponent
void UC_StateComponent::StaticRegisterNativesUC_StateComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UC_StateComponent);
UClass* Z_Construct_UClass_UC_StateComponent_NoRegister()
{
	return UC_StateComponent::StaticClass();
}
struct Z_Construct_UClass_UC_StateComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Component/C_StateComponent.h" },
		{ "ModuleRelativePath", "Component/C_StateComponent.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UC_StateComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UC_StateComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UC_StateComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UC_StateComponent_Statics::ClassParams = {
	&UC_StateComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UC_StateComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UC_StateComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UC_StateComponent()
{
	if (!Z_Registration_Info_UClass_UC_StateComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UC_StateComponent.OuterSingleton, Z_Construct_UClass_UC_StateComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UC_StateComponent.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<UC_StateComponent>()
{
	return UC_StateComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UC_StateComponent);
UC_StateComponent::~UC_StateComponent() {}
// End Class UC_StateComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Component_C_StateComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UC_StateComponent, UC_StateComponent::StaticClass, TEXT("UC_StateComponent"), &Z_Registration_Info_UClass_UC_StateComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UC_StateComponent), 3002133333U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Component_C_StateComponent_h_2660687225(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Component_C_StateComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Component_C_StateComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
