// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/Player/EmberPlayerCharacter.h"
#include "EnhancedInput/Public/InputActionValue.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEmberPlayerCharacter() {}

// Begin Cross Module References
EMBER_API UClass* Z_Construct_UClass_AEmberPlayerCharacter();
EMBER_API UClass* Z_Construct_UClass_AEmberPlayerCharacter_NoRegister();
EMBER_API UClass* Z_Construct_UClass_UC_CameraComponent_NoRegister();
EMBER_API UClass* Z_Construct_UClass_UC_CharacterMovementComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENHANCEDINPUT_API UScriptStruct* Z_Construct_UScriptStruct_FInputActionValue();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Class AEmberPlayerCharacter Function Look
struct Z_Construct_UFunction_AEmberPlayerCharacter_Look_Statics
{
	struct EmberPlayerCharacter_eventLook_Parms
	{
		FInputActionValue value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Player/EmberPlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEmberPlayerCharacter_Look_Statics::NewProp_value = { "value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EmberPlayerCharacter_eventLook_Parms, value), Z_Construct_UScriptStruct_FInputActionValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_value_MetaData), NewProp_value_MetaData) }; // 494646648
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEmberPlayerCharacter_Look_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEmberPlayerCharacter_Look_Statics::NewProp_value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEmberPlayerCharacter_Look_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEmberPlayerCharacter_Look_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEmberPlayerCharacter, nullptr, "Look", nullptr, nullptr, Z_Construct_UFunction_AEmberPlayerCharacter_Look_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEmberPlayerCharacter_Look_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEmberPlayerCharacter_Look_Statics::EmberPlayerCharacter_eventLook_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEmberPlayerCharacter_Look_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEmberPlayerCharacter_Look_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AEmberPlayerCharacter_Look_Statics::EmberPlayerCharacter_eventLook_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEmberPlayerCharacter_Look()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEmberPlayerCharacter_Look_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEmberPlayerCharacter::execLook)
{
	P_GET_STRUCT_REF(FInputActionValue,Z_Param_Out_value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Look(Z_Param_Out_value);
	P_NATIVE_END;
}
// End Class AEmberPlayerCharacter Function Look

// Begin Class AEmberPlayerCharacter Function Move
struct Z_Construct_UFunction_AEmberPlayerCharacter_Move_Statics
{
	struct EmberPlayerCharacter_eventMove_Parms
	{
		FInputActionValue value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Player/EmberPlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEmberPlayerCharacter_Move_Statics::NewProp_value = { "value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EmberPlayerCharacter_eventMove_Parms, value), Z_Construct_UScriptStruct_FInputActionValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_value_MetaData), NewProp_value_MetaData) }; // 494646648
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEmberPlayerCharacter_Move_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEmberPlayerCharacter_Move_Statics::NewProp_value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEmberPlayerCharacter_Move_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEmberPlayerCharacter_Move_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEmberPlayerCharacter, nullptr, "Move", nullptr, nullptr, Z_Construct_UFunction_AEmberPlayerCharacter_Move_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEmberPlayerCharacter_Move_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEmberPlayerCharacter_Move_Statics::EmberPlayerCharacter_eventMove_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEmberPlayerCharacter_Move_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEmberPlayerCharacter_Move_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AEmberPlayerCharacter_Move_Statics::EmberPlayerCharacter_eventMove_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEmberPlayerCharacter_Move()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEmberPlayerCharacter_Move_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEmberPlayerCharacter::execMove)
{
	P_GET_STRUCT_REF(FInputActionValue,Z_Param_Out_value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Move(Z_Param_Out_value);
	P_NATIVE_END;
}
// End Class AEmberPlayerCharacter Function Move

// Begin Class AEmberPlayerCharacter Function StartSprint
struct Z_Construct_UFunction_AEmberPlayerCharacter_StartSprint_Statics
{
	struct EmberPlayerCharacter_eventStartSprint_Parms
	{
		FInputActionValue value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Player/EmberPlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEmberPlayerCharacter_StartSprint_Statics::NewProp_value = { "value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EmberPlayerCharacter_eventStartSprint_Parms, value), Z_Construct_UScriptStruct_FInputActionValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_value_MetaData), NewProp_value_MetaData) }; // 494646648
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEmberPlayerCharacter_StartSprint_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEmberPlayerCharacter_StartSprint_Statics::NewProp_value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEmberPlayerCharacter_StartSprint_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEmberPlayerCharacter_StartSprint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEmberPlayerCharacter, nullptr, "StartSprint", nullptr, nullptr, Z_Construct_UFunction_AEmberPlayerCharacter_StartSprint_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEmberPlayerCharacter_StartSprint_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEmberPlayerCharacter_StartSprint_Statics::EmberPlayerCharacter_eventStartSprint_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEmberPlayerCharacter_StartSprint_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEmberPlayerCharacter_StartSprint_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AEmberPlayerCharacter_StartSprint_Statics::EmberPlayerCharacter_eventStartSprint_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEmberPlayerCharacter_StartSprint()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEmberPlayerCharacter_StartSprint_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEmberPlayerCharacter::execStartSprint)
{
	P_GET_STRUCT_REF(FInputActionValue,Z_Param_Out_value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartSprint(Z_Param_Out_value);
	P_NATIVE_END;
}
// End Class AEmberPlayerCharacter Function StartSprint

// Begin Class AEmberPlayerCharacter Function StopSprint
struct Z_Construct_UFunction_AEmberPlayerCharacter_StopSprint_Statics
{
	struct EmberPlayerCharacter_eventStopSprint_Parms
	{
		FInputActionValue value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Player/EmberPlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEmberPlayerCharacter_StopSprint_Statics::NewProp_value = { "value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EmberPlayerCharacter_eventStopSprint_Parms, value), Z_Construct_UScriptStruct_FInputActionValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_value_MetaData), NewProp_value_MetaData) }; // 494646648
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEmberPlayerCharacter_StopSprint_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEmberPlayerCharacter_StopSprint_Statics::NewProp_value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEmberPlayerCharacter_StopSprint_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEmberPlayerCharacter_StopSprint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEmberPlayerCharacter, nullptr, "StopSprint", nullptr, nullptr, Z_Construct_UFunction_AEmberPlayerCharacter_StopSprint_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEmberPlayerCharacter_StopSprint_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEmberPlayerCharacter_StopSprint_Statics::EmberPlayerCharacter_eventStopSprint_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEmberPlayerCharacter_StopSprint_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEmberPlayerCharacter_StopSprint_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AEmberPlayerCharacter_StopSprint_Statics::EmberPlayerCharacter_eventStopSprint_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEmberPlayerCharacter_StopSprint()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEmberPlayerCharacter_StopSprint_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEmberPlayerCharacter::execStopSprint)
{
	P_GET_STRUCT_REF(FInputActionValue,Z_Param_Out_value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopSprint(Z_Param_Out_value);
	P_NATIVE_END;
}
// End Class AEmberPlayerCharacter Function StopSprint

// Begin Class AEmberPlayerCharacter
void AEmberPlayerCharacter::StaticRegisterNativesAEmberPlayerCharacter()
{
	UClass* Class = AEmberPlayerCharacter::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Look", &AEmberPlayerCharacter::execLook },
		{ "Move", &AEmberPlayerCharacter::execMove },
		{ "StartSprint", &AEmberPlayerCharacter::execStartSprint },
		{ "StopSprint", &AEmberPlayerCharacter::execStopSprint },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEmberPlayerCharacter);
UClass* Z_Construct_UClass_AEmberPlayerCharacter_NoRegister()
{
	return AEmberPlayerCharacter::StaticClass();
}
struct Z_Construct_UClass_AEmberPlayerCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Player/EmberPlayerCharacter.h" },
		{ "ModuleRelativePath", "Player/EmberPlayerCharacter.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpringArmComp_MetaData[] = {
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Player/EmberPlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraComponent_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Player/EmberPlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MovementComponent_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Player/EmberPlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraLogicComp_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Player/EmberPlayerCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpringArmComp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MovementComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraLogicComp;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AEmberPlayerCharacter_Look, "Look" }, // 683968589
		{ &Z_Construct_UFunction_AEmberPlayerCharacter_Move, "Move" }, // 443050814
		{ &Z_Construct_UFunction_AEmberPlayerCharacter_StartSprint, "StartSprint" }, // 928981553
		{ &Z_Construct_UFunction_AEmberPlayerCharacter_StopSprint, "StopSprint" }, // 1367296105
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEmberPlayerCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEmberPlayerCharacter_Statics::NewProp_SpringArmComp = { "SpringArmComp", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEmberPlayerCharacter, SpringArmComp), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpringArmComp_MetaData), NewProp_SpringArmComp_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEmberPlayerCharacter_Statics::NewProp_CameraComponent = { "CameraComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEmberPlayerCharacter, CameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraComponent_MetaData), NewProp_CameraComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEmberPlayerCharacter_Statics::NewProp_MovementComponent = { "MovementComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEmberPlayerCharacter, MovementComponent), Z_Construct_UClass_UC_CharacterMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MovementComponent_MetaData), NewProp_MovementComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEmberPlayerCharacter_Statics::NewProp_CameraLogicComp = { "CameraLogicComp", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEmberPlayerCharacter, CameraLogicComp), Z_Construct_UClass_UC_CameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraLogicComp_MetaData), NewProp_CameraLogicComp_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEmberPlayerCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEmberPlayerCharacter_Statics::NewProp_SpringArmComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEmberPlayerCharacter_Statics::NewProp_CameraComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEmberPlayerCharacter_Statics::NewProp_MovementComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEmberPlayerCharacter_Statics::NewProp_CameraLogicComp,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEmberPlayerCharacter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEmberPlayerCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEmberPlayerCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEmberPlayerCharacter_Statics::ClassParams = {
	&AEmberPlayerCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AEmberPlayerCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AEmberPlayerCharacter_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEmberPlayerCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AEmberPlayerCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEmberPlayerCharacter()
{
	if (!Z_Registration_Info_UClass_AEmberPlayerCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEmberPlayerCharacter.OuterSingleton, Z_Construct_UClass_AEmberPlayerCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEmberPlayerCharacter.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<AEmberPlayerCharacter>()
{
	return AEmberPlayerCharacter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEmberPlayerCharacter);
AEmberPlayerCharacter::~AEmberPlayerCharacter() {}
// End Class AEmberPlayerCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_1st_Team4_Final_Project_Source_EMBER_Player_EmberPlayerCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEmberPlayerCharacter, AEmberPlayerCharacter::StaticClass, TEXT("AEmberPlayerCharacter"), &Z_Registration_Info_UClass_AEmberPlayerCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEmberPlayerCharacter), 1243605553U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_1st_Team4_Final_Project_Source_EMBER_Player_EmberPlayerCharacter_h_846947555(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_1st_Team4_Final_Project_Source_EMBER_Player_EmberPlayerCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_1st_Team4_Final_Project_Source_EMBER_Player_EmberPlayerCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
