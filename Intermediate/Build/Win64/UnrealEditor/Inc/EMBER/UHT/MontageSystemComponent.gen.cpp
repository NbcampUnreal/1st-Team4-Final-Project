// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/Component/MontageSystemComponent.h"
#include "UObject/CoreNet.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMontageSystemComponent() {}

// Begin Cross Module References
EMBER_API UClass* Z_Construct_UClass_UMontageSystemComponent();
EMBER_API UClass* Z_Construct_UClass_UMontageSystemComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Class UMontageSystemComponent Function MulticastPlayMontage
struct MontageSystemComponent_eventMulticastPlayMontage_Parms
{
	UAnimMontage* Montage;
	float PlayRate;
	FName SectionName;
};
static const FName NAME_UMontageSystemComponent_MulticastPlayMontage = FName(TEXT("MulticastPlayMontage"));
void UMontageSystemComponent::MulticastPlayMontage(UAnimMontage* Montage, float PlayRate, FName SectionName)
{
	MontageSystemComponent_eventMulticastPlayMontage_Parms Parms;
	Parms.Montage=Montage;
	Parms.PlayRate=PlayRate;
	Parms.SectionName=SectionName;
	UFunction* Func = FindFunctionChecked(NAME_UMontageSystemComponent_MulticastPlayMontage);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UMontageSystemComponent_MulticastPlayMontage_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xeb\xaa\xa8\xeb\x93\xa0 \xed\x81\xb4\xeb\x9d\xbc\xec\x9d\xb4\xec\x96\xb8\xed\x8a\xb8\xec\x97\x90\xea\xb2\x8c \xeb\xaa\xbd\xed\x83\x80\xec\xa3\xbc \xec\x9e\xac\xec\x83\x9d \xeb\xaa\x85\xeb\xa0\xb9 broadcast */" },
#endif
		{ "ModuleRelativePath", "Component/MontageSystemComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xaa\xa8\xeb\x93\xa0 \xed\x81\xb4\xeb\x9d\xbc\xec\x9d\xb4\xec\x96\xb8\xed\x8a\xb8\xec\x97\x90\xea\xb2\x8c \xeb\xaa\xbd\xed\x83\x80\xec\xa3\xbc \xec\x9e\xac\xec\x83\x9d \xeb\xaa\x85\xeb\xa0\xb9 broadcast" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Montage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayRate;
	static const UECodeGen_Private::FNamePropertyParams NewProp_SectionName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMontageSystemComponent_MulticastPlayMontage_Statics::NewProp_Montage = { "Montage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MontageSystemComponent_eventMulticastPlayMontage_Parms, Montage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMontageSystemComponent_MulticastPlayMontage_Statics::NewProp_PlayRate = { "PlayRate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MontageSystemComponent_eventMulticastPlayMontage_Parms, PlayRate), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UMontageSystemComponent_MulticastPlayMontage_Statics::NewProp_SectionName = { "SectionName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MontageSystemComponent_eventMulticastPlayMontage_Parms, SectionName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMontageSystemComponent_MulticastPlayMontage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMontageSystemComponent_MulticastPlayMontage_Statics::NewProp_Montage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMontageSystemComponent_MulticastPlayMontage_Statics::NewProp_PlayRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMontageSystemComponent_MulticastPlayMontage_Statics::NewProp_SectionName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMontageSystemComponent_MulticastPlayMontage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMontageSystemComponent_MulticastPlayMontage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMontageSystemComponent, nullptr, "MulticastPlayMontage", nullptr, nullptr, Z_Construct_UFunction_UMontageSystemComponent_MulticastPlayMontage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMontageSystemComponent_MulticastPlayMontage_Statics::PropPointers), sizeof(MontageSystemComponent_eventMulticastPlayMontage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00024CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMontageSystemComponent_MulticastPlayMontage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMontageSystemComponent_MulticastPlayMontage_Statics::Function_MetaDataParams) };
static_assert(sizeof(MontageSystemComponent_eventMulticastPlayMontage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMontageSystemComponent_MulticastPlayMontage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMontageSystemComponent_MulticastPlayMontage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMontageSystemComponent::execMulticastPlayMontage)
{
	P_GET_OBJECT(UAnimMontage,Z_Param_Montage);
	P_GET_PROPERTY(FFloatProperty,Z_Param_PlayRate);
	P_GET_PROPERTY(FNameProperty,Z_Param_SectionName);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->MulticastPlayMontage_Implementation(Z_Param_Montage,Z_Param_PlayRate,Z_Param_SectionName);
	P_NATIVE_END;
}
// End Class UMontageSystemComponent Function MulticastPlayMontage

// Begin Class UMontageSystemComponent Function RequestPlayMontage
struct Z_Construct_UFunction_UMontageSystemComponent_RequestPlayMontage_Statics
{
	struct MontageSystemComponent_eventRequestPlayMontage_Parms
	{
		UAnimMontage* Montage;
		float PlayRate;
		FName SectionName;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Animation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Montage \xec\x9e\xac\xec\x83\x9d \xec\x9a\x94\xec\xb2\xad (\xed\x81\xb4\xeb\x9d\xbc\xec\x9d\xb4\xec\x96\xb8\xed\x8a\xb8 \xed\x98\xb8\xec\xb6\x9c) */" },
#endif
		{ "CPP_Default_PlayRate", "1.000000" },
		{ "CPP_Default_SectionName", "None" },
		{ "ModuleRelativePath", "Component/MontageSystemComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Montage \xec\x9e\xac\xec\x83\x9d \xec\x9a\x94\xec\xb2\xad (\xed\x81\xb4\xeb\x9d\xbc\xec\x9d\xb4\xec\x96\xb8\xed\x8a\xb8 \xed\x98\xb8\xec\xb6\x9c)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Montage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayRate;
	static const UECodeGen_Private::FNamePropertyParams NewProp_SectionName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMontageSystemComponent_RequestPlayMontage_Statics::NewProp_Montage = { "Montage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MontageSystemComponent_eventRequestPlayMontage_Parms, Montage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMontageSystemComponent_RequestPlayMontage_Statics::NewProp_PlayRate = { "PlayRate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MontageSystemComponent_eventRequestPlayMontage_Parms, PlayRate), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UMontageSystemComponent_RequestPlayMontage_Statics::NewProp_SectionName = { "SectionName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MontageSystemComponent_eventRequestPlayMontage_Parms, SectionName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMontageSystemComponent_RequestPlayMontage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMontageSystemComponent_RequestPlayMontage_Statics::NewProp_Montage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMontageSystemComponent_RequestPlayMontage_Statics::NewProp_PlayRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMontageSystemComponent_RequestPlayMontage_Statics::NewProp_SectionName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMontageSystemComponent_RequestPlayMontage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMontageSystemComponent_RequestPlayMontage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMontageSystemComponent, nullptr, "RequestPlayMontage", nullptr, nullptr, Z_Construct_UFunction_UMontageSystemComponent_RequestPlayMontage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMontageSystemComponent_RequestPlayMontage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMontageSystemComponent_RequestPlayMontage_Statics::MontageSystemComponent_eventRequestPlayMontage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMontageSystemComponent_RequestPlayMontage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMontageSystemComponent_RequestPlayMontage_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMontageSystemComponent_RequestPlayMontage_Statics::MontageSystemComponent_eventRequestPlayMontage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMontageSystemComponent_RequestPlayMontage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMontageSystemComponent_RequestPlayMontage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMontageSystemComponent::execRequestPlayMontage)
{
	P_GET_OBJECT(UAnimMontage,Z_Param_Montage);
	P_GET_PROPERTY(FFloatProperty,Z_Param_PlayRate);
	P_GET_PROPERTY(FNameProperty,Z_Param_SectionName);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestPlayMontage(Z_Param_Montage,Z_Param_PlayRate,Z_Param_SectionName);
	P_NATIVE_END;
}
// End Class UMontageSystemComponent Function RequestPlayMontage

// Begin Class UMontageSystemComponent Function ServerPlayMontage
struct MontageSystemComponent_eventServerPlayMontage_Parms
{
	UAnimMontage* Montage;
	float PlayRate;
	FName SectionName;
};
static const FName NAME_UMontageSystemComponent_ServerPlayMontage = FName(TEXT("ServerPlayMontage"));
void UMontageSystemComponent::ServerPlayMontage(UAnimMontage* Montage, float PlayRate, FName SectionName)
{
	MontageSystemComponent_eventServerPlayMontage_Parms Parms;
	Parms.Montage=Montage;
	Parms.PlayRate=PlayRate;
	Parms.SectionName=SectionName;
	UFunction* Func = FindFunctionChecked(NAME_UMontageSystemComponent_ServerPlayMontage);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UMontageSystemComponent_ServerPlayMontage_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xec\x84\x9c\xeb\xb2\x84\xec\x97\x90\xec\x84\x9c \xeb\xaa\xbd\xed\x83\x80\xec\xa3\xbc \xec\x9e\xac\xec\x83\x9d\xed\x95\x98\xea\xb8\xb0 (\xec\x8b\xa4\xec\xa0\x9c \xec\x9e\xac\xec\x83\x9d \xed\x95\xa8\xec\x88\x98) */" },
#endif
		{ "ModuleRelativePath", "Component/MontageSystemComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x84\x9c\xeb\xb2\x84\xec\x97\x90\xec\x84\x9c \xeb\xaa\xbd\xed\x83\x80\xec\xa3\xbc \xec\x9e\xac\xec\x83\x9d\xed\x95\x98\xea\xb8\xb0 (\xec\x8b\xa4\xec\xa0\x9c \xec\x9e\xac\xec\x83\x9d \xed\x95\xa8\xec\x88\x98)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Montage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayRate;
	static const UECodeGen_Private::FNamePropertyParams NewProp_SectionName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMontageSystemComponent_ServerPlayMontage_Statics::NewProp_Montage = { "Montage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MontageSystemComponent_eventServerPlayMontage_Parms, Montage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMontageSystemComponent_ServerPlayMontage_Statics::NewProp_PlayRate = { "PlayRate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MontageSystemComponent_eventServerPlayMontage_Parms, PlayRate), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UMontageSystemComponent_ServerPlayMontage_Statics::NewProp_SectionName = { "SectionName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MontageSystemComponent_eventServerPlayMontage_Parms, SectionName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMontageSystemComponent_ServerPlayMontage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMontageSystemComponent_ServerPlayMontage_Statics::NewProp_Montage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMontageSystemComponent_ServerPlayMontage_Statics::NewProp_PlayRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMontageSystemComponent_ServerPlayMontage_Statics::NewProp_SectionName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMontageSystemComponent_ServerPlayMontage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMontageSystemComponent_ServerPlayMontage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMontageSystemComponent, nullptr, "ServerPlayMontage", nullptr, nullptr, Z_Construct_UFunction_UMontageSystemComponent_ServerPlayMontage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMontageSystemComponent_ServerPlayMontage_Statics::PropPointers), sizeof(MontageSystemComponent_eventServerPlayMontage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMontageSystemComponent_ServerPlayMontage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMontageSystemComponent_ServerPlayMontage_Statics::Function_MetaDataParams) };
static_assert(sizeof(MontageSystemComponent_eventServerPlayMontage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMontageSystemComponent_ServerPlayMontage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMontageSystemComponent_ServerPlayMontage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMontageSystemComponent::execServerPlayMontage)
{
	P_GET_OBJECT(UAnimMontage,Z_Param_Montage);
	P_GET_PROPERTY(FFloatProperty,Z_Param_PlayRate);
	P_GET_PROPERTY(FNameProperty,Z_Param_SectionName);
	P_FINISH;
	P_NATIVE_BEGIN;
	if (!P_THIS->ServerPlayMontage_Validate(Z_Param_Montage,Z_Param_PlayRate,Z_Param_SectionName))
	{
		RPC_ValidateFailed(TEXT("ServerPlayMontage_Validate"));
		return;
	}
	P_THIS->ServerPlayMontage_Implementation(Z_Param_Montage,Z_Param_PlayRate,Z_Param_SectionName);
	P_NATIVE_END;
}
// End Class UMontageSystemComponent Function ServerPlayMontage

// Begin Class UMontageSystemComponent
void UMontageSystemComponent::StaticRegisterNativesUMontageSystemComponent()
{
	UClass* Class = UMontageSystemComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "MulticastPlayMontage", &UMontageSystemComponent::execMulticastPlayMontage },
		{ "RequestPlayMontage", &UMontageSystemComponent::execRequestPlayMontage },
		{ "ServerPlayMontage", &UMontageSystemComponent::execServerPlayMontage },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMontageSystemComponent);
UClass* Z_Construct_UClass_UMontageSystemComponent_NoRegister()
{
	return UMontageSystemComponent::StaticClass();
}
struct Z_Construct_UClass_UMontageSystemComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Component/MontageSystemComponent.h" },
		{ "ModuleRelativePath", "Component/MontageSystemComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentMontage_MetaData[] = {
		{ "ModuleRelativePath", "Component/MontageSystemComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentMontage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMontageSystemComponent_MulticastPlayMontage, "MulticastPlayMontage" }, // 3597237182
		{ &Z_Construct_UFunction_UMontageSystemComponent_RequestPlayMontage, "RequestPlayMontage" }, // 3808385977
		{ &Z_Construct_UFunction_UMontageSystemComponent_ServerPlayMontage, "ServerPlayMontage" }, // 2152754901
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMontageSystemComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMontageSystemComponent_Statics::NewProp_CurrentMontage = { "CurrentMontage", nullptr, (EPropertyFlags)0x0020080000000020, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMontageSystemComponent, CurrentMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentMontage_MetaData), NewProp_CurrentMontage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMontageSystemComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMontageSystemComponent_Statics::NewProp_CurrentMontage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMontageSystemComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UMontageSystemComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMontageSystemComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMontageSystemComponent_Statics::ClassParams = {
	&UMontageSystemComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UMontageSystemComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UMontageSystemComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMontageSystemComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UMontageSystemComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMontageSystemComponent()
{
	if (!Z_Registration_Info_UClass_UMontageSystemComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMontageSystemComponent.OuterSingleton, Z_Construct_UClass_UMontageSystemComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMontageSystemComponent.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<UMontageSystemComponent>()
{
	return UMontageSystemComponent::StaticClass();
}
void UMontageSystemComponent::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static const FName Name_CurrentMontage(TEXT("CurrentMontage"));
	const bool bIsValid = true
		&& Name_CurrentMontage == ClassReps[(int32)ENetFields_Private::CurrentMontage].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in UMontageSystemComponent"));
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMontageSystemComponent);
UMontageSystemComponent::~UMontageSystemComponent() {}
// End Class UMontageSystemComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_Component_MontageSystemComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMontageSystemComponent, UMontageSystemComponent::StaticClass, TEXT("UMontageSystemComponent"), &Z_Registration_Info_UClass_UMontageSystemComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMontageSystemComponent), 1041425873U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_Component_MontageSystemComponent_h_1539582620(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_Component_MontageSystemComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_Component_MontageSystemComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
