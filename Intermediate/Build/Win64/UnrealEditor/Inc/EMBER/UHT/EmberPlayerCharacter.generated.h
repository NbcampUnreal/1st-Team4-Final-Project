// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Player/EmberPlayerCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FInputActionValue;
#ifdef EMBER_EmberPlayerCharacter_generated_h
#error "EmberPlayerCharacter.generated.h already included, missing '#pragma once' in EmberPlayerCharacter.h"
#endif
#define EMBER_EmberPlayerCharacter_generated_h

#define FID_1st_Team4_Final_Project_Source_EMBER_Player_EmberPlayerCharacter_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execStopSprint); \
	DECLARE_FUNCTION(execStartSprint); \
	DECLARE_FUNCTION(execLook); \
	DECLARE_FUNCTION(execMove);


#define FID_1st_Team4_Final_Project_Source_EMBER_Player_EmberPlayerCharacter_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEmberPlayerCharacter(); \
	friend struct Z_Construct_UClass_AEmberPlayerCharacter_Statics; \
public: \
	DECLARE_CLASS(AEmberPlayerCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EMBER"), NO_API) \
	DECLARE_SERIALIZER(AEmberPlayerCharacter)


#define FID_1st_Team4_Final_Project_Source_EMBER_Player_EmberPlayerCharacter_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AEmberPlayerCharacter(AEmberPlayerCharacter&&); \
	AEmberPlayerCharacter(const AEmberPlayerCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEmberPlayerCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEmberPlayerCharacter); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEmberPlayerCharacter) \
	NO_API virtual ~AEmberPlayerCharacter();


#define FID_1st_Team4_Final_Project_Source_EMBER_Player_EmberPlayerCharacter_h_14_PROLOG
#define FID_1st_Team4_Final_Project_Source_EMBER_Player_EmberPlayerCharacter_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_1st_Team4_Final_Project_Source_EMBER_Player_EmberPlayerCharacter_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_1st_Team4_Final_Project_Source_EMBER_Player_EmberPlayerCharacter_h_17_INCLASS_NO_PURE_DECLS \
	FID_1st_Team4_Final_Project_Source_EMBER_Player_EmberPlayerCharacter_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EMBER_API UClass* StaticClass<class AEmberPlayerCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_1st_Team4_Final_Project_Source_EMBER_Player_EmberPlayerCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
