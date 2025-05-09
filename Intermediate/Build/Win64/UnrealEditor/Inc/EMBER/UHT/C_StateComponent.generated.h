// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Component/C_StateComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EStateType : uint8;
#ifdef EMBER_C_StateComponent_generated_h
#error "C_StateComponent.generated.h already included, missing '#pragma once' in C_StateComponent.h"
#endif
#define EMBER_C_StateComponent_generated_h

#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Component_C_StateComponent_h_8_DELEGATE \
EMBER_API void FStateTypeChanged_DelegateWrapper(const FMulticastScriptDelegate& StateTypeChanged, EStateType InPrevType, EStateType InNewType);


#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Component_C_StateComponent_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUC_StateComponent(); \
	friend struct Z_Construct_UClass_UC_StateComponent_Statics; \
public: \
	DECLARE_CLASS(UC_StateComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EMBER"), NO_API) \
	DECLARE_SERIALIZER(UC_StateComponent)


#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Component_C_StateComponent_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UC_StateComponent(UC_StateComponent&&); \
	UC_StateComponent(const UC_StateComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UC_StateComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UC_StateComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UC_StateComponent) \
	NO_API virtual ~UC_StateComponent();


#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Component_C_StateComponent_h_10_PROLOG
#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Component_C_StateComponent_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_1st_Team4_Final_Project_Source_EMBER_Component_C_StateComponent_h_13_INCLASS_NO_PURE_DECLS \
	FID_Git_1st_Team4_Final_Project_Source_EMBER_Component_C_StateComponent_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EMBER_API UClass* StaticClass<class UC_StateComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_1st_Team4_Final_Project_Source_EMBER_Component_C_StateComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
