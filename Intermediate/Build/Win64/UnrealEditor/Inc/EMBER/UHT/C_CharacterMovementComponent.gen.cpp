// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/Component/C_CharacterMovementComponent.h"
#include "EnhancedInput/Public/InputActionValue.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeC_CharacterMovementComponent() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
EMBER_API UClass* Z_Construct_UClass_UC_CharacterMovementComponent();
EMBER_API UClass* Z_Construct_UClass_UC_CharacterMovementComponent_NoRegister();
EMBER_API UEnum* Z_Construct_UEnum_EMBER_ESpeedType();
EMBER_API UFunction* Z_Construct_UDelegateFunction_EMBER_OnMoveDelegate__DelegateSignature();
ENGINE_API UClass* Z_Construct_UClass_ACharacter_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCharacterMovementComponent();
ENHANCEDINPUT_API UScriptStruct* Z_Construct_UScriptStruct_FInputActionValue();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Delegate FOnMoveDelegate
struct Z_Construct_UDelegateFunction_EMBER_OnMoveDelegate__DelegateSignature_Statics
{
	struct _Script_EMBER_eventOnMoveDelegate_Parms
	{
		FVector2D MoveVector;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\x8d\xb8\xeb\xa6\xac\xea\xb2\x8c\xec\x9d\xb4\xed\x8a\xb8 \xec\x84\xa0\xec\x96\xb8: FVector2D\xeb\xa5\xbc \xed\x8c\x8c\xeb\x9d\xbc\xeb\xaf\xb8\xed\x84\xb0\xeb\xa1\x9c \xeb\xb0\x9b\xeb\x8a\x94 \xeb\x8f\x99\xec\xa0\x81 \xeb\xa9\x80\xed\x8b\xb0\xec\xba\x90\xec\x8a\xa4\xed\x8a\xb8 \xeb\x8d\xb8\xeb\xa6\xac\xea\xb2\x8c\xec\x9d\xb4\xed\x8a\xb8\n" },
#endif
		{ "ModuleRelativePath", "Component/C_CharacterMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\x8d\xb8\xeb\xa6\xac\xea\xb2\x8c\xec\x9d\xb4\xed\x8a\xb8 \xec\x84\xa0\xec\x96\xb8: FVector2D\xeb\xa5\xbc \xed\x8c\x8c\xeb\x9d\xbc\xeb\xaf\xb8\xed\x84\xb0\xeb\xa1\x9c \xeb\xb0\x9b\xeb\x8a\x94 \xeb\x8f\x99\xec\xa0\x81 \xeb\xa9\x80\xed\x8b\xb0\xec\xba\x90\xec\x8a\xa4\xed\x8a\xb8 \xeb\x8d\xb8\xeb\xa6\xac\xea\xb2\x8c\xec\x9d\xb4\xed\x8a\xb8" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_MoveVector;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_EMBER_OnMoveDelegate__DelegateSignature_Statics::NewProp_MoveVector = { "MoveVector", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_EMBER_eventOnMoveDelegate_Parms, MoveVector), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_EMBER_OnMoveDelegate__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_EMBER_OnMoveDelegate__DelegateSignature_Statics::NewProp_MoveVector,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_EMBER_OnMoveDelegate__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_EMBER_OnMoveDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_EMBER, nullptr, "OnMoveDelegate__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_EMBER_OnMoveDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_EMBER_OnMoveDelegate__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_EMBER_OnMoveDelegate__DelegateSignature_Statics::_Script_EMBER_eventOnMoveDelegate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_EMBER_OnMoveDelegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_EMBER_OnMoveDelegate__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_EMBER_OnMoveDelegate__DelegateSignature_Statics::_Script_EMBER_eventOnMoveDelegate_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_EMBER_OnMoveDelegate__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_EMBER_OnMoveDelegate__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnMoveDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnMoveDelegate, FVector2D MoveVector)
{
	struct _Script_EMBER_eventOnMoveDelegate_Parms
	{
		FVector2D MoveVector;
	};
	_Script_EMBER_eventOnMoveDelegate_Parms Parms;
	Parms.MoveVector=MoveVector;
	OnMoveDelegate.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnMoveDelegate

// Begin Class UC_CharacterMovementComponent Function GetCanDash
struct Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanDash_Statics
{
	struct C_CharacterMovementComponent_eventGetCanDash_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Component/C_CharacterMovementComponent.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanDash_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((C_CharacterMovementComponent_eventGetCanDash_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanDash_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(C_CharacterMovementComponent_eventGetCanDash_Parms), &Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanDash_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanDash_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanDash_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanDash_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanDash_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UC_CharacterMovementComponent, nullptr, "GetCanDash", nullptr, nullptr, Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanDash_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanDash_Statics::PropPointers), sizeof(Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanDash_Statics::C_CharacterMovementComponent_eventGetCanDash_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanDash_Statics::Function_MetaDataParams), Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanDash_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanDash_Statics::C_CharacterMovementComponent_eventGetCanDash_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanDash()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanDash_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UC_CharacterMovementComponent::execGetCanDash)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetCanDash();
	P_NATIVE_END;
}
// End Class UC_CharacterMovementComponent Function GetCanDash

// Begin Class UC_CharacterMovementComponent Function GetCanMove
struct Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanMove_Statics
{
	struct C_CharacterMovementComponent_eventGetCanMove_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\x09\xec\xb6\x94\xea\xb0\x80\n" },
#endif
		{ "ModuleRelativePath", "Component/C_CharacterMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xb6\x94\xea\xb0\x80" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanMove_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((C_CharacterMovementComponent_eventGetCanMove_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanMove_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(C_CharacterMovementComponent_eventGetCanMove_Parms), &Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanMove_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanMove_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanMove_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanMove_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanMove_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UC_CharacterMovementComponent, nullptr, "GetCanMove", nullptr, nullptr, Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanMove_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanMove_Statics::PropPointers), sizeof(Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanMove_Statics::C_CharacterMovementComponent_eventGetCanMove_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanMove_Statics::Function_MetaDataParams), Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanMove_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanMove_Statics::C_CharacterMovementComponent_eventGetCanMove_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanMove()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanMove_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UC_CharacterMovementComponent::execGetCanMove)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetCanMove();
	P_NATIVE_END;
}
// End Class UC_CharacterMovementComponent Function GetCanMove

// Begin Class UC_CharacterMovementComponent Function GetCurrentSpeed
struct Z_Construct_UFunction_UC_CharacterMovementComponent_GetCurrentSpeed_Statics
{
	struct C_CharacterMovementComponent_eventGetCurrentSpeed_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Component/C_CharacterMovementComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UC_CharacterMovementComponent_GetCurrentSpeed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(C_CharacterMovementComponent_eventGetCurrentSpeed_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UC_CharacterMovementComponent_GetCurrentSpeed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UC_CharacterMovementComponent_GetCurrentSpeed_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UC_CharacterMovementComponent_GetCurrentSpeed_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UC_CharacterMovementComponent_GetCurrentSpeed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UC_CharacterMovementComponent, nullptr, "GetCurrentSpeed", nullptr, nullptr, Z_Construct_UFunction_UC_CharacterMovementComponent_GetCurrentSpeed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UC_CharacterMovementComponent_GetCurrentSpeed_Statics::PropPointers), sizeof(Z_Construct_UFunction_UC_CharacterMovementComponent_GetCurrentSpeed_Statics::C_CharacterMovementComponent_eventGetCurrentSpeed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UC_CharacterMovementComponent_GetCurrentSpeed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UC_CharacterMovementComponent_GetCurrentSpeed_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UC_CharacterMovementComponent_GetCurrentSpeed_Statics::C_CharacterMovementComponent_eventGetCurrentSpeed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UC_CharacterMovementComponent_GetCurrentSpeed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UC_CharacterMovementComponent_GetCurrentSpeed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UC_CharacterMovementComponent::execGetCurrentSpeed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetCurrentSpeed();
	P_NATIVE_END;
}
// End Class UC_CharacterMovementComponent Function GetCurrentSpeed

// Begin Class UC_CharacterMovementComponent Function OnMove
struct Z_Construct_UFunction_UC_CharacterMovementComponent_OnMove_Statics
{
	struct C_CharacterMovementComponent_eventOnMove_Parms
	{
		FInputActionValue Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Component/C_CharacterMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UC_CharacterMovementComponent_OnMove_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(C_CharacterMovementComponent_eventOnMove_Parms, Value), Z_Construct_UScriptStruct_FInputActionValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) }; // 494646648
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UC_CharacterMovementComponent_OnMove_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UC_CharacterMovementComponent_OnMove_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UC_CharacterMovementComponent_OnMove_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UC_CharacterMovementComponent_OnMove_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UC_CharacterMovementComponent, nullptr, "OnMove", nullptr, nullptr, Z_Construct_UFunction_UC_CharacterMovementComponent_OnMove_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UC_CharacterMovementComponent_OnMove_Statics::PropPointers), sizeof(Z_Construct_UFunction_UC_CharacterMovementComponent_OnMove_Statics::C_CharacterMovementComponent_eventOnMove_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UC_CharacterMovementComponent_OnMove_Statics::Function_MetaDataParams), Z_Construct_UFunction_UC_CharacterMovementComponent_OnMove_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UC_CharacterMovementComponent_OnMove_Statics::C_CharacterMovementComponent_eventOnMove_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UC_CharacterMovementComponent_OnMove()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UC_CharacterMovementComponent_OnMove_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UC_CharacterMovementComponent::execOnMove)
{
	P_GET_STRUCT_REF(FInputActionValue,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnMove(Z_Param_Out_Value);
	P_NATIVE_END;
}
// End Class UC_CharacterMovementComponent Function OnMove

// Begin Class UC_CharacterMovementComponent
void UC_CharacterMovementComponent::StaticRegisterNativesUC_CharacterMovementComponent()
{
	UClass* Class = UC_CharacterMovementComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetCanDash", &UC_CharacterMovementComponent::execGetCanDash },
		{ "GetCanMove", &UC_CharacterMovementComponent::execGetCanMove },
		{ "GetCurrentSpeed", &UC_CharacterMovementComponent::execGetCurrentSpeed },
		{ "OnMove", &UC_CharacterMovementComponent::execOnMove },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UC_CharacterMovementComponent);
UClass* Z_Construct_UClass_UC_CharacterMovementComponent_NoRegister()
{
	return UC_CharacterMovementComponent::StaticClass();
}
struct Z_Construct_UClass_UC_CharacterMovementComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Component/C_CharacterMovementComponent.h" },
		{ "ModuleRelativePath", "Component/C_CharacterMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCanMove_MetaData[] = {
		{ "Category", "Move" },
		{ "ModuleRelativePath", "Component/C_CharacterMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsDash_MetaData[] = {
		{ "Category", "Move" },
		{ "ModuleRelativePath", "Component/C_CharacterMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OwnerCharacter_MetaData[] = {
		{ "Category", "Base" },
		{ "ModuleRelativePath", "Component/C_CharacterMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeedType_MetaData[] = {
		{ "Category", "Move" },
		{ "ModuleRelativePath", "Component/C_CharacterMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnMoveDelegate_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Component/C_CharacterMovementComponent.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bCanMove_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanMove;
	static void NewProp_bIsDash_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsDash;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OwnerCharacter;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SpeedType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SpeedType;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnMoveDelegate;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanDash, "GetCanDash" }, // 2733969886
		{ &Z_Construct_UFunction_UC_CharacterMovementComponent_GetCanMove, "GetCanMove" }, // 1542968216
		{ &Z_Construct_UFunction_UC_CharacterMovementComponent_GetCurrentSpeed, "GetCurrentSpeed" }, // 3336116802
		{ &Z_Construct_UFunction_UC_CharacterMovementComponent_OnMove, "OnMove" }, // 2443679109
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UC_CharacterMovementComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_UC_CharacterMovementComponent_Statics::NewProp_bCanMove_SetBit(void* Obj)
{
	((UC_CharacterMovementComponent*)Obj)->bCanMove = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UC_CharacterMovementComponent_Statics::NewProp_bCanMove = { "bCanMove", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UC_CharacterMovementComponent), &Z_Construct_UClass_UC_CharacterMovementComponent_Statics::NewProp_bCanMove_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCanMove_MetaData), NewProp_bCanMove_MetaData) };
void Z_Construct_UClass_UC_CharacterMovementComponent_Statics::NewProp_bIsDash_SetBit(void* Obj)
{
	((UC_CharacterMovementComponent*)Obj)->bIsDash = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UC_CharacterMovementComponent_Statics::NewProp_bIsDash = { "bIsDash", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UC_CharacterMovementComponent), &Z_Construct_UClass_UC_CharacterMovementComponent_Statics::NewProp_bIsDash_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsDash_MetaData), NewProp_bIsDash_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UC_CharacterMovementComponent_Statics::NewProp_OwnerCharacter = { "OwnerCharacter", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UC_CharacterMovementComponent, OwnerCharacter), Z_Construct_UClass_ACharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OwnerCharacter_MetaData), NewProp_OwnerCharacter_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UC_CharacterMovementComponent_Statics::NewProp_SpeedType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UC_CharacterMovementComponent_Statics::NewProp_SpeedType = { "SpeedType", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UC_CharacterMovementComponent, SpeedType), Z_Construct_UEnum_EMBER_ESpeedType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeedType_MetaData), NewProp_SpeedType_MetaData) }; // 1406011391
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UC_CharacterMovementComponent_Statics::NewProp_OnMoveDelegate = { "OnMoveDelegate", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UC_CharacterMovementComponent, OnMoveDelegate), Z_Construct_UDelegateFunction_EMBER_OnMoveDelegate__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnMoveDelegate_MetaData), NewProp_OnMoveDelegate_MetaData) }; // 605856165
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UC_CharacterMovementComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UC_CharacterMovementComponent_Statics::NewProp_bCanMove,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UC_CharacterMovementComponent_Statics::NewProp_bIsDash,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UC_CharacterMovementComponent_Statics::NewProp_OwnerCharacter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UC_CharacterMovementComponent_Statics::NewProp_SpeedType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UC_CharacterMovementComponent_Statics::NewProp_SpeedType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UC_CharacterMovementComponent_Statics::NewProp_OnMoveDelegate,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UC_CharacterMovementComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UC_CharacterMovementComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UCharacterMovementComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UC_CharacterMovementComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UC_CharacterMovementComponent_Statics::ClassParams = {
	&UC_CharacterMovementComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UC_CharacterMovementComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UC_CharacterMovementComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UC_CharacterMovementComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UC_CharacterMovementComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UC_CharacterMovementComponent()
{
	if (!Z_Registration_Info_UClass_UC_CharacterMovementComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UC_CharacterMovementComponent.OuterSingleton, Z_Construct_UClass_UC_CharacterMovementComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UC_CharacterMovementComponent.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<UC_CharacterMovementComponent>()
{
	return UC_CharacterMovementComponent::StaticClass();
}
UC_CharacterMovementComponent::UC_CharacterMovementComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UC_CharacterMovementComponent);
UC_CharacterMovementComponent::~UC_CharacterMovementComponent() {}
// End Class UC_CharacterMovementComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_Component_C_CharacterMovementComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UC_CharacterMovementComponent, UC_CharacterMovementComponent::StaticClass, TEXT("UC_CharacterMovementComponent"), &Z_Registration_Info_UClass_UC_CharacterMovementComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UC_CharacterMovementComponent), 4188285000U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_Component_C_CharacterMovementComponent_h_36742646(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_Component_C_CharacterMovementComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_1st_Team4_Final_Project_Source_EMBER_Component_C_CharacterMovementComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
