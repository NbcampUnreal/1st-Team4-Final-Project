// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Component/C_CharacterMovementComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FInputActionValue;
#ifdef EMBER_C_CharacterMovementComponent_generated_h
#error "C_CharacterMovementComponent.generated.h already included, missing '#pragma once' in C_CharacterMovementComponent.h"
#endif
#define EMBER_C_CharacterMovementComponent_generated_h

#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Component_C_CharacterMovementComponent_h_10_DELEGATE \
EMBER_API void FOnMoveDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnMoveDelegate, FVector2D MoveVector);


#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Component_C_CharacterMovementComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnMove); \
	DECLARE_FUNCTION(execGetCurrentSpeed); \
	DECLARE_FUNCTION(execGetCanDash); \
	DECLARE_FUNCTION(execGetCanMove);


#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Component_C_CharacterMovementComponent_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUC_CharacterMovementComponent(); \
	friend struct Z_Construct_UClass_UC_CharacterMovementComponent_Statics; \
public: \
	DECLARE_CLASS(UC_CharacterMovementComponent, UCharacterMovementComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EMBER"), NO_API) \
	DECLARE_SERIALIZER(UC_CharacterMovementComponent)


#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Component_C_CharacterMovementComponent_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UC_CharacterMovementComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UC_CharacterMovementComponent(UC_CharacterMovementComponent&&); \
	UC_CharacterMovementComponent(const UC_CharacterMovementComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UC_CharacterMovementComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UC_CharacterMovementComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UC_CharacterMovementComponent) \
	NO_API virtual ~UC_CharacterMovementComponent();


#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Component_C_CharacterMovementComponent_h_12_PROLOG
#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Component_C_CharacterMovementComponent_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_1st_Team4_Final_Project_Source_EMBER_Component_C_CharacterMovementComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Git_1st_Team4_Final_Project_Source_EMBER_Component_C_CharacterMovementComponent_h_15_INCLASS_NO_PURE_DECLS \
	FID_Git_1st_Team4_Final_Project_Source_EMBER_Component_C_CharacterMovementComponent_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EMBER_API UClass* StaticClass<class UC_CharacterMovementComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_1st_Team4_Final_Project_Source_EMBER_Component_C_CharacterMovementComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
